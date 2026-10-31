# Teverun-IO-Bridge – Hardware-Dokumentation (ESP32)

**Zweck:** Ersatz der IVCU-Peripherie (Display, BLE-App, LEDs) bei VESC-Umbau.
**Firmware:** `bridge_esp32/` (PlatformIO, Arduino-ESP32) · **VESC-Seite:** `vesc_ivcu_emulator.lisp`
**Datenbasis:** Firmware-Analyse AWIVCU_APP_R3_4_13 (Pins/Bauds/Frames) + Community-Doku (Steckerfamilien).
**Status:** Alle *elektrisch relevanten* Werte sind aus dem Code belegt; Stecker-Pinbelegungen am Fahrzeug zu verifizieren.

---

## 1. Systemübersicht

```
   ┌---------------------------┐        ┌----------------------------------┐
   │ Stock-Display (TFT)       │        │ originales BLE-Modul             │
   │  UART 9600, Frames        │        │  UART 115200, 0xAA/0x55,         │
   │  0x35(TX)/0x4C,8A,8B,8C   │        │  AT-Kommandos (Feasycom-Stil)    │
   └--------│──────────────────┘        └──────────────│───────────────────┘
            │ 3V3-UART                                 │ 3V3-UART
   ┌--------▼──────────────┐   UART1        ┌--------▼──────────────┐
   │        ESP32          │◄──────────────►│   (RX/TX/GND/VCC)     │
   │  UART1  Display 9600  │                └───────────────────────┘
   │  UART2  BLE    115200 │
   │  UART0  VESC   115200 │◄────────► VESC (COMM-UART, 3V3)
   │  GPIO27 WS2812 (opt.) │──────────► LED-Streifen (5 V Datenpegel!)
   │  GPIO2  Status-LED    │
   └--------│──────────────┘
            │ 5 V
   ┌--------▼──────────────┐
   │ Buck 12 V->5 V (>=1 A)│◄──── Fahrzeug-12-V-Rail (am Harness MESSEN!)
   └───────────────────────┘
```
* Der **VESC** regelt den Motor (Gas/Bremse über dessen ADC, Lisp-Skript).
* Die **Bridge** bedient alle Teverun-Protokolle und übersetzt VESC ↔ Teverun.

---

## 2. Stückliste (BOM, Vorschlag)

| # | Teil | Beispiel | Zweck |
|---|---|---|---|
| 1 | ESP32-DevKitC V4 (WROOM-32) | Espressif DevKitC | Bridge-MCU (3 UARTs) |
| 1a | *Alternative:* ESP32-S3-DevKitC-1 | native USB-CDC + 3 UARTs, **empfohlen** wenn Debug wichtig ist | |
| 2 | Buck 12 V→5 V, ≥1 A | MP1584EN / LM2596-Modul | Fahrzeug- auf Logikspannung |
| 3 | 5 V-Level-Shifter | 74HCT245 (oder SN74AHCT1G125) | WS2812-Datenpegel (nur wenn LEDs genutzt) |
| 4 | Stecker passend zum Fahrzeug | JST-SM / M8-Rundstecker (IVCU-Harness) | Aufnahme der Original-Leitungen |
| 5 | Serienwiderstände 100 Ω (4×) | 0603/THT | Schutz der UART-TX-Leitungen |
| 6 | Elko 470 µF/25 V + 100 nF | – | Versorgungsstabilisierung (LED-Strom!) |
| 7 | Schrumpfschlauch/Gehäuse, Kabel AWG26 | – | Mechanik |
| opt | Logic-Analyzer/USB-UART | CH340/CP2102 3V3 | Erstinbetriebnahme, Mitschnitt |

**Wichtig:** VESC-COMM-Stecker liefert auf einem Pin **5 V** – niemals mit ESP32-3V3/GPIO verbinden; nur GND/TX/RX nutzen.

---

## 3. ESP32-Pinbelegung

| GPIO | Richtung | Nutzung | Hinweise |
|---|---|---|---|
| GPIO1 (TX0) | out | → VESC RX | nach Flashen **USB abziehen** (USB-Bridge mit GPIO1/3 verbunden) |
| GPIO3 (RX0) | in | ← VESC TX | wie oben; 100 Ω Serie |
| GPIO25 | in | ← Display TX | frei verfügbar, 100 Ω Serie |
| GPIO26 | out | → Display RX | 100 Ω Serie |
| GPIO16 | in | ← BLE-Modul TX | **nicht** bei Modulen mit PSRAM (16/17 belegt) |
| GPIO17 | out | → BLE-Modul RX | 100 Ω Serie |
| GPIO27 | out | → WS2812 DIN | Level-Shifter auf 5 V! |
| GPIO2 | out | Status-LED | Onboard-LED, Strapping-Pin (nur LED, ok) |
| GND | – | gemeinsame Masse | zwingend für alle 4 Teilnehmer |
| VIN/5V | in | 5 V vom Buck | DevKit-Regler erzeugt 3V3 |
| 3V3 | out | BLE-Modul-VCC (max ~200 mA) | Display **nicht** über 3V3 speisen! |

**Nicht verwenden:** GPIO34–39 (nur Eingang), GPIO6–11 (Flash), GPIO0/12/15 (Strapping) für aktive Ausgänge.

**Variante ESP32-S3:** identische Logik, zusätzlich Debug-Log über native USB — bei S3 die Pins in `bridge_config.h` anpassen (UART-Matrix frei).

---

## 4. Spannungsversorgung & Pegel

