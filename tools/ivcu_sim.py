#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ivcu_sim.py - IVCU-Seiten-Simulator fuer Teverun (Firmware R3.4.13).

Erzeugt den Frame-Strom, den eine echte IVCU sendet, als annotierten
Hexdump (Dateilog) und optional auf einen seriellen Port (pyserial optional,
wird nur benutzt wenn installiert - sonst Hinweis).

Erzeugte Streams (Standard):
  * BLE/App (USART1, 115200): VCU->App-Telemetrie 55 43/52/71/72/73 alle 200 ms
  * Display (USART3, 9600)  : VCU->Display '35 27 3A/3B' alle 100 ms
                              (Speed-Feld aus --speed ueber den Rotationsrohwert,
                               Wheel-Rohbyte = --wheel, Default 100)
  * ESC (USART2, 9600)      : VCU->ESC '4A 11 3A/3B' alle 100 ms (Round-Robin,
                              Variante 0x11 mit Firmware-Checksummen-Eigenheit;
                              abschaltbar mit --no-esc)
  * Keep-Alive              : 10 Byte 00..09 an ESC UND Display alle 100 ms

Beispiele:
  python ivcu_sim.py --out sim_log.txt --duration 5 --speed 22 --soc 74 --gear 3 --version 3.4.13
  python ivcu_sim.py --selftest --duration 1 --out sim_selftest.txt
  python ivcu_sim.py --port COM3 --duration 10          (pyserial optional)
  python ivcu_sim.py --port COM3 --baud-mode --duration 10

