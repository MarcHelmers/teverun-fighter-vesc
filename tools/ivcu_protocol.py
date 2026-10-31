#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ivcu_protocol.py - Codec-Bibliothek fuer die drei Teverun-IVCU-Links (Firmware R3.4.13).

Nur Python-Standardbibliothek. Verifiziert gegen die Firmware AWIVCU_APP_R3_4_13
(Decompile in D:\\DEV\\Teverun) sowie die oeffentliche, am Fahrzeug validierte
Community-Referenz (Laufbursche42/tr-lb-edition, "BLE protocol reference").

=============================================================================
1) BLE/App-Link (USART1, 115200 Bd) - 20-Byte-Frames, CRC-8/ATM
=============================================================================
  App -> VCU :  [0]=0xAA  [1]=cmdId  [2..18]=Payload(17)  [19]=CRC-8
  VCU -> App :  [0]=0x55  [1]=Frame-ID/Subtyp (0x43,0x52,0x71,...)
                [2..18]=Payload(17)  [19]=CRC-8
  CRC-8/ATM  :  Poly 0x07, Init 0x00, MSB-first, kein Reflektieren,
                kein XOR-out, ueber Bytes [0..18]. (FUN_0800bda6/FUN_0800f9ac)
  Mehrbytewerte: BIG-ENDIAN.
  Hinweis: Die 0xAA-Rahmung gilt fuer App->VCU; die Telemetrie des VCU beginnt
  mit 0x55 (Firmware-Fund: CONCAT22(_,0x4355) = Bytes "55 43" im Framebuffer,
  CRC ueber 19 Bytes; konsistent mit der am Fahrzeug validierten Community-
  Referenz, die eingehende Frames auf t[0]==0x55 prueft).

  Telemetrie-Telegramme (Feldindizes = Volle 20-Byte-Frame-Indizes!):
    55 43  Hardwareinfo : [2..4]=SW a,b,c ; [6..8]=HW a,b,c  (0=unbenutzt)
    55 52  Batterie     : [2..3] Pack V*0.1 BE ; [4..5] Pol V*0.1 ;
                          [6..7] Strom*0.1-1000 (0=keine Angabe) ; [8] SOC% ;
                          [9] SOH ; [10..16] Akku-Temps -40 ; [17]/[18]
                          max/min Zelltemperatur -40
    55 71  Settings-Echo: [2] Unlock/TestLock ; [3] Gang ; [4] rControlStatus ;
                          [5] Polpaare ; [6] Wheel*0.1 (roh) ; [7] Schutz-Temp ;
                          [8] Nibbles (low=FrontStart-Level) ; [9] (high=EABS,
                          low=RearStart-Level) ; [10] Gang-Limit ; [11] Haupt-
                          Limit ; [12] Front-Strom ; [13] Rear-Strom ;
                          [15] Pack nom. ; [16] fControlStatus ; [17] Statusbits
                          ; [18] Timer-Byte (Sleep=&7, PowerOff=(>>3)&31)
    55 72  Motor        : [2]/[3] Front-ECU-Status ; [4..5] FrontStrom*0.1 ;
                          [9] FrontTemp ; [10]/[11] ECU-Status (Bit3=RearOn) ;
                          [12..13] RearStrom*0.1 ; [15..16] Speed-Roh ;
                          [17] RearTemp ; [18] Status3
    55 73  Fahrt        : [2..3] Avg*0.1 ; [4..5] Max*0.1 ; [6..7] Trip*0.1 ;
                          [8..10] Odometer 3B BE (km) ; [11..12] Regen*0.1 ;
                          [16] System2 (bit0 BatLock, bit1 GPS-Lock) ;
                          [17] customKey ; [18] Status73
  App->VCU-Befehle (Auswahl): 0x1F = FIN-/BLE-Name ([2..17] 16 ASCII, space-
  padded, [18]=0xFF). Weitere Cmd-IDs existieren; Parser bleibt generisch.

=============================================================================
2) ESC/Motorcontroller-Link (USART2, 9600 Bd) - 4A-Frames + 0x71-Antworten
=============================================================================
  VCU -> ESC, Baupuffer 20 Byte @0x20001392, vier Varianten (4A 11/14 3A/3B),
  Round-Robin FUN_080105a8 (Single: 0x11er, Dual: 0x14er bzw. alternierend):
    [0]=0x4A [1]=Laengenvariante(0x11|0x14) [2]=Subtyp(0x3A|0x3B) [3]=0
    [4]=Gang [5]=Steuerflags ([5] Bit5 = Clamp/Scale-Latch 0x2000030D)
    [6]=Polpaare [7]=Wheel [8]=Temp-Schwelle [9]=Front-Start-Strom
    [10]=Gang-Limit [11]=Power-Limit [12]=Rear-Start-Strom
    [13]=Spannungscode [14]=Pack-Spannung [15]=Statusflags (Bit7 0x200002CD,
    Bit5 0x20000314)
    [16..18] = 0x200002CE/CF/D0 (NUR bei 0x14er-Varianten geschrieben)
    [19]=XOR ueber die 19 Pufferbytes [0..18]

  EIGENHEIT der 0x11-Varianten (FUN_0800fe96/FUN_08010238), exakt wie Firmware:
    * XOR wird ueber den 19-Byte-Baupuffer [0..18] gerechnet (Checksumme @[19]).
    * Auf die Leitung gehen NUR [0..15] + Checksumme => TX = 17 Byte:
            wire = build[0..15] + build[19]
      Die Pufferbytes [16..18] werden NICHT uebertragen, sind aber Teil der
      XOR-Summe! (Single-Mode: sie stammen aus dem geteilten Baupuffer, d.h.
      zuletzt von einem 0x14er-Frame beschrieben oder uninitialisiert.)
    * 0x14-Varianten: XOR ueber [0..18] @[19], TX = kompletter Puffer (20 Byte).

  ESC -> VCU: 0x71-Frame, ISR FUN_0800b5ca sammelt 13 Bytes; Consumer
  FUN_0800fa94 prueft XOR ueber 12 Byte == letztes Byte (13.):
    [0]=0x71 [1]..[11]=11 Datenbytes [2]=Typmarker ':'(0x3A)/';'(0x3B)
    [9] Bit0 => Dual/Single-Flag 0x20000398 ; [12]=XOR([0..11]).
  (Der RAM-Schatten hat an Index 12 eine Luecke, daher im Decompile "+13".)

=============================================================================
3) Display-Link (USART3, 9600 Bd)
=============================================================================
  VCU -> Display Befehl 0x35, Laenge 0x27=39, Subtyp '3A' (FUN_080107da) bzw.
  '3B' (FUN_08010648), XOR ueber [0..37] in [38].  VERIFIZIERTES Layout
  (Ghidra-Ausgabe beider Builder; Datenspiegel 0x200002xx/0x200003xx):
    [0]=0x35 [1]=0x27 [2]=Subtyp
    [3]=Status (0x200002DB)         [4]=Flagbyte (Bit1=Clamp/Scale 0x2000030D)
    [5..6]=u16 BE (0x200002DE)      [7]=(0x200002E0)
    [8..9]=u16 BE (0x200002E4-analog) = ROTATIONSZEIT (Display-FW-verifiziert!)
                                 [10]=0x200002E6
    [11]=Gang                        [12]=0x200002A3/A2 & 0xFE (Spiegelflags)
    [13]=Speed-Feld (0x2000036D-0x28, 0 unter 0x29)
    [14]=SOC (0x20000364)            [15]=0x2000035E [16]=0x2000035F
    [17..18]=u16 BE (0x200002F0)     [19]=0x200002F2 & 0x5F
    [20..21]=u16 BE (0x200002F4)     [22..23]=u16 BE (0x200002F8)
    [24..25]=u16 BE (0x200002FE)     [26..28]=Odometer/10, 3B BE (0x20000300/10)
    [29]=Statusbyte (0x20000306)     [30]=Wheel (0x200002A5)
    [31]=Pack-Spannung (0x200002C7)  [32]=Polpaare (0x200002A4)
    [33]=(Temp-80)/5                 [34]=Start-Level (0x200002A7[Gang])
    [35]=Gang-Limit (0x200002B3[G])  [36]=Power-Limit (0x200002B9)
    [37]=Rear-Strom (0x200002BA[G] / 0x200002C0[G])   [38]=XOR ueber [0..37]
  ACHTUNG: Byte [12] existiert (Spiegelflags). Eine kursierende Kurzangabe
  liess es aus und war ab Index 12 um +1 verschoben - hier gilt das am ROM
  verifizierte Layout.

  Display -> VCU (ISR FUN_0800b6cc, exakte Laengen):
    0x4C ('L') 19 B : XOR ueber 18 B == Byte 18; Byte2==0x35 => Kommandoframe,
                      Byte3 = Cmd-ID 1..9 (1 Gang, 2 Flags/Clamp-Latch=Byte5
                      Bit5, 3 Eco, 4 Dual/TCS, 5 Settings-Write, 7 Smart/TCS,
                      9 0x2000031E; Tail: Byte6 Bit2/Bit7 -> 0x20000314/0x200002CD)
    0x8A       11 B : Byte2 8/9/10 = 3-stufige Uebernahme
    0x8B        8 B : Byte2/4/6 == 0xAA
    0x8C        8 B : Byte2==1, Byte5/6==0xAA
  Keep-Alive: 10 Byte 00 01 02 ... 09 an ESC UND Display (FUN_08019b82).

