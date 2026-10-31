#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""make_armnt_pe.py -- Minimaler ARMNT-PE-Wrapper fuer REA/Ghidra-Analysen

Verpackt ein Roh-Firmware-Image (.bin oder Intel-.hex) in eine minimale
ARMNT-PE-Datei, damit Windows-REA/Ghidra das Thumb-2-Image laden und
analysieren kann (Rohbilder werden dort abgelehnt).

Aufbau (an der Vorlage AWIVCU_APP_R3_4_13.pe4/5.bin verifiziert):
  - DOS-Header, e_lfanew=0x40, "PE\\0\\0"
  - COFF: machine=0x01C4 (ARMNT), 2 Sektionen, chars=0x0102
  - PE32-Optionalheader, ImageBase/RVA so, dass die Firmware-Adresse stimmt:
        ImageBase + RVA == Startadresse des Firmware-Images
  - .text  = Firmware
  - .stubs = Kette korrekt codierter Thumb-BL-Instruktionen auf alle
             Call-Targets (aus BL-Scan beider Thumb-BL-Codierungen) plus die
             Vektoreintraege -> zwingt Ghidra, Funktionen anzulegen.
             Entry-Point zeigt auf 0x1 der .stubs-Sektion.

Beispiele:
  python make_armnt_pe.py --fw firmware.bin --out fw.pe.bin \
         --image-base 0x08000000 --text-rva 0x7000
  python make_armnt_pe.py --fw display_app.bin --out display.pe.bin \
         --image-base 0x0 --text-rva 0x10000
