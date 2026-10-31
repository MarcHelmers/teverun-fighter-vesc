# VESC-Ersatz der Teverun-IVCU – Anleitung (R3.4.13-Analyse)

**Ziel:** Die Funktionen der IVCU (Box C, Fighter Mini/Pro/ECO) auf VESC umziehen – Stock-Display, App-Telemetrie (optional), Motorregelung mit Original-Kennwerten.
**Grundlage:** `AWIVCU_APP_R3_4_13_Doku_FINAL.md`, `…_Kennlinien_und_Datenbereiche.md`, `decompiled.c`, `soc_kennlinie.c`, Codec `ivcu_protocol.py`.
**Wichtig:** Alles aus statischer Analyse abgeleitet – **vor dem Fahren auf der Werkbank validieren**. Kein Originalcode.

---

## 1. Architektur – zwei Varianten

### Variante A – „VESC + IO-Bridge" (EMPFOHLEN, größte Originaltreue)
```
    Stock-Display ──UART 9600──┐
    LED-Streifen ───PWM───────►│  Teverun-IO-Bridge           ┌─ ADC1 Gas
    BLE-Modul ◄───UART 115200──┤  (ESP32/STM32, 3×UART,      ──┤  ADC2 Bremse
                               │   PWM, 3,3 V)                 │
                     UART 115200 (Teverun-Bridge-Protokoll)    │
                               │                               │
     VESC ◄────────────────────┴──────────────────────────────►┘
            (Motor, ADC, UART; Lisp-Skript vesc_ivcu_emulator.lisp)
```
* VESC macht **nur Motor + Sensorik**; die Bridge emuliert alle Teverun-Peripherie (Display `0x35`/`0x4C`, App `0xAA/55xx`, LEDs).
* Bridge-Protokoll (im Lisp definiert): 8-Byte `54 <cmd> p0..p4 XOR`; Cmd 0x01 Telemetrie VESC→Bridge (Speed, SOC, Spannung, Gang, Eco), 0x02 Gang Bridge→VESC, 0x03 Modus, 0x04 Heartbeat.
* Vorteil: **komplettes** Originalverhalten inkl. App & Licht; VESC-Tool bleibt über zweiten Kanal (Bridge-USB oder WLAN am VESC) erreichbar.

### Variante B – „VESC-only / Standalone"
* VESC-COMM-UART direkt = **Display (9600)**; `vesc_ivcu_emulator.lisp` (MODE 1) sendet `0x35`-Frames + Keep-Alive und liest `0x4C` (Gang/Eco).
* Kein App-BLE, keine LEDs (Hardware-Ausgänge fehlen) – nur Fahren + Display. Geeignet für Minimal-Umbau/Tests.

---

## 2. Hardware

