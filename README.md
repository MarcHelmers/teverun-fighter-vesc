# Teverun Fighter Mini — IVCU Hardware Documentation & VESC Conversion

**Status:** static-analysis based (REA/Ghidra) · bench validation pending · community work-in-progress
**Analyzed firmware:** `AWIVCU_APP R3.4.13` (IVCU "Box C")
**SHA-256:** `613ee4166800c02039a247ed7c39c320b14d9442202cb9ac79c1c609bc5b1318`

This repository documents the **Teverun Fighter Mini** (and related Fighter/Box-C
platforms, FW R3.4.13) down to the byte level — pinout, all four communication
links, protocols, curves and EEPROM layout — and provides **three practical ways
to replace the stock drive electronics with a VESC-based controller**, including
open reference implementations:

1. **ESP32 I/O bridge** — keeps the stock IVCU, bridges display, BLE/app and VESC
2. **Custom IVCU firmware** (`ivcu_fw/`) — replaces the stock firmware entirely; no ESP32 needed
3. **ESC emulation** — stock IVCU stays 100 % original; a VESC emulates the stock ESC on the 9600-baud link

Language note: the in-depth documents in `docs/` are **German**; this README
summarizes everything essential in English. 🇩🇪 Kurzfassung am Ende.

---

## ⭐ What is NEW here (not, or not this precisely, publicly documented before)

To the best of our knowledge, the following findings were **not published
before this project** (sources: our static analysis of R3.4.13 + community
cross-checks). If you work on this platform, these are the highlights:

1. **Pinout correction with register evidence:** the display link (USART3) is
   **PB10/PB11** — an earlier PC10/PC11 claim circulating in the scene is wrong.
   Full pin map with per-signal proof addresses: `docs/PINOUT.md`.
2. **The IVCU has NO ADC at all** — its peripheral map is USART×3, CAN, I²C,
   TIM, DMA, GPIO only. **Throttle and brake are wired directly to the ESC(s),
   the IVCU never sees them.** For every VESC conversion this means: throttle +
   brake hall sensors must be re-routed to the VESC ADC inputs (with ≤ 3.3 V
   care!) — see `docs/ESC_Emulation_VESC.md` §5 and `docs/UBox_Dual_Adapterplan.md`.
3. **Complete ESC protocol decode (IVCU ⇄ stock ESC, 9600 Bd):**
   field tables for all four `4A` frame variants (`11/14` × `3A/3B`) incl. the
   RAM sources of every byte (gear, speed limit, phase current, start/EABS
   levels, voltage code, flags) — and the **variant selection rule**:
   the ESC reports its **dual capability in `0x71` byte [11] bit 0** (honored
   only from the `3A` reply); `1` → IVCU talks `0x14` (20-byte frames),
   `0` → `0x11` (17-byte), `0xFF` at boot → **alternating probe** until answered.
4. **`0x11`-frame checksum quirk:** the XOR is computed over **all 19 builder
   bytes**, but only `[0..15]` + checksum go on the wire — bytes 16..18 can be
   stale garbage. Any reimplementation must replicate/ tolerate this.
5. **`0x71` telemetry map byte-exact:** `FUN_0800F4FA` copies ESC `[3]`→`0x2DB`,
   `[4]`→`0x2DC`, `[5..6]`→u16@`0x2DE`, `[7]`→`0x2E0`, `[8..9]`→u16@`0x2E2`,
   `[10]`→`0x2E4` ("rotation raw"), `[11]`→`0x2E5`; the `3B` reply mirrors to
   `0x2E6..0x2EF`. **Alive rule: ≤ 600 ticks per subtype**, else display/app
   error flags.
6. **Display `0x35` frame verified byte-exact** — incl. the previously missed
   byte `[12]` (mirror flags; all following fields shift +1) and the
   **rotation-time candidate fields `[17..18]/[20..21]/[22..23]/[24..25]`**
   (`rot = wheel_code · 287 / km/h`, 0.1 ms units; the community-checked
   `speedRaw ≥ 3000 ⇒ 0` rule applies).
