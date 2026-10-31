#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""ivcu_fw/build.py -- plattformuebergreifender Build (Windows/Linux/macOS)

Baut die eigene IVCU-Firmware OHNE make:
  python build.py                         # -> build/ivcu_fw.elf/.bin/.hex
  python build.py --clean
  python build.py --ldscript ld/ivcu_app_boot.ld   # Bootloader-Fenster-Variante

Toolchain: Arm GNU Toolchain (arm-none-eabi-gcc). Falls nicht im PATH, werden
uebliche Windows-Installationspfade automatisch durchsucht. Hinweis: Dieses
Skript ist die Primaervariante; Makefile und platformio.ini sind Alternativen.
"""
import argparse
import glob
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
BUILD = ROOT / "build"

CFLAGS = ["-mcpu=cortex-m3", "-mthumb", "-O2", "-g3",
          "-Wall", "-Wextra", "-std=gnu11",
          "-ffunction-sections", "-fdata-sections"]

WIN_HINTS = [
    r"C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\*\bin",
    r"C:\Program Files\Arm GNU Toolchain arm-none-eabi\*\bin",
    r"C:\Program Files (x86)\GNU Arm Embedded Toolchain\*\bin",
]


def find_tool(name: str) -> str:
    p = shutil.which(name)
    if p:
        return p
    for pat in WIN_HINTS:
        for d in glob.glob(pat):
            cand = Path(d) / (name + ".exe")
            if cand.exists():
                return str(cand)
    sys.exit("FEHLER: %s nicht gefunden. Arm GNU Toolchain installieren "
             "oder in den PATH legen." % name)


def run(cmd):
    print("+", " ".join(str(c) for c in cmd))
    subprocess.run([str(c) for c in cmd], check=True)


def main():
    ap = argparse.ArgumentParser(description="ivcu_fw bauen (ohne make)")
    ap.add_argument("--clean", action="store_true", help="build/ loeschen")
    ap.add_argument("--ldscript", default="ld/ivcu_full.ld",
                    help="Linker-Skript (Default: Vollersatz ab 0x08000000)")
    ap.add_argument("--target", default="ivcu_fw", help="Ausgabe-Basisname")
    args = ap.parse_args()

    if args.clean and BUILD.exists():
        shutil.rmtree(BUILD)
        print("build/ geloescht")

    cc = find_tool("arm-none-eabi-gcc")
    objcopy = find_tool("arm-none-eabi-objcopy")
    size = find_tool("arm-none-eabi-size")

    ld = ROOT / args.ldscript
    if not ld.exists():
        sys.exit("FEHLER: Linker-Skript %s fehlt" % ld)

    srcs = sorted((ROOT / "src").glob("*.c"))
    if not srcs:
        sys.exit("FEHLER: keine Quelldateien in src/")
    BUILD.mkdir(exist_ok=True)

    objs = []
    for s in srcs:
        o = BUILD / (s.stem + ".o")
        run([cc] + CFLAGS + ["-I", ROOT / "include", "-c", s, "-o", o])
        objs.append(o)

    elf = BUILD / (args.target + ".elf")
    run([cc] + CFLAGS + objs +
        ["-T", ld, "-nostartfiles",
         "-Wl,--gc-sections", "-Wl,-Map=" + str(BUILD / (args.target + ".map")),
         "-o", elf])

    run([objcopy, "-O", "binary", elf, BUILD / (args.target + ".bin")])
    run([objcopy, "-O", "ihex", elf, BUILD / (args.target + ".hex")])
    run([size, elf])

    print("\nFertig: %s" % BUILD)
    print("Flashen (Beispiel):")
    print('  openocd -f interface/stlink.cfg -f target/stm32f1x.cfg '
          '-c "program build/%s.hex verify reset exit"' % args.target)


if __name__ == "__main__":
    main()
