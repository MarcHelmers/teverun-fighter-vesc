# Analyse: `AWIVCU_APP_R3_4_13.hex`

> **Hinweis (Aktualität, 31.10.2026):** Dies ist die *erste* Tiefenanalyse. Maßgeblich/aktueller sind
> `AWIVCU_APP_R3_4_13_Doku_FINAL.md` (Gesamtdokument), `AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md`
> (Datenbereiche/Kennlinien) und `VESC_IVCU_Ersatz_Anleitung.md` (Umbau). Einzelne Angaben hier sind
> inzwischen präzisiert (z. B. Baudraten 115200/9600/9600, Display-/ESC-Frameformate, SOC-Kennlinie).

**Firmware der IVCU (Vehicle Control Unit) „Box C“ (HW V5.x) für Teverun Fighter Mini / Pro / ECO u. a.**
Version **3.4.13** (internationale/EU-Linie, Präfix `R`), Stand der Analyse: 31.10.2026

---

## 1. Was ist die Datei? (verifizierte Fakten)

| Eigenschaft | Wert |
|---|---|
| Format | Intel-HEX (ASCII), 5.856 Records, EOF-Record vorhanden, **alle Checksummen gültig** (0 Fehler) |
| Zieladresse | **0x08007000–0x0801DDBB** (91.396 Bytes Data, 0x16DBC = 91.388 B „virtuell“; ein einziger, lückenloser Block) |
| SHA-256 (Rohimage) | `613ee4166800c02039a247ed7c39c320b14d9442202cb9ac79c1c609bc5b1318` |
| HEX-Trailer | `:07AAA555` mit Daten `00 00 03 04 0D E3 49` → Version **3.4.13** (Bytes 03/04/0D) + **CRC-16/MODBUS = 0xE349** über das gesamte Image — eigenständig nachgerechnet: **stimmt überein** ✔ |
| Start-Adresse (Record 05) | 0x08007149 (Thumb, Startup-Code, entspricht dem Vektor `Reset = 0x08007161`) |
| Vector Table | @ 0x08007000: SP = 0x20003B90, Reset = 0x08007161, SysTick/IRQs – nur **TIM2 (IRQ28)** und **USART1/2/3 (IRQ37/38/39)** haben echte Handler, alle anderen zeigen auf Default-Handler |
| „App“-Charakter | Flash-Basis **0x08007000** ⇒ Bootloader belegt 0x08000000–0x08006FFF (nicht in dieser Datei enthalten) |

Für die Analyse wurden aus der HEX-Datei ein Rohimage (`AWIVCU_APP_R3_4_13.bin`), eine String-Liste und zwei PE-Wrapper (nur als Analysehilfen für Ghidra, s. Abschnitt 9) erzeugt.

---

## 2. Geräte-Kontext (Web-Recherche)

* **Teverun Fighter Mini / Mini Pro / ECO** sind E-Scooter; die **IVCU** ist das zentrale Steuergerät („Gehirn“) des **1.5-Systems** mit CAN-Bus. Firmware-Dateien heißen `AWIVCU_APP_...hex`.
* IVCU-Hardware-Revisionen (Quellen: eScootNow „Teverun Reference“, Teverun/Anleitungen):
  * 3.X (A)/4.X (B/B1): schwarze **AWVCU-TTMB1** (Modelle bis 2024)
  * **5.X (C): gelbe AWVCU-TTMC** (Blade GT II, Fighter Mini/11, Supreme+)
  * 5.X (C+GPS): TTMC+ mit GPS/PKE, 5.X (C1+): TTMC1+ (Supreme Ultra/7260R), C2: Tetra
