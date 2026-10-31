#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ivcu_esc_sniffer.py -- Dekoder fuer Mitschnitte des IVCU<->ESC-Links (Weg 2)

Verarbeitet Rohdaten oder Hex-Dumps eines UART-Mitschnitts der 9600-Bd-Leitung
(IVCU USART2 <-> Motorcontroller) und dekodiert die Firmware-Frames:

  * 4A 11/14 3A/3B : IVCU -> ESC   (17 bzw. 20 Byte)
  * 0x71 3A/3B     : ESC -> IVCU   (13 Byte, XOR ueber [0..11])

Damit lassen sich die noch offenen Punkte klaeren:
  - Byte [1] des 0x71-Frames (Bedeutung unklar)
  - Einheiten der ESC-Datenbytes [4..9] (u16-Felder)
  - Skalierung von [10] ("Rot-Rohwert", 1 Byte)
  - Takt/Alive der 3A/3B-Kanaele

Beispiele:
  python ivcu_esc_sniffer.py capture.bin
  python ivcu_esc_sniffer.py capture.txt --hex
  python ivcu_esc_sniffer.py capture.bin --jsonl frames.jsonl --stats
  python ivcu_esc_sniffer.py --selftest

Hinweis: Frame-Layouts stammen aus der statischen Analyse (AWIVCU_APP R3.4.13,
siehe ivcu_protocol.py / ESC_Emulation_VESC.md). Das Skript aendert nichts --
es liest nur Logs, ideal fuer die geplante Sniffer-Session am Fahrzeug.
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ivcu_protocol as P  # noqa: E402

FOUR_A_LEN = {0x11: 17, 0x14: 20}
SUBTYPES = (0x3A, 0x3B)


# ---------------------------------------------------------------------------
#  Frame-Scanner (mit Resynchronisation)
# ---------------------------------------------------------------------------
def iter_frames(data, times=None):
    """Liefert (kind, frame_bytes, zeit) fuer jedes erkannte Frame.

    kind = '4A' oder '71'. Bei Zweifelsfaellen wird verworfen und um ein Byte
    weitergesucht (Resynchronisation), damit Teil-Mitschnitte nutzbar bleiben.
    """
    i, n = 0, len(data)
    while i < n:
        b = data[i]
        if b == 0x4A and i + 1 < n and data[i + 1] in FOUR_A_LEN:
            ln = FOUR_A_LEN[data[i + 1]]
            if (i + ln <= n) and (data[i + 2] in SUBTYPES):
                yield "4A", bytes(data[i:i + ln]), (times[i] if times else None)
                i += ln
                continue
        elif b == 0x71 and i + 13 <= n:
            if (data[i + 2] in SUBTYPES) or (P.xor8(data[i:i + 12]) == data[i + 12]):
                yield "71", bytes(data[i:i + 13]), (times[i] if times else None)
                i += 13
                continue
        i += 1


# ---------------------------------------------------------------------------
#  Laden (Binaer oder Hex-Text, optional mit Zeitstempeln je Zeile)
# ---------------------------------------------------------------------------
def load_binary(path):
    return Path(path).read_bytes(), None


def load_hexdump(path):
    tok = re.compile(r"\b[0-9A-Fa-f]{2}\b")
    # Zeitstempel tolerant: "1.234 ..." (mit Dezimalpunkt) oder "123: ..." (Ganzzahl + Doppelpunkt);
    # reine Hex-Zeilen wie "71 3A 00 ..." duerfen NICHT als Zeitstempel gelten!
    tline = re.compile(r"^\s*\[?\s*(\d+\.\d+)\s*\]?\s*[: ]|^\s*\[?\s*(\d+)\s*\]?\s*:")
    data = bytearray()
    times = []
    for raw in Path(path).read_text(encoding="utf-8", errors="replace").splitlines():
        line = raw.split(";", 1)[0].split("#", 1)[0]
        t = None
        m = tline.match(line)
        if m:
            try:
                t = float(m.group(1) or m.group(2))
            except ValueError:
                t = None
            line = line[m.end():]
        for h in tok.findall(line):
            data.append(int(h, 16))
            times.append(t)
    return bytes(data), times


# ---------------------------------------------------------------------------
#  Ausgabe
# ---------------------------------------------------------------------------
def describe_4a(frame):
    d = P.esc_parse(frame)
    parts = [
        "4A %s %s" % (d["variant_hex"], d["subtype"]),
        "GangByte=%d" % d["gear"],
        "Limit=%d" % d["gear_limit"],
        "Strom(F/R)=%d/%d" % (d["front_start_current"], d["rear_start_current"]),
        "Pack=%dV Code=%d" % (d["pack_voltage"], d["voltage_code"]),
        "Flags=0x%02X%s" % (d["control_flags"], " [CLAMP]" if d["clamp_scale_latch"] else ""),
        "ck=%s" % ("OK" if d["checksum_ok"] else ("?" if d["checksum_ok"] is None else "FALSCH")),
    ]
    if d["variant"] == 0x14:
        parts.append("tail=%s" % (" ".join("%02X" % b for b in d["tail3"])))
    return "  ".join(parts), d


