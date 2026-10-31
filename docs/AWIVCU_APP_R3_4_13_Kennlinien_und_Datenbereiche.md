# IVCU R3.4.13 - Kennlinien, Datenbereiche, Zuordnung & Naeherungen

**Ergaenzung zur Abschlussdokumentation** - Quelle: `AWIVCU_APP_R3_4_13.hex` (SHA-256 `613ee416...`)

## Teil A - Datenbereiche -> Funktionen -> Bedeutung -> Auswirkung

| Bereich | Nutzende Funktion(en) | Bedeutung | Auswirkung im Code |
|---|---|---|---|
| Vektortabelle 0x08007000 | `FUN_08007286` (setzt VTOR), `FUN_08007CDC` | 64 Vektoren | IRQ-Bedienung nach Bootloader-Uebergabe; nur TIM2 + USART1/2/3 belegt |
| HPRE-Shift 0x0801D8B4 | `FUN_08007324` | log2(AHB-Teiler) | `HCLK = SYSCLK >> shift[HPRE]` -> Zeitbasis 0x20000000 (Delays/Timeouts) |
| Frequenz-Staffel 0x0801D8CC | `FUN_08007324` | 100k..4M Hz | Fallback-CoreClock (andere Taktquelle) |
| Staffel-Tabellen 0x0801D8F8/910/924 | Funktion 0x0800824A-0x080082EC (unbenannt) + Clock-Helfer 0x0800809C/81CA/8218/8232 | Prescaler-/Zeitstaffeln | Baud-/Delay-Berechnung (USART 115200/9600) |
| SOC-Kennlinie 0x0801DC78 (101 x u16) | `FUN_0801C1B8`, `FUN_0801C1F8` (Binaersuche `FUN_0801C162`), Rufer `FUN_0801C5E4` | Zellspannung mV -> SOC % | SOC (`DAT_20000364`): BLE 55 52, Displaybyte, **LED-Farbe rot <20 %, gelb <50 %, gruen <100 %**, stufenweise Leistungsfreigabe (SOC>>3, max 14), Bitfeld-Telemetrie |
| LED-Farb-Records 0x0801D940 (6 x 28 B) | `FUN_08015DB6`, `FUN_080133C4`, `FUN_0801503A`, `FUN_080154B2`, `FUN_080163BE` | je 7 RGB-Farben | memcpy + `FUN_080117BC/116FC` -> LED-PWM je Zustand (`DAT_20000067`) |
| PWM-Muster 0x0801DA70-0x0801DC78 | LED-Treiber 0x08013xxx/0x08016xxx (indirekt) | 4-Byte-Muster | LED-Phasen/Gamma (Vermutung) |
| Fabriktabelle 0x0801DA40+0x0801DA49 | `FUN_08017230` (inline) + Funktion ~0x0801737F-0x08017414 | Werks-Settings + 5 Gaenge | Defaults bei Block-1-Checksummenfehler |
| Block-0-Defaults 0x0801D9E8-0x0801DA40 | **`FUN_08017784`** (Loader), `FUN_0801744C` (Defaults) | VCU-Magie, HW 1.1, FW 03/04/0D, Frame-Nr., `AWPE-VCU-220212`, `01DB99` | Block0 = 80 B, XOR ueber 0x4E, Halbwort @0x4E; **Versionsmigration auf FW-Stand**, sonst Defaults |
| Init-Tabelle 0x0801DD44 (2 Eintraege) | `FUN_0801D81C` (Reset) | {src,dst,len,fn} | (1) dekomprimierte Kopie 0x70C B -> RAM 0x20000000 (Initialdaten, Flash enthaelt `AWVCUB123480`); (2) Zero-Fill 0x3484 B -> RAM 0x2000070C..Stackfuss |
| C-Runtime-Bank 0x0801D2EC-0x0801D8C4 | s. A2 | IAR-Laufzeit | memcpy/memset/strlen/64-Bit-Division/Dekomprimierer |
| Float-Block 0x0801D035 | (nur ADR/indirekt; nicht abschliessend zugeordnet) | s. A3 | Parameter fuer Limits-/LED-Logik (vermutet) |

### A2 C-Runtime-Bank