"""
import argparse
import struct
import sys
from pathlib import Path


# ---------------------------------------------------------------------------
# Laden
# ---------------------------------------------------------------------------
def load_hex(path):
    data = {}
    base = 0
    for line in Path(path).read_text(encoding="ascii", errors="ignore").splitlines():
        line = line.strip()
        if not line.startswith(":"):
            continue
        raw = bytes.fromhex(line[1:])
        n, addr, typ = raw[0], (raw[1] << 8) | raw[2], raw[3]
        payload = raw[4:4 + n]
        if typ == 0x00:
            for i, b in enumerate(payload):
                data[base + addr + i] = b
        elif typ == 0x04:
            base = ((payload[0] << 8) | payload[1]) << 16
        elif typ == 0x02:
            base = ((payload[0] << 8) | payload[1]) << 4
        elif typ == 0x01:
            break
    if not data:
        raise SystemExit("FEHLER: keine Daten im HEX")
    lo, hi = min(data), max(data)
    out = bytearray(hi - lo + 1)
    for a, b in data.items():
        out[a - lo] = b
    return bytes(out), lo


def load_fw(path):
    p = Path(path)
    if p.suffix.lower() == ".hex":
        return load_hex(p)
    return p.read_bytes(), None


# ---------------------------------------------------------------------------
# Thumb-BL: Decoder (beide Codierungen) und Encoder (T1, M3/M4-Standard)
# ---------------------------------------------------------------------------
def decode_bl_t1(addr, hw1, hw2):
    """ARMv7-M BL (T1). Rueckgabe Zieladresse oder None."""
    if (hw1 & 0xF800) != 0xF000 or (hw2 & 0xD000) != 0xD000:
        return None
    s = (hw1 >> 10) & 1
    j1 = (hw2 >> 13) & 1
    j2 = (hw2 >> 11) & 1
    i1 = (~(j1 ^ s)) & 1
    i2 = (~(j2 ^ s)) & 1
    imm = (s << 24) | (i1 << 23) | (i2 << 22) | ((hw1 & 0x3FF) << 12) | ((hw2 & 0x7FF) << 1)
    if s:
        imm -= 1 << 25
    return addr + 4 + imm


def decode_bl_t1_thumb1(addr, hw1, hw2):
    """ARMv6-M (Cortex-M0) BL: 11110/11111. Rueckgabe Zieladresse oder None."""
    if (hw1 & 0xF800) != 0xF000 or (hw2 & 0xF800) != 0xF800:
        return None
    imm = ((hw1 & 0x7FF) << 12) | ((hw2 & 0x7FF) << 1)
    if imm & (1 << 22):
        imm -= 1 << 23
    return addr + 4 + imm


def encode_bl_t1(addr, target):
    """Erzeugt 4 Byte Thumb-2-BL von addr nach target (Ziel|1 wird akzeptiert)."""
    offset = (target & ~1) - (addr + 4)
    if offset % 2:
        raise ValueError("BL-Offset ungerade")
    if not (-(1 << 24) <= offset < (1 << 24)):
        raise ValueError("BL-Offset ausserhalb 25-bit")
    v = offset & 0x1FFFFFF          # 25-bit Zweierkomplement (S:I1:I2:imm10:imm11:0)
    s = (v >> 24) & 1
    i1 = (v >> 23) & 1
    i2 = (v >> 22) & 1
    j1 = ((~i1) ^ s) & 1
    j2 = ((~i2) ^ s) & 1
    hw1 = 0xF000 | (s << 10) | ((v >> 12) & 0x3FF)
    hw2 = 0xF800 | (j1 << 13) | (j2 << 11) | ((v >> 1) & 0x7FF)
    return struct.pack("<HH", hw1, hw2)


def find_targets(fw, start_addr):
    """Alle BL-Ziele (beide Codierungen) + Vektoreintraege im Image."""
    targets = set()
    n = len(fw) - 4
    for i in range(0, n, 2):
        hw1, hw2 = struct.unpack_from("<HH", fw, i)
        if (hw1 & 0xF800) != 0xF000:
            continue
        a = start_addr + i
        for dec in (decode_bl_t1, decode_bl_t1_thumb1):
            t = dec(a, hw1, hw2)
            if t is not None and start_addr <= (t & ~1) < start_addr + len(fw):
                targets.add(t & ~1)
    # Vektoren (max 64 Worte)
    for k in range(0, min(64 * 4, len(fw) - 3), 4):
        v = struct.unpack_from("<I", fw, k)[0]
        if v & 1 and start_addr <= (v & ~1) < start_addr + len(fw):
            targets.add(v & ~1)
    return sorted(targets)


# ---------------------------------------------------------------------------
# PE bauen
# ---------------------------------------------------------------------------
def build_pe(fw, start_addr, out_path, with_stubs=True, max_stubs=6000):
    image_base = start_addr & ~0xFFFF
    text_rva = start_addr - image_base
    if text_rva < 0x1000:
        # Header-Kollision vermeiden: naechstniedrigere 64K-Basis verwenden
        if image_base < 0x10000:
            raise SystemExit("FEHLER: Startadresse %#x zu niedrig fuer PE-Wrapper"
                             % start_addr)
        image_base -= 0x10000
        text_rva = start_addr - image_base

    size_headers = 0x400
    file_align = 0x200
    sect_align = 0x1000

    text_rawsize = (len(fw) + file_align - 1) // file_align * file_align
    blob = bytearray()
    blob += fw + b"\x00" * (text_rawsize - len(fw))

    stubs = b""
    stub_rva = 0
    if with_stubs:
        targets = find_targets(fw, start_addr)[:max_stubs]
        stub_rva = (text_rva + len(fw) + sect_align - 1) // sect_align * sect_align
        stub_addr = image_base + stub_rva
        parts = []
        for idx, t in enumerate(targets):
            from_addr = stub_addr + idx * 4
            parts.append(encode_bl_t1(from_addr, t))
        stubs = b"".join(parts)
        # Selbsttest: alle Stubs rueckwaerts decodieren
        for idx, t in enumerate(targets):
            a = stub_addr + idx * 4
            hw1, hw2 = struct.unpack_from("<HH", stubs, idx * 4)
            if (decode_bl_t1(a, hw1, hw2) & ~1) != (t & ~1):
                raise SystemExit("FEHLER: Stub-Selbsttest bei %#x" % a)
        stubs_raw = stubs + b"\x00" * (-len(stubs) % file_align)
        stub_va = stub_rva
        entry = stub_va | 1
        nsec = 2
        size_image = (stub_rva + len(stubs) + sect_align - 1) // sect_align * sect_align
    else:
        reset = struct.unpack_from("<I", fw, 4)[0] if len(fw) > 8 else text_rva
        entry = (reset - image_base) & 0xFFFFFFFF
        nsec = 1
        size_image = (text_rva + len(fw) + sect_align - 1) // sect_align * sect_align

    # Header
    hdr = bytearray(size_headers)
    hdr[0:2] = b"MZ"
    struct.pack_into("<I", hdr, 0x3C, 0x40)
    hdr[0x40:0x44] = b"PE\x00\x00"
    # COFF
    struct.pack_into("<HHIIIHH", hdr, 0x44, 0x01C4, nsec, 0, 0, 0, 0xE0, 0x0102)
    opt = 0x44 + 20
    # PE32-Optionalheader
    struct.pack_into("<H", hdr, opt + 0, 0x010B)          # Magic
    struct.pack_into("<I", hdr, opt + 4, 0)               # SizeOfCode (nicht kritisch)
    struct.pack_into("<I", hdr, opt + 8, len(fw))
    struct.pack_into("<I", hdr, opt + 12, 0)
    struct.pack_into("<I", hdr, opt + 16, entry)          # AddressOfEntryPoint
    struct.pack_into("<I", hdr, opt + 20, text_rva)       # BaseOfCode
    struct.pack_into("<I", hdr, opt + 24, stub_rva)
    struct.pack_into("<I", hdr, opt + 28, image_base)
    struct.pack_into("<I", hdr, opt + 32, sect_align)
    struct.pack_into("<I", hdr, opt + 36, file_align)
    struct.pack_into("<I", hdr, opt + 56, size_image)
    struct.pack_into("<I", hdr, opt + 60, size_headers)
    struct.pack_into("<H", hdr, opt + 68, 3)              # Subsystem: console
    struct.pack_into("<I", hdr, opt + 92, 0)              # NumberOfRvaAndSizes
    # Sektionstabelle (8s + 6xI + 2xH + I = 40 Byte je Eintrag)
    secoff = opt + 0xE0
    struct.pack_into("<8sIIIIIIHHI", hdr, secoff, b".text",
                     len(fw), text_rva, text_rawsize, size_headers, 0, 0,
                     0, 0, 0x60000020)
    if with_stubs:
        struct.pack_into("<8sIIIIIIHHI", hdr, secoff + 40, b".stubs",
                         len(stubs), stub_rva, len(stubs_raw), size_headers + text_rawsize,
                         0, 0, 0, 0, 0x60000020)

    out = bytes(hdr) + bytes(blob)
    if with_stubs:
        out += stubs_raw
    Path(out_path).write_bytes(out)
    print("PE geschrieben: %s" % out_path)
    print("  ImageBase=%#010x  .text RVA=%#x (%d B)  Entry=%#010x" %
          (image_base, text_rva, len(fw), image_base + entry))
    if with_stubs:
        print("  .stubs RVA=%#x  %d BL-Stubs (%d B)" % (stub_rva, len(stubs) // 4, len(stubs)))
    print("  SizeOfImage=%#x" % size_image)


def main():
    ap = argparse.ArgumentParser(description="ARMNT-PE-Wrapper fuer Ghidra/REA")
    ap.add_argument("--fw", required=True, help="Firmware .bin oder .hex")
    ap.add_argument("--out", required=True, help="Ziel-PE-Datei")
    ap.add_argument("--image-base", default="0x08000000", help="PE-ImageBase")
    ap.add_argument("--text-rva", default="0x7000", help="RVA des .text")
    ap.add_argument("--no-stubs", action="store_true", help="ohne Stub-Kette")
    ap.add_argument("--max-stubs", type=int, default=6000)
    args = ap.parse_args()

    fw, hexbase = load_fw(args.fw)
    start = int(args.image_base, 0) + int(args.text_rva, 0)
    if hexbase is not None:
        print("HEX-Basis %#x, Image %d B" % (hexbase, len(fw)))
        if hexbase != start:
            print("  HINWEIS: HEX-Basis weicht von ImageBase+RVA ab!")
    build_pe(fw, start, args.out, with_stubs=not args.no_stubs, max_stubs=args.max_stubs)


if __name__ == "__main__":
    sys.exit(main())