def describe_71(frame):
    d = P.esc_parse_rx(frame)
    data = " ".join("%02X" % b for b in d["data11"])
    s = "71 %s  dual=%d  data=[%s]  ck=%s" % (
        d["subtype"], 1 if d["dual"] else 0, data,
        "OK" if d["checksum_ok"] else "FALSCH")
    return s, d


def main():
    ap = argparse.ArgumentParser(description="IVCU<->ESC UART-Mitschnitt dekodieren")
    ap.add_argument("input", nargs="?", help="Rohdatei (.bin) oder Hex-Dump (.txt)")
    ap.add_argument("--hex", action="store_true", help="Eingabe als Hex-Text lesen")
    ap.add_argument("--jsonl", metavar="DATEI", help="dekodierte Frames als JSONL schreiben")
    ap.add_argument("--stats", action="store_true", help="Statistik am Ende ausgeben")
    ap.add_argument("--selftest", action="store_true", help="Selbsttest mit synthetischen Frames")
    args = ap.parse_args()

    if args.selftest:
        return run_selftest()
    if not args.input:
        ap.error("Eingabedatei fehlt (oder --selftest verwenden)")

    data, times = (load_hexdump(args.input) if args.hex else load_binary(args.input))
    n_4a = n_71 = 0
    ck_bad = 0
    dual_seen = set()
    t_first = t_last = None
    jf = open(args.jsonl, "w", encoding="utf-8") if args.jsonl else None

    for kind, frame, t in iter_frames(data, times):
        if t is not None:
            t_first = t if t_first is None else min(t_first, t)
            t_last = t if t_last is None else max(t_last, t)
        stamp = ("%9.3f  " % t) if t is not None else ""
        if kind == "4A":
            n_4a += 1
            line, dec = describe_4a(frame)
            if dec.get("checksum_ok") is False:
                ck_bad += 1
        else:
            n_71 += 1
            line, dec = describe_71(frame)
            if not dec.get("checksum_ok"):
                ck_bad += 1
            if dec.get("dual"):
                dual_seen.add(dec.get("subtype"))
        print(stamp + line)
        if jf:
            jf.write(json.dumps({"t": t, "kind": kind, "raw": frame.hex(),
                                 "decoded": dec}, ensure_ascii=False) + "\n")
    if jf:
        jf.close()

    if args.stats:
        span = (t_last - t_first) if (t_first is not None and t_last is not None) else None
        print("\n--- Statistik ---")
        print("Frames: %d x 4A (IVCU->ESC), %d x 0x71 (ESC->IVCU)" % (n_4a, n_71))
        print("Checksummen-Fehler: %d" % ck_bad)
        print("Dual-Flag gesehen in: %s" % (", ".join(sorted(dual_seen)) or "keinem 0x71-Frame"))
        if span is not None:
            print("Zeitspanne laut Zeitstempeln: %.3f s" % span)
            if n_71 >= 4 and span > 0:
                print("0x71-Rate: ~%.1f Frames/s (je Subtyp entsprechend halb)" % (n_71 / span))
    return 0


# ---------------------------------------------------------------------------
#  Selbsttest (ohne Hardware)
# ---------------------------------------------------------------------------
def run_selftest():
    f1 = P.esc_build_4a("3A", 0x11, gear=2, gear_limit=25, rear_start_current=30,
                        pole_pairs=30, wheel=100, pack_voltage=60)
    f2 = P.esc_build_4a("3B", 0x14, gear=4, gear_limit=45, rear_start_current=55,
                        pack_voltage=60, tail3=(0x11, 0x22, 0x33))
    f3 = P.esc_build_4a("3B", 0x11, gear=0, gear_limit=15, rear_start_current=15)
    g1 = P.esc_build_71("3A", dual=True)
    g2 = P.esc_build_71("3B", dual=False)

    junk = bytes([0x00, 0xFF, 0x4A, 0x99, 0x71, 0x02, 0xAA])
    stream = junk + f1 + f2 + junk + f3 + g1 + g2
    frames = list(iter_frames(stream))
    ok = True

    def check(cond, msg):
        nonlocal ok
        if not cond:
            ok = False
        print("  [%s] %s" % ("OK" if cond else "FAIL", msg))

    check(len(frames) == 5, "5 Frames erkannt (ist %d)" % len(frames))
    if len(frames) == 5:
        kinds = [k for k, _, _ in frames]
        check(kinds == ["4A", "4A", "4A", "71", "71"], "Reihenfolge/Typen: %s" % kinds)
        d1 = P.esc_parse(frames[0][1])
        check(d1["gear"] == 2 and d1["gear_limit"] == 25, "Frame1: GangByte=2, Limit=25")
        d2 = P.esc_parse(frames[1][1])
        check(d2["variant"] == 0x14 and tuple(d2["tail3"]) == (0x11, 0x22, 0x33),
              "Frame2: 0x14 mit tail 11 22 33")
        d4 = P.esc_parse_rx(frames[3][1])
        d5 = P.esc_parse_rx(frames[4][1])
        check(d4["subtype"] == "3A" and d4["dual"] is True, "0x71 3A dual=True")
        check(d5["subtype"] == "3B" and d5["dual"] is False, "0x71 3B dual=False")
        check(d4["checksum_ok"] and d5["checksum_ok"], "0x71-Checksummen OK")

    print("Ergebnis: %s" % ("PASS" if ok else "FAIL"))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