| Adresse | Rolle | Belegte Aufrufer |
|---|---|---|
| 0x0801D2EC | memcpy | Queue-Enqueue, Framebuilder, Fabrik-Writer, LED-Records |
| 0x0801D31E / D322 | memset (0) / memset (Wert) | Puffer-Nullung in Sendewrappern |
| 0x0801D334 | strlen | FIN-Pruefung FUN_0800BAD2 |
| 0x0801D342 + D484/D48A/D490/D574 | 64-Bit-/Divisions-Helfer | Mathe-Region 0x08011044/111B4/11378/1144C/1646A |
| D652/D66C/D6A0/D6D0/D700/D71E/D73E/D780 | Rechen-Helfer | 0x08011378/116FC/16944 u. a. |
| 0x0801D81C | IAR-Init-Runner | Reset 0x08007160 |
| 0x0801D840 | Dekomprimierer (Literal/Repeat/Rueckwaertsreferenz) | 0x0801D81C |

### A3 Float-Block 0x0801D035 (IEEE-754, Auszug)

* `0x0801D04D` = -655360f
* `0x0801D055` = -163840f
* `0x0801D065` = -0.000610352f
* `0x0801D069` = -2.5f
* `0x0801D06D` = -0.000152588f
* `0x0801D0A9` = 0.0166017f
* `0x0801D0B1` = 4.25003f
* `0x0801D0D5` = 3.13213f
* `0x0801D109` = 0.0166017f
* `0x0801D135` = -3.13067f
* `0x0801D13D` = 206184f
* `0x0801D15D` = 206154f
* `0x0801D179` = -507904f
* `0x0801D181` = 206116f
* `0x0801D19D` = 27.5152f
* `0x0801D1A9` = 0.363041f
* `0x0801D1B1` = 0.0266195f
* `0x0801D1B9` = 109.026f
* `0x0801D1BD` = 4.25003f
* `0x0801D1D1` = 206038f

### A4 LED-Farb-Records (6 x 28 B, 7 Farben)

* `0x0801D940`: #093D00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000
* `0x0801D95C`: #FF00FF00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000
* `0x0801D978`: #FF00FF00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000
* `0x0801D994`: #FF00FF00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000
* `0x0801D9B0`: #FF00FF00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000
* `0x0801D9CC`: #FF00FF00, #00FF00, #7FFF00, #FFFF00, #FF0000, #FFFF0000, #FF000000

## Teil B - Naeherungsfunktionen (SOC-Kennlinie)

Stuetzpunkte: 3.000-4.150 mV, 101 Werte; Firmware macht Index-Lookup (Stufenfunktion).

| Verfahren | max. Fehler | RMS | Bemerkung |
|---|---|---|---|
| Firmware-Stufenfunktion | 0.95 % | 0.54 % | Original (Springe bis 1 %SOC je 10-20 mV) |
| Stuecklinear 101 Pkt | ~0.5 % | ~0.3 % | exakt (Rundung) |
| 21 Stuetzstellen (5%-Raster) | 0.05 % | 0.02 % | kompakt |
| 11 Stuetzstellen (10%-Raster) | 1.67 % | 0.40 % | sehr kompakt |
| **5 Segmente (DP-optimal)** | 1.10 % | 0.54 % | **empfohlen** (Breakpoints 3000/3100/3200/3511/3898/4150 mV) |
| Polynom Grad 6 | 1.08 % | 0.40 % | t=(mv-3700)/100 |
| Polynom Grad 8 | 0.86 % | 0.32 % | t=(mv-3700)/100 |
| Polynom Grad 10 | 0.75 % | 0.28 % | t=(mv-3700)/100 |
| Polynom Grad 12 | 0.55 % | 0.15 % | t=(mv-3700)/100 |

*Getestet und **verworfen**: Logistik `SOC=100/(1+exp((mv-c)/s))` - die Kurve ist nahezu stuecklinear, max. Fehler ~96 %SOC.*

**Bestes Polynom (Grad 8)**: `-3.804279e-06, -1.569478e-04, -2.050973e-04, 9.679363e-03, 9.821610e-03, -2.166607e-01, -1.966326e-02, 1.070190e+01, 5.832563e+01`

**DP-Segmente (mV -> SOC):** 3000->0, 3100->5, 3200->15, 3511->40, 3898->78, 4150->100

*C-Code: `soc_kennlinie.c` (fw/linear/seg/poly/invers) - Plot: `soc_kennlinie.png`.*

