#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generator fuer die externen I2C-EEPROM-Bloecke der IVCU (Teverun).

Zielsystem : IVCU / AWIVCU_APP R3.4.13 (GD32F303-Klasse, Cortex-M4F; STM32F1-artige Peripherie)
Umgebung   : reines Python 3 (nur Standardbibliothek)

Verifizierte Quellen (Reverse Engineering, Ghidra 12.1.4):
-------------------------------------------------------------------------------
* I2C-Transferpfad (externes EEPROM, 24C32/64/128-Klasse):
    decomp/functions/0x80188ba.c  FUN_080188BA @ 0x080188BA
      -> Slave-Schreibadresse 0xA0 (7-bit: 0x50), 16-bit Wortadresse (Hi,Lo),
         Schreibseiten <= 32 Byte (FUN_08018FFE @ 0x08018FFE teilt auf)
* EEPROM-Speicherroutine:
    decomp/functions/0x8016fc4.c  FUN_08016FC4 @ 0x08016FC4
      case 0: Pruefsumme u16 -> 0x20001A56 (= Block0-Puffer + 0x4E),
              Write 0x50 B an Wortadresse 0x00
      case 1: Pruefsumme u16 -> 0x20001A8C (= Block1-Puffer + 0x34),
              Write 0x38 B an Wortadresse 0x50
* Block 0 (Wortadresse 0x00, 80 Byte):
    decomp/functions/0x801744c.c  FUN_0801744C @ 0x0801744C (Werksdefaults)
    decomp/functions/0x8017784.c  FUN_08017784 @ 0x08017784 (Loader/Validator;
      liest 0x50 B, prueft "VCU"+01 01 03 04 0D @ +8..+15 und vergleicht das
      gelesene u16 @ +0x4E mit FUN_08016F96(Puffer, 0x4E) -> Byte-XOR)
* Block 1 (Wortadresse 0x50, 56 Byte):
    decomp/functions/0x8017230.c  FUN_08017230 @ 0x08017230 (Werks-Writer)
    decomp/functions/0x8017cde.c  FUN_08017CDE @ 0x08017CDE (Settings -> Block)
    Fabriktabelle ROM @ 0x0801DA40 (9 B Settings) / 0x0801DA49 (36 B Gangtabelle),
    Hexdump: AWIVCU_APP_R3_4_13_decompiled.c, Zeilen 24129-24135:
      0801DA40  90 90 1E 6E 78 64 30 3C 00
      0801DA49  00 00 00 00 00 00 | 01 14 11 11 0F 0F | 02 28 22 22 14 14 |
                03 3C 33 33 19 19 | 04 50 44 44 1E 1E | 05 64 55 55 37 37
    Gang-Zeile (6 Byte, laut Doku-FINAL §Fabriktabelle):
      [idx, Limit, EABS|RearStart, FrontStart, RearI, FrontI]
      Gaenge 1..5: Limit 20/40/60/80/100, Nibbles 0x11..0x55, Stroeme 15/20/25/30/55
* Pruefsumme (beide Bloecke):
    XOR ueber die Nutzbytes, Ergebnis als u16 LITTLE-ENDIAN abgelegt.
      Block 0: XOR ueber [0x00..0x4D] -> u16 @ [0x4E..0x4F]
      Block 1: XOR ueber [0x00..0x33] -> u16 @ [0x34..0x35]
    Da der XOR-Wert ein Byte ist, ist das High-Byte stets 0x00; der Loader
    liest/vergleicht den Wert aber als u16 (FUN_08017784).

Aufruf:
    python eeprom_images.py --outdir <verzeichnis>
        [--wheel-mm 279.4] [--pack-v 48|52|60|72] [--full-v 60]
        [--gear-limits 15,25,35,45,55] [--pole-pairs 30]
    python eeprom_images.py --selftest [--outdir <temp-verzeichnis>]

Erzeugte Dateien: block0.bin, block1.bin, block0.hex, block1.hex,
                  README_eeprom.txt