* Die im Image eingebetteten Kennungen passen exakt dazu: **`AWPE-VCU-220212`** (Werksname/Buildcode 2022-02-12) und **`AWVCUB123480`** (Board-ID) – dieselben Strings wurden in Community-Analysen der 3.4.10 gefunden.
* Versionseinordnung: `R3.4.13` = **internationale 3.4.x-Linie** (Box C). Deutsche eKFV-Geräte laufen mit `D…`-Versionen (z. B. `AWIVCU_APP_D5_4_14_11.hex`, 22-km/h-Clamp). „ALI“-Images (`ALI D3.4.12`) sind Aftermarket-Boxen. Rydology listet **„Firmware 3.4.13 (latest)“** als regulären Download für Blade GT+/11/Fighter Mini/Supreme – d. h. diese 3.4.13 ist ein offizielles, globales Release der 3.4-Linie.
* Bekanntes Community-Ökosystem:
  * **Laufbursche Firmware Patcher** (github.com/Laufbursche42/tr-fw, Nachfolger lb-webpatcher.pages.dev) – dokumentiert die eKFV-Sperre, EEPROM-Reset, CRC/Trailer-Prüfungen.
  * **Laufbursche Edition** (github.com/Laufbursche42/tr-lb-edition) – alternative Android-App; BLE-Protokoll-Referenz, Firmware-Updater.
  * Foren (escooter-stammtisch.de, escooter-treff.de) mit Reverse-Engineering-Threads (3.4.10-Analyse, Hex-Adress-Excel).

---

## 3. Hardware-Plattform (aus Code extrahiert)

Peripherie-Fingerprint aus den Literal-Pools des Codes ⇒ **STM32F1-artige Peripheriekarte**; Kern nach Community-Doku + eigener Beobachtung: **GD32F303-Klasse (Cortex-M4F mit FPU)**:

| Block | Adresse(n) im Code | Beweis |
|---|---|---|
| RCC | 0x40021000 | Clock-Setup `FUN_08007184`: HSE an → PLL → SW=PLL; PLLSRC=HSE/2, PLLMUL=×12; PPRE1=/4, PPRE2=/2 ⇒ plausibel **48 MHz SYSCLK, 12 MHz APB1, 24 MHz APB2** (abgeleitet) |
| FLASH-IF | 0x40022000 | Flash-Zugriffe (Latenz/Keys) |
| AFIO / GPIOA–D | 0x40010004 / 0x40010800–0x40011400 | Pin-Konfiguration |
| **USART1 = BLE** | 0x40013800 | 20-Byte-`0xAA`-Frames + AT-Kommandos (s. u.) |
| **USART2 = Motor-Controller** | 0x40004400 | Motortelegramme (`0x4A`-Frames) |
| **USART3 = Display** | 0x40004800 | Display-Link |
| **CAN1** (+Filter 0x40006600) | 0x40006400 | CAN-Filter-Init `FUN_0801BDC4` mit 32-Bit-Masken-Filtern ⇒ **BMS/Batterie-Bus** |
| I2C1 | 0x40005400 | externes EEPROM (FIN, Version, Settings, Odometer) |
| TIM2 | 0x40000000 | einziger Timer-IRQ (IRQ28) = Systemtick |
| DMA1 | 0x40020000 | Speichertransfers |
| SCB/NVIC | 0xE000E... | VTOR-Relocation auf App-Basis (`0xE000ED0C` @ 0x08016F54) |

**Speicherbild:** App 0x08007000–~0x0801DDBB; RAM bis ~0x20002A90 genutzt, Stack-Top 0x20003B90 ⇒ **16 KB-RAM-Klasse**; Flash-Gesamtgröße ≥128 KB (Bootloader + Flag-Pages 0x0801F000/0x0801F800 laut Community-Analyse, nicht Teil dieser Datei).

---

## 4. Protokolle & Kernfunktionen (Ghidra-verifiziert, Adressen in R3.4.13)

### 4.1 BLE-App-Protokoll (USART1)