## Teil C – Verifiziertes Byte-Layout der VCU→Display-Frames (Ergänzung 31.10.2026)

Rahmen: Befehl `0x35`, Länge `0x27` (39 B), Subtyp `3A` (`FUN_080107DA`) bzw. `3B` (`FUN_08010648`), XOR über [0..37] in [38].
**Wichtig:** Gegenüber einer früheren Zwischenfassung existiert **Byte [12]** (Spiegelflags) – alle Felder ab 12 sind daher +1 verschoben (ROM-abgeglichen via `ivcu_protocol.py`):

| Byte(s) | Inhalt (Quelle) |
|---|---|
| [3] | Status (0x200002DB) |
| [4] | Flagbyte, Bit1 = Clamp/Scale-Latch 0x2000030D |
| [5..6] | u16 BE (0x200002DE) |
| [7] | 0x200002E0 |
| [8..9] | u16 BE (0x200002E2) |
| [10] | 0x200002E4 (Rotationsrohwert) |
| [11] | Gang |
| [12] | Spiegelflags (0x200002A3/A2 & 0xFE) |
| [13] | **Speed-Feld** (max(0, 0x2000036D−0x28)) |
| [14] | **SOC** (0x20000364) |
| [15]/[16] | 0x2000035E / 0x2000035F |
| [17..18] | u16 BE (0x200002F0) – Rotationszeit-Kandidat |
| [19] | 0x200002F2 & 0x5F |
| [20..21] | u16 BE (0x200002F4) – Kandidat |
| [22..23] | u16 BE (0x200002F8) – Kandidat |
| [24..25] | u16 BE (0x200002FE) – Kandidat |
| [26..28] | Odometer/10, 3B BE (0x20000300/10) |
| [29] | Statusbyte (0x20000306) |
| [30] | Wheel (0x200002A5) |
| [31] | Pack-Spannung (0x200002C7) |
| [32] | Polpaare (0x200002A4) |
| [33] | (Temp−80)/5 |
| [34] | Start-Level (0x200002A7[Gang]) |
| [35] | Gang-Limit (0x200002B3[Gang]) |
| [36] | Power-Limit (0x200002B9) |
| [37] | Rear-Strom (0x200002BA/C0[Gang]) |
| [38] | XOR über [0..37] |

**Quelle der Messfelder (neu, `FUN_0800F4FA`):** Die Werte `0x2DB..0x2E5` sind die Kopie der ESC-`0x71`-Bytes `[3..11]` — `[3]`→`0x2DB`, `[4]`→`0x2DC`, `[5..6]`→u16 BE @`0x2DE`, `[7]`→`0x2E0`, `[8..9]`→u16 BE @`0x2E2`, `[10]`→`0x2E4` (Rot-Rohwert, 1 Byte), `[11]`→`0x2E5`; die 3B-Antwort spiegelt nach `0x2E6..0x2EF`. **Bit0 von ESC[11] = Dual-Motorfähigkeit** und steuert die `0x11`/`0x14`-Variantenwahl der IVCU-Frames (`FUN_080105A8`).

**Rotationszeit-Formel (community-verifiziert + Analyse):** `Speed = Wheel · 287 / rot` ⇒ `rot = Wheel-Code · 287 / speed_kmh` (Wheel-Code = Zoll×10, rot in 0,1 ms). Bestätigt durch die App-/Community-Doku (tr-lb-edition/tr-fw): dieselbe Kette gilt fürs Telemetriefeld `speedRaw = 55 72 t[15..16]`; `speedRaw ≥ 3000` oder `Speed ≤ 0,5` ⇒ Anzeige 0. Die eKFV-Anzeige-Kompensation skaliert die gesendete Rotationszeit mit `100/W` (W = realer Rad-Code in RAM `0x2000029D`; R5-Patchstellen 0x0801078E/0x08010ABA) — das Display erwartet also genau diese normierte Zeit. Bis zur Verifikation werden im `0x35`-Frame alle Kandidatenfelder ([17..18]/[20..21]/[22..23]/[24..25]) beschickt (Details: §16.2 der Haupt-Doku).

---

*Alle Angaben: statische Analyse (REA/Ghidra) + Numerik (NumPy) + Community-Doku (Web-Nachtrag §16 der Haupt-Doku).*