Sicherheitshinweis: Diese Dateien sind fuer ein EEPROM an I2C1 gedacht
(Slave 0x50, 7-bit). Vor einem realen Schreibzugriff Slave-Adresse, Bus und
Pegel am Fahrzeug verifizieren; Falschdaten koennen die IVCU in den
Werksdefault-Pfad zwingen (selbstheilend, aber unerwuenscht).
"""

import argparse
import functools
import operator
import os
import sys

# ---------------------------------------------------------------------------
# Verifizierte Speicherorte / Konstanten
# ---------------------------------------------------------------------------
BLOCK0_WORD_ADDR = 0x00          # EEPROM-Wortadresse (Offset), NICHT Slave-Adresse
BLOCK0_SIZE = 80                 # 0x50 Byte
BLOCK1_WORD_ADDR = 0x50          # EEPROM-Wortadresse
BLOCK1_SIZE = 56                 # 0x38 Byte

I2C_SLAVE_ADDR_7BIT = 0x50       # gesehen als Schreibbyte 0xA0 (0x80188BA)
I2C_SLAVE_WRITE_BYTE = 0xA0
EEPROM_PAGE_SIZE = 32            # Seitenaufteilung (FUN_08018FFE)

# Block 0 -- Werksdefaults (FUN_0801744C / geprueft in FUN_08017784)
BLOCK0_MAGIC = b"VCU"
BLOCK0_VERSION = (3, 4, 13)      # [13]=0x03, [14]=0x04, [15]=0x0D
BLOCK0_IDENT = b"AWPE-VCU-220212"  # [0x34..0x42]
BLOCK0_BATCH = b"01DB99"         # [0x47..0x4C]

# Block 1 -- Werkswerte (FUN_08017230, Fabriktabelle ROM @ 0x0801DA40)
BLOCK1_CONTROL_DEFAULT = 0x90    # [0] Cruise(1-2)/EABS(3)/Kickstart(6)/RearFree(7)
BLOCK1_DUAL_DEFAULT = 0x90       # [1] Dual (Bit7)
BLOCK1_POLEPAIRS_DEFAULT = 0x1E  # [2] 30 Polpaare
BLOCK1_WHEEL_DEFAULT = 0x6E      # [3] 110 -> 11,0 Zoll (0,1-Zoll-Kodierung)
BLOCK1_TEMP_DEFAULT = 0x78       # [4] 120
BLOCK1_POWER_DEFAULT = 0x64      # [5] 100 %
BLOCK1_VOLTCODE_DEFAULT = 0x30   # [6] Spannungscode 0x30 = 48 V
BLOCK1_PACK_DEFAULT = 0x3C       # [7] Pack 60 V (Rohwert, Fabrik)

GEAR_LIMITS_FACTORY = (20, 40, 60, 80, 100)
GEAR_NIBBLES_FACTORY = (0x11, 0x22, 0x33, 0x44, 0x55)
GEAR_CURRENTS_FACTORY = (15, 20, 25, 30, 55)

# Fabrik-Gangtabelle, 36 Byte, exakt wie ROM @ 0x0801DA49 (Gang 0 leer):
#   Zeile = [idx, Limit, EABS|RearStart, FrontStart, RearI, FrontI]
FACTORY_GEAR_TABLE = bytes((
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   # Gang 0 (leer)
    0x01, 0x14, 0x11, 0x11, 0x0F, 0x0F,   # Gang 1: Limit 20, Nibble 0x11, Strom 15
    0x02, 0x28, 0x22, 0x22, 0x14, 0x14,   # Gang 2: Limit 40, Nibble 0x22, Strom 20
    0x03, 0x3C, 0x33, 0x33, 0x19, 0x19,   # Gang 3: Limit 60, Nibble 0x33, Strom 25
    0x04, 0x50, 0x44, 0x44, 0x1E, 0x1E,   # Gang 4: Limit 80, Nibble 0x44, Strom 30
    0x05, 0x64, 0x55, 0x55, 0x37, 0x37,   # Gang 5: Limit 100, Nibble 0x55, Strom 55
))

# Spannungscode [6] laut Analyse: 0x30=48, 0x34=52, 0x3C=60, 0x48=72.
# Zweiter Wert = Rohwert fuer [7] ("Pack"), abgeleitet als 1,25 x Nennspannung.
# VERIFIZIERT ist nur der Fabrikfall 48 V -> [6]=0x30, [7]=0x3C (60 V).
PACK_VOLTAGE_MAP = {
    48: (0x30, 0x3C),   # Fabrikwert (verifiziert)
    52: (0x34, 0x41),   # 52 * 1,25 = 65 = 0x41  -- NICHT verifiziert
    60: (0x3C, 0x4B),   # 60 * 1,25 = 75 = 0x4B  -- NICHT verifiziert
    72: (0x48, 0x5A),   # 72 * 1,25 = 90 = 0x5A  -- NICHT verifiziert
}


# ---------------------------------------------------------------------------
# Pruefsummen (XOR, u16 little-endian)
# ---------------------------------------------------------------------------
def checksum16(data, count):
    """XOR ueber data[0:count] (Byte fuer Byte), Rueckgabe als u16 (0..255)."""
    c = 0
    for i in range(count):
        c ^= data[i]
    return c & 0xFFFF


def store_checksum_little_endian(buf, count, offset):
    """Berechnet XOR ueber buf[0:count] und legt es als u16 LE bei offset ab."""
    c = checksum16(buf, count)
    buf[offset] = c & 0xFF
    buf[offset + 1] = (c >> 8) & 0xFF
    return c


# ---------------------------------------------------------------------------
# Block-Erzeugung
# ---------------------------------------------------------------------------
def build_block0():
    """Block 0 (80 Byte, EEPROM-Wortadresse 0x00) mit Werksdefaults.

    Layout (FUN_0801744C, geprueft in FUN_08017784):
      [0..2]    "VCU"
      [3]       0x00
      [4]       0x53 ('S'), [5] 0x05, [6..7] 0x00
      [8..10]   "VCU"
      [11..15]  01 01 03 04 0D  (HW 1.1, Version 3.4.13)
      [16]      0x17, [17] 0x00
      [18..0x2E] 29 x '0' (0x30)
      [0x2F..0x33] 14 16 0C 01 00       (Identity-Block)
      [0x34..0x42] "AWPE-VCU-220212"    (Identitaet/Frame-Nr.)
      [0x43..0x46] 00 00 00 00
      [0x47..0x4C] "01DB99"             (Batch/Serie)
      [0x4D]     0x00
      [0x4E..0x4F] Pruefsumme u16 LE (XOR ueber [0x00..0x4D])
      (Der Block umfasst genau 0x00..0x4F = 80 Byte; der naechste Block
       beginnt bei EEPROM-Wortadresse 0x50.)
    """
    b = bytearray(BLOCK0_SIZE)

    b[0x00:0x03] = BLOCK0_MAGIC          # "VCU"
    b[0x03] = 0x00
    b[0x04] = 0x53                       # 'S'
    b[0x05] = 0x05
    # [0x06..0x07] bleiben 0x00
    b[0x08:0x0B] = BLOCK0_MAGIC          # "VCU"
    b[0x0B] = 0x01
    b[0x0C] = 0x01
    b[0x0D], b[0x0E], b[0x0F] = BLOCK0_VERSION
    b[0x10] = 0x17
    b[0x11] = 0x00
    b[0x12:0x2F] = b"0" * 29             # 29 x 0x30
    b[0x2F] = 0x14
    b[0x30] = 0x16
    b[0x31] = 0x0C
    b[0x32] = 0x01
    b[0x33] = 0x00
    b[0x34:0x43] = BLOCK0_IDENT          # 15 Byte
    # [0x43..0x46] bleiben 0x00
    b[0x47:0x4D] = BLOCK0_BATCH          # 6 Byte
    b[0x4D] = 0x00
    store_checksum_little_endian(b, 0x4E, 0x4E)
    return b


def build_gear_table(limits=None):
    """36-Byte-Gangtabelle. Default = Fabrik-Gangtabelle (ROM 0x0801DA49).

    limits: optional Sequenz mit 5 Rohbytes (Gaenge 1..5), ersetzt Spalte 1
            ("Limit", Fabrik: 20/40/60/80/100). Keine Skalierung -> Rohbytes.
    """
    table = bytearray(FACTORY_GEAR_TABLE)
    if limits is None:
        return bytes(table)
    limits = list(limits)
    if len(limits) != 5:
        raise ValueError("Gangtabelle: genau 5 Limit-Rohbytes erforderlich")
    for i, lim in enumerate(limits, start=1):
        lim = int(lim)
        if not 0 <= lim <= 0xFF:
            raise ValueError("Limit-Wert ausserhalb 0..255: {!r}".format(lim))
        table[i * 6 + 1] = lim          # Zeile i, Spalte "Limit"
    return bytes(table)


def build_block1(pole_pairs=BLOCK1_POLEPAIRS_DEFAULT,
                 wheel_code=BLOCK1_WHEEL_DEFAULT,
                 volt_code=BLOCK1_VOLTCODE_DEFAULT,
                 pack_raw=BLOCK1_PACK_DEFAULT,
                 control=BLOCK1_CONTROL_DEFAULT,
                 dual=BLOCK1_DUAL_DEFAULT,
                 temp_raw=BLOCK1_TEMP_DEFAULT,
                 power_raw=BLOCK1_POWER_DEFAULT,
                 flags=0x00,
                 gear_table=None):
    """Block 1 (56 Byte, EEPROM-Wortadresse 0x50).

    Layout (FUN_08017230 / FUN_08017CDE):
      [0]  Control (Cruise Bit1-2, EABS Bit3, Kickstart Bit6, RearFree Bit7)
      [1]  Dual (Bit7)
      [2]  Polpaare (Fabrik 0x1E = 30)
      [3]  Wheel-Code (0,1 Zoll; Fabrik 0x6E = 110 -> 11,0")
      [4]  0x78 (120), [5] 0x64 (100)   (Temp/Leistungsfeld, Fabrik)
      [6]  Spannungscode (0x30=48, 0x34=52, 0x3C=60, 0x48=72)
      [7]  Pack-Rohwert (Fabrik 0x3C = 60 V)
      [8]  Flags
      [9..0x2C] Gangtabelle 6 x 6 Byte
      [0x2D] 0, [0x2E] 0, [0x2F..0x33] 0
      [0x34..0x35] Pruefsumme u16 LE (XOR ueber [0x00..0x33])
      [0x36..0x37] 0
    """
    if gear_table is None:
        gear_table = FACTORY_GEAR_TABLE
    if len(gear_table) != 36:
        raise ValueError("Gangtabelle muss 36 Byte lang sein")

    b = bytearray(BLOCK1_SIZE)
    b[0x00] = control & 0xFF
    b[0x01] = dual & 0xFF
    b[0x02] = pole_pairs & 0xFF
    b[0x03] = wheel_code & 0xFF
    b[0x04] = temp_raw & 0xFF
    b[0x05] = power_raw & 0xFF
    b[0x06] = volt_code & 0xFF
    b[0x07] = pack_raw & 0xFF
    b[0x08] = flags & 0xFF
    b[0x09:0x2D] = gear_table
    b[0x2D] = 0x00
    b[0x2E] = 0x00
    # [0x2F..0x33] bleiben 0x00
    store_checksum_little_endian(b, 0x34, 0x34)
    return b


def wheel_code_from_mm(mm):
    """Rechnet einen Raddurchmesser in mm in die 0,1-Zoll-Kodierung um.

    Fabrikwert [3] = 0x6E = 110 -> 11,0 Zoll (= 279,4 mm).
    """
    code = int(round(float(mm) / 25.4 * 10.0))
    if not 0 <= code <= 0xFF:
        raise ValueError("Raddurchmesser ausserhalb des kodierbaren Bereichs")
    return code


# ---------------------------------------------------------------------------
# Ausgabe (Hexdump / README)
# ---------------------------------------------------------------------------
def hexdump(data, base=0):
    """Klassischer Hexdump: Offset, 16 Hexbytes, ASCII (nicht druckbar = '.')."""
    lines = []
    for off in range(0, len(data), 16):
        chunk = data[off:off + 16]
        hex_part = " ".join("{:02X}".format(b) for b in chunk)
        ascii_part = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        lines.append("{:04X}  {:47s}  |{:s}|".format(base + off, hex_part, ascii_part))
    return "\n".join(lines) + "\n"


def _gear_rows_text(block1):
    rows = []
    for i in range(6):
        row = block1[0x09 + i * 6:0x0F + i * 6]
        rows.append("  Gang {0}: {1}".format(i, " ".join("{:02X}".format(x) for x in row)))
    return rows


def build_readme(block0, block1, notes=None):
    """Erzeugt den Inhalt der README_eeprom.txt als Liste von Zeilen."""
    notes = list(notes or [])
    lines = []
    lines.append("README_eeprom.txt -- erzeugt von eeprom_images.py")
    lines.append("=" * 62)
    lines.append("")
    lines.append("Erzeugte Dateien:")
    lines.append("  block0.bin / block0.hex : 80 Byte @ EEPROM-Wortadresse 0x00")
    lines.append("  block1.bin / block1.hex : 56 Byte @ EEPROM-Wortadresse 0x50")
    lines.append("")
    lines.append("I2C-Rahmenbedingungen (verifiziert):")
    lines.append("  * Slave 7-bit 0x50 (Schreibbyte 0xA0)   [0x80188BA]")
    lines.append("  * 16-bit Wortadresse (Hi,Lo)            [0x80188BA]")
    lines.append("  * Schreibseiten <= 32 Byte              [0x8018FFE]")
    lines.append("")
    lines.append("Pruefsummen (XOR ueber Nutzbytes, u16 little-endian):")
    lines.append("  Block 0: XOR[0x00..0x4D] = 0x{:02X}  -> [0x4E]=0x{:02X}, [0x4F]=0x{:02X}".format(
        block0[0x4E], block0[0x4E], block0[0x4F]))
    lines.append("  Block 1: XOR[0x00..0x33] = 0x{:02X}  -> [0x34]=0x{:02X}, [0x35]=0x{:02X}".format(
        block1[0x34], block1[0x34], block1[0x35]))
    lines.append("")
    lines.append("Block 0 (Werksdefaults, Version 3.4.13):")
    lines.append("  Identitaet : {}".format(block0[0x34:0x43].decode("ascii", "replace")))
    lines.append("  Batch      : {}".format(block0[0x47:0x4D].decode("ascii", "replace")))
    lines.append("")
    lines.append("Block 1 (aktuelle Werte):")
    lines.append("  [0] Control     = 0x{:02X}".format(block1[0x00]))
    lines.append("  [1] Dual        = 0x{:02X}".format(block1[0x01]))
    lines.append("  [2] Polpaare    = {}".format(block1[0x02]))
    lines.append("  [3] Wheel-Code  = 0x{:02X} ({:.1f} Zoll)".format(block1[0x03], block1[0x03] / 10.0))
    lines.append("  [6] Spannungscode = 0x{:02X}".format(block1[0x06]))
    lines.append("  [7] Pack-Rohwert  = 0x{:02X} ({} V)".format(block1[0x07], block1[0x07]))
    lines.append("  Gangtabelle (idx, Limit, Nibble, Nibble, Strom, Strom):")
    lines.extend(_gear_rows_text(block1))
    if notes:
        lines.append("")
        lines.append("Hinweise:")
        for n in notes:
            lines.append("  * " + n)
    lines.append("")
    lines.append("Referenzen (Dekompilat): 0x801744C, 0x8017784, 0x8016FC4 (Block 0);")
    lines.append("  0x8017230, 0x8017CDE, ROM 0x0801DA40/0x0801DA49 (Block 1);")
    lines.append("  0x80188BA, 0x8018FFE (I2C); 0x8016F96 (XOR-Pruefsumme).")
    lines.append("")
    return lines


def write_outputs(outdir, block0, block1, readme_lines):
    """Schreibt beide Binaerdateien, Hexdumps und README in outdir."""
    os.makedirs(outdir, exist_ok=True)
    paths = []
    p = os.path.join(outdir, "block0.bin")
    with open(p, "wb") as f:
        f.write(block0)
    paths.append(p)
    p = os.path.join(outdir, "block1.bin")
    with open(p, "wb") as f:
        f.write(block1)
    paths.append(p)
    p = os.path.join(outdir, "block0.hex")
    with open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write(hexdump(block0))
    paths.append(p)
    p = os.path.join(outdir, "block1.hex")
    with open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write(hexdump(block1))
    paths.append(p)
    p = os.path.join(outdir, "README_eeprom.txt")
    with open(p, "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(readme_lines) + "\n")
    paths.append(p)
    return paths


# ---------------------------------------------------------------------------
# Selbsttest
# ---------------------------------------------------------------------------
def run_selftest(outdir=None):
    """Erzeugt beide Bloecke, prueft Laengen + Pruefsummen (unabhaengige
    Rechnung) + Fabrikwerte und schreibt die Dateien zur Kontrolle."""
    checks = []

    def check(name, ok, detail=""):
        checks.append((name, bool(ok), detail))
        return bool(ok)

    def xor_ref(chunk):
        # Unabhaengiger Rechenweg (functools.reduce statt Schleife in checksum16)
        return functools.reduce(operator.xor, chunk, 0)

    b0 = build_block0()
    b1 = build_block1()

    check("Laenge Block 0 == 80 Byte", len(b0) == BLOCK0_SIZE, "len={}".format(len(b0)))
    check("Laenge Block 1 == 56 Byte", len(b1) == BLOCK1_SIZE, "len={}".format(len(b1)))

    c0_stored = int.from_bytes(b0[0x4E:0x50], "little")
    c0_ref = xor_ref(b0[0x00:0x4E])
    check("Block 0: Pruefsumme unabhaengig nachgerechnet", c0_stored == c0_ref,
          "gespeichert=0x{:04X} referenz=0x{:04X}".format(c0_stored, c0_ref))
    check("Block 0: High-Byte der Pruefsumme == 0", b0[0x4F] == 0x00)

    c1_stored = int.from_bytes(b1[0x34:0x36], "little")
    c1_ref = xor_ref(b1[0x00:0x34])
    check("Block 1: Pruefsumme unabhaengig nachgerechnet", c1_stored == c1_ref,
          "gespeichert=0x{:04X} referenz=0x{:04X}".format(c1_stored, c1_ref))
    check("Block 1: High-Byte der Pruefsumme == 0", b1[0x35] == 0x00)

    # Struktur-Invariante: XOR ueber den kompletten Block (inkl. Pruefsumme) == 0
    check("Block 0: XOR ueber gesamten Block == 0", xor_ref(b0) == 0)
    check("Block 1: XOR ueber gesamten Block == 0", xor_ref(b1) == 0)

    check("Block 0: Magic/Version [0..2,8..10,13..15]",
          b0[0:3] == b"VCU" and b0[8:11] == b"VCU" and
          tuple(b0[13:16]) == BLOCK0_VERSION)
    check("Block 0: Ident/Batch @0x34/0x47",
          bytes(b0[0x34:0x43]) == BLOCK0_IDENT and bytes(b0[0x47:0x4D]) == BLOCK0_BATCH)
    check("Block 0: 29 x '0' @0x12..0x2E", bytes(b0[0x12:0x2F]) == b"0" * 29)
    check("Block 0: Reserve [0x43..0x46] und [0x4D] == 0",
          bytes(b0[0x43:0x47]) == b"\x00" * 4 and b0[0x4D] == 0x00)

    check("Block 1: Fabrik-Header [0..8]",
          b1[0] == 0x90 and b1[1] == 0x90 and b1[2] == 0x1E and b1[3] == 0x6E and
          b1[4] == 0x78 and b1[5] == 0x64 and b1[6] == 0x30 and b1[7] == 0x3C and
          b1[8] == 0x00)
    check("Block 1: [0x2D]=0 und [0x2E]=0", b1[0x2D] == 0 and b1[0x2E] == 0)
    check("Block 1: Gangtabelle == Fabrik-ROM 0x0801DA49",
          bytes(b1[0x09:0x2D]) == FACTORY_GEAR_TABLE)
    check("Gangtabelle: Gang 0 leer", FACTORY_GEAR_TABLE[0:6] == b"\x00" * 6)

    ok = True
    det = ""
    for i in range(1, 6):
        row = FACTORY_GEAR_TABLE[i * 6:(i + 1) * 6]
        if not (row[0] == i and row[1] == GEAR_LIMITS_FACTORY[i - 1] and
                row[2] == GEAR_NIBBLES_FACTORY[i - 1] == row[3] and
                row[4] == GEAR_CURRENTS_FACTORY[i - 1] == row[5]):
            ok = False
            det = "Zeile {}".format(i)
    check("Gangtabelle: Limit/Nibble/Strom-Muster (1..5)", ok, det)

    check("Zoll-Kodierung: 279,4 mm -> 0x6E (11,0 Zoll)", wheel_code_from_mm(279.4) == 0x6E)
    check("Spannungskarte: 48 V -> (0x30, 0x3C)", PACK_VOLTAGE_MAP.get(48) == (0x30, 0x3C))

    # Alternativer Ganglimit-Pfad (--gear-limits): konsistent, aber andere Summe
    alt_table = build_gear_table([15, 25, 35, 45, 55])
    b1_alt = build_block1(gear_table=alt_table)
    c_alt_ref = xor_ref(b1_alt[0x00:0x34])
    check("--gear-limits-Pfad: Pruefsumme konsistent, != Fabrikwert",
          c_alt_ref == int.from_bytes(b1_alt[0x34:0x36], "little") and c_alt_ref != c1_ref)

    # Dateiausgabe + Ruecklesen
    if outdir is None:
        import tempfile
        outdir = tempfile.mkdtemp(prefix="ivcu_eeprom_selftest_")
    written = write_outputs(outdir, b0, b1, build_readme(b0, b1, []))

    read_ok = True
    read_detail = ""
    try:
        with open(os.path.join(outdir, "block0.bin"), "rb") as f:
            d0 = f.read()
        with open(os.path.join(outdir, "block1.bin"), "rb") as f:
            d1 = f.read()
        if (bytes(d0) != bytes(b0)) or (bytes(d1) != bytes(b1)):
            read_ok = False
            read_detail = "Binaerdateien weichen von den Puffern ab"
        elif (len(d0) != 80) or (len(d1) != 56):
            read_ok = False
            read_detail = "Laengen nach Ruecklesen falsch"
        elif int.from_bytes(d0[0x4E:0x50], "little") != xor_ref(d0[0:0x4E]) or \
             int.from_bytes(d1[0x34:0x36], "little") != xor_ref(d1[0:0x34]):
            read_ok = False
            read_detail = "Pruefsumme nach Ruecklesen inkonsistent"
        hex_ok = True
        with open(os.path.join(outdir, "block0.hex"), "r", encoding="utf-8") as f:
            hex0 = f.read()
        with open(os.path.join(outdir, "block1.hex"), "r", encoding="utf-8") as f:
            hex1 = f.read()
        if not hex0.startswith("0000  56 43 55") or not hex1.startswith("0000  90 90 1E"):
            hex_ok = False
        check("Dateiausgabe + Ruecklesen (bin, 80/56, Pruefsummen)", read_ok, read_detail)
        check("Hexdumps vorhanden und plausibel", hex_ok)
    except OSError as exc:
        check("Dateiausgabe + Ruecklesen", False, str(exc))

    print("Selbsttest: Ausgabeordner = {}".format(os.path.abspath(outdir)))
    for name, ok_, detail in checks:
        line = "[{}] {}".format("OK  " if ok_ else "FAIL", name)
        if detail and not ok_:
            line += "  ({})".format(detail)
        print(line)
    failed = sum(1 for _, ok_, _ in checks if not ok_)
    print("-" * 62)
    if failed == 0:
        print("SELFTEST: PASS ({} Pruefungen, Ausgabe: {})".format(len(checks), outdir))
        return True
    print("SELFTEST: FAIL ({} von {} Pruefungen fehlgeschlagen)".format(failed, len(checks)))
    return False


# ---------------------------------------------------------------------------
# CLI
# ---------------------------------------------------------------------------
def parse_gear_limits(text):
    parts = [p.strip() for p in text.split(",") if p.strip() != ""]
    if len(parts) != 5:
        raise ValueError("genau 5 Werte erforderlich, z. B. 15,25,35,45,55")
    return [int(p, 0) for p in parts]


def main(argv=None):
    ap = argparse.ArgumentParser(
        prog="eeprom_images.py",
        description="Erzeugt die externen I2C-EEPROM-Bloecke der IVCU "
                    "(Block 0 @0x00/80 B, Block 1 @0x50/56 B).")
    ap.add_argument("--outdir", default=".", help="Zielverzeichnis (Default: .)")
    ap.add_argument("--wheel-mm", type=float, default=None,
                    help="Raddurchmesser in mm -> Kodierung [3] (Fabrik: 279,4 = 11,0 Zoll = 0x6E)")
    ap.add_argument("--pack-v", type=int, default=48, choices=sorted(PACK_VOLTAGE_MAP),
                    help="Pack-Nennspannung; setzt [6]-Spannungscode und [7]-Rohwert")
    ap.add_argument("--full-v", type=int, default=None,
                    help="Override fuer [7]-Rohwert (z. B. 0x3C=60); nur mit Pruefung verwenden")
    ap.add_argument("--gear-limits", default=None,
                    help="5 Rohbytes fuer Gang-Limits 1..5, z. B. 15,25,35,45,55")
    ap.add_argument("--pole-pairs", type=int, default=30,
                    help="Polpaare -> [2] (Fabrik: 30 = 0x1E)")
    ap.add_argument("--selftest", action="store_true",
                    help="Selbsttest: Bloecke erzeugen, Pruefsummen/Laengen pruefen")
    args = ap.parse_args(argv)

    if args.selftest:
        ok = run_selftest(args.outdir if args.outdir != "." else None)
        return 0 if ok else 1

    notes = []

    limits = None
    if args.gear_limits is not None:
        try:
            limits = parse_gear_limits(args.gear_limits)
        except ValueError as exc:
            ap.error("--gear-limits: {}".format(exc))
        notes.append("Gang-Limits manuell gesetzt (Rohbytes): {}".format(limits))

    if args.wheel_mm is not None:
        try:
            wheel_code = wheel_code_from_mm(args.wheel_mm)
        except ValueError as exc:
            ap.error("--wheel-mm: {}".format(exc))
        notes.append("Wheel-Code aus {:.1f} mm -> 0x{:02X} ({:.1f} Zoll)".format(
            args.wheel_mm, wheel_code, wheel_code / 10.0))
    else:
        wheel_code = BLOCK1_WHEEL_DEFAULT

    if not 0 <= args.pole_pairs <= 0xFF:
        ap.error("--pole-pairs: Wert ausserhalb 0..255")

    volt_code, pack_raw = PACK_VOLTAGE_MAP[args.pack_v]
    if args.full_v is not None:
        if not 0 <= args.full_v <= 0xFF:
            ap.error("--full-v: Wert ausserhalb 0..255")
        pack_raw = args.full_v
        notes.append("[7]-Rohwert per --full-v auf 0x{:02X} gesetzt".format(pack_raw))
    if args.pack_v != 48 or args.full_v is not None:
        notes.append("WARNUNG: Pack-/Spannungskombination 0x{:02X}/0x{:02X} ist NICHT "
                     "verifiziert (verifiziert ist nur 48 V -> 0x30/0x3C). Vor dem "
                     "Schreiben am Fahrzeug pruefen!".format(volt_code, pack_raw))

    gear_table = build_gear_table(limits)
    b0 = build_block0()
    b1 = build_block1(pole_pairs=args.pole_pairs, wheel_code=wheel_code,
                      volt_code=volt_code, pack_raw=pack_raw, gear_table=gear_table)

    readme = build_readme(b0, b1, notes)
    paths = write_outputs(args.outdir, b0, b1, readme)

    print("EEPROM-Images erzeugt:")
    for p in paths:
        print("  " + os.path.abspath(p))
    print("Block 0: 80 Byte, Pruefsumme 0x{:02X} (u16 LE @ [0x4E..0x4F])".format(b0[0x4E]))
    print("Block 1: 56 Byte, Pruefsumme 0x{:02X} (u16 LE @ [0x34..0x35])".format(b1[0x34]))
    for n in notes:
        print("  Hinweis: " + n)
    return 0


if __name__ == "__main__":
    sys.exit(main())