7. **SOC curve extracted and approximated:** ROM table @`0x0801DC78`
   (3.000–4.150 mV); ready-to-use approximations with error figures —
   21-point table **0.05 %SOC**, 5-segment DP **1.10 %**, poly-12 **0.55 %**
   (`tools/soc_kennlinie.c` + plot).
8. **EEPROM layout + generator:** external 24Cxx at I²C `0x50`, blocks
   `0x00/0x50/0x88/0x94/0xA0/0xB0`; `tools/eeprom_images.py` reproduces the
   factory settings — **block 1 is byte-identical to the ROM factory table**.
9. **Full BLE/App command map implemented in open firmware:** `0x01` handshake,
   `0x02` sleep, `0x03` charge, `0x08` LED (RGB), **`0x18` settings write**
   (per-gear layout, `0xFF` = "no change"), `0x1A` custom-key functions,
   `0x1C` RTC, `0x1F` FIN name. Previously only fragments of this were public.
10. **Three open reference implementations (first ones known for this platform):**
    * `firmware/ivcu_fw/` — **custom ARM firmware for the stock IVCU board**
      (GD32F303-class), replaces the original app completely, compiled clean,
      with CI; keeps display + stock BLE/app and talks to the VESC
      (identical Lisp protocol as the ESP32 bridge).
    * `firmware/bridge_esp32/` — ESP32 bridge (display/BLE/VESC in one, LED
      option), compiled clean.
    * `lisp/vesc_esc_emulator.lisp` — VESC **emulates the stock ESC** for a
    *completely untouched* IVCU, incl. **dual-motor support** (CAN mirroring
      to the second controller; `can-send-sid`, packets 1/2).

11. **Display firmware decoded (REA deep-dive, 31.10.2026):** the display computes
    `speed = wheel([30]) · 287 / rot` with **rot = bytes [8..9]** (u16 BE;
    `< 5 ⇒ 0x640`, `> 2999 ⇒ 0` — the community "≥3000" rule is now code-proven),
    maps the full `0x35` frame, builds the `0x4C` command frame field-exactly,
    and introduces the **new-generation `A5` frames** (which replace `0x8A/8B/8C`
    and are not parsed by R5/D5 → they belong to the **10.x firmware family**).
    Also documented: R5 display-builder field map, the eKFV **`0x16`=22 clamp**
    on the 4A frame's limit byte (flag `0x2000030C`), and the blinker pins
    **PB3/PB4/PB12** (GPIOB).

Additionally confirmed: MCU is a **GD32F303-class part (Cortex-M4F, FPU)** with
STM32F1-style peripherals (SWD pads; RDP check non-destructive; app window
`0x08007000…0x0801EFFF`, flag pages `0x0801F000`/`0x0801F800`, CRC-16 poly
`0x8005`) — see `docs/AWIVCU_APP_R3_4_13_Doku_FINAL.md` §2/§16/§17.

## Repository layout

```
docs/        byte-level documentation (German):
               Doku_FINAL (master, incl. §16 web supplement + §17 approaches)
               Analyse.md · Kennlinien_und_Datenbereiche.md (curves + data map)
               PINOUT.md (pin map with sources) · ESC_Emulation_VESC.md
               VESC_IVCU_Ersatz_Anleitung.md · Teverun_IO_Bridge_Hardware.md
               UBox_Dual_Adapterplan.md (Spintend UBOX dual harness plan)
firmware/    ivcu_fw/ (custom IVCU firmware: build.py/Makefile/PlatformIO, CI)
             bridge_esp32/ (ESP32 bridge, PlatformIO) · can_sniffer_esp32/ (BMS CAN)
             ivcu_linker.ld, startup_ivcu.c (early skeleton, superseded by ivcu_fw)
lisp/        vesc_ivcu_emulator.lisp (MODE 0 bridge / MODE 1 standalone display)
             vesc_esc_emulator.lisp (stock-IVCU ESC emulation, DUAL support)
tools/       ivcu_protocol.py + ivcu_sim.py (codec + frame simulator)
             ivcu_esc_sniffer.py (decode ESC-bus UART captures)
             ivcu_fw_tool.py (HEX validate/patch/CRC) · eeprom_images.py
             soc_kennlinie.c/.png · ghidra_apply_annotations.py · build_callgraph.py
             make_armnt_pe.py (ARMNT-PE wrapper for Ghidra/REA deep-dives)
analysis/    decompiled.c (671 functions, 83.1 % of code bytes, commented)
             function_index.csv · strings.txt · callgraph.dot/.svg (+reduced)
             decomp_r5/ · decomp_d5/ · decomp_display/ (REA/Ghidra exports, §20)
```

