# Teverun-IO-Bridge – ESP32-Firmware (`bridge_esp32`)

Ersetzt die Peripherie-Aufgaben der Teverun-IVCU gegenüber **Display**, **App/BLE**
und optional **LEDs**, während ein **VESC** die Motorregelung übernimmt
(`../vesc_ivcu_emulator.lisp`).

## Aufgaben der Bridge
| Link | Pins (Default) | Baud | Funktion |
|---|---|---|---|
| UART0 ↔ VESC | GPIO1 / GPIO3 | 115200 | 8-Byte-Protokoll `54 cmd p0..p4 XOR` (Telemetrie, Gang, Heartbeat) |
| UART1 ↔ Stock-Display | GPIO25 / GPIO26 | 9600 | `0x35`-Frames (39 B, XOR), `0x4C/8A/8B/8C`-Empfang, Keep-Alive |
| UART2 ↔ BLE-Modul | GPIO16 / GPIO17 | 115200 | `0xAA`-RX (App-Kommandos 0x08/0x18/0x1A werden umgesetzt), `0x55xx`-Telemetrie-TX, `AT+LENAME`-Weiterleitung |
| WS2812 (optional) | GPIO27 | – | LED-Farben (SOC-Farbschwellen, `WS2812_COUNT=0` = aus) |

## Bauen & Flashen
```
cd bridge_esp32
pio run            # bauen
pio run -t upload  # flashen
```
Danach **USB-Kabel abziehen** (UART0 ist dann der VESC-Link).

Build verifiziert (PlatformIO `espressif32` 8.0.0 / Arduino 3.3.12): **0 Warnungen**,
RAM 6,8 %, Flash 22,6 % (Stand 31.10.2026).

## Konfiguration
Alles in `include/bridge_config.h`: Pins, Baudraten, Rad-/Motor-Codes,
Gangtabelle, Rotationszeit-Felder, Timeouts, LED-Optionen.

## App-Kommandos (BLE `0xAA` → Bridge)
Die Kommandokarte der App wurde aus der IVCU-Firmware + Community-Doku
rekonstruiert (siehe `../AWIVCU_APP_R3_4_13_Doku_FINAL.md` §16.3).
Es gilt überall: **`0xFF` in einem Feld = „keine Änderung“**.

| Cmd | Bedeutung | Bridge-Reaktion |
|---|---|---|
| 0x01 | Handshake/Keep-Alive (~6,5 s) | setzt Verbindungsstatus (greet) |
| 0x02 | Deep Sleep | bewusst nur geloggt |
| 0x03 | Lademodus | bewusst nur geloggt |
| 0x08 | LED an/aus, Modus, RGB | LED-Override (WS2812); RGB aus `[4..6]` |
| 0x18 | Settings-Write | Gangprofile 1..5: Wheelcode, Polpaare, Temp, Start-/EABS-Level, Limits, Ströme, Spannungscode, Flags; bei Modus 0 wird der Gang an den VESC gemeldet (`54 02`) |
| 0x1A | Custom-Key-Funktion | Wert geht in `55 73` t[17] ein |
| 0x1C | RTC-Sync | ignoriert |
| 0x1F | FIN-Name | `AT+LENAME` ans BLE-Modul (sofern Modul-Firmware mitspielt) |

## Werkbank-Test (ohne Fahrzeug)
1. PC statt VESC an UART0 (USB-Seriell-Adapter): `python ../ivcu_sim.py --out sim.txt --speed 22`
   erzeugt/verteilt passende Frames (siehe `ivcu_protocol.py` als Referenz).
2. Display-Emulation prüfen: `0x35`-Frames alle 100 ms, Keep-Alive alle 100 ms.
3. Display-Kommandos testen: Gang im Displaymenü wechseln → Bridge loggt/übernimmt
   (Status-LED / optionaler Debug).
4. App-Test: Teverun-App verbinden; Bridge streamt `55 43/42/52/71/72/73`.
   Gang in der App ändern → Bridge sendet `54 02` an den VESC; App-LED-Funktion (`0x08`)
   testet den WS2812-Override (sofern `WS2812_COUNT > 0`).

## Grenzen / offene Punkte
* **Rotationszeit-Feld** im `0x35`-Frame: Kandidaten werden alle beschickt, bis
  das richtige Feld per Test identifiziert ist (`ROT_FIELD_*`).
* `0x8A/0x8B/0x8C`-Frames werden konsumiert (Inhalt unbekannt).
* Settings-Writes des Displays (Cmd 5) werden verworfen – Limits kommen jetzt vom VESC.
* App-Cmds 0x02/0x03/0x1C (Sleep/Laden/RTC) werden bewusst nur geloggt.
* Rotierendes Odometer: 16-bit km vom VESC (Bridge-Protokoll Cmd 0x05).
* LED: Anzahl/Farbkanäle am Fahrzeug verifizieren (`WS2812_COUNT`).

*Statische Analyse-Grundlage: AWIVCU_APP_R3_4_13; alles auf eigene Verantwortung.*