| Rail | Quelle | Verbraucher | Hinweis |
|---|---|---|---|
| 12 V (?) Fahrzeug-Rail | Harness (am IVCU-Stecker **messen**) | Buck | Spannung/Polung vor Anschluss prüfen! |
| 5 V | Buck | ESP32-VIN, WS2812-Leiste, Display-Versorgung (nur durchreichen) | LED-Strom einplanen (x·60 mA) |
| 3,3 V | ESP32-Regler | BLE-Modul, UART-Pegel | BLE-Modul-Peakstrom beachten |
| Logikpegel | alle UARTs 3,3 V | – | **kein 5-V-TTL an Display/BLE-RX** |
| WS2812-Daten | 3,3 V → 5 V | LED-Streifen | Level-Shifter 74HCT245 (VCC=5 V) |

Masse aller Komponenten (VESC, Bridge, Display, BLE-Modul, LED) **gemeinsam** führen (sternförmig, LED-Strom getrennt zurückführen).

---

## 5. Anschluss/Verdrahtung im Detail

### 5.1 Display (Stock-TFT)
| Signal | Bridge | Display | Anmerkung |
|---|---|---|---|
| TX (Bridge→Display) | GPIO26 | Display-RX | 9600 8N1 |
| RX (Display→Bridge) | GPIO25 | Display-TX | |
| GND | GND | GND | |
| VCC | 5 V (durchgereicht) | Display-VCC | **am Fahrzeug messen** (5 V oder 12 V!) |

### 5.2 BLE-Modul (Original weiterverwenden)
| Signal | Bridge | Modul |
|---|---|---|
| Modul-TX → Bridge | GPIO16 | TX | 115200 |
| Bridge-TX → Modul | GPIO17 | RX | AT-Kommandos + App-Frames |
| VCC | 3V3 | VCC (3,3 V) | |
| GND | GND | GND | |

### 5.3 VESC
| Signal | Bridge | VESC-COMM (Modell prüfen!) |
|---|---|---|
| Bridge-TX → VESC-RX | GPIO1 | RX |
| Bridge-RX ← VESC-TX | GPIO3 | TX |
| GND | GND | GND |
| – | – | 5V-Pin **frei lassen** |

### 5.4 LED (optional)
* Original-IVCU nutzte einen **adressierbaren LED-Treiber** (Bit-Bang-Treiber in der Firmware). Datenleitung im Harness identifizieren, LED-Typ/Anzahl ermitteln; Daten über 74HCT245 auf 5 V anheben; `WS2812_COUNT` setzen.

---

## 6. Einbau

1. Bridge nahe IVCU-Position (Original-Steckplatz), Zugentlastung, Gehäuse.
2. Massefuehrung getrennt für LED-Strom.
3. Kabelquerschnitte: Logik AWG26; 5 V LED AWG22.
4. Absicherung der 12-V-Zufuhr (z. B. 1 A Polyfuse).
5. Erstinbetriebnahme **ohne** Motor: nur Display + BLE testen.

---

## 7. Inbetriebnahme- & Verifikations-Checkliste (am Fahrzeug)

| # | Messung/Test | Werkzeug | Erwartung |
|---|---|---|---|
| 1 | Versorgungsspannung am IVCU-Stecker | Multimeter | Wert notieren (5/12 V?) → Buck-Auslegung |
| 2 | Display-Pinbelegung bestätigen | Multimeter/Durchgang + UART-Sniffer | TX/RX/VCC/GND wie 5.1 |
| 3 | BLE-Modul-Pinbelegung | wie oben | wie 5.2 |
| 4 | Baudraten bestätigen | Logic-Analyzer | Display 9600, Modul 115200 |
| 5 | **Rotationszeit-Feld** im 0x35-Frame | Display-Beobachtung bei vorgegebener Fahrt (simuliert) | eines der Felder [17..18]/[20..21]/[22..23]/[24..25] steuert km/h → in `bridge_config.h` fixieren |
| 6 | LED-Datenleitung + Typ | Scope/Analyzer | Bitmuster 24 Bit/LED, 5 V |
| 7 | App-Kompatibilität | Teverun-App | 55 43 zeigt 3.4.13; 55 52/71/72/73 plausibel |
| 8 | Gangwechsel über Display | – | Bridge → VESC-Cmd 0x02, VESC-Limits ändern sich |
| 9 | Heartbeat-Ausfall | VESC trennen | Speed=0 auf Display, Status-LED schnell |
| 10 | Dauerlauf/Temperatur | – | keine Resets, Spannung stabil |

---

## 8. Bekannte Unsicherheiten

* **Display-Versorgung/Pinout** nicht aus Firmware ableitbar — am Fahrzeug messen.
* **LED-Streifen:** Anzahl/Farbordnung/Zonen (IVCU hatte 6 Farb-Records für Zustände) verifizieren.
* **12-V-Rail:** Wert aus Harness übernehmen; Buck entsprechend wählen.
* **BLE-Modul:** AT-Modus/Timing beim Umbenennen kann „+++"-Sequenzen benötigen (Original sendet nur die Zeile) — beobachten.
* **VESC-COMM-Pinout** variiert je Hersteller (Flipsky/MakerX/Trampa) — Schaltplan des eigenen VESC prüfen.

---

## 9. Dateien

| Datei | Inhalt |
|---|---|
| `bridge_esp32/platformio.ini`, `src/main.cpp`, `include/bridge_config.h` | Firmware |
| `bridge_esp32/README.md` | Build/Test-Kurzanleitung |
| `vesc_ivcu_emulator.lisp` | VESC-Seite (Regelung, Bridge-Protokoll) |
| `VESC_IVCU_Ersatz_Anleitung.md` | Gesamtablauf + VESC-Konfiguration |
| `AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md` | Protokoll-/Tabellenreferenz |

*Stand 31.10.2026 · statische Analyse; Aufbau/Test auf eigene Verantwortung.*