Ausgabezeilen:  [t in s] LINK RICHTUNG HEX-BYTES | Anmerkung
"""

import argparse
import os
import re
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ivcu_protocol as P  # noqa: E402

try:  # pyserial NUR optional
    import serial as _serial  # type: ignore
    HAVE_PYSERIAL = True
except Exception:  # ImportError oder kaputte Installation
    _serial = None
    HAVE_PYSERIAL = False

__version__ = "1.0"

# Link-Baudraten der drei IVCU-UARTs (fuer --baud-mode)
LINK_BAUD = {"BLE": 115200, "DSP": 9600, "ESC": 9600, "KA": 9600}
KA_ON_BOTH = "->ESC+DSP"

VERSION_RE = re.compile(r"^\s*(\d+)\s*\.\s*(\d+)\s*\.\s*(\d+)\s*$")
LINE_RE = re.compile(r"^\[\s*([\d.]+)\s*\]\s+(\S+)\s+(\S+)\s+((?:[0-9A-F]{2}\s*)+)\|\s*(.*)$")


def _hexs(data):
    return " ".join("%02X" % b for b in data)


def parse_version(text):
    m = VERSION_RE.match(text)
    if not m:
        raise ValueError("--version erwartet 'a.b.c' (z.B. 3.4.13): %r" % text)
    ver = tuple(int(x) for x in m.groups())
    if any(v > 255 for v in ver):
        raise ValueError("Versionsbytes muessen 0..255 sein: %r" % (ver,))
    return ver


class Scenario(object):
    """Abgeleitete Fahrzeugwerte aus den CLI-Parametern."""

    def __init__(self, speed=22.0, soc=74, gear=3, version="3.4.13",
                 wheel_raw=100, cells=14):
        self.speed = float(speed)
        self.soc = int(soc)
        self.gear = int(gear)
        self.ver = parse_version(version)
        self.hw = (1, 0, 0)
        self.wheel_raw = int(wheel_raw)
        self.wheel_internal = self.wheel_raw * 0.1
        self.cells = int(cells)
        # Zellspannung aus SOC-Kennlinie -> Pack-Spannung
        self.cell_mv = P.mv_from_soc(self.soc)
        self.pack_v = self.cell_mv * self.cells / 1000.0
        # Stroeme/Temperaturen aus der Geschwindigkeit (glatte, plausible Werte)
        self.front_a = round(0.25 * self.speed, 1)
        self.rear_a = round(6.0 + 0.3 * self.speed, 1)
        self.pack_a = round(self.front_a + self.rear_a, 1)
        self.front_temp = int(round(32 + 0.4 * self.speed))
        self.rear_temp = int(round(35 + 0.5 * self.speed))
        # Rotationsrohwert + Display-Speed-Feld (aus --speed)
        self.rot_raw = P.rotation_raw_from_kmh(self.speed)
        self.speed_field = P.display_speed_field(self.speed)
        self.speed_raw = P.ble_speed_raw_from_kmh(self.speed, self.wheel_internal)
        # Fahrtwerte
        self.avg = round(self.speed * 0.9, 1)
        self.max = round(self.speed * 1.1, 1)
        self.trip = 12.3
        self.odo = 1234
        self.regen = round(0.07 * self.speed, 1)
        # Settings-Echo
        self.gear_limit = 60
        self.main_limit = 80
        self.pack_nominal = 60
        self.pole_pairs = 30


def scenario_notes(sc):
    """Annotationsbausteine je Frame (deutsch)."""
    return {
        "43": "55 43 HW-Info: SW %d.%d.%d" % sc.ver,
        "52": "55 52 Batterie: Pack %.1fV SOC %d%% Strom %.1fA"
              % (sc.pack_v, sc.soc, sc.pack_a),
        "71": "55 71 Settings: Gang %d Limit %d/%d Polpaare %d Wheel %.1f"
              % (sc.gear, sc.gear_limit, sc.main_limit, sc.pole_pairs,
                 sc.wheel_internal),
        "72": "55 72 Motor: F %.1fA R %.1fA SpeedRaw %d Temp R%d"
              % (sc.front_a, sc.rear_a, sc.speed_raw, sc.rear_temp),
        "73": "55 73 Fahrt: Avg %.1f Max %.1f Trip %.1f Odo %d"
              % (sc.avg, sc.max, sc.trip, sc.odo),
    }


def make_stream(sc, duration, esc=True):
    """Baut den kompletten Frame-Strom: Liste (t_ms, link, richtung, bytes, note)."""
    stream = []
    n = scenario_notes(sc)
    dur_ms = int(round(float(duration) * 1000.0))
    if dur_ms <= 0:
        raise ValueError("--duration muss > 0 sein")

    # Vorab gebaute Frames (Inhalt ist ueber die Laufzeit konstant)
    tele = [
        (P.ble_telemetry_5543(sc.ver, sc.hw), "BLE", n["43"]),
        (P.ble_telemetry_5552(sc.pack_v, sc.soc, pole_voltage_v=sc.pack_v - 0.1,
                              current_a=sc.pack_a,
                              temps=(24, 25, 25, 25, 25, 24, 25)),
         "BLE", n["52"]),
        (P.ble_telemetry_5571(gear=sc.gear, pole_pairs=sc.pole_pairs,
                              wheel_raw=sc.wheel_raw, gear_limit=sc.gear_limit,
                              main_limit=sc.main_limit, front_current=5,
                              rear_current=12, pack_nominal_v=sc.pack_nominal,
                              sleep_time=1, power_off_time=5), "BLE", n["71"]),
        (P.ble_telemetry_5572(sc.front_a, sc.rear_a, sc.speed_raw,
                              sc.front_temp, sc.rear_temp, front_ecu2=0x08,
                              ecu2=0x08), "BLE", n["72"]),
        (P.ble_telemetry_5573(sc.avg, sc.max, sc.trip, sc.odo, sc.regen,
                              system_status2=0x00), "BLE", n["73"]),
    ]

    def disp_frame(sub):
        return P.display_build_35(
            sub, status=0x00, flags=0x00, val_de=0x0000, val_e0=0,
            val_e2=0x0000, val_e4=sc.rot_raw, gear=sc.gear, mirror_flags=0x00,
            speed_field=sc.speed_field, soc=sc.soc, v35e=0x00, v35f=0x00,
            val_f0=0x0000, flag_f2=0x00, val_f4=0x0000, val_f8=0x0000,
            val_fe=0x0000, odometer=sc.odo * 10, status306=0x00,
            wheel=sc.wheel_raw, pack_voltage=int(round(sc.pack_v)),
            pole_pairs=sc.pole_pairs, temp_c=sc.rear_temp,
            start_level=2, gear_limit=sc.gear_limit, power_limit=70,
            rear_current=int(round(sc.rear_a)))

    def esc_frame(sub):
        # Firmware-Single-Mode: 0x11er, XOR ueber 19 Baupufferbytes,
        # Bytes [16..18] werden nicht uebertragen (tail3 hier 00 00 00).
        return P.esc_build_4a(sub, 0x11, gear=sc.gear, control_flags=0x00,
                              pole_pairs=sc.pole_pairs, wheel=sc.wheel_raw,
                              temp_threshold=120, front_start_current=2,
                              gear_limit=sc.gear_limit, power_limit=70,
                              rear_start_current=12, voltage_code=48,
                              pack_voltage=int(round(sc.pack_v)),
                              tail3=(0x00, 0x00, 0x00))

    ka = P.keepalive()
    t = 0
    tick = 0
    while t < dur_ms:
        sub = "3A" if tick % 2 == 0 else "3B"
        stream.append((t, "DSP", "VCU->DSP", disp_frame(sub),
                       "35 27 %s Display: SpeedFeld %d (Rot-Roh %d) SOC %d%% "
                       "Wheel %d Pack %dV"
                       % (sub, sc.speed_field, sc.rot_raw, sc.soc,
                          sc.wheel_raw, int(round(sc.pack_v)))))
        stream.append((t, "KA", KA_ON_BOTH, ka,
                       "Keep-Alive 00..09 an ESC + Display"))
        if esc:
            stream.append((t, "ESC", "VCU->ESC", esc_frame(sub),
                           "4A 11 %s ESC: Gang %d GearLimit %d Pack %dV "
                           "(17B, XOR ueber 19 Pufferbytes)"
                           % (sub, sc.gear, sc.gear_limit,
                              int(round(sc.pack_v)))))
        if t % 200 == 0:
            for frame, link, note in tele:
                stream.append((t, link, "VCU->APP", frame, note))
        t += 100
        tick += 1
    return stream


def expected_counts(duration, esc=True):
    dur_ms = int(round(float(duration) * 1000.0))
    ticks = (dur_ms + 99) // 100
    ble_ticks = (dur_ms + 199) // 200
    return {
        "BLE": 5 * ble_ticks,
        "DSP": ticks,
        "ESC": ticks if esc else 0,
        "KA": ticks,
    }


def write_stream(stream, path, sc, duration, esc=True):
    counts = {"BLE": 0, "DSP": 0, "ESC": 0, "KA": 0}
    with open(path, "w", encoding="utf-8", newline="\n") as fh:
        fh.write("# ivcu_sim.py %s - IVCU-Frame-Strom (Firmware R3.4.13)\n" % __version__)
        fh.write("# Parameter: duration=%.1fs speed=%.1f soc=%d gear=%d "
                 "version=%d.%d.%d wheel=%d\n"
                 % (duration, sc.speed, sc.soc, sc.gear, sc.ver[0], sc.ver[1],
                    sc.ver[2], sc.wheel_raw))
        fh.write("# Zeilen: [t s] LINK RICHTUNG HEX-BYTES | Anmerkung\n")
        for t_ms, link, direction, data, note in stream:
            counts[link] = counts.get(link, 0) + 1
            fh.write("[%6.3f] %-3s %-9s %s | %s\n"
                     % (t_ms / 1000.0, link, direction, _hexs(data), note))
        fh.write("# Summe: %d BLE, %d Display, %d ESC, %d Keep-Alive "
                 "(%d Frames, %.1f s)\n"
                 % (counts.get("BLE", 0), counts.get("DSP", 0),
                    counts.get("ESC", 0), counts.get("KA", 0),
                    len(stream), duration))
    return counts


def replay_serial(stream, port, baud, baud_mode):
    """Optionale serielle Ausgabe der generierten Frames."""
    if not HAVE_PYSERIAL:
        print("[Hinweis] pyserial ist nicht installiert - --port wird ignoriert "
              "(nur Dateilog). Installation: pip install pyserial")
        return 0
    try:
        ser = _serial.Serial(port, baudrate=baud, timeout=0, write_timeout=2)
    except Exception as exc:  # noqa: BLE001
        print("[Hinweis] %s konnte nicht geoeffnet werden (%r) - nur Dateilog."
              % (port, exc))
        return 0
    sent = 0
    try:
        t0 = time.perf_counter()
        for t_ms, link, _direction, data, _note in stream:
            if not baud_mode:
                target = t0 + t_ms / 1000.0
                delay = target - time.perf_counter()
                if delay > 0:
                    time.sleep(delay)
            ser.write(data)
            if baud_mode:
                ser.flush()
                link_baud = LINK_BAUD.get(link, 9600)
                time.sleep(len(data) * 10.0 / link_baud)
            sent += 1
    finally:
        ser.close()
    print("[OK] %d Frames auf %s gesendet (baud=%d%s)."
          % (sent, port, baud, ", baud-mode" if baud_mode else ""))
    return sent


def reparse_log(path):
    """Liest den Hexdump zurueck und prueft jeden Frame frame-genau."""
    errors = []
    counts = {"BLE": 0, "DSP": 0, "ESC": 0, "KA": 0}
    subtypes = {}
    with open(path, "r", encoding="utf-8") as fh:
        for lineno, line in enumerate(fh, 1):
            line = line.rstrip("\n")
            if not line or line.startswith("#"):
                continue
            m = LINE_RE.match(line)
            if not m:
                errors.append("Zeile %d nicht lesbar: %r" % (lineno, line))
                continue
            link = m.group(2)
            data = bytes(int(x, 16) for x in m.group(4).split())
            counts[link] = counts.get(link, 0) + 1
            try:
                if link == "BLE":
                    dec = P.BleFrame.parse(data).decode()
                    if len(data) != 20 or not dec["crc_ok"]:
                        errors.append("BLE Zeile %d: CRC/LEN" % lineno)
                    subtypes["BLE 55 %02X" % data[1]] = \
                        subtypes.get("BLE 55 %02X" % data[1], 0) + 1
                elif link == "DSP":
                    dec = P.display_parse(data)
                    if not dec["checksum_ok"]:
                        errors.append("DSP Zeile %d: XOR" % lineno)
                    key = "DSP 35 27 %s" % dec["subtype"]
                    subtypes[key] = subtypes.get(key, 0) + 1
                elif link == "ESC":
                    dec = P.esc_parse(data, hidden=(0x00, 0x00, 0x00))
                    if not dec["checksum_ok"]:
                        errors.append("ESC Zeile %d: XOR" % lineno)
                    if dec["variant"] != 0x11 or len(data) != 17:
                        errors.append("ESC Zeile %d: Variante/Laenge" % lineno)
                elif link == "KA":
                    if data != bytes(range(10)):
                        errors.append("KA Zeile %d: Zaehlerfolge" % lineno)
                else:
                    errors.append("Zeile %d: unbekannter Link %r" % (lineno, link))
            except Exception as exc:  # noqa: BLE001
                errors.append("Zeile %d: %r" % (lineno, exc))
    return counts, subtypes, errors


def run_selftest(duration, out_path, sc=None, esc=True):
    """Vollstaendiger Selbsttest: Protokoll-Checks + Sim-Stream-Roundtrip."""
    rows = []
    ok_all = True

    p_ok, p_lines = P.run_selftest(verbose=False)
    rows.extend(p_lines)
    ok_all &= p_ok

    sc = sc or Scenario()
    stream = make_stream(sc, duration, esc=esc)
    counts = write_stream(stream, out_path, sc, duration, esc=esc)
    exp = expected_counts(duration, esc=esc)
    r_counts, r_subtypes, errors = reparse_log(out_path)
    ok_stream = (not errors) and r_counts == exp
    ok_all &= ok_stream
    detail = ", ".join("%s %d/%d" % (k, r_counts.get(k, 0), exp[k])
                       for k in ("BLE", "DSP", "ESC", "KA"))
    rows.append("[S1] Sim-Stream (%s, %.1fs, %d Frames) reparst: %s  (%s%s)"
                % (os.path.basename(out_path), duration, len(stream),
                   "PASS" if ok_stream else "FAIL", detail,
                   "" if not errors else "; " + "; ".join(errors[:3])))
    sub_detail = ", ".join("%s=%d" % kv for kv in sorted(r_subtypes.items()))
    rows.append("[S2] Inhalt (Subtypen/CRC/XOR): %s  (%s)"
                % ("PASS" if ok_stream else "FAIL", sub_detail))
    rows.append("Ergebnis: %s" % ("PASS" if ok_all else "FAIL"))
    for row in rows:
        print(row)
    return ok_all


def main(argv=None):
    ap = argparse.ArgumentParser(
        description="ivcu_sim - IVCU-Seiten-Simulator (annotierter Frame-Strom)")
    ap.add_argument("--out", default="sim_log.txt", help="Zieldatei (Default sim_log.txt)")
    ap.add_argument("--duration", type=float, default=5.0, help="Sekunden (Default 5)")
    ap.add_argument("--speed", type=float, default=22.0, help="km/h (Default 22)")
    ap.add_argument("--soc", type=int, default=74, help="SOC %% (Default 74)")
    ap.add_argument("--gear", type=int, default=3, help="Gang 1..5 (Default 3)")
    ap.add_argument("--version", dest="version", default="3.4.13",
                    help="IVCU-Version a.b.c (Default 3.4.13)")
    ap.add_argument("--wheel", type=int, default=100,
                    help="Wheel-Rohbyte, Display/ESC (Default 100 = 10.0)")
    ap.add_argument("--cells", type=int, default=14,
                    help="Zellzahl fuer SOC->Pack-Spannung (Default 14)")
    ap.add_argument("--no-esc", action="store_true",
                    help="ESC-4A-Frames nicht erzeugen")
    ap.add_argument("--port", default=None, help="optionaler serieller Port (pyserial)")
    ap.add_argument("--baud", type=int, default=115200,
                    help="Baudrate fuer --port (Default 115200)")
    ap.add_argument("--baud-mode", action="store_true",
                    help="Sende-Timing je Link-Baudrate simulieren (9600/115200)")
    ap.add_argument("--selftest", action="store_true",
                    help="Selbsttest (CRC, Build->Parse, XOR, SOC, Stream-Roundtrip)")
    args = ap.parse_args(argv)

    esc = not args.no_esc
    try:
        sc = Scenario(args.speed, args.soc, args.gear, args.version,
                      args.wheel, args.cells)
    except ValueError as exc:
        print("Fehler: %s" % exc, file=sys.stderr)
        return 2

    if args.selftest:
        ok = run_selftest(args.duration, args.out, sc, esc=esc)
        return 0 if ok else 1

    stream = make_stream(sc, args.duration, esc=esc)
    counts = write_stream(stream, args.out, sc, args.duration, esc=esc)
    print("[OK] %s: %d Frames (%d BLE, %d Display, %d ESC, %d Keep-Alive, %.1f s)"
          % (args.out, len(stream), counts.get("BLE", 0), counts.get("DSP", 0),
             counts.get("ESC", 0), counts.get("KA", 0), args.duration))
    if args.port:
        replay_serial(stream, args.port, args.baud, args.baud_mode)
    elif not HAVE_PYSERIAL:
        print("[Hinweis] pyserial nicht installiert - serielle Ausgabe via "
              "--port erst nach 'pip install pyserial' moeglich.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
