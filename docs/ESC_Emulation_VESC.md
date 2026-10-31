# Weg 2 – Stock-IVCU behalten, VESC emuliert den Original-ESC (ESC_Emulation)

**Prinzip:** Die Original-IVCU bleibt **unverändert** (Display, Teverun-App,
EEPROM, LED, eKFV-Kompensation – alles Werksverhalten). Nur der Stock-ESC wird
durch den VESC ersetzt. Der VESC hängt dazu am **ESC-Port der IVCU**
(USART2, 9600 Bd, 3,3 V) und spielt per Lisp (`vesc_esc_emulator.lisp`) den
Original-ESC: `0x4A`-Frames der IVCU empfangen, `0x71`-Statusframes
zurücksenden.

```
 IVCU (unveraendert!)
  USART3 --> Stock-Display
  USART1 --> Stock-BLE (Teverun-App)
  USART2 <--9600--> VESC   ('4A'-Settings rein, '71'-Status raus)
                     └ ADC: Gas + Bremse DIREKT am VESC!
```

> **Wichtig – Gas/Bremse:** Die IVCU hat **keinen ADC** (Peripherie-Analyse:
> nur USART/CAN/I2C/TIM/GPIO). Gas- und Bremshebel hängen im Original also am
> ESC. Bei Weg 2 müssen sie **direkt an die ADC-Eingänge des VESC** (wie in der
> VESC_IVCU_Ersatz_Anleitung beschrieben: App „None", Lisp regelt).

---

## 1. Rahmen-Layouts (aus dem Dekompilat, R3.4.13)

### 1.1 IVCU → ESC: `0x4A` (vier Varianten, Round-Robin)

| Variante | Builder (R3) | Länge auf der Leitung |
|---|---|---|
| `4A 11 3A` | `FUN_08010238` | 17 B: `[0..15]` + Checksumme (aus Pufferbyte [19]) |
| `4A 11 3B` | `FUN_0800FE96` | 17 B (dito) |
| `4A 14 3A` | `FUN_080103AC` | 20 B: `[0..19]` inkl. XOR in [19] |
| `4A 14 3B` | `FUN_080100AA` | 20 B (dito) |

**Feldtabelle (Pufferindizes; Quelle der 3A/3B-Unterschiede sind zwei
Gang-Arraysätze – vermutlich Rear/Front):**

| Idx | `4A 11 3A` (Rear?) | `4A 14 3B` (Front?) | Bedeutung (abgeleitet) |
|---|---|---|---|
| 0..2 | `4A 11 3A` | `4A 14 3B` | Header/Variante |
| 3 | 0 | 0 | – |
| 4 | `DAT_200002a1` (Gang 0–4; 0 bei Gangschalter aus) | dito | **Gang-Index (0-basiert)** |
| 5 | Flags: Bit0 Kickstart-Latch (0x2000030A), Bit7 Freigabe (0x2A3/0x2E7), **Bit5 = Clamp/Scale-Latch 0x2000030D** | dito (Bit1-Latch 0x2000030A) | Steuerflags |
| 6 | `0x200002A4` | dito | Polpaare (Werk-Rohwert 30) |
| 7 | `0x200002A5` | dito | **Rad-Code (Zoll×10)** |
| 8 | `0x200002A6` | dito | (offen) |
| 9 | Start-Level `0x2A7[Gang]` | `0x2AD[Gang]` | **Anfahr-/Startstufe** |
| 10 | Gang-Limit `0x2B3[Gang]` | dito | **Speed-Limit (km/h)** |
| 11 | `0x2B9` bzw. `0x2CA` (Limit-Modus 0x20000313=2) | dito | Zweit-Limit (Power-Limit %) |
| 12 | Strom `0x2BA[Gang]` | `0x2C0[Gang]` | **Phasenstrom (A)** |
| 13 | `0x200002C6` | dito | Spannungscode (48 = 60-V-Pack) |
| 14 | `0x200002C7` | dito | Pack-Nennspannung (V) |
| 15 | `0x200002CD`→Bit7, `0x20000314`→Bit5 | dito | Flags2 (Licht/Kickstart?) |
| 16..18 | – (Altwerte) | `0x2CE/0x2CF/0x2D0` | nur `0x14`-Variante: 3 Extrabytes |
| 19 | XOR über [0..18] | XOR über [0..18] | **Achtung `0x11`-Eigenheit:** XOR rechnet über alle 19 Pufferbytes, gesendet werden aber nur 16+ck – Bytes 16..18 können Altwerte sein ⇒ Empfänger tolerant prüfen! |

### 1.2 ESC → IVCU: `0x71` (13 Byte)

ISR `FUN_0800B5CA` (IRQ38) sammelt 13 Byte; Consumer `FUN_0800FA94` prüft
XOR über `[0..11]` gegen `[12]` und verarbeitet die Subtypen **`:` (0x3A)** und
**`;` (0x3B)**:

| Byte | Inhalt |
|---|---|
| 0 | `0x71` (Header) |
| 1 | (unbekannt – per Sniffer klären) |
| 2 | **Subtyp `0x3A` / `0x3B`** |
| 3..11 | 9 Datenbytes (Schattenkopie 0x200013A6..) |
| 12 | XOR über [0..11] |

**Alive-Logik:** je Subtyp Zähler `0x2000040E` / `0x20000410`; ohne gültigen
Frame eines Subtyps > **600 Ticks** ⇒ Alive-Flag `0x20000311` / `0x20000310`
= Fehler (Display/App zeigen ESC-Fehler). ⇒ Der Emulator muss **beide**
Subtypen deutlich schneller als 600 ms senden (Vorschlag: abwechselnd alle
100 ms).

**Weiterverwendung der Daten:** Display-Frame `0x35` bezieht `[3]=Status`,
`[5..6]=u16`, `[7]`, `[8..9]=u16`, `[10]=Rotationsrohwert` aus RAM
`0x200002DB..0x200002E4` — **exakte Zuordnung jetzt belegt** (`FUN_0800F4FA`,
siehe 1.3).

### 1.3 Kanäle, Variantenwahl und exakte Datenzuordnung (neu: FUN_0800F4FA / FUN_080105A8)

* **Zwei Kanäle auf einem Bus:** `3A` und `3B` haben je eigene Alive-Überwachung
  (600 ms) und eigene Datenkopien — `3A` → `0x200002DB..0x2E5`,
  `3B` → `0x200002E6..0x2EF`. Bei **Dual-Modellen** (z. B. Fighter Mini Pro,
  2 Motoren) bedient das je einen Motor-/Controller-Kanal (Heck/Front — in der
  Praxis ein Controller je Motor); Single-Modelle nutzen den Hecksatz.
* **Variantenwahl (`FUN_080105A8`):** Das Flag `0x20000398` wählt den Frame-Satz:
  `1` → `0x14`-Frames (20 B), `0` → `0x11` (17 B), `0xFF` (Boot/unbekannt) →
  **alternierend beide**, bis die erste gültige `3A`-Antwort das Flag setzt.
* **Wer setzt das Flag?** `FUN_0800F4FA` bei Empfang des `3A`-Frames:
  **Bit0 von ESC-Byte `[11]`** → `0` = Single, `1` = Dual.
* **Datenkopie (Byte für Byte):** ESC`[3]`→`0x2DB`, `[4]`→`0x2DC`,
  `[5..6]`→u16 BE `0x2DE`, `[7]`→`0x2E0`, `[8..9]`→u16 BE `0x2E2`,
  `[10]`→`0x2E4` („Rot-Rohwert“, 1 Byte), `[11]`→`0x2E5` (Bit0 Dual-Flag).
  Das **Display liest genau diese Bytes** (Kennlinien-Doku Teil C); die Einheiten
  von `[4..9]` und die Skalierung von `[10]` sind noch zu verifizieren.

## 2. Mapping-Konzept (im Lisp umgesetzt/geplant)

| IVCU-Frame | VESC-Wirkung |
|---|---|
| Gang `[4]` (+1) | aktiver Gang, Limits folgen |
| Speed-Limit `[10]` | ERPM-Clamp (`ERPM = km/h·16666.7·Polpaare/Umfang_mm`) |
| Strom `[12]` | maximaler Phasenstrom (`set-current`-Obergrenze) |
| Start `[9]` | Slew-Limiter-Zeit (Anfahrverhalten) |
| Flags `[5]`: Bit5 Clamp | eKFV-Scale → ECO-artige Leistungsreduktion (optional) |
| – | ADC am VESC: Gas→`set-current`, Bremse→`set-brake` (wie Skript) |
| `0x71` 3A/3B | Status anzeigen: Status OK, Spannung×10, Temp, Strom, **speedRaw** aus `287·Wheel/kmh` |

## 3. Offene Punkte (vor dem Fahren klären!)

1. **Byte [1] des 0x71-Frames** – Sniffer.
2. **Einheiten/Zuordnung der ESC-Felder:** `[3..11]`→RAM ist belegt
   (`FUN_0800F4FA`); offen sind **Bedeutung/Einheiten** von `[4]`, `[5..6]`,
   `[7]`, `[8..9]` sowie die **Skalierung** von `[10]` (Rot-Rohwert) — Sniffer +
   Vergleich Original-ESC vs. Emulator.
3. Unterschied `0x11` vs. `0x14`-Variante in der Wirkung (nur Settings vs.
   erweiterte Info) – unkritisch für v1 (beide werden geparst).
4. Verhalten bei fehlenden IVCU-Frames (VESC-Sicherheitsmodus definieren:
   Skript fällt auf sichere Default-Limits zurück).

## 4. Werkbank-Testplan (ohne Fahren)

1. **Sniffer** (3,3-V-UART-Logger) zwischen Original-ESC und IVCU: 10 min
   mitloggen (Boot, Gas/Bremse am ESC, Gangwechseln im Display) → Referenz:
   Frame-Takt, `0x71`-Inhalte, Byte[1].
2. Original-ESC abklemmen, VESC + `vesc_esc_emulator.lisp` anstecken.
   Display/App beobachten: keine ESC-Fehler (Alive), Gang/Limit sichtbar.
3. Parametertest: IVCU-Gang im Display ändern → VESC-Limit im Tool/Lisp-Log.
4. Erst danach Antrieb am Prüfstand.

## 5. Hardware (Weg 2): Spintend UBOX ALU Lite 100V 100A ×2 (Dual)

**Produkt/Firmware:** UBOX = *Spintend*, VESC-basiert (FW-Name z. B.
`UBOX_SINGLE_100` je Variante). Auslieferung mit FW 6.02; Spintend pflegt
FW-Sammlungen — **≥ 6.05 nötig für LispBM** (Community betreibt Lisp nachweislich
auf dem Ubox Single Lite 100V, FW 7.00). **Nie blind updaten** – FW-Dateiname muss
zum exakten Modell passen, sonst droht Hardware-Schaden.

**Dual-Aufbau (Werkstatthandbuch):** Zwei ESCs („Main" + „Second"). Verdrahtet
wird praktisch alles am **Main ESC**; der Zweite bekommt **nur Motor-Phasen + Hall**
(sowie gemeinsame Stromversorgung/Masse und die Verbindungsleitung zum Main).
VESC Tool verbindet am Main (USB-C); „Multi Settings" spiegelt die Konfiguration.
**Zweiter ESC: App = „None"** – er wird per CAN gesteuert.

| Anschluss (Main ESC) | Belegung | Bei uns (Weg 2) |
|---|---|---|
| ADC-Port | **Throttle: 3,3 V / GND / ADC1** — **Brake: GND / ADC2** | Teverun-Gas → ADC1, Teverun-Bremse → ADC2 |
| Hall-Kabel (je Motor) | Rot **5 V**, Schwarz GND, Weiß Temp, H1/H2/H3 | Stock-Motorkabel |
| Phase U/V/W (je Motor) | 4-mm-Bullet | Reihenfolge egal — FOC-Detection paart |
| Akku (XT90) | Pack direkt | 60-V-Pack (16S; uBox bis 22S, Spitzen < 93 V) |
| COMM (UART) | 3,3-V-Pegel | **→ IVCU USART2 (PA2/PA3), TX/RX gekreuzt + GND; 9600 via Lisp** |
| NRF | BLE-/Display-Dongle | optional; USB-C bleibt für VESC Tool |
| CAN | Main ↔ Second | Verbindungsleitung des Dual-Kits; Controller-IDs eindeutig setzen |
| PWR.BTN **oder** Ignite | Ein-/Aus | **niemals beide nutzen** — Ignite brücken bzw. auf Zündschalter |
| 12 V | nur Nicht-Lite-Modelle | **Lite hat KEINE 12-V-Ports** → separater Step-Down (28–90 V → 12 V) für Licht/Hupe, schaltet mit Ignite |

**Gas/Bremse – kritische Stelle:**
* VESC-ADC-Eingänge sind **strikt ≤ 3,3 V** (VESC-Projekt/esk8-Forum).
* Spintend schreibt: „5 V-Signale können an den 3,3-V-Ports angeschlossen werden" —
  sicherer sind dennoch **(a)** der *E-wheel ADC Adapter V3* (5-V-Umschalter,
  Bremshebel-Schalter → Bremslicht, Licht/Hupe ≤ 3 A) oder **(b)** Spannungsteiler
  (z. B. 10 k/20 k) je Signalleitung. **Vorher mit dem Multimeter messen!**
* Teverun-Gas/Bremse = Hall-Geber: bevorzugt über die 3,3-V-Pins des ADC-Ports
  versorgen (wenn die Geber damit arbeiten), sonst 5 V + Teiler.

**Lisp-Anpassung für Dual (im Skript enthalten):** `DUAL 1` → die `3A`-Antwort
meldet Dual-Fähigkeit (IVCU nutzt die `0x14`-Frames); der zweite ESC wird per CAN
gespiegelt (`can-cur`; VESC-Pakete 1/2, `CAN_SLAVE_ID` = dessen Controller-ID).
Bei Dual-Hardware mit EINEM MCU alternativ `(select-motor 1/2)`.

**Inbetriebnahme-Reihenfolge:** FOC-Detection je Kanal → App „None" + Skript laden
→ UART-Baud 9600 prüfen → ADC-Mapping erst OHNE Motor (Bar-Anzeige) → dann IVCU
anstecken (0x71-Alive im Blick).

*Quellen: Spintend UBOX User Manual (manuals.plus), VESC-Project-Forum,
LispBM-Referenz (lispbm.com).*

---

*Grundlage: statische Analyse AWIVCU_APP R3.4.13 (FUN_0800B5CA, FUN_0800FA94,
FUN_08010238, FUN_080100AA) + Community-Doku. Stand 31.10.2026 –_
_Bench-Validierung offen.*