## Which conversion path for me?

| | A: ESP32 bridge | 1: custom IVCU firmware | 2: ESC emulation |
|---|---|---|---|
| Stock IVCU | stays | **replaced** (flashed via SWD) | **100 % stock** |
| Stock display/app/LED | yes | yes | yes |
| Extra hardware | ESP32 + wiring | none | none (VESC only) |
| VESC role | motor only | motor only | motor + ESC emulation |
| Throttle/brake | to VESC ADC | to VESC ADC | to VESC ADC |
| Effort/risk | low/build a harness | medium (SWD flash, bench bring-up) | medium (protocol edge cases) |
| Docs | VESC guide + bridge docs | `ivcu_fw/README.md` | `ESC_Emulation_VESC.md` + adapter plan |

All three share the same VESC-side control core (`GEAR_*`, EABS, slew, temp
limits, SOC from the extracted curve) and the community-checked speed law.

## Open items (help welcome)

* ✅ **Rotation field solved** (31.10.2026): the display reads it from byte `[8..9]`
  — all senders updated. Next analysis target: the **10.x firmware family**
  (A5 display protocol, e.g. `D10_4_6_4`).
* **`0x71` byte [1]** and the **units** of bytes `[4..9]` / scaling of `[10]`
  → use `tools/ivcu_esc_sniffer.py` on a logic-analyzer capture.
* **BMS CAN IDs/payloads** → `firmware/can_sniffer_esp32/` (listen-only) is ready.
* **LED strip:** data line pin + LED count (addressable RGB per firmware).
* **Connector pinouts** (IVCU M8 / motor / hall) — photos + continuity tests welcome.
* EEPROM bus pin confirmation (PB6/7 vs PB8/9) and CAN pin remap.

## Firmware versions & sources (research update 31.10.2026)

| Source | Contents |
|---|---|
| Teverun After-Sale Guide (official) | IVCU **2.2.17 / 3.4.10 / 3.6.10** — 3.6.10 is newer than the analyzed R3.4.13 |
| Rydology | **3.4.13** (identical to the analyzed image) + 3.4.5 — direct .hex links |
| **Spooonky's repo** (German RE project) | IVCU **D5.4.10 / D5.4.14 (eKFV!)**, **R5.4.19** (the build patched by the tr-fw project), **ALI D3.4.12** (+bootloader/chipdump) — **display firmware** (`display_app.bin`, `display_bootloader.bin`) — web-patcher sources incl. exact **patch profiles (JSON)** |
| eScooter-Stammtisch thread 3219 | older eKFV **D10_4_6_4**, **R3_4_10** (+address-analysis Excel) |
| Official app | 3.6.10 & battery "AWE" firmware are distributed in-app only |
| **ESC / motor-controller firmware** | **not public**; zero-start unlock requires a dealer update device + cable |

All downloaded IVCU images validate with our tooling (`tools/ivcu_fw_tool.py`,
CRC OK) — see `docs/AWIVCU_APP_R3_4_13_Doku_FINAL.md` §19 for sizes/hashes/sources
and first insights from the community patch profiles:

* R5.4.19 **carries the `0x16` (=22) speed clamp** in all four controller-frame
  builders; **R3.4.13 does not** — version history of the "speed/pull" clamp.
* eKFV **D5.4.14** clamps the 4A-frame output byte (`[+0xA]`, our Gear-Limit byte)
  to an artificial value; removal yields the natural ~100 like the ALI box.