### 2.1 VESC
* Beliebiger VESC-basierter Controller mit **FW ≥ 6.05**, ADC1+ADC2 am COMM-Port, UART, CAN (nur für Dual-Motor/Tetra): z. B. Flipsky 75100/75200, MakerX, Trampa, Spintend (je nach Motorleistung; Original: 60 V/16S-Klasse).
* **Dual-Motor (Pro/Tetra):** 2× VESC + CAN; Traction Control (TCS) als VESC-TC konfigurieren (die „Smart"-Funktion der IVCU wird so angenähert).
* Motorphasen/Hall vom Stock-ESC übernehmen (Sensor-Typ prüfen: Hall üblich).

### 2.2 Zusätzliche UARTs
| Variante | Zusätzliche Hardware | UARTs |
|---|---|---|
| A | **ESP32-DevKitC** (3× UART, LEDC-PWM, BLE-Onboard) | UART0↔VESC, UART1↔Display, UART2↔BLE-Modul |
| A (Alternative) | **VESC Express** + 1× USB-UART für Display | Express-UART1↔Display, UART2↔BLE; Express-BLE für App (Custom-BLE-Service mit ISSC-UUIDs nötig) |
| B | keine | VESC-COMM = Display |

**Level:** alles 3,3 V; **niemals 5 V TTL direkt** an Display/BLE-Modul (RX), TX-seitig prüfen. Gemeinsame Masse zwingend. Display-Versorgung (5 V/12 V) aus dem Fahrzeugharness – **am Fahrzeug messen** (nicht im Code erkennbar).

### 2.3 Signale/Stecker (aus Firmware abgeleitet)
| Link | IVCU-Pins (verifiziert) | Baud | Richtung | Ersatz durch |
|---|---|---|---|---|
| Display | PB10/PB11 (USART3, DMA7; Registerbefund, am Fahrzeug gegenprüfen) | 9600 | bidirektional | Bridge UART1 bzw. VESC-COMM |
| BLE-Modul | PA9/PA10 (USART1, DMA5) | 115200 | bidirektional | Bridge UART2 (Originalmodul weiterverwenden!) |
| Stock-ESC | PA2/PA3 (USART2) | 9600 | bidirektional | entfällt (VESC ersetzt ESC) |
| BMS | CAN1 (Pins am Fahrzeug prüfen: PA11/12 o. PB8/9) | ? | bidirektional | VESC-CAN (BMS-Protokoll unbekannt → zunächst nicht anbinden) |
| EEPROM | I2C1 (Pins prüfen) | – | – | entfällt (Settings jetzt in VESC) |
| LEDs | (nicht im Code zuordenbar) | PWM? | – | Bridge-PWM (Pins/Farben am Fahrzeug ermitteln) |

---

## 3. VESC-Tool-Konfiguration (Variante A/B)

1. **Motor:** FOC-Detection, Halls; **Motor Poles = Polpaare** (Werk 30 Rohwert→ 15 Paare prüfen!), **Wheel Diameter** = `WHEEL_MM`.
2. **Strom/Limits:** Motor Current = max(GEAR_CURRENT_A) + Reserve; Battery Current = gemäß Zellen (60 V/16S: 30–40 A je nach BMS); **Battery Voltage: Cells=16, Start=3.4 V/Zelle, End=3.0 V/Zelle, Max=4.25 V/Zelle** (48 V→13S, 52 V→14S, 72 V→20S).
3. **Temperatur:** FET 80–85 °C, Motor 120 °C (Teverun-Wert).
4. **App:** „None" (Lisp regelt); ADC-Kanäle bleiben frei nutzbar über `get-adc`. Timeout optional verlängern – das Skript ruft zyklisch `set-current`/`timeout-reset`.
5. **Regen:** VESC-Regen aktiv lassen (dient als Rückfallebene), Lisp regelt EABS separat per `set-brake`.
6. **Lisp:** `vesc_ivcu_emulator.lisp` in VESC Tool → Lisp-Editor laden, startet nach Boot automatisch. Logs über VESC Tool beobachten.
7. **Dual:** zweiter VESC via CAN (gleiche ID-Kette), TC aktivieren.

---

## 4. Parameter-Mapping Teverun → VESC

| Teverun (Quelle) | Wert/Fabrik | VESC-Entsprechung | Hinweis/Formel |
|---|---|---|---|
| Polpaare (Block1 [2], 0x1E) | 30 | Motor **Pole Pairs** | 30 Rohwert = vermutlich 30 **Pole** → **15 Paare**; per Display-Geschwindigkeitsabgleich kalibrieren |
| Raddurchmesser (Block1 [3] = 0x6E = 11.0″) | je Modell | Wheel Diameter (mm) | 10″=254, 11″=279.4; Umfang = π·D |
| Gang-Speed-Limits (Fabrik 20/40/60/80/100) | Byte ≈ km/h | `GEAR_LIMIT_KMH` im Skript | ERPM-Grenze: `ERPM = km/h · 16666.7 · Polpaare / Umfang_mm` |
| Gang-Ströme (15/20/25/30/55) | A | `GEAR_CURRENT_A` | = Phasenstrom je Gang |
| EABS-Level 1..5 | – | `GEAR_EABS_A` | Bremsstrom für `set-brake` |
| Start-Level 1..5 | – | `GEAR_RAMP_MS` | Slew-Limiter im Skript |
| Power-Limit % (Block1 [5]) | 100 | `POWER_LIMIT` | skaliert Gang-Strom |
| Übertemp.-Schwelle (0x78=120) | 120 °C | Motor-Temp-Limit (VESC **und** Skript) | |
| Spannungscode (Block1 [6]/App a[14]) | 0x30 | – (nur Code fürs App-Menü) | **Code ≠ Volt:** 36 V→0x1E, 48 V→0x27, 52 V→0x2A, **60 V→0x30**, 72 V→0x3C, 84 V→0x45 |
| Pack-Nennspannung (Block1 [7]) | 0x3C = 60 V | Cells 13/14/16/20 | 0x30=48 V→13S, 0x34=52 V→14S, 0x3C=60 V→16S, 0x48=72 V→20S (`FUN_0801BE92`) |
| Pack-Spannung (0x3C=60 V) | nominal | Battery-Cutoffs | 3.0/3.4/4.25 V je Zelle |
| SOC-Kennlinie @0x0801DC78 | 3,00–4,15 V/Zelle | **Skript `soc-from-mv`** (21 Stützstellen) | VESC-eigene % ist linear → für App/Display das Skript nutzen |
| Clamp/Scale-Bit (Display-Frame Byte4/Bit1) | R3: offen | – (VESC kennt keinen eKFV-Clamp) | bei R5-ähnlichem Verhalten `CLAMP_SCALE_BIT=2` + Limits setzen |
| Cruise/ABS/TCS | Flags | TCS→VESC-TC; Cruise→nicht nativ (Lisp-Option: RPM halten) | ABS nicht im Roller |
| LED-Farben (6×28-B-Records) | Rot<20 %, Gelb<50 %, Grün<100 % | Bridge-PWM | Farben: siehe Kennlinien-Doku A4 |
| Keep-Alive 10 B / 100 ms | – | im Skript (`keepalive-send`) | beide Busse bedienen |

> **Geschwindigkeitskette (community-verifiziert, §16.2 Doku):** `speed_kmh = 287 · wheel / speedRaw`,
> `wheel = 55 71 t[6] × 0,1″`, `speedRaw` = Rotationszeit in 0,1 ms (`55 72` t[15..16], `≥ 3000` ⇒ Anzeige 0).
> Die Bridge/Lisp erzeugt `speedRaw = wheel-Code · 287 / km/h` (`ROT_MAX` bei Stillstand).
> Damit wird das Kalibrierfeld im `0x35`-Frame im Testplan Punkt 3 fixiert.

---

## 5. Testplan

**Werkbank (Räder frei, Motor aus):**
1. Display anschließen (Bridge/VESC), Boot: Display muss normal starten (kein „IVCU connection error").
2. `display-send-35`-Strom prüfen: Geschwindigkeit 0; **Gang im Displaymenü umschalten** → Skript-Log muss Gangwechsel via `0x4C/Cmd1` zeigen.
3. **Speed-Kalibrierung:** Feld `[17..18]`/`[20..21]`/`[22..23]`/`[24..25]` experimentell mit `Wert = Wheel·287 / Wunsch-km/h` beschicken, beobachten, welches Feld die Anzeige treibt → endgültige Formel in `display-send-35` festlegen (R5-Doku nennt zwei Rotationszeit-Sites; in R3 entsprechen ihnen diese Felder).
4. SOC/Spannung/Temp plausibel anzeigen lassen (Werte über VESC Tool vorgeben/ändern).
5. App-Test (nur Variante A): Teverun-App verbinden, `55 43` (Version), `55 52` (SOC), `55 71` (Gänge/Limits) prüfen; Umbenennen (Cmd 0x1F) testen.
6. Motor-Test an der Bank: Gas/Bremse, Slew-Rampe, Temperatur-Abschaltung.

**Fahrt (schrittweise, gesetzlich zulässige Konfiguration!):**
7. Erst Eco + Gang 1; ERPM-Limit und EABS beobachten; dann höhere Gänge.
8. Abgleich Display-/GPS-Geschwindigkeit → `POLE_PAIRS`/`WHEEL_MM` final justieren.

---

## 6. Grenzen & offene Punkte (ehrlich)

* **Rotationszeit-Feld** im `0x35`-Frame: Kandidaten bekannt, exakte Zuordnung nur per Mitschnitt/Kalibrierung.
* **`0x8A/0x8B/0x8C`-Frames** des Displays: Rahmen/Ziel bekannt, Inhalt unklar → Bridge konsumiert sie zunächst folgenlos.
* **LED-Ansteuerung:** Pins/Cluster aus dem Code nicht bestimmbar; am Fahrzeug messen (Bridge-PWM nachrüsten).
* **BMS/CAN:** Protokoll (IDs/Inhalt) unbekannt → BMS vorerst autark lassen (Laden/Wake wie original); SOC kommt aus der Spannungs-Kennlinie.
* **App-Kompatibilität:** 55xx-Frames sind dokumentiert, aber nicht jede App-Funktion (z. B. Firmware-Update über App) ist über die Bridge sinnvoll/nachbaubar.
* **NFC/PKE/GPS** (C+/C1-Geräte): eigene Hardware – mit VESC nicht abgebildet.
* **EKFV-Regeln:** Umbau = Änderung der genehmigten Konfiguration; nur auf Privatgelände/legal nutzen.

---

## 7. Dateien im Paket

| Datei | Inhalt |
|---|---|
| `vesc_ivcu_emulator.lisp` | VESC-Skript (Modus A/B, Regelung, SOC, Display-/Bridge-Frames, Bridge-Protokoll v2) |
| `bridge_esp32/` | **ESP32-Firmware der IO-Bridge** (PlatformIO: `platformio.ini`, `src/main.cpp`, `include/bridge_config.h`, `README.md`) |
| `Teverun_IO_Bridge_Hardware.md` | **Bridge-Hardware**: BOM, Pinbelegung, Versorgung/Pegel, Verdrahtung, Prüfcheckliste |
| `ivcu_protocol.py`, `ivcu_sim.py` | Referenz-Codec + Simulator (Bridge-Entwicklung, Sniffer-Auswertung, Bench) |
| `ivcu_fw_tool.py` | Firmware-HEX validieren/patchen (Selbsttest: 3/3 PASS, Version/CRC verifiziert) |
| `soc_kennlinie.c`, `soc_kennlinie.png` | SOC-Kennlinie + Näherungen |
| `AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md` | Frame-/Tabellen-/Effekt-Referenz |

*Stand 31.10.2026 · statische Analyse; Umsetzung auf eigene Verantwortung.*