=============================================================================
4) SOC-Kennlinie
=============================================================================
  Tabelle soc_mv[101] wird zur Laufzeit aus soc_kennlinie.c geladen (Regex).
  soc_from_mv(mv): stuecklinear ueber alle 101 Punkte (gerundet, 0..100).
  mv_from_soc(soc): Tabellenwert. Zusatz: soc_from_mv_step() = Firmware-
  Binärsuche; display_speed_field() = [13]-Feld aus dem Rotationsrohwert.
  HINWEIS: soc_from_mv(3600) == 48 (Tabelleninterpolation; die in der
  Aufgabenstellung genannten "~41-45" stammen aus einer groeberen Naeherung).

API-Uebersicht:
  crc8_atm(data[, length]) ; xor8(data[, length])
  BleFrame.build/parse/decode/telemetry
  ble_telemetry_5543(ver, hw) ; ble_telemetry_5552(...) ; ble_telemetry_5571(...)
  ble_telemetry_5572(...) ; ble_telemetry_5573(...) ; ble_cmd_fin(name)
  ble_parse(data) (Alias: BleFrame.parse + decode)
  esc_build_4a(subtype, length_variant, **felder) ; esc_parse(frame[, hidden])
  esc_build_71(subtype, data, dual) ; esc_parse_rx(frame)
  display_build_35(subtype, **felder) ; display_parse(frame) ; display_parse_rx(frame)
  keepalive(i=0)
  load_soc_table([path]) ; soc_table() ; soc_from_mv(mv) ; soc_from_mv_step(mv)
  soc_from_mv_float(mv) ; mv_from_soc(soc) ; display_speed_field(kmh)
  ble_speed_raw_from_kmh(kmh, wheel)