* `FUN_0800B4FE` – **USART1-RX-ISR**:
  * Ringpuffer 200 Bytes @ 0x20001F88 (Wrap bei 200)
  * Frame-Parser: **20-Byte-Frames: `[0]=0xAA`, `[1]=Cmd-ID`, `[2..18]=Payload (17 B)`, `[19]=CRC`** — Frame-Buffer @ 0x2000070C
  * fertige Frames werden per Enqueue `FUN_0800DEAA` in eine **Queue (15 Slots à 20 B) @ 0x2000078E** gelegt und im Hauptloop verarbeitet.
  * Deckt sich exakt mit der öffentlich dokumentierten „ISSC/Microchip Transparent-UART“-Implementierung (Community-Doku: 20-Byte-Frames, CRC-8/ATM, Werte Big-Endian, Sollwerte mit Offsets −1000/−40).
* `FUN_0800DD7C` / `FUN_0800DE4A` – Sender 20-Byte-Response über `FUN_08019B3A` (blockierendes USART1-TX).
* `FUN_0800BB42` – **FIN-Umbenennen** (BLE-Cmd `0x1F`): baut `AT+LENAME=<19 Zeichen>` und schickt es an das BLE-Modul; prüft Namensformat.
* `FUN_0800BA8C` – zyklisch „`AT+FC=1\r\n`“ (Flow-Control) bis >20 Versuche; weitere AT-Templates im Image: `AT+FC?`, `AT+FC=0`, `AT+LENAME=…` ⇒ **UART-BLE-Modul mit AT-Firmware (Feasycom-Kommandosatz)**.

### 4.2 `55 xx`-Telemetrie (VCU → App)

* `FUN_0800C608` – **`55 43`-Builder (Hardware-Info)**: überträgt u. a. die **Versionsbytes aus RAM 0x20000011–13 (= 3/4/13)** sowie Identitäts-/Board-Bytes (0x20000019/1A/1B, 0x2000002C–2F, Identitätsbyte 0x20000017) und Live-Werte. ⇒ **Bestätigt: 3.4.13 wird aus diesen drei Bytes gespeist.**
* Weitere Builder/Dispatcher im Bereich 0x0800C276–0x0800C608 (`55 42` Frame-Nr. aus RAM 0x20000742, `55 71` Settings-Echo etc.; vgl. Community-Doku, die dieselben Strukturen für R5 beschreibt — Adressen verschieben sich je Version).

### 4.3 Motor-/Display-Telegramme