* **PB5** is involved in the turn-signal branch (R5.4.19) — new pin hint for LED work.
* **Zero-start** is an EEPROM **block 5 @0xB0** setting (→ RAM `0x20000399`), absent
  from the D5 series — confirms our EEPROM block layout.

**Next steps enabled by this:** decompile-compare **D5.4.14 (eKFV) / R5.4.19** against
R3.4.13, and **analyze the display firmware** — which can settle the remaining
display-protocol open items (rotation-time field in `0x35`, meaning of `0x8A/0x8B/0x8C`).

## Safety, legal, credits

* Work on your own risk; high-voltage battery, brakes and motor safety are on
  you. Bench-test everything before riding (checklists in the docs).
* No vendor firmware binary is included here; obtain the stock HEX via the
  usual channels and **verify the SHA-256 above** before restoring. All docs/
  code are our own reverse-engineering output for interoperability/repair.
* Not affiliated with Teverun or Spintend. Credits to the community work of
  *Laufbursche42* (`tr-fw`, `tr-lb-edition`), **Spooonky** (eKFV reverse-engineering,
  display firmware & web patcher) and all eScooter-Stammtisch / forum contributors.

## License

* Documentation (`docs/`, `analysis/`, README): **CC BY-NC-SA 4.0**
* Source code (`firmware/`, `lisp/`, `tools/`): **MIT** — see `LICENSE.md`.

---

## 🇩🇪 Deutsche Kurzfassung

Dieses Repo dokumentiert die Teverun-*Fighter-Mini*-Hardware (IVCU „Box C",
FW R3.4.13) bis auf Byte-Ebene und beschreibt **drei Umbauwege auf VESC**:
ESP32-Bridge, **eigene IVCU-Firmware** (`firmware/ivcu_fw/` — ohne ESP32) und
**ESC-Emulation** (IVCU bleibt unangetastet). Die Tiefendokumente in `docs/`
sind deutsch.

**Besonders hervorheben (bislang nicht öffentlich bekannt):**

1. **Pinout-Korrektur:** Display hängt an **PB10/PB11** (nicht PC10/11).
2. **Die IVCU hat keinen ADC** — Gas/Bremse liegen direkt am ESC; bei jedem
   VESC-Umbau müssen sie an die VESC-ADC-Eingänge (≤ 3,3 V beachten!).
3. **ESC-Protokoll vollständig dekodiert** (4× `4A`-Varianten, Feldtabellen)
   inkl. **Variantenwahl:** Dual-Fähigkeit steckt in `0x71`-Byte **[11] Bit0**
   (nur 3A-Antwort) → `0x14`- statt `0x11`-Frames; beim Boot alternierendes Probieren.
4. **`0x11`-Checksummen-Eigenheit** (XOR über 19 Bytes, gesendet werden 16+Prüfsumme).
5. **`0x71`-Datenzuordnung Byte→RAM→Anzeige** exakt + Alive-Grenze 600 Ticks.
6. **Display-`0x35`-Layout verifiziert** (inkl. fehlendem Byte [12], +1-Verschiebung)
   und Rotationszeit-Kandidatenfeldern.
7. **SOC-Kennlinie** aus ROM extrahiert + Näherungen (21 Punkte: 0,05 %SOC).
8. **EEPROM-Layout** + Generator (Block 1 byte-identisch zum Werksabbild).
9. **Komplette BLE-Kommandokarte** (0x01–0x1F) in offener Firmware umgesetzt.
10. **Drei offene Referenzimplementierungen** (IVCU-Firmware, ESP32-Bridge,
    ESC-Emulator inkl. Dual-CAN-Spiegelung) — für diese Plattform unseres
    Wissens die ersten öffentlichen.

**Offen (Werkbank/Fahrzeug):** Rotationsfeld-Kalibrierung, `0x71`-Byte [1] und
Einheiten der ESC-Datenbytes (Sniffer liegt bereit), BMS-CAN-IDs (Sniffer-FW
liegt bereit), LED-Ader/Anzahl, Stecker-Pinouts.

*Alles auf eigene Verantwortung. Kein Hersteller-Firmware-Binary enthalten
(SHA-256 siehe oben).*
