# ivcu_fw – Eigene Firmware für die Original-IVCU (Weg 1)

**Ziel:** Die Original-IVCU (Teverun, „Box C", GD32F303-Klasse) bekommt **eigene
Firmware**, die exakt die Aufgabe der bisherigen ESP32-Bridge übernimmt – Display,
Teverun-App (Stock-BLE-Modul) und VESC-Anbindung in **einem** Gerät. Der ESP32
entfällt. Das VESC-Lisp-Skript bleibt **unverändert**
(`../vesc_ivcu_emulator.lisp`, MODE 0).

```
 Stock-Display <--9600-- USART3 ┐
 Teverun-App   <--115200 USART1 ┤  IVCU mit ivcu_fw        ┌ VESC
 (Stock-BLE-Modul)              ├──────────────────────────┤  (Lisp MODE 0)
 VESC          <--115200 USART2 ┘  8-Byte '54 cmd … XOR'   └ Motor/ADC
```

## Entscheidungen (dokumentiert)

| Frage | Wahl | Begründung |
|---|---|---|
| Toolchain | **arm-none-eabi-gcc + Makefile** (CMSIS-frei) | passt exakt zum vorhandenen Skelett (`../startup_ivcu.c`, `../ivcu_linker.ld`); keine IDE-Abhängigkeit |
| Flash-Strategie Standard | **Vollersatz ab 0x08000000** (`ld/ivcu_full.ld`) | einfachster, robustester Bring-up; Original-Bootloader wird überschrieben; Original-HEX (`../AWIVCU_APP_R3_4_13.hex`, SHA-256 verifiziert) liegt als Restore-Backup vor |
| Flash-Strategie Alternative | **Bootloader-Fenster 0x08007000** (`ld/ivcu_app_boot.ld`) | nur falls der Original-Bootloader behalten werden soll – dann müssen App-Valid-Magic `0x5A5A5A5A` @0x0801F800 und CRC (poly 0x8005) nachgebildet werden (Details: tr-fw/Community; am Fahrzeug verifizieren) |
| UART2-Baudrate | **115200 statt 9600** | Ziel ist der VESC (nicht der Stock-ESC); damit ist das bestehende Lisp-Protokoll 1:1 nutzbar |

## Dateien

| Datei | Inhalt |
|---|---|
| `Makefile` | Build (`.elf/.bin/.hex/.map`), `make flash` (OpenOCD/ST-Link) |
| **`build.py`** | Build **ohne make** (Windows/Linux/macOS); findet die Toolchain auch in Windows-Standardpfaden |
| `platformio.ini` | alternativer PlatformIO-Build (ungetestet; kein Framework) |
| `ld/ivcu_full.ld` | Vollersatz-Linker (Standard) |
| `ld/ivcu_app_boot.ld` | Alternative: Bootloader-Fenster |
| `include/ivcu_config.h` | Pins/Bauds, Fahrzeug-Konstanten, Timing, Rot-Kandidaten |
| `include/ivcu_hw.h` | Registerkarte (RCC/FLASH/GPIO/USART/SysTick/NVIC/SCB), BRR-Werte |
| `src/startup.c` | Vektortabelle, Reset-Handler, VTOR |
| `src/uart.c/.h` | 3× UART (IRQ-RX-Ringe, blockierendes Kurz-TX) |
| `src/main.c` | Clock-Setup, SysTick, Display-/BLE-/VESC-Protokolle + State Machines |

## Build & Flash

```
# Variante 1: Python (ohne make, Windows/Linux/macOS)
python build.py                        # -> build/ivcu_fw.elf/.bin/.hex
python build.py --ldscript ld/ivcu_app_boot.ld --target ivcu_fw_boot

# Variante 2: Make (Linux/macOS)
sudo apt install gcc-arm-none-eabi
make                                   # -> build/ivcu_fw.elf/.bin/.hex
make flash                             # OpenOCD + ST-Link (Ziel stm32f1x)
```

Toolchain: Arm GNU Toolchain (auf diesem Analyse-Rechner als **14.2.Rel1**
installiert und verifiziert). CI baut beide Linker-Varianten automatisch
(`.github/workflows/ivcu-build.yml`).

**Vorher zwingend:** SWD-Pads (SWDIO/SWCLK) anlöten, RDP-/Optionsbyte-Status
nicht-destruktiv prüfen, **Backup ziehen** (der Original-HEX-Stand liegt ohnehin
vor). Bei RDP1 würde ein Mass-Erase nötig – das ist unkritisch, weil wir das
Original-Image besitzen.

## Bring-up-/Testplan (Werkbank, Räder frei)

1. **Strom an, SWD verbinden** – mit `ld/ivcu_full.ld` bei 0x08000000 flashen.
2. **Takt prüfen:** HSE vorhanden? (Firmware fällt sonst automatisch auf HSI
   zurück – dann sind alle Baudraten ungenauer, aber funktionsfähig.)
3. **Display:** 0x35-Frames alle 100 ms + Keep-Alive – Display muss normal
   starten (keine „IVCU communication"-Fehler). Gang im Displaymenü wechseln →
   `vesc_send(0x02)` erscheint am VESC-UART.
4. **Speed-Kalibrierung:** In `include/ivcu_config.h` sind alle vier
   Rotations-Kandidatenfelder aktiv. Per Test (z. B. Simulation wie im
   Bridge-README, oder Schritt 5) das **richtige Feld** identifizieren und die
   übrigen `CFG_ROT_FIELD_*` auf 0 setzen.
5. **VESC:** Lisp laden (`MODE 0`), UART 115200. Prüfen: `54 01`-Telemetrie
   kommt an (Speed/SOC/Pack/Gang), Heartbeat; bei Timeout > 1 s zeigt das Skript
   Speed 0 an.
6. **App:** Teverun-App verbinden – `55 43/42/52/71/72/73`-Stream, Gangwechsel,
   Settings-Write (0x18), Umbenennen (0x1F → `AT+LENAME`). **IVCU-OTA in der App
   NICHT anstoßen** (diese Firmware hat keinen Bootloader).
7. **Endurance:** 1 h Standbetrieb (Display + BLE + VESC) auf Ringpuffer-/
   Timing-Fehler beobachten.

## Offene Punkte / Roadmap

* **LED-Ausgang** (adressierbare Kette, App-Cmd 0x08): Pins/Anzahl am Fahrzeug
  ermitteln, dann Bit-Bang-Treiber ergänzen (`0x08`-Felder werden bereits
  gespeichert).
* **EEPROM (I2C1, 0x50)**: Block0/Block1-Format ist bekannt
  (`../eeprom_images.py`) – Settings-Persistenz als Stufe 2; I2C-Pins zuerst in
  `../PINOUT.md` verifizieren.
* **CAN-BMS**: IDs/Layout nicht öffentlich – optional BMS-Werte statt
  VESC-Näherungen einspeisen.
* **TX per IRQ** statt blockierend (derzeit ~41 ms pro Display-Frame @9600 –
  unkritisch, aber ausbaufähig).
* **Status:** **Kompiliert** mit Arm GNU Toolchain 14.2 — beide Linker-Varianten
  (`ivcu_full.ld`, `ivcu_app_boot.ld`) bauen **ohne Warnungen** (3984 B Text,
  1692 B BSS); Vektortabellen verifiziert (SP 0x20004000, Reset @0x08000C34
  bzw. @0x08007C34). Zusätzlich: `build.py`, `platformio.ini`, CI-Workflow.
  **Bench-Validierung offen.**

## Sicherheit

Kein Originalcode; alles aus der statischen Analyse + Community-Doku
rekonstruiert. Flashen auf eigene Verantwortung. Vor dem ersten Fahren:
Bremsen/Gas-Totmann, Kickstart, Temperaturgrenzen und Timeouts wie in
`../VESC_IVCU_Ersatz_Anleitung.md` beschrieben prüfen. 3,3-V-Logik (nie 5 V an
die MCU-Pins).