* **Vier Motor-Frame-Builder** (USART2 zum ESC), Header `0x4A`, 19–20 Byte, XOR-Checksumme über 0x13 Bytes (`FUN_0800F9AC`):
  * `FUN_0800FE96` (orr.w r6,r6,#0x20 @ 0x0800FF9A)
  * `FUN_080101AA` (… @ 0x080101AE)
  * `FUN_08010238` (… @ 0x08010328)
  * `FUN_080103AC` (… @ 0x0801051C)
* Im Builder: Sollwert-Skalierungsbit 5 (0x20) wird je nach Flag **0x2000030D** gesetzt/gelöscht; mehrere Felder stammen aus den per-Gang-Arrays (Limit, Ströme, EABS). **Ein auf `0x16` (22) festgenagelter Clamp wie in der R5.4.19/eKFV-Firmware existiert hier NICHT** (Byte-Suche `movs r7,#0x16` = 0 Treffer) — konsistent mit der Community-Aussage: **R3-Images liefern ohne 22-km/h-Begrenzung aus** (die Sperre ist R5-/D-Serien-spezifisch und wird über Identität „TDE“ + Display-Bit gelatcht).

### 4.4 CAN (BMS)

* `FUN_0801BDC4` – CAN-Akzeptanzfilter (32-Bit-Maskenmodus, Beispielmasken 0x04030201/0x08070605, 0x01020304/0x05060708, ID 0x12345678) ⇒ **CAN1 ist aktiv als BMS-Bus**; die VCU geht bei fehlender BMS-Kommunikation nicht an (Community-Doku, plausibel konsistent).
* `FUN_0801C1F8` – Sensor-/Messwert-Filter (10-Sample-Ring, Max/Min/Ø mit Ausreißerprüfung) mit **Lookup-Tabelle @ 0x0801DC78** (16-Bit, ~3.000–4.150, unlineare Interpolation, Cap 101) — vermutlich Drehzahl-/ADC-Kennlinie.

### 4.5 EEPROM-Modell (externes I2C-EEPROM)

Bestätigt am Code (Loader `FUN_0801728A`, Writer `FUN_08017230`, Save `FUN_08016FC4`):

* **Block 1** (physisch I2C-Adresse **0x50**, 56 Bytes) = Fahr-Einstellungen:
  * `+0x00` Steuerbits (u. a. Cruise/EABS/Kickstart/Rear-free), `+0x01` Dual-Motor, `+0x02` Polpaare, `+0x03` **Raddurchmesser**, `+0x04` Übertemp.-Schwelle, `+0x05` Power-Limit %, `+0x06` Spannungscode, `+0x07` Pack-Spannung, `+0x08` Flags (AT/Miles/Eco)
  * `+0x09…+0x2C` **6 Gänge × 6 Bytes**: [Gang-Index, Speed-Limit, EABS|Rear-Start, Front-Start, Rear-Strom, Front-Strom]
  * `+0x2D`/`+0x2E` (u. a. Smart/TCS), `+0x34/0x35` **Prüfsumme über 0x34 Bytes**, `+0x36/0x37` reserviert
  * **Checksummenprüfung im Loader**: bei Mismatch wird der **Werks-Writer** `FUN_08017230` aufgerufen (schreibt Fabriktabelle + speichert → selbstheilende Defaults).
* **Block 0** (I2C 0x00, 80 B) = Identität/Version/FIN-Fallback (Writer `FUN_0801744C`):
  * `"VCU"`-Magie, Identitätsbytes, `"VCU" 01 01` (HW 1.1), **Version 03/04/0D = 3.4.13**, Identity-Block `14 16 0C 01`, Frame-Nr.-Feld (19 ASCII) und Sparefelder; RAM-Schatten u. a. 0x20000011–13 (Version), 0x20000019/1A/1B, 0x2000002C–30.
  * Werks-/Fallback-Name: **`AWPE-VCU-220212`**, Batch/Serie: **`01DB99`**, Board-ID: **`AWVCUB123480`**.
  * Die 55-43-Frames lesen aus diesen RAM-Schatten; ein **FIN-Rename (Cmd 0x1F)** schreibt den Namen zusätzlich ins BLE-Modul (`AT+LENAME`) → überlebt Reboots, ist per App änderbar (Community-verifiziert für R5; hier im Code bestätigt).
* **Fabriktabelle in ROM @ 0x0801DA40** (8 Bytes + 36-Byte-Gangtabelle ab 0x0801DA49):
  * `90 90 1E 6E 78 64 30 3C 00` = Flags, Polpaare=30, **Raddurchmesser 0x6E (11,0″)**, Temp 120, Power 100 %, Spannungscode 48, Pack 60 V
  * Gangtabelle (Fabrik): Gänge 1–5 mit Limit 20/40/60/80/100, EABS/Start-Nibbles 0x11/…/0x55, Strömen 15/20/25/30/55 (Gang 0 leer) — passt zu „5 Fahrstufen ≈ 15/…/55 km/h“-Community-Angaben für die EU-Software.

### 4.6 Weitere Datenbereiche am Image-Ende

* 0x0801D8B0–0x0801D900: Parametertabellen (u. a. `0x186A0`=100000 … `0x3D0900`=4 000 000 — Frequenz-/Teilerstaffel), CRC-/Bit-Felder, Byte-Tabellen `01 02 03 04 06 07 08 09 …`, Optionstabellen `01 02 04 06 08 0A 0C 10 20 40 80 …`
* 0x0801D940–0x0801D9E7: Muster aus 00/FF/7F (Farb-/Bitmap-Tabelle)
* 0x0801DC78–0x0801DD42: 16-Bit-Kennlinientabelle (siehe 4.4)
* 0x0801DD44 ff.: Zeiger-/Deskriptorstruktur (0x0801DD64, 0x20000000, 0x70C, 0x0801D840, 0x0801DDBC, 0x2000070C, 0x3484) — vermutlich Flash-/Service-Deskriptor

---

## 5. Version, Update & Flash-Mechanik (recherchiert + im Image geprüft)

* **Trailer-Format** der HEX (`:07AAA555 …`): uId/proj-Bytes + **Versions-Tripel (03 04 0D = 3.4.13)** + **CRC-16/MODBUS** über das Image. CRC eigenständig verifiziert (0xE349). Community-Doku bestätigt: Bootloader prüft **nur CRC + Adressbereich, keine Signatur**.
* **Bootloader (nicht Teil dieser Datei, Community-dokumentiert für Box C):**
  * App-Sprung nur bei Magic `0x5A5A5A5A` @ 0x0801F800; Update-Anforderung `0xA5A5A5A5` @ 0x0801F000
  * OTA-Kommandos 0x710–0x714 (START/FINISH/INFO/PACKINFO/PACKDATA); **kein Readback** (Dump nur per SWD/JTAG)
  * Schreibfenster 0x08007000–0x0801EFFF; unterbrochener Flash = bleibt im Bootloader (re-flashbar) — „fast nie Brick“ (Quelle: tr-fw README, ALI-Bootloader-Dump-Analyse)
  * Cross-Flash: Box-C-Images (R3/R5/ALI-D3/D10_4) teilen Basis 0x08007000; R2/D2 nutzten 0x08008000 (nicht kompatibel)
* **Flash-Update der App** erfolgt über die Teverun-App/BLE oder Community-Tools; Dauer ~13 min, „Auto-Off“ vorher im Display auf 30 min/aus stellen (BLE kann den Sleep-Timer bug-bedingt nicht ändern — im `55 71`-Frame fehlt Byte t[18]; in dieser Firmware-Generation strukturell).
* **eKFV-Sperre (nur R5/D-Linien):** doppeltes Gatter `letzte 3 FIN-Zeichen == "TDE"` **ODER** Display-Frame-Bit (Byte6 Bit2) ⇒ Sollwert-Clamp `0x16` in vier Frame-Buildern + Sollwert-Scale-Bit. In **R3.4.13 nicht enthalten** (kein `movs r7,#0x16`); EU-/R3-Images sind „offen“ (Community: Downgrade auf R3.4.10 als Unlock-Weg; R3.4.13 ist die neuere offizielle 3.4-er Version).

---

## 6. Bewertung / Einschränkungen

* MCU-Exakttyp: durch Community-Doku (tr-fw README, „Chip and hardware access") konkretisiert — **GD32F303-Klasse (Cortex-M4F mit FPU)** auf STM32F1-artiger Peripheriekarte; deckt sich mit eigener Beobachtung (FPU/CPACR-Aktivierung, VFP-Nutzung, Flash-Latenz jenseits F103). Bestückungstyp (z. B. GD32F303CB, 128 KB Flash) erst per SWD/Teardown verifizierbar. Uhren: aus RCC-Konfiguration abgeleitet (HSE/2 ×12).
* CAN-Frame-IDs/Dateninhalte (BMS-Protokoll) wurden nicht im Detail rekonstruiert (nur Filter-Setup und Nutzung belegt).
* Manche Code-Regionen sind nur über die Vector-Tabelle erreichbar; Ghidra erkannte sie erst nach einem Analyse-Trick (Stub-Section mit BLs auf alle Vektoren). Einzelne Funktionen (z. B. Gate-Latch) konnten dadurch nur teils zugeordnet werden.
* Die R5-spezifischen Detailadressen der Community (z. B. 0x08017264 Loader) verschieben sich in R3.4.13 leicht (hier: Loader `FUN_0801728A`, Writer `FUN_08017230`, Save `FUN_08016FC4`).

---

## 7. Artefakte in diesem Ordner

| Datei | Zweck |
|---|---|
| `AWIVCU_APP_R3_4_13.hex` | Original (unverändert) |
| `AWIVCU_APP_R3_4_13.bin` | Rohimage (Basis 0x08007000) – für weitere Tool-Analysen |
| `AWIVCU_APP_R3_4_13.strings.txt` | alle ASCII-Strings (≥5 Zeichen) mit Adressen |
| `AWIVCU_APP_R3_4_13.pe.bin`, `….pe2.bin`, `….pe3.bin` | nur Analyse-Wrapper (PE mit ARMNT-Header, ImageBase 0x08000000; pe2/pe3 mit Stub-Section für Ghidra-Funktionserkennung) – keine Firmware! |

Analyse-Skripte: `%TEMP%\opencode\hex2bin_teverun.py`, `make_pe_teverun.py`, `make_pe2_teverun.py`.

---

## 8. Wichtigste Belegstellen (REA/Ghidra-Evidenz, Session 31.10.2026)

| Thema | Adresse | Evidence-ID (REA) |
|---|---|---|
| Gesamt-Inventar | – | `ev_6d38674f49accd42d7d513326db7d6e3cd16b6761038854bfd66bb09a4acde11` |
| Motor-Builder (ohne Clamp) | 0x0800FE96 | `ev_4f880bbda7dbbecfcbbd1a656f20957a74925408cf6782f7284b091b88edb942` |
| Fabrik-Writer (Block 1) | 0x08017230 | `ev_e2b91e5ed4c032069b9265faba7970730357a8b8b3d3e238722fcbade82ad853` |
| Block-0-Defaults/Version | 0x0801744C | `ev_ee6d29ad4e526784bee3929784006e706fa3df18e2dbb801739bcd12a9f1b443` |
| Settings-Loader (EEPROM 0x50) | 0x0801728A | `ev_aefda33955914f55ef4ed25ffa0e21f80eaa2c9d3cc6513f7e16e262ad1ac307` |
| USART1-ISR / 0xAA-Parser | 0x0800B4FE | `ev_66194ac5f436732bf24173026c254c211efd6e0395e63225c66f37ea9291fbfc` |
| `55 43`-Hardwareframe | 0x0800C608 | `ev_777b4adae661482a588c14516b6d9ec6875a9c33ee6274086a2ff2c56bd2ffd8` |
| AT+FC=1 (BLE-Init) | 0x0800BA8C | `ev_86c8a49f73adc7fb48b538d297328e1a01318a34c07a5f3703a3af79cbc54b02` |
| AT+LENAME (FIN) | 0x0800BB42 | `ev_3a9b5a030ba4d65d204d37396d82a0d966fd39d8b9badda539bfd4547c1a9535` |
| CAN-Filter-Setup | 0x0801BDC4 | `ev_d28f1e901f664c40bd2b3b4fc5f4ab6bccc848291a2bcb605f043572fee845a0` |
| Clock/PLL-Init | 0x08007184 | `ev_f3476f3c4c5b19725e319aec8a41b02402ef474d35fb510a087a3ade5a63b8bc` |

---

## 9. Community-Quellen (Web)

* github.com/Laufbursche42/tr-fw – Firmware-Patcher & Reverse-Engineering-Notizen (Clamp, EEPROM, Bootloader, Trailer/CRC)
* github.com/Laufbursche42/tr-lb-edition – Android-App, BLE-Protokollreferenz, Updater
* escootnow.com.au/products/teverun-reference – IVCU-Versionstaxonomie, Systempläne
* rydology.com/blogs/news/teverun-firmware – offizielle 3.4.13-Verfügbarkeit
* escooter-stammtisch.de / escooter-treff.de – Tuning-/Reverse-Threads (3.4.10-Analyse, eKFV-Zwangsupdates)

## 10. Nachtrag: Display-/ESC-Protokoll & VESC-Eignung

### 10.1 Display-Link (USART3) — neue, im Web nicht dokumentierte Details

**VCU → Display** („Command-0x35“-Frames, beide 39 Bytes, XOR-Checksumme über Byte 0–37 in Byte 38):

| Builder | Frame | Inhalt (RAM-Quellen) |
|---|---|---|
| `FUN_080107DA` | `35 27 3A …` | Statusflags (Byte 4: 0x80/0x40/0x20/0x10/0x08/0x04/**0x02 = Clamp-/Scale-Latch `0x2000030D`**), 16-Bit-Messwerte (`0x200002DE/E2/F0/F4/F8/FE`), Gang, Wheel (`0x200002A5`), Pack-Spannung (`0x200002C7`), Polpaare (`0x200002A4`), (Temp−80)/5, Gang-Speed-Limit (`0x200002B3[gang]`), Ströme (`0x200002AD/C0[gang]`, `0x200002B9`), 3-Byte-Odometer (`0x20000300`/10, Big-Endian), Geschw.-Feld (`max(0, 0x2000036D−0x28)`) |
| `FUN_08010648` | `35 27 3B …` | Gleiche Struktur, einfachere Statusquelle (`0x200002E6/E7/E8…`), ebenfalls XOR-Checksumme |

**Display → VCU** (ISR `FUN_0800B6CC`, Queue-Consumer `FUN_0800FA94`):

| Header | Länge | Prüfung | Ziel-Schatten |
|---|---|---|---|
| `0x4C` (`L`) | 19 B | XOR über 18 B == Byte 18 | `0x2000137F…0x20001391` (**Byte 6 = 0x20001385**, dort laut Community das eKFV-Clamp-Bit Bit 2) |
| `0x8A` | 11 B | – | `0x200013B3…` (+ `DAT_2000040A=1`) |
| `0x8B` | 8 B | – | `0x200013B3…` |
| `0x8C` | 8 B | – | `0x200013B3…` |

Timeouts: 600 ms ohne gültige Frames ⇒ Fehlerflags `0x2000030E` (Display), `0x20000310`/`0x20000311` (ESC); Zähler sättigen bei 5000 ms.

**Keep-Alive:** `FUN_08019B82` schickt zyklisch einen 10-Byte-Zählerframe (`00 01 02 … 09`-Muster) an **Display und ESC gleichzeitig**.

**TX-Architektur:** zentraler Pump `FUN_0800FE3A` (Display-Puffer `0x2000128E` → USART3 via `FUN_08019B5E`; ESC-Puffer `0x200010FA` → USART2 via `FUN_08019B4C`).

### 10.2 ESC-Link (USART2)

* VCU → ESC: `4A`-Frames in vier Varianten: `4A 11 3A`, `4A 11 3B`, `4A 14 3A`, `4A 14 3B` (0x11-Variante: TX 17 B = [0..15]+XOR aus Pufferbyte[19], XOR selbst über alle 19 Pufferbytes; 0x14-Variante: TX 20 B, XOR @[19]; Builder `FUN_0800FE96`, `FUN_080100AA`, `FUN_08010238`, `FUN_080103AC`, plus Statusvariante `FUN_080103AA`). **Kein 0x16-Clamp** in R3.4.13 (bestätigt).
* ESC → VCU: `71`-Frames (ISR `FUN_0800B5CA`, Puffer `0x20000720`), 13 Byte (11 Daten + Typmarker + XOR; ISR sammelt 13), Untertypen `3A`/`3B`, Consumer `FUN_0800FA94` ⇒ Alive-Flags + Shadow `0x200013A6…`.
* Baudraten der USART2/3-Links konnten statisch nicht extrahiert werden (Init-Routine nicht eindeutig lokalisiert) — per Logikanalysator/Scope messbar.

### 10.3 Könnte ein VESC mit LispBM die Werksanzeige ansteuern?

**Technisch: ja, plausibel.** VESC-LispBM (FW ≥ 6.00) bietet genau die nötigen Bausteine:

| LispBM-Funktion | Zweck hier |
|---|---|
| `(uart-start baud [‘half-duplex])` | USART des VESC (COMM-Port; Express: mehrere Ports frei wählbar) |
| `(uart-write array)` | Display-Frames senden (0x35-Frames, Keep-Alive) |
| `(uart-read …)`, `(uart-read-bytes …)`, `(uart-read-until …)` | Display-Frames 0x4C/0x8A/0x8B/0x8C empfangen |
| `(crc16 …)`, eigene Lisp-Schleifen | XOR-Checksummen der Teverun-Frames |
| `(set-current/-rpm/-duty …)`, `(get-… )` | Motorregelung + eigene Messwerte für die Anzeige |

**Vorgehen (empfohlen):** 1) UART-Mitschnitt zwischen IVCU und Display an einem realen Scooter (z. B. 2-Kanal-USB-UART-Sniffer), 2) Lisp-Skript emuliert die IVCU-Seite: `0x35 0x27 0x3A/0x3B`-Frames (39 B, XOR) senden, die 4 Display-Frames parsen, Keep-Alive senden, 3) Speed/Leistung aus VESC-Werten in die Frame-Felder mappen.

**Risiken/Offene Punkte:** ~~Baudrate (unbekannt, sniffen)~~ ✅ inzwischen bekannt: **Display 9600, ESC 9600, BLE 115200** (siehe Doku_FINAL §2.1); offen bleiben: Semantik einzelner Display-Felder (0x8A/0x8B/0x8C), Timing/Toleranz des Displays, Stromversorgung/Pegel des Displays (3,3 V UART), der VESC-COMM-Port ist je nach Variante für VESC Tool belegt. **Umsetzung:** `vesc_ivcu_emulator.lisp` + `VESC_IVCU_Ersatz_Anleitung.md` (Stand 31.10.2026). Ein „Blindflug" ohne Mitschnitt ist riskant, ein Replay-/Emulationsansatz aber realistisch.

### 10.4 Was davon ist neu (nicht im Web)?

* Öffentlich bereits dokumentiert: BLE-App-Protokoll (`55 xx`, sehr detailliert), eKFV-Clamp-Mechanik (TDE-Identität + Display-Bit), Bootloader/CRC-16-OTA, EEPROM-Blöcke, IVCU-Versions-/Hardware-Taxonomie, grobe Aussage „Display hängt an USART3, Frames 0x4c/0x8a/0x8b/0x8c“.
* **Neu aus dieser Analyse:** exakte Display-Frame-Formate (0x35/39 B, Untertypen 3A/3B, XOR-Felder, Builder↔RAM-Feldzuordnung), Display-RX-Formate mit Längen/Prüfung/Schatten, Timeout-Mechanik (600/5000 ms), 10-Byte-Keep-Alive an Display+ESC, ESC-Frame-Formate (4A 11/14 × 3A/3B; 71-Antworten 12 B) samt Puffern/Adressen, zentrale Sende-Architektur, vollständige RAM-/Factory-Tabellenkarte der R3.4.13, Bestätigung „kein 22er-Clamp“ in R3.4.13.

---

*Bericht erstellt mit REA (Ghidra 12.1.4) + eigener HEX/Binary-Analyse. Alle Angaben ohne Gewähr; Flashen von Fremd-/Mod-Images geschieht auf eigenes Risiko. Nachtrag 31.10.2026: Display-/ESC-Protokoll + VESC-Eignung.*