"""

import argparse
import os
import re
import sys

__version__ = "1.0"

# ---------------------------------------------------------------------------
# Hilfsfunktionen
# ---------------------------------------------------------------------------


def _bytes(data):
    if isinstance(data, (bytes, bytearray, memoryview)):
        return bytes(data)
    raise TypeError("Bytes erwartet, nicht %r" % type(data).__name__)


def _u16be(data, i):
    return (data[i] << 8) | data[i + 1]


def _u24be(data, i):
    return (data[i] << 16) | (data[i + 1] << 8) | data[i + 2]


def _put_u16be(buf, i, value):
    value &= 0xFFFF
    buf[i] = (value >> 8) & 0xFF
    buf[i + 1] = value & 0xFF


def _put_u24be(buf, i, value):
    value &= 0xFFFFFF
    buf[i] = (value >> 16) & 0xFF
    buf[i + 1] = (value >> 8) & 0xFF
    buf[i + 2] = value & 0xFF


def _need_byte(name, value):
    v = int(value)
    if not 0 <= v <= 0xFF:
        raise ValueError("Feld %r ausserhalb 0..255: %r" % (name, value))
    return v


def _need_u16(name, value):
    v = int(value)
    if not 0 <= v <= 0xFFFF:
        raise ValueError("Feld %r ausserhalb 0..65535: %r" % (name, value))
    return v


def _hexs(data, sep=" "):
    return sep.join("%02X" % b for b in data)


# ---------------------------------------------------------------------------
# Pruefsummen
# ---------------------------------------------------------------------------


def crc8_atm(data, length=None):
    """CRC-8/ATM: Poly 0x07, Init 0x00, MSB-first, kein Reflektieren/XOR-out.

    Entspricht FUN_0800bda6 / FUN_0800f9ac der Firmware (8 Shifts je Byte,
    Akkumulator wird je Byte auf 8 Bit maskiert; Ergebnis identisch zur
    ueblichen Implementierung). length=None => ueber gesamte Sequenz.
    """
    data = _bytes(data)
    if length is not None:
        data = data[: int(length)]
    crc = 0
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = ((crc << 1) ^ 0x07) & 0xFF if crc & 0x80 else (crc << 1) & 0xFF
    return crc


# Alias fuer Aufrufer, die nur "crc8" erwarten
crc8 = crc8_atm


def xor8(data, length=None):
    """Byte-XOR ueber data (bzw. die ersten length Bytes) - Frame-Pruefsumme
    der Display-/ESC-Frames. Reihenfolge ist fuer XOR irrelevant, aber die
    Firmware prueft ueber exakt diese Laengen."""
    data = _bytes(data)
    if length is not None:
        data = data[: int(length)]
    acc = 0
    for b in data:
        acc ^= b
    return acc


# ---------------------------------------------------------------------------
# BLE/App-Link (20-Byte-Frames, CRC-8/ATM)
# ---------------------------------------------------------------------------

BLE_FRAME_LEN = 20
BLE_HEADER_APP = 0xAA  # App -> VCU
BLE_HEADER_VCU = 0x55  # VCU -> App (Telemetrie)

# Subtypen der VCU->App-Telemetrie
BLE_55_HWINFO = 0x43
BLE_55_BATTERY = 0x52
BLE_55_SETTINGS = 0x71
BLE_55_MOTOR = 0x72
BLE_55_RIDE = 0x73
# App->VCU-Befehle (Auszug; Parser bleibt generisch)
BLE_CMD_FIN_NAME = 0x1F


class BleFrame(object):
    """20-Byte-BLE-Frame des Teverun-IVCU-Protokolls.

    App -> VCU : Header 0xAA, [1]=cmdId, [2..18]=Payload, [19]=CRC-8.
    VCU -> App : Header 0x55, [1]=Frame-ID, [2..18]=Payload, [19]=CRC-8.
    """

    APP_HEADER = BLE_HEADER_APP
    VCU_HEADER = BLE_HEADER_VCU
    LEN = BLE_FRAME_LEN

    def __init__(self, header, cmd, payload, crc=None, crc_ok=True):
        payload = _bytes(payload)
        if len(payload) != 17:
            raise ValueError("BLE-Payload muss 17 Byte sein (ist %d)" % len(payload))
        self.header = int(header) & 0xFF
        self.cmd = int(cmd) & 0xFF
        self.payload = payload
        self.crc = int(crc) & 0xFF if crc is not None else crc8_atm(bytes([self.header, self.cmd]) + payload)
        self.crc_ok = bool(crc_ok)

    # -- Bauen -------------------------------------------------------------
    @classmethod
    def build(cls, cmd, payload=b"", header=BLE_HEADER_APP, fill=0xFF):
        """App->VCU-Frame: payload wird auf 17 Byte mit fill aufgefuellt."""
        payload = _bytes(payload)
        if len(payload) > 17:
            raise ValueError("Payload > 17 Byte (%d)" % len(payload))
        payload = payload + bytes([fill & 0xFF]) * (17 - len(payload))
        body = bytes([header & 0xFF, cmd & 0xFF]) + payload
        return cls(header, cmd, payload, crc8_atm(body))

    @classmethod
    def telemetry(cls, subtype, payload=b"", fill=0x00):
        """VCU->App-Telemetrie: Header 0x55, [1]=Subtyp (Payload mit fill)."""
        return cls.build(subtype, payload, header=BLE_HEADER_VCU, fill=fill)

    # -- Parsen ------------------------------------------------------------
    @classmethod
    def parse(cls, data):
        """Parst 20 Byte; CRC-Fehler sind kein Fehler, crc_ok wird False."""
        data = _bytes(data)
        if len(data) != BLE_FRAME_LEN:
            raise ValueError("BLE-Frame muss 20 Byte sein (ist %d)" % len(data))
        header, cmd = data[0], data[1]
        if header not in (BLE_HEADER_APP, BLE_HEADER_VCU):
            raise ValueError("Unbekannter BLE-Header 0x%02X" % header)
        payload = data[2:19]
        frame = cls(header, cmd, payload, crc=data[19])
        frame.crc_ok = crc8_atm(data[:19]) == data[19]
        return frame

    # -- Ausgabe -----------------------------------------------------------
    def to_bytes(self):
        return bytes([self.header, self.cmd]) + self.payload + bytes([self.crc])

    def __bytes__(self):
        return self.to_bytes()

    def __repr__(self):
        return "BleFrame(header=0x%02X, cmd=0x%02X, crc_ok=%s)" % (
            self.header,
            self.cmd,
            self.crc_ok,
        )

    # -- Semantik ----------------------------------------------------------
    def decode(self):
        """Feldwerte + Plausibilitaetswarnungen fuer bekannte Subtypen."""
        t = bytes([self.header, self.cmd]) + self.payload
        out = {
            "header": self.header,
            "cmd": self.cmd,
            "payload_hex": _hexs(self.payload),
            "raw_hex": _hexs(t + bytes([self.crc])),
            "crc_ok": self.crc_ok,
            "warnings": [],
        }
        w = out["warnings"]
        if not self.crc_ok:
            w.append("CRC-8 stimmt nicht (erwartet 0x%02X, gelesen 0x%02X)"
                     % (crc8_atm(t[:19]), self.crc))
        if self.header == BLE_HEADER_VCU:
            d = _decode_telemetry(self.cmd, t, w)
        else:
            d = _decode_app_cmd(self.cmd, t, w)
        out["fields"] = d
        return out


def _decode_telemetry(sub, t, w):
    """t = 20 Byte Frame (0x55 ...). Liefert Feld-Dict gemaess Community-
    verifiziertem Layout; unbekannte Subtypen bleiben roh."""
    if sub == BLE_55_HWINFO:
        sw = (t[2], t[3], t[4])
        hw = (t[6], t[7], t[8])
        if sw == (0, 0, 0):
            w.append("SW-Version 0.0.0 (Feld nicht gesetzt?)")
        return {"kind": "hardwareinfo", "sw_ver": sw, "sw_str": "%d.%d.%d" % sw,
                "hw_ver": hw, "hw_str": None if hw[0] == 0 else "%d.%d.%d" % hw}
    if sub == BLE_55_BATTERY:
        pack_v = _u16be(t, 2) * 0.1
        pole_v = _u16be(t, 4) * 0.1
        cur_raw = _u16be(t, 6)
        d = {
            "kind": "battery",
            "pack_voltage_v": pack_v,
            "pole_voltage_v": pole_v,
            "pack_current_a": None if cur_raw == 0 else cur_raw * 0.1 - 1000.0,
            "soc_pct": t[8],
            "soh_pct": t[9],
            "temps_c": [t[10 + i] - 40 for i in range(7)],
            "max_cell_temp_c": t[17] - 40,
            "min_cell_temp_c": t[18] - 40,
        }
        if not 20.0 <= pack_v <= 120.0 and pack_v != 0.0:
            w.append("Pack-Spannung %.1f V unplausibel (erwartet 20..120 V)" % pack_v)
        if t[8] > 100:
            w.append("SOC %d%% > 100" % t[8])
        if cur_raw == 0:
            w.append("Stromfeld 0 (kein Messwert? Community: nicht gemeldet)")
        return d
    if sub == BLE_55_SETTINGS:
        timer = t[18]
        d = {
            "kind": "settings",
            "unlock_testlock": t[2],
            "gear": t[3],
            "rear_control_status": t[4],
            "pole_pairs": t[5],
            "wheel_raw": t[6],
            "wheel_internal": t[6] * 0.1,
            "protection_temp_c": t[7],
            "assist1": t[8],
            "front_start_level": t[8] & 0x0F,
            "assist2": t[9],
            "eabs_regen": (t[9] >> 4) & 0x0F,
            "rear_start_level": t[9] & 0x0F,
            "gear_limit": t[10],
            "main_limit": t[11],
            "front_current": t[12],
            "rear_current": t[13],
            "pack_nominal_v": t[15],
            "fcontrol_status": t[16],
            "system_status": t[17],
            "eco_mode": bool(t[17] & 0x01),
            "unit_miles": bool(t[17] & 0x02),
            "anti_theft": bool(t[17] & 0x04),
            "traction_control": bool(t[17] & 0x10),
            "reverse": bool(t[17] & 0x20),
            "ekfv_hw_flag": bool(t[17] & 0x40),
            "monitor_mode": bool(t[17] & 0x80),
            "sleep_timer": timer & 0x07,
            "power_off_timer": (timer >> 3) & 0x1F,
            "timer_byte": timer,
        }
        if not 1 <= d["gear"] <= 5:
            w.append("Gang %d ausserhalb 1..5" % d["gear"])
        return d
    if sub == BLE_55_MOTOR:
        d = {
            "kind": "motor",
            "front_ecu_status1": t[2],
            "front_ecu_status2": t[3],
            "dual_motor_bit": bool(t[3] & 0x08),
            "front_motor_current_a": _u16be(t, 4) * 0.1,
            "front_motor_temp_c": t[9] if t[9] > 0 else None,
            "ecu_status1": t[10],
            "ecu_status2": t[11],
            "rear_motor_on": bool(t[11] & 0x08),
            "rear_motor_current_a": _u16be(t, 12) * 0.1,
            "speed_raw": _u16be(t, 15),
            "rear_motor_temp_c": t[17] if t[17] > 0 else None,
            "system_status3": None if t[18] == 0xFF else t[18],
        }
        if d["speed_raw"] >= 3000:
            w.append("speed_raw >= 3000 (Community: als 0 zu behandeln)")
        return d
    if sub == BLE_55_RIDE:
        d = {
            "kind": "ride",
            "avg_speed_kmh": _u16be(t, 2) * 0.1,
            "max_speed_kmh": _u16be(t, 4) * 0.1,
            "trip_km": _u16be(t, 6) * 0.1,
            "odometer_km": _u24be(t, 8),
            "regen": _u16be(t, 11) * 0.1,
            "system_status2": None if t[16] == 0xFF else t[16],
            "battery_lock": None if t[16] == 0xFF else bool(t[16] & 0x01),
            "gps_lock": None if t[16] == 0xFF else bool(t[16] & 0x02),
            "custom_key": t[17],
            "status73": None if t[18] == 0xFF else t[18],
        }
        for k in ("avg_speed_kmh", "max_speed_kmh"):
            if d[k] > 120.0:
                w.append("%s %.1f km/h unplausibel" % (k, d[k]))
        return d
    return {"kind": "raw"}


def _decode_app_cmd(cmd, t, w):
    if cmd == BLE_CMD_FIN_NAME:
        name = bytes(t[2:18]).decode("ascii", "replace").rstrip(" ")
        if t[18] != 0xFF:
            w.append("Byte [18]=0x%02X (erwartet 0xFF)" % t[18])
        return {"kind": "fin_name", "name": name}
    return {"kind": "raw"}


def ble_parse(data):
    """Komfort-Alias: 20-Byte-BLE-Frame parsen + dekodieren (dict)."""
    return BleFrame.parse(data).decode()


# --- Telemetrie-Builder ----------------------------------------------------


def ble_telemetry_5543(ver=(3, 4, 13), hw=(0, 0, 0), extra=None):
    """VCU->App 55 43 Hardwareinfo. ver/hw = (a,b,c); hw=(0,0,0) = 'unbenutzt'."""
    p = bytearray(17)
    p[0:3] = bytes([_need_byte("ver.a", ver[0]), _need_byte("ver.b", ver[1]),
                    _need_byte("ver.c", ver[2])])
    p[4:7] = bytes([_need_byte("hw.a", hw[0]), _need_byte("hw.b", hw[1]),
                    _need_byte("hw.c", hw[2])])
    # [3] = 0x2000000F (Identitaetsbyte), [7..11]/[12..16] = Board-/Rahmendaten
    if extra:
        for idx, val in extra.items():
            p[int(idx)] = _need_byte("extra[%d]" % idx, val)
    return BleFrame.telemetry(BLE_55_HWINFO, bytes(p)).to_bytes()


def ble_telemetry_5552(pack_voltage_v, soc, pole_voltage_v=0.0, current_a=None,
                       soh=100, temps=(25, 25, 25, 25, 25, 25, 25),
                       max_cell_temp_c=None, min_cell_temp_c=None, extra=None):
    """VCU->App 55 52 Batterie. current_a=None => Feld 0 (nicht gemeldet)."""
    p = bytearray(17)
    _put_u16be(p, 0, int(round(pack_voltage_v * 10)))
    _put_u16be(p, 2, int(round(pole_voltage_v * 10)))
    _put_u16be(p, 4, 0 if current_a is None else int(round((current_a + 1000.0) * 10)))
    p[6] = _need_byte("soc", soc)
    p[7] = _need_byte("soh", soh)
    for i in range(7):
        p[8 + i] = _need_byte("temp%d" % i, temps[i] + 40)
    tmax = max(temps) if max_cell_temp_c is None else max_cell_temp_c
    tmin = min(temps) if min_cell_temp_c is None else min_cell_temp_c
    p[15] = _need_byte("max_cell_temp", tmax + 40)
    p[16] = _need_byte("min_cell_temp", tmin + 40)
    if extra:
        for idx, val in extra.items():
            p[int(idx)] = _need_byte("extra[%d]" % idx, val)
    return BleFrame.telemetry(BLE_55_BATTERY, bytes(p)).to_bytes()


def ble_telemetry_5571(gear=1, pole_pairs=30, wheel_raw=100, gear_limit=0,
                       main_limit=0, front_current=0, rear_current=0,
                       pack_nominal_v=60, unlock=0, rear_control_status=0,
                       protection_temp_c=120, front_start_level=0,
                       eabs_regen=0, rear_start_level=0, fcontrol_status=0,
                       system_status=0, sleep_time=0, power_off_time=0,
                       assist1=None, assist2=None, extra=None):
    """VCU->App 55 71 Settings-Echo (aktueller Gang + dessen Werte)."""
    p = bytearray(17)
    p[0] = _need_byte("unlock", unlock)
    p[1] = _need_byte("gear", gear)
    p[2] = _need_byte("rear_control_status", rear_control_status)
    p[3] = _need_byte("pole_pairs", pole_pairs)
    p[4] = _need_byte("wheel_raw", wheel_raw)
    p[5] = _need_byte("protection_temp_c", protection_temp_c)
    p[6] = (_need_byte("assist1", assist1) if assist1 is not None
            else (_need_byte("front_start_level", front_start_level) & 0x0F))
    p[7] = (_need_byte("assist2", assist2) if assist2 is not None
            else (((_need_byte("eabs_regen", eabs_regen) & 0x0F) << 4)
                  | (_need_byte("rear_start_level", rear_start_level) & 0x0F)))
    p[8] = _need_byte("gear_limit", gear_limit)
    p[9] = _need_byte("main_limit", main_limit)
    p[10] = _need_byte("front_current", front_current)
    p[11] = _need_byte("rear_current", rear_current)
    p[13] = _need_byte("pack_nominal_v", pack_nominal_v)
    p[14] = _need_byte("fcontrol_status", fcontrol_status)
    p[15] = _need_byte("system_status", system_status)
    p[16] = _need_byte("timer_byte", (sleep_time & 0x07) | ((power_off_time & 0x1F) << 3))
    if extra:
        for idx, val in extra.items():
            p[int(idx)] = _need_byte("extra[%d]" % idx, val)
    return BleFrame.telemetry(BLE_55_SETTINGS, bytes(p)).to_bytes()


def ble_telemetry_5572(front_current_a=0.0, rear_current_a=0.0, speed_raw=0,
                       front_temp_c=0, rear_temp_c=0, front_ecu1=0, front_ecu2=0,
                       ecu1=0, ecu2=0, status3=0xFF, extra=None):
    """VCU->App 55 72 Motor (Stroeme, Rohtempo, Temperaturen, ECU-Status)."""
    p = bytearray(17)
    p[0] = _need_byte("front_ecu1", front_ecu1)
    p[1] = _need_byte("front_ecu2", front_ecu2)
    _put_u16be(p, 2, int(round(front_current_a * 10)))
    p[7] = _need_byte("front_temp_c", front_temp_c)
    p[8] = _need_byte("ecu1", ecu1)
    p[9] = _need_byte("ecu2", ecu2)
    _put_u16be(p, 10, int(round(rear_current_a * 10)))
    _put_u16be(p, 13, _need_u16("speed_raw", speed_raw))
    p[15] = _need_byte("rear_temp_c", rear_temp_c)
    p[16] = _need_byte("status3", status3)
    if extra:
        for idx, val in extra.items():
            p[int(idx)] = _need_byte("extra[%d]" % idx, val)
    return BleFrame.telemetry(BLE_55_MOTOR, bytes(p)).to_bytes()


def ble_telemetry_5573(avg_speed_kmh=0.0, max_speed_kmh=0.0, trip_km=0.0,
                       odometer_km=0, regen=0.0, system_status2=0xFF,
                       custom_key=0, status73=0xFF, extra=None):
    """VCU->App 55 73 Fahrt. odometer_km wird als 3-Byte-BE (km) kodiert."""
    p = bytearray(17)
    _put_u16be(p, 0, int(round(avg_speed_kmh * 10)))
    _put_u16be(p, 2, int(round(max_speed_kmh * 10)))
    _put_u16be(p, 4, int(round(trip_km * 10)))
    _put_u24be(p, 6, int(odometer_km))
    _put_u16be(p, 9, int(round(regen * 10)))
    p[14] = _need_byte("system_status2", system_status2)
    p[15] = _need_byte("custom_key", custom_key)
    p[16] = _need_byte("status73", status73)
    if extra:
        for idx, val in extra.items():
            p[int(idx)] = _need_byte("extra[%d]" % idx, val)
    return BleFrame.telemetry(BLE_55_RIDE, bytes(p)).to_bytes()


def ble_cmd_fin(name):
    """App->VCU 0x1F: FIN-/BLE-Name, 16 ASCII space-padded, [18]=0xFF."""
    if isinstance(name, str):
        raw = name.encode("ascii", "replace")[:16]
    else:
        raw = _bytes(name)[:16]
    return BleFrame.build(BLE_CMD_FIN_NAME, raw + b" " * (16 - len(raw))).to_bytes()


def ble_speed_raw_from_kmh(speed_kmh, wheel=10.0):
    """55-72-Speed-Rohwert aus km/h: speed = 287*wheel/speedRaw (Community)."""
    if speed_kmh is None or speed_kmh <= 0.5:
        return 0
    raw = int(round(287.0 * wheel / float(speed_kmh)))
    return max(1, min(2999, raw))


# ---------------------------------------------------------------------------
# ESC-Link (USART2): 4A-Frames + 0x71-RX
# ---------------------------------------------------------------------------

ESC_BUILD_LEN = 20  # Baupuffer 0x20001392
ESC_SUBTYPES = {0x3A: "3A", 0x3B: "3B"}
ESC_VARIANTS = (0x11, 0x14)


def _esc_subtype_byte(subtype):
    if isinstance(subtype, str):
        s = subtype.strip().upper()
        if s in ("3A", ":"):
            return 0x3A
        if s in ("3B", ";"):
            return 0x3B
        if s.startswith("0X"):
            return _need_byte("subtype", int(s, 16))
        raise ValueError("Unbekannter ESC-Subtyp %r" % subtype)
    v = int(subtype)
    if v not in ESC_SUBTYPES:
        raise ValueError("Unbekannter ESC-Subtyp 0x%02X" % v)
    return v


def esc_build_4a(subtype="3B", length_variant=0x11, gear=1, control_flags=0,
                 pole_pairs=30, wheel=100, temp_threshold=120,
                 front_start_current=0, gear_limit=0, power_limit=0,
                 rear_start_current=0, voltage_code=48, pack_voltage=60,
                 status_flags=0, tail3=(0x00, 0x00, 0x00)):
    """Baut einen auf die Leitung gehenden 4A-Frame (17 oder 20 Byte).

    length_variant=0x14: TX = Baupuffer [0..19] (20 B); [16..18] = tail3.
    length_variant=0x11: TX = Baupuffer [0..15] + Checksumme (17 B); tail3
        geht NICHT auf die Leitung, ist aber Teil der XOR-Summe ueber die
        19 Baupufferbytes (Firmware-Eigenheit, siehe Modul-Docstring).
    Rueckgabe: Rohbytes exakt so, wie die Firmware sie sendet.
    """
    sub = _esc_subtype_byte(subtype)
    if length_variant not in ESC_VARIANTS:
        raise ValueError("length_variant muss 0x11 oder 0x14 sein")
    if len(tail3) != 3:
        raise ValueError("tail3 braucht genau 3 Bytes")
    buf = bytearray(ESC_BUILD_LEN)
    buf[0] = 0x4A
    buf[1] = length_variant
    buf[2] = sub
    buf[3] = 0x00
    buf[4] = _need_byte("gear", gear)
    buf[5] = _need_byte("control_flags", control_flags)
    buf[6] = _need_byte("pole_pairs", pole_pairs)
    buf[7] = _need_byte("wheel", wheel)
    buf[8] = _need_byte("temp_threshold", temp_threshold)
    buf[9] = _need_byte("front_start_current", front_start_current)
    buf[10] = _need_byte("gear_limit", gear_limit)
    buf[11] = _need_byte("power_limit", power_limit)
    buf[12] = _need_byte("rear_start_current", rear_start_current)
    buf[13] = _need_byte("voltage_code", voltage_code)
    buf[14] = _need_byte("pack_voltage", pack_voltage)
    buf[15] = _need_byte("status_flags", status_flags)
    for i in range(3):
        buf[16 + i] = _need_byte("tail3[%d]" % i, tail3[i])
    buf[19] = xor8(buf, 19)  # XOR ueber Baupuffer [0..18] -> [19]
    if length_variant == 0x14:
        return bytes(buf[0:20])
    return bytes(buf[0:16]) + bytes([buf[19]])


def esc_parse(frame, hidden=None):
    """Parst einen VCU->ESC-4A-Frame (17 B = 0x11 oder 20 B = 0x14).

    hidden: fuer 0x11er-Frames die 3 nicht uebertragenen Baupufferbytes
    [16..18]; nur damit ist die XOR-Pruefsumme verifizierbar. Ohne hidden
    bleibt checksum_ok=None (Pruefung nicht moeglich) - siehe Docstring.
    """
    frame = _bytes(frame)
    out = {"warnings": []}
    w = out["warnings"]
    if len(frame) == 20:
        variant = 0x14
        build = bytearray(frame)
    elif len(frame) == 17:
        variant = 0x11
        build = bytearray(frame[0:16]) + bytearray(3) + bytearray([frame[16]])
        if hidden is not None:
            h = bytes(hidden)
            if len(h) != 3:
                raise ValueError("hidden braucht 3 Bytes")
            build[16:19] = h
    else:
        raise ValueError("4A-Frame muss 17 (0x11) oder 20 (0x14) Byte sein "
                         "(ist %d)" % len(frame))
    if build[0] != 0x4A:
        w.append("Header 0x4A fehlt (0x%02X)" % build[0])
    if int(build[1]) != variant:
        w.append("Variantenbyte 0x%02X passt nicht zur Laenge (0x%02X)"
                 % (build[1], variant))
    sub = build[2]
    if sub not in ESC_SUBTYPES:
        w.append("Subtyp 0x%02X nicht 0x3A/0x3B" % sub)
    checksum = build[19]
    if variant == 0x14:
        ok = xor8(build, 19) == checksum
        if not ok:
            w.append("XOR-Checksumme falsch (erwartet 0x%02X, gelesen 0x%02X)"
                     % (xor8(build, 19), checksum))
    else:
        if hidden is None:
            ok = None
            w.append("0x11-Frame: Checksumme geht ueber 19 Baupufferbytes, "
                     "Bytes [16..18] sind nicht auf der Leitung - Pruefung "
                     "nur mit hidden=(b16,b17,b18) moeglich")
        else:
            ok = xor8(build, 19) == checksum
            if not ok:
                w.append("XOR-Checksumme falsch fuer hidden=%s (erwartet 0x%02X, "
                         "gelesen 0x%02X)" % (_hexs(hidden), xor8(build, 19), checksum))
    out.update({
        "variant": variant,
        "variant_hex": "0x%02X" % variant,
        "subtype": ESC_SUBTYPES.get(sub, "0x%02X" % sub),
        "wire_len": len(frame),
        "raw_hex": _hexs(frame),
        "checksum": checksum,
        "checksum_ok": ok,
        "gear": build[4],
        "control_flags": build[5],
        "clamp_scale_latch": bool(build[5] & 0x20),
        "pole_pairs": build[6],
        "wheel": build[7],
        "temp_threshold": build[8],
        "front_start_current": build[9],
        "gear_limit": build[10],
        "power_limit": build[11],
        "rear_start_current": build[12],
        "voltage_code": build[13],
        "pack_voltage": build[14],
        "status_flags": build[15],
        "status_cd": bool(build[15] & 0x80),
        "status_14": bool(build[15] & 0x20),
        "tail3": tuple(build[16:19]),
        "tail3_on_wire": variant == 0x14,
    })
    if not 1 <= build[4] <= 5:
        w.append("Gang %d ausserhalb 1..5" % build[4])
    return out


def esc_build_71(subtype="3A", data=(0,) * 11, dual=False):
    """Synthetischer ESC->VCU-0x71-Frame (13 Byte) fuer Tests/Emulation.

    [0]=0x71, [1..11]=11 Datenbytes ([2]=Typmarker ':'/';',
    [11] Bit0=Dual-Motorfaehigkeit - wird von der FW nur aus der 3A-Antwort
    uebernommen, siehe FUN_0800f4fa), [12]=XOR ueber [0..11]."""
    sub = _esc_subtype_byte(subtype)
    body = bytearray(_bytes(bytes(data)) if not isinstance(data, (bytes, bytearray))
                     else data)
    if len(body) != 11:
        raise ValueError("data muss 11 Byte sein")
    body[1] = sub
    if dual:
        body[10] |= 0x01
    else:
        body[10] &= 0xFE
    head = bytes([0x71]) + bytes(body)
    return head + bytes([xor8(head)])


def esc_parse_rx(frame):
    """Parst einen ESC->VCU-0x71-Frame (Firmware-Rahmen: 13 Byte).

    Firmware-Fund (ISR FUN_0800b5ca + Consumer FUN_0800fa94): 13 Bytes auf
    der Leitung, Pruefung XOR ueber 12 Byte == 13. Byte. Ein 12-Byte-Input
    wird tolerant als Rahmen ohne eigenes Pruefbyte interpretiert
    (XOR ueber 11 Byte == Byte 11) und mit Warnung versehen.
    """
    frame = _bytes(frame)
    out = {"warnings": []}
    w = out["warnings"]
    if len(frame) == 13:
        checksum = frame[12]
        ok = xor8(frame, 12) == checksum
        body = frame[0:12]
        if not ok:
            w.append("XOR-Checksumme falsch (erwartet 0x%02X, gelesen 0x%02X)"
                     % (xor8(frame, 12), checksum))
    elif len(frame) == 12:
        checksum = frame[11]
        ok = xor8(frame, 11) == checksum
        body = frame[0:11]
        w.append("12-Byte-Variante interpretiert; Firmware-Rahmen ist 13 Byte "
                 "(XOR ueber 12 Byte == Pruefbyte)")
        if not ok:
            w.append("XOR-Checksumme falsch (erwartet 0x%02X, gelesen 0x%02X)"
                     % (xor8(frame, 11), checksum))
    else:
        raise ValueError("0x71-Frame: 13 Byte erwartet (Firmware), 12 toleriert "
                         "(ist %d)" % len(frame))
    if frame[0] != 0x71:
        w.append("Header 0x71 fehlt (0x%02X)" % frame[0])
    marker = body[2] if len(body) > 2 else None
    if marker not in (0x3A, 0x3B):
        w.append("Typmarker Byte[2]=0x%02X nicht ':'/';'" % (marker or 0))
    out.update({
        "subtype": {0x3A: "3A", 0x3B: "3B"}.get(marker, None),
        "marker": marker,
        "wire_len": len(frame),
        "raw_hex": _hexs(frame),
        "checksum": checksum,
        "checksum_ok": ok,
        "data11": tuple(body[1:12]),
        "dual": bool(body[11] & 0x01),
        "raw_bytes": tuple(body),
    })
    return out


# ---------------------------------------------------------------------------
# Display-Link (USART3)
# ---------------------------------------------------------------------------

DISPLAY_TX_LEN = 39
DISPLAY_RX_LEN = {0x4C: 19, 0x8A: 11, 0x8B: 8, 0x8C: 8}
KEEPALIVE_LEN = 10


def display_build_35(subtype="3A", status=0, flags=0, val_de=0, val_e0=0,
                     val_e2=0, val_e4=0, gear=1, mirror_flags=0,
                     speed_field=0, soc=0, v35e=0, v35f=0, val_f0=0,
                     flag_f2=0, val_f4=0, val_f8=0, val_fe=0, odometer=0,
                     status306=0, wheel=100, pack_voltage=60, pole_pairs=30,
                     temp_c=None, temp_byte=None, start_level=0, gear_limit=0,
                     power_limit=0, rear_current=0, rotation=None):
    """Baut einen VCU->Display-Frame 0x35 (39 Byte, XOR ueber [0..37] @[38]).

    Feldlagen = am ROM verifiziert (FUN_080107da '3A' / FUN_08010648 '3B',
    inkl. Byte [12] = Spiegelflags - siehe Modul-Docstring).
    odometer = Rohwert 0x20000300 (0.1-km-Domain); es wird odometer//10
    als 3-Byte-BE geschrieben. temp_c => temp_byte=(Temp-80)/5 (trunkiert);
    temp_byte hat Vorrang, wenn beide gesetzt sind.
    """
    sub = _esc_subtype_byte(subtype)  # gleiche '3A'/'3B'-Notation
    if temp_byte is None:
        tc = 25.0 if temp_c is None else float(temp_c)
        # C: (int)(temp-80)/5, danach Kopie in uint8 => Wrap mod 256
        temp_byte = int((tc - 80.0) / 5.0)
    temp_byte = int(temp_byte) & 0xFF
    buf = bytearray(DISPLAY_TX_LEN)
    buf[0] = 0x35
    buf[1] = 0x27
    buf[2] = sub
    buf[3] = _need_byte("status", status)
    buf[4] = _need_byte("flags", flags)
    _put_u16be(buf, 5, _need_u16("val_de", val_de))
    buf[7] = _need_byte("val_e0", val_e0)
    _put_u16be(buf, 8, _need_u16("rotation", rotation)
               if rotation is not None else _need_u16("val_e2", val_e2))
    buf[10] = _need_byte("val_e4", val_e4)
    buf[11] = _need_byte("gear", gear)
    buf[12] = _need_byte("mirror_flags", mirror_flags)
    buf[13] = _need_byte("speed_field", speed_field)
    buf[14] = _need_byte("soc", soc)
    buf[15] = _need_byte("v35e", v35e)
    buf[16] = _need_byte("v35f", v35f)
    _put_u16be(buf, 17, _need_u16("val_f0", val_f0))
    buf[19] = _need_byte("flag_f2", flag_f2) & 0x5F
    _put_u16be(buf, 20, _need_u16("val_f4", val_f4))
    _put_u16be(buf, 22, _need_u16("val_f8", val_f8))
    _put_u16be(buf, 24, _need_u16("val_fe", val_fe))
    _put_u24be(buf, 26, (int(odometer) // 10) & 0xFFFFFF)
    buf[29] = _need_byte("status306", status306)
    buf[30] = _need_byte("wheel", wheel)
    buf[31] = _need_byte("pack_voltage", pack_voltage)
    buf[32] = _need_byte("pole_pairs", pole_pairs)
    buf[33] = temp_byte
    buf[34] = _need_byte("start_level", start_level)
    buf[35] = _need_byte("gear_limit", gear_limit)
    buf[36] = _need_byte("power_limit", power_limit)
    buf[37] = _need_byte("rear_current", rear_current)
    buf[38] = xor8(buf, 38)
    return bytes(buf)


def display_parse(frame):
    """Parst einen VCU->Display-0x35-Frame (39 B) inkl. XOR-Pruefung."""
    frame = _bytes(frame)
    if len(frame) != DISPLAY_TX_LEN:
        raise ValueError("Display-0x35-Frame muss 39 Byte sein (ist %d)" % len(frame))
    out = {"warnings": []}
    w = out["warnings"]
    if frame[0] != 0x35 or frame[1] != 0x27:
        w.append("Header erwartet 35 27, gelesen %02X %02X" % (frame[0], frame[1]))
    sub = frame[2]
    if sub not in ESC_SUBTYPES:
        w.append("Subtyp 0x%02X nicht 0x3A/0x3B" % sub)
    checksum = frame[38]
    ok = xor8(frame, 38) == checksum
    if not ok:
        w.append("XOR-Checksumme falsch (erwartet 0x%02X, gelesen 0x%02X)"
                 % (xor8(frame, 38), checksum))
    out.update({
        "subtype": ESC_SUBTYPES.get(sub, "0x%02X" % sub),
        "raw_hex": _hexs(frame),
        "checksum": checksum,
        "checksum_ok": ok,
        "status": frame[3],
        "flags": frame[4],
        "clamp_scale_latch": bool(frame[4] & 0x02),
        "val_de": _u16be(frame, 5),
        "val_e0": frame[7],
        "val_e2": _u16be(frame, 8),
        "rotation": _u16be(frame, 8),             # [8..9] = Rotationszeit (verifiziert)
        "val_e4": frame[10],
        "gear": frame[11],
        "mirror_flags": frame[12],
        "speed_field": frame[13],
        "soc": frame[14],
        "v35e": frame[15],
        "v35f": frame[16],
        "val_f0": _u16be(frame, 17),
        "flag_f2": frame[19],
        "val_f4": _u16be(frame, 20),
        "val_f8": _u16be(frame, 22),
        "val_fe": _u16be(frame, 24),
        "odometer_x10": _u24be(frame, 26),
        "odometer_km": _u24be(frame, 26),
        "status306": frame[29],
        "wheel": frame[30],
        "pack_voltage": frame[31],
        "pole_pairs": frame[32],
        "temp_byte": frame[33],
        "temp_c_approx": ((frame[33] - 256) if frame[33] >= 128 else frame[33]) * 5 + 80,
        "start_level": frame[34],
        "gear_limit": frame[35],
        "power_limit": frame[36],
        "rear_current": frame[37],
    })
    if not 1 <= frame[11] <= 5:
        w.append("Gang %d ausserhalb 1..5" % frame[11])
    if frame[14] > 100:
        w.append("SOC %d%% > 100" % frame[14])
    if frame[30] == 0:
        w.append("Wheel 0 (nicht gesetzt?)")
    return out


def display_parse_rx(frame):
    """Parst Display->VCU-Frames: 0x4C (19 B), 0x8A (11 B), 0x8B/0x8C (8 B)."""
    frame = _bytes(frame)
    out = {"warnings": []}
    w = out["warnings"]
    header = frame[0] if frame else None
    if header not in DISPLAY_RX_LEN:
        raise ValueError("Unbekannter Display-RX-Header 0x%02X" % (header or 0))
    want = DISPLAY_RX_LEN[header]
    if len(frame) != want:
        w.append("Laenge %d, erwartet %d fuer Header 0x%02X"
                 % (len(frame), want, header))
    out.update({
        "header": "0x%02X" % header,
        "wire_len": len(frame),
        "raw_hex": _hexs(frame),
        "checksum_ok": None,
        "cmd_frame": None,
        "cmd_id": None,
        "fields": {},
    })
    if header == 0x4C:
        checksum = frame[18] if len(frame) >= 19 else None
        ok = checksum is not None and xor8(frame, 18) == checksum
        if not ok:
            w.append("XOR-Checksumme falsch/fehlt")
        out["checksum_ok"] = ok
        out["cmd_frame"] = bool(len(frame) > 2 and frame[2] == 0x35)
        cmd = frame[3] if len(frame) > 3 else None
        out["cmd_id"] = cmd
        f = out["fields"]
        if out["cmd_frame"]:
            if cmd == 1:
                f["gear"] = frame[4]
                if frame[4] > 5:
                    w.append("Gangwahl %d > 5" % frame[4])
            elif cmd == 2:
                f["light_dual_byte"] = frame[4]
                f["clamp_latch"] = bool(frame[5] & 0x20)
            elif cmd == 3:
                f["eco"] = bool(frame[6] & 0x01)
            elif cmd == 4:
                f["dual_tcs"] = bool(frame[6] & 0x02)
            elif cmd == 5:
                f["start_front"] = frame[5]
                f["start_rear"] = frame[6]
                f["pole_pairs"] = frame[7]
                f["wheel"] = frame[8]
                f["temp_threshold_c"] = frame[9] * 5 + 80
                f["gear1"] = frame[10]
                f["gear2"] = frame[11]
                f["power_limit"] = frame[12]
                f["voltage_code"] = frame[13]
                f["pack_voltage"] = frame[14]
            elif cmd == 7:
                f["smart_tcs"] = True
            elif cmd == 9:
                f["cmd9_flag"] = True
            else:
                w.append("Cmd-ID %s unbekannt (1..9 erwartet)" % cmd)
            f["clamp_indicator"] = bool(frame[6] & 0x04)
            f["tail_powercd"] = bool(frame[6] & 0x80)
    elif header == 0x8A:
        out["fields"]["stage"] = frame[2] if len(frame) > 2 else None
        if out["fields"]["stage"] not in (8, 9, 10):
            w.append("Byte2=%r nicht 8/9/10 (3-stufige Uebernahme)"
                     % out["fields"]["stage"])
    elif header == 0x8B:
        aa = all(len(frame) > i and frame[i] == 0xAA for i in (2, 4, 6))
        out["fields"]["aa_pattern"] = aa
        if not aa:
            w.append("Byte2/4/6 != 0xAA")
    elif header == 0x8C:
        f = out["fields"]
        f["byte2_is_1"] = bool(len(frame) > 2 and frame[2] == 1)
        f["byte5_6_aa"] = bool(len(frame) > 6 and frame[5] == 0xAA and frame[6] == 0xAA)
        if not (f["byte2_is_1"] and f["byte5_6_aa"]):
            w.append("Byte2=1 und Byte5/6=0xAA erwartet")
    return out


def keepalive(i=0):
    """10-Byte-Keep-Alive (00 01 02 ... 09) an ESC UND Display.

    i verschiebt die Zählerfolge ((i+k)&0xFF) - die Firmware sendet stets
    00..09 (FUN_08019b82); i dient nur Test-/Variantenzwecken."""
    i = int(i) & 0xFF
    return bytes([(i + k) & 0xFF for k in range(KEEPALIVE_LEN)])


# ---------------------------------------------------------------------------
# SOC-Kennlinie (soc_mv[101] aus soc_kennlinie.c)
# ---------------------------------------------------------------------------

_SOC_TABLE = None

SOC_TABLE_RE = re.compile(
    r"static\s+const\s+uint16_t\s+soc_mv\s*\[\s*101\s*\]\s*=\s*\{(.*?)\}\s*;",
    re.S)


def default_soc_table_path():
    return os.path.join(os.path.dirname(os.path.abspath(__file__)),
                        "soc_kennlinie.c")


def load_soc_table(path=None):
    """Laedt soc_mv[101] zur Laufzeit aus soc_kennlinie.c (Regex)."""
    global _SOC_TABLE
    p = path or default_soc_table_path()
    with open(p, "r", encoding="utf-8", errors="replace") as fh:
        text = fh.read()
    m = SOC_TABLE_RE.search(text)
    if not m:
        raise RuntimeError("soc_mv[101]-Array nicht gefunden in %s" % p)
    body = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    vals = [int(v) for v in re.findall(r"\d+", body)]
    if len(vals) != 101:
        raise RuntimeError("soc_mv hat %d Werte (101 erwartet)" % len(vals))
    _SOC_TABLE = vals
    return list(vals)


def soc_table():
    if _SOC_TABLE is None:
        load_soc_table()
    return _SOC_TABLE


def soc_from_mv_float(mv):
    """Stuecklineare Interpolation ueber die 101 Tabellenpunkte (float, %)."""
    tab = soc_table()
    mv = int(mv)
    if mv <= tab[0]:
        return 0.0
    if mv >= tab[100]:
        return 100.0
    i = 0
    while mv >= tab[i + 1]:
        i += 1
    lo, hi = tab[i], tab[i + 1]
    return i + (mv - lo) / float(hi - lo)


def soc_from_mv(mv):
    """SOC in % (0..100) aus Zellspannung mV - stuecklinear, kaufmaennisch
    gerundet, wie die Stuecklinear-Naeherung in soc_kennlinie.c."""
    return int(soc_from_mv_float(mv) + 0.5)


def soc_from_mv_step(mv):
    """Firmware-aequivalent (FUN_0801c162-Binaersuche): groesster Tabellenindex
    mit soc_mv[i] <= mv (Stufenfunktion)."""
    tab = soc_table()
    mv = int(mv)
    if mv < tab[0]:
        return 0
    lo, hi = 0, 100
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if mv >= tab[mid]:
            lo = mid
        else:
            hi = mid - 1
    return lo


def mv_from_soc(soc):
    """Zellspannung in mV fuer SOC % (Tabellenwert, 0..100 geklemmt)."""
    return soc_table()[max(0, min(100, int(soc)))]


def display_speed_field(speed_kmh):
    """Display-0x35 Byte [13] aus km/h ueber den Rotationsrohwert.

    Firmware: [13] = max(0, 0x2000036D-0x28); 0x2000036D = 0x200006A0+0x29;
    0x200006A0 = (0x200002E4*2)/3 (0x200002E4 = Rotationsrohwert ~1.5x km/h).
    => [13] ~= min(61, km/h) + 1.
    """
    raw = int(round(float(speed_kmh) * 1.5))  # 0x200002E4-Rohwert
    q = min(61, (raw * 2) // 3)               # 0x200006A0
    return (q + 1) & 0xFF                     # 0x2000036D - 0x28


def rotation_raw_from_kmh(speed_kmh):
    """0x200002E4-Rohwert (Bytes [10] im Display-Frame; ~1.5x km/h)."""
    return int(round(float(speed_kmh) * 1.5)) & 0xFFFF


# ---------------------------------------------------------------------------
# Selftest
# ---------------------------------------------------------------------------


def _round_trips():
    """Jede Build->Parse-Runde: (Name, Frame, Parse-Aufruf mit Ergebnis)."""
    cases = []

    def add(name, frame, parsed):
        cases.append((name, frame, parsed))

    ver, hw = (3, 4, 13), (1, 0, 0)
    add("BLE 55 43", ble_telemetry_5543(ver, hw), None)
    add("BLE 55 52", ble_telemetry_5552(53.8, 74, pole_voltage_v=53.7,
                                        current_a=17.0, temps=(24, 25, 26, 25, 25, 24, 25)),
        None)
    add("BLE 55 71", ble_telemetry_5571(gear=3, gear_limit=60, main_limit=80,
                                        front_current=5, rear_current=12), None)
    add("BLE 55 72", ble_telemetry_5572(5.5, 12.5, 130, 40, 46), None)
    add("BLE 55 73", ble_telemetry_5573(20.0, 24.2, 12.3, 12345, 1.5), None)
    add("BLE 0x1F FIN", ble_cmd_fin("TDE1234567890ABC"), None)

    add("ESC 4A 11 3A", esc_build_4a("3A", 0x11, gear=3, gear_limit=60,
                                     pack_voltage=54, tail3=(0x11, 0x22, 0x33)), None)
    add("ESC 4A 11 3B", esc_build_4a("3B", 0x11, gear=3, gear_limit=60,
                                     pack_voltage=54, tail3=(0x11, 0x22, 0x33)), None)
    add("ESC 4A 14 3A", esc_build_4a("3A", 0x14, gear=3, gear_limit=60,
                                     pack_voltage=54, tail3=(0x01, 0x02, 0x03)), None)
    add("ESC 4A 14 3B", esc_build_4a("3B", 0x14, gear=3, gear_limit=60,
                                     pack_voltage=54, tail3=(0x01, 0x02, 0x03)), None)
    add("ESC 0x71 RX", esc_build_71("3A", dual=True), None)

    add("Display 35 3A", display_build_35("3A", gear=3, soc=74, speed_field=23),
        None)
    add("Display 35 3B", display_build_35("3B", gear=3, soc=74, speed_field=23),
        None)
    add("Keep-Alive", keepalive(), None)
    return cases


def run_selftest(verbose=True):
    """Fuehrt die 4 vorgesehenen Pruefungen aus; Rueckgabe: (ok, zeilen)."""
    lines = []
    ok_all = True

    # 1) CRC-8/ATM: bekannte Vektoren + Determinismus (doppelte Berechnung)
    a1 = crc8_atm(b"\xAA")
    a2 = crc8_atm(b"\xAA")
    c1 = crc8_atm(b"123456789")
    c2 = crc8_atm(b"123456789")
    e1 = crc8_atm(b"")
    ok1 = (a1 == 0x5F and a2 == a1 and c1 == 0xF4 and c2 == c1 and e1 == 0)
    ok_all &= ok1
    lines.append("[1] CRC-8/ATM Vektoren+Determinismus ... %s  "
                 "(crc8(AA)=0x%02X, crc8('123456789')=0x%02X, crc8(leer)=0x%02X)"
                 % ("PASS" if ok1 else "FAIL", a1, c1, e1))

    # 2) jede build->parse Runde framegenau
    rounds = 0
    bad = []
    for name, frame, _ in _round_trips():
        rounds += 1
        try:
            if name.startswith("BLE 0x1F"):
                dec = BleFrame.parse(frame).decode()
                good = dec["crc_ok"] and dec["fields"]["name"] == "TDE1234567890ABC"
            elif name.startswith("BLE"):
                dec = BleFrame.parse(frame).decode()
                good = dec["crc_ok"] and dec["header"] == 0x55
            elif name.startswith("ESC 4A"):
                hidden = (0x11, 0x22, 0x33) if " 11 " in name else None
                dec = esc_parse(frame, hidden=hidden)
                good = (dec["checksum_ok"] is True and dec["subtype"] == name[-2:]
                        and dec["gear"] == 3)
            elif name.startswith("ESC 0x71"):
                dec = esc_parse_rx(frame)
                good = dec["checksum_ok"] and dec["dual"] is True
            elif name.startswith("Display 35"):
                dec = display_parse(frame)
                good = dec["checksum_ok"] and dec["subtype"] == name[-2:]
            elif name.startswith("Keep-Alive"):
                good = frame == bytes(range(10))
            else:
                good = False
        except Exception as exc:  # noqa: BLE001 - Selftest soll alles melden
            good = False
            dec = {"error": repr(exc)}
        if not good:
            bad.append("%s:%r" % (name, dec))
    ok2 = not bad
    ok_all &= ok2
    lines.append("[2] Build->Parse framegenau (%d Rundlaeufe) ... %s%s"
                 % (rounds, "PASS" if ok2 else "FAIL",
                    "" if ok2 else "  " + "; ".join(bad[:3])))

    # 3) XOR-Kenndaten: Display-0x35 XOR ueber [0..37] == [38]
    f3 = display_build_35("3A", gear=3, soc=74, speed_field=23, odometer=12340)
    x1 = xor8(f3, 38)
    x2 = 0
    for i in range(38):
        x2 ^= f3[i]
    ok3 = (f3[38] == x1 == x2)
    ok_all &= ok3
    lines.append("[3] XOR Display-0x35 ([0..37]==[38]) ... %s  (Byte38=0x%02X)"
                 % ("PASS" if ok3 else "FAIL", f3[38]))

    # 4) SOC-Kennlinie
    try:
        t = soc_table()
        m50 = mv_from_soc(50)
        s3624 = soc_from_mv(3624)
        s3600 = soc_from_mv(3600)
        s0 = soc_from_mv(3000)
        s100 = soc_from_mv(4150)
        mono = all(t[i] <= t[i + 1] for i in range(100))
        ok4 = (len(t) == 101 and t[50] == 3624 and m50 == 3624 and s3624 == 50
               and s3600 == 48 and s0 == 0 and s100 == 100 and mono)
        note = ("soc_from_mv(3600)=%d, mv_from_soc(50)=%d" % (s3600, m50))
        if s3600 != 48:
            note += " (Goldwert 48 erwartet)"
        elif not (41 <= s3600 <= 45):
            note += " [Hinweis: Vorgabe ~41-45 nicht bestaetigt - " \
                    "101-Punkte-Interpolation ergibt 48; ~43 liefert das " \
                    "groebe 5%-Raster]"
        lines.append("[4] SOC-Kennlinie ... %s  (%s)" % ("PASS" if ok4 else "FAIL", note))
        ok_all &= ok4
    except Exception as exc:  # noqa: BLE001
        ok_all = False
        lines.append("[4] SOC-Kennlinie ... FAIL  (%r)" % exc)

    if verbose:
        for line in lines:
            print(line)
        print("Ergebnis: %s" % ("PASS" if ok_all else "FAIL"))
    return ok_all, lines


def main(argv=None):
    parser = argparse.ArgumentParser(
        description="ivcu_protocol - Codec fuer die drei Teverun-IVCU-Links")
    parser.add_argument("--selftest", action="store_true",
                        help="Selbsttest ausfuehren (CRC, Build->Parse, XOR, SOC)")
    parser.add_argument("--soc-table", default=None,
                        help="Pfad zu soc_kennlinie.c (Default: neben dieser Datei)")
    parser.add_argument("--version", action="store_true", help="Version anzeigen")
    args = parser.parse_args(argv)
    if args.version:
        print("ivcu_protocol %s" % __version__)
        return 0
    if args.soc_table:
        load_soc_table(args.soc_table)
    if args.selftest:
        ok, _ = run_selftest()
        return 0 if ok else 1
    parser.print_help()
    return 0


if __name__ == "__main__":
    sys.exit(main())
