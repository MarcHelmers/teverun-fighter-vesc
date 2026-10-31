# IVCU-Firmware `AWIVCU_APP_R3_4_13` — Abschlussdokumentation

**Gerät:** Teverun Fighter Mini / Pro / ECO (und Box-C-Schwestermodelle), IVCU „Box C“ (HW V5.x, AWVCU-TTMC)
**Datei:** `AWIVCU_APP_R3_4_13.hex` · SHA-256 (Rohimage): `613ee4166800c02039a247ed7c39c320b14d9442202cb9ac79c1c609bc5b1318`
**Analyse:** REA/Ghidra 12.1.4 (ARMNT-PE-Wrapper + Stub-Funktionssuche), eigene HEX-/Binary-Tools, Web-Recherche
**Stand:** 31.10.2026 · Version 1.0 (Abschluss)

---

## 0. Kurzfassung (Executive Summary)

* Die Datei ist die **Applikations-Firmware der IVCU** (Flash-Basis 0x08007000, 91.388 Bytes, Version **3.4.13**, internationale/EU-Linie). Der Bootloader (0x08000000–0x08006FFF) ist **nicht** in dieser Datei.
* Das System ist eine **GD32F303-Klasse (ARM Cortex-M4F mit FPU) auf STM32F1-artiger Peripheriekarte** mit vier Kommunikationswegen: **BLE/App (USART1, 115200 Bd)**, **Motorcontroller/ESC (USART2, 9600 Bd)**, **Display (USART3, 9600 Bd)**, **BMS (CAN1)** sowie **externem I2C-EEPROM** für Persistenz.
* Die Firmware ist eine **kooperative Echtzeit-Applikation**: Init-Kette → Endlosschleife mit **Timer-Scheduler** (Tasks alle 10/20/50/100/200/500/1000/2000/5000 ms). Kommandos laufen über **20-Byte-Ringpuffer → Queues** (BLE/ESC/Display getrennt) und werden in den 100-ms-Tasks verarbeitet.
* **Alle Frames der drei UART-Links sind im Rahmen (Header/Länge/Checksumme) bekannt**, große Teile auch feldweise; eine vollständige, bytegenaue Semantik **jedes** Bytes ist noch nicht erreicht (offene Punkte in §10/§11).
* **Wichtig für Umbauten:** Die IVCU setzt **keinen 22-km/h-Clamp** (R3-Linie ist offen). Die eKFV-Sperre der R5/D-Linien ist hier nicht implementiert.

* **Ergänzung (Dekompilat-Export):** Alle automatisch identifizierbaren Funktionen wurden als kommentierte C-Quelle exportiert: **671 Funktionen, 83,1 % der Image-Bytes als Pseudocode**; die restlichen 21.988 Bytes (155 Regionen: Tabellen, Pointer-Pools, Fragmente, Padding) sind im **Byte-Anhang** der Quelle erfasst. Dateien: `AWIVCU_APP_R3_4_13_decompiled.c` (≈802 KB) und `AWIVCU_APP_R3_4_13_function_index.csv`.

---

## 1. Datei, Format & Integrität

| Punkt | Befund |
|---|---|
| Format | Intel-HEX, 5.856 Records, **alle Zeilen-Checksummen gültig**, EOF-Record vorhanden |
| Adressen | ein Block 0x08007000–0x0801DDBB (0x16DBC = 91.388 B Nutzdaten) |
| Start-Record | `:0400000508007149 35` → Startadresse 0x08007149 (Thumb-Startup) |
| Trailer | `:07AAA555` + `00 00 03 04 0D E3 49` = uId/proj `0x0000`, **Version 3.4.13**, **CRC-16/MODBUS 0xE349** (nachgerechnet: identisch) |
| Bootloader-Erwartung | App-Fenster 0x08007000–0x0801EFFF; Flag-Pages 0x0801F000 (Update-Request `0xA5A5A5A5`) und 0x0801F800 (App-Valid `0x5A5A5A5A`) — **nicht** Teil dieses Images; Magic-Wörter im App-Code nicht vorhanden |
| Werkskennungen im Image | `AWPE-VCU-220212` (Produkt/Buildcode), `AWVCUB123480` (Board-ID), `01DB99` (Serie/Batch), `VCU`-Magie-Blöcke |

---

## 2. Hardware-Plattform

**MCU: GD32F303-Klasse (ARM Cortex-M4F mit FPU), STM32F1-artige Peripheriekarte** — belegt durch die F1-kompatible Peripherie-Map (RCC/FLASH/GPIO/USART/CAN/I2C/DMA) **plus FPU-Aktivierung (CPACR) und VFP-Nutzung**; die Community-Analyse nennt explizit „ARM Cortex-M4F auf STM32F1-style peripheral map ⇒ GD32F303-class part" mit FPU/VFP und Flash-Latenz-Bits jenseits des F103 (tr-fw README, „Chip and hardware access"; deckt sich mit unseren CPACR-/Flash-Beobachtungen). **SWD-Pads (SWDIO/SWCLK)** vorhanden; RDP-/Optionsbyte-Status ist **nicht-destruktiv** prüfbar; ein Firmware-Dump ist nur per SWD möglich (kein BLE-Readback). RAM: Stacktop 0x20003B90, Init-Block 0x70C B @0x20000000 + BSS 0x3484 B bis 0x20003B90 ⇒ **RAM-Klasse ≈16–32 KB**; Flash ≥128 KB (App-Fenster bis 0x0801EFFF; Flag-Pages 0x0801F000/0x0801F800).

### 2.1 Kommunikationswege & Baudraten (aus Init `FUN_080198EC`)

| Link | USART | Pins | Baud | RX-Mechanik |
|---|---|---|---|---|
| BLE-Modul / App | USART1 0x40013800 | PA9/PA10 | **115200** | DMA-Kanal 5 → Ringpuffer 200 B @ 0x20001F88 |
| Motorcontroller (ESC) | USART2 0x40004400 | PA2/PA3 | **9600** | IRQ (IRQ38) |
| Display | USART3 0x40004800 | **PB10/PB11** (Registerbefund 0x80198EC: GPIOB-Masken Bit10/11; frühere PC10/PC11-Annahme korrigiert) | **9600** | DMA-Kanal 7 → Ringpuffer 200 B @ 0x20002118 |
| BMS | CAN1 0x40006400 | — | Bitrate nicht statisch ermittelt | Filterbänke 32-Bit-Maskenmodus (`FUN_0801BDC4`) |
| EEPROM | I2C1 0x40005400 | — | — | Blöcke 0x00/0x50/0x88/0x94/0xA0 |

Weitere Peripherie-Nutzung: **TIM2** als Zeitbasis (IRQ28, Handler `FUN_0800B4F0` löscht nur das Update-Flag; Zeitholen über `FUN_08019152`), SysTick unbenutzt, **SCB/VTOR**-Relocation auf 0x08007000 (`0xE000ED0C` bei 0x08016F54), PWR 0x40007000, SPI/ADC nicht nachgewiesen.

---

## 3. Systemstart & Mainloop

### 3.1 Startkette

1. Vektor `Reset` 0x08007161 → Startup @0x08007144: `LDR SP,=0x20003B90` → `BL SystemInit` → `LDR/BX __main (0x0800B87C)`.
2. `FUN_0800B87C` (thunk) → **`FUN_0801C700` = Hauptschleife**.
3. Init-Phasen (gesteuert über `DAT_200006FD`, Setzer `FUN_0801C640(1/3/5)`):
   * **Schritt 1 (`FUN_08018718`):** Zeitbasis/TIM2 (`FUN_0801914A`→`FUN_080190E0`), Board-/LL-Treiber (`FUN_0801938E`, `FUN_08019BD8`, `FUN_080194EC`, `FUN_08019690`), **CAN-Init (`FUN_0801BA92`→`FUN_0801BA4E`)**, dann **UART-Init für USART1, USART2, USART3 (`FUN_080198EC`)**, `enableIRQinterrupts()`.
   * **Schritt 2/3:** `FUN_0801874C` (Peripherie-/Sensor-/EEPROM-Nachlauf), dann Wechsel in die zyklische Verarbeitung. (Zwischenschritte `FUN_08018748/74A` für Sonderfälle.)

### 3.2 Scheduler (`FUN_0801C700`)

Kooperativer Software-Timer: liest `now = FUN_08019152()` und ruft je Periode eine Task, wenn die Differenz zur letzten Ausführung den Schwellwert überschreitet. Zusätzlich wird **die Ausführungszeit jeder Task** gemessen (Start/Ende über `FUN_08019152`, Ergebnis in 0x200006DE…0x200006EE).

| Periode | Task | Inhalt (Kurz) |
|---|---|---|
| 10 ms | `FUN_0801876C` | Tick-Zähler `0x20000530++` |
| 20 ms | `FUN_08018778` | (leer) |
| 50 ms | `FUN_0801877A` | (klein; Perioden-Slot) |
| **100 ms** | **`FUN_0801877C`** | `FUN_0801959C`, `FUN_080186F4`, `FUN_080195DC`, **`FUN_0800FE26`**, `FUN_08015CAA` |
| 200 ms | `FUN_08018794` | (Perioden-Slot) |
| 500 ms | `FUN_08018796` | (Perioden-Slot) |
| 1000 ms | `FUN_080187AE` | (Perioden-Slot) |
| 2000 ms | `FUN_080187BE` | (Perioden-Slot) |
| 5000 ms | `FUN_080187D4` | **`FUN_08017E2C`** (Settings-/Persistenz-Nachlauf) |

**100-ms-Kern (`FUN_0800FE26`):** `FUN_0800FA94` (RX-Consumer ESC+Display) → `FUN_0800F4FA` (Kommandoverarbeitung Display/ESC) → `FUN_0800EF96` (Fahrzeug-State) → `FUN_0800EE76` (Display-Sonderrrahmen 0x8A/8B/8C) → Telemetrie-/Sende-Builder (u. a. `FUN_0800DEEA`, `FUN_0800C608`, `FUN_0800C5B8`).
**TX-Pump (`FUN_0800FE3A`):** sendet bei Bedarf Display-Puffer 0x2000128E→USART3 und ESC-Puffer 0x200010FA→USART2.

---

## 4. Datenmodell (wichtige RAM-Bereiche)

| Bereich | Rolle |
|---|---|
| 0x20000004/05, 0x2000070C… | BLE-RX-Framestate / 20-B-Framepuffer (0xAA) |
| 0x20000720 | ESC-RX-Framepuffer (0x71) / 0x20000E2C = ESC-Queue |
| 0x2000072E | Display-RX-Framepuffer (0x4C/0x8A/0x8B/0x8C) / 0x20000F01 = Display-Queue |
| 0x2000078E | BLE-Kommando-Queue (15 Slots × 20 B) |
| 0x20000D8A…0x20000E2A | BLE-TX-Frame-Aufbau (55 42/43/71/72/73-Bausteine) |
| 0x200010FA (Länge 0x200011C2) | ESC-TX-Frame |
| 0x2000128E (Länge 0x20001356) | Display-TX-Frame |
| 0x20001358…0x2000137E | Arbeitspuffer Display-Frame 0x35 (39 B) |
| 0x2000137F…0x20001391 | Schatten Display-RX 0x4C-Frame (19 B) |
| 0x200013A6… / 0x200013B3… | Schatten ESC-0x71 (12 B) / Display-0x8A/8B/8C (11/8 B) |
| 0x2000029B…0x200002DA | Laufzeit-Settings-Sicht (aus EEPROM geladen) |
| 0x200002A1 | aktiver Gang · 0x200002A4 Polpaare · 0x200002A5 Raddurchmesser · 0x200002A6 Übertemp.-Schwelle |
| 0x200002A7/AD/B3/BA/C0 [6] | Per-Gang-Arrays (Front-Start, EABS/Rear-Start, Limit, Rear-/Front-Strom) |
| 0x200002B9 | Power-Limit % · 0x200002C6/C7 Spannungscode/Pack-Spannung |
| 0x20000308/09/0A/0D/0E/10/11/12/14 | Zustands-/Fehlerflags (Dual, Eco, ?, **Clamp/Scale 0x2000030D**, Display-Timeout 0E, ESC-Timeouts 10/11, Smart 12, Clamp-Indikator 14) |
| 0x20000398/9A | Dual-/Standby-Flags (aus ESC/Display-Frames) |
| 0x20001A08…0x20001A57 | EEPROM-Block-0-Schatten (Identität/Version/Rahmennummer) |
| 0x20001A58…0x20001A8F | EEPROM-Block-1-Schatten (Fahr-Settings, 0x38 B) |

---

## 5. Protokolle im Detail

### 5.1 BLE/App (USART1, 115200 Bd) — 0xAA-Protokoll

* **RX-ISR `FUN_0800B4FE`:** 20-Byte-Frames `[0]=0xAA, [1]=Cmd, [2..18]=Payload, [19]=CRC`; Rohbytes zusätzlich in 200-B-Ringpuffer 0x20001F88; vollständige Frames → Queue 0x2000078E (Enqueue `FUN_0800DEAA`, Vollprüfung `FUN_0800DE88`).
* **TX:** `FUN_0800DD7C`/`FUN_0800DE4A` bauen Frames aus 16/20-Byte-Strukturen und senden über `FUN_08019B3A` (USART1). Frame-Aufbau der 55xx-Telemetrie über `FUN_0800DEEA` (Settings-Echo), `FUN_0800C608` (55 43 Hardwareinfo inkl. Versionsbytes 0x20000011-13 = 3.4.13), `FUN_0800C5B8`/`FUN_0800C276`/`FUN_0800C4F4` (State-getriebene Sender).
* **AT-Kommandos für das BLE-Modul:** `FUN_0800BA8C` sendet zyklisch `AT+FC=1` (Flow-Control) bis >20 Versuche; `FUN_0800BB42` = FIN-Umbenennung (BLE-Cmd 0x1F → `AT+LENAME=<19 Zeichen>`); weitere Templates `AT+FC?`, `AT+FC=0`. ⇒ UART-BLE-Modul mit AT-Firmware (Feasycom-artig).
* **Payload-Referenz:** Die 55xx-Frames sind öffentlich vollständig dokumentiert (Community „BLE protocol reference“): 55 41/42/43/44/45/4D (Identität/Versionen), 55 52/53/54 (BMS), 55 71 (Settings/Gang), 55 72 (Motor/ECU), 55 73 (Fahrt), 55 79/7A (Tetra). Diese Analyse bestätigt die Frame-Bausteine und RAM-Quellen.

### 5.2 ESC/Motorcontroller (USART2, 9600 Bd)

* **TX (VCU→ESC):** `4A`-Frames, **vier Varianten**: `4A 11 3A` (`FUN_08010238`), `4A 11 3B` (`FUN_0800FE96`), `4A 14 3A` (`FUN_080103AC`/`FUN_080103AA`), `4A 14 3B` (`FUN_080100AA`); Länge 17 bzw. 20 Byte (Feld `0x200011C2`); 0x11-TX = [0..15]+Checksumme aus Baustelle [19] (XOR über alle 19 Pufferbytes); 0x14-TX = 20 B, XOR @[19] (`FUN_0800F9AC`), Gesendet über `FUN_08019B4C`. **Round-Robin** in `FUN_080105A8` (alternierend Kanal 3A/3B; **Variantenwahl über das Dual-Flag `0x20000398`:** 1 → `0x14`-Frames, 0 → `0x11`, 0xFF = unbekannt → alternierend beide, bis die erste gültige 3A-Antwort das Flag setzt).
* **RX (ESC→VCU):** ISR `FUN_0800B5CA` (IRQ38), Header **`0x71`**, 13-Byte-Frames (11 Daten + Typmarker + XOR; ISR sammelt 13) in Queue 0x20000E2C; Consumer `FUN_0800FA94` prüft Checksumme (XOR über 12 B) und verarbeitet Untertypen **`:` (0x3A)** und **`;` (0x3B)** → Alive-Flags `0x20000310/0x20000311` (Timeout 600 ms → Fehler), Datenkopien nach 0x200002DB… und 0x200002E6…, **Dual/Single-Flag `0x20000398`** (aus **`frame[11]` Bit0**, nur 3A-Antwort; `FUN_0800F4FA` kopiert ESC[3]→`0x2DB`, [4]→`0x2DC`, [5..6]→u16@`0x2DE`, [7]→`0x2E0`, [8..9]→u16@`0x2E2`, [10]→`0x2E4`, [11]→`0x2E5`; 3B analog nach `0x2E6..0x2EF`).
* **Kein 0x16-Clamp** in R3.4.13 (Byte-Suche `movs r7,#0x16` = 0). Sollwert-Scale-Bit (0x20) in den Motorframes wird über `0x2000030D` gesteuert.

### 5.3 Display (USART3, 9600 Bd)

* **RX-ISR `FUN_0800B6CC`:** Frameparser für 4 Startbytes; Ringpuffer 200 B @ 0x20002118; Frames → Queue 0x20000F01 (Enqueue `FUN_08010C72`).

| Frame | Länge | Prüfung | Inhalt/Ziel |
|---|---|---|---|
| `0x4C` (`L`) | 19 B | XOR über 18 B | Schatten 0x2000137F… **Byte 2=0x35 ⇒ Display-Kommando**, Byte 3 = Cmd-ID, Byte 5 Bit5 ⇒ `0x2000030D` (Clamp/Scale), Byte 6: Bit2 ⇒ `0x20000314` (Clamp-Indikator), Bit0/Eco ⇒ `0x20000309`, Bit1 ⇒ `0x20000308`, Bit4 Smart ⇒ `0x20000312`, Bit7 ⇒ `0x200002CD`, Bit6 ⇒ `0x2000030F` |
| `0x8A` | 11 B | — | Schatten 0x200013B3…; Byte2 8/9/0x0A ⇒ 3-stufige Datenübernahme nach 0x20000768/6F/76 (`FUN_08018236`) |
| `0x8B` | 8 B | — | Byte2/4/6 = 0xAA ⇒ `FUN_08016EC0` |
| `0x8C` | 8 B | — | Byte2=1, Byte5/6=0xAA ⇒ `FUN_08017E1A` |

* **Display-Kommandos im 0x4C-Frame (Byte3) — verarbeitet in `FUN_0800F4FA`:**
  * `1` = **Gangwahl** (Byte4 → `0x200002A1`, max. 5)
  * `2` = Flags: Licht/Dual-Bits (`0x200002A3/A2`), `0x2000030A=3`, **Clamp-Latch `0x2000030D` = Byte5 Bit5**
  * `3` = **Eco** (Byte6 Bit0 → `0x20000309`)
  * `4` = **Dual/TCS-Flag** (Byte6 Bit1 → `0x20000308`)
  * `5` = **Settings-Write (Display-Menü):** Start-Leistungsstufen/EABS (Byte5/6), Polpaare (Byte7), **Raddurchmesser (Byte8)**, Temperaturschwelle (Byte9·5+80), Per-Gang-Werte (Byte10/11/13/14), Power-Limit (Byte12), Spannungscode (Byte13), Pack-Spannung (Byte14)
  * `7` = Smart/TCS (`0x20000312`), `9` = `0x2000031E`
  * Tail-Update: `0x20000314` (Byte6 Bit2), `0x200002CD` (Byte6 Bit7), `0x20000408=1`
* **TX (VCU→Display):** Befehl **`0x35`**, Länge **39 B (0x27)**, zwei Varianten:
  * `35 27 3A …` (`FUN_080107DA`): Statusbyte (u. a. Clamp/Scale-Bit1 ← `0x2000030D`, 0x80/0x40/0x20/0x10/0x08/0x04 aus Flags), 16-Bit-Messfelder (0x200002DE/E2/F0/F4/F8/FE), Gang, Wheel (0x200002A5), Pack-Spannung, Polpaare, (Temp−80)/5, Gang-Limit/-Ströme, 3-Byte-Odometer (BE, /10), Geschwindigkeitsfeld (`max(0,0x2000036D−0x28)`), **XOR-Checksumme über 38 B in Byte 38**. *Verifiziertes Byte-Layout: [4]=Flagbyte, [11]=Gang, [12]=Spiegelflags, [13]=Speed, [14]=SOC, [15]/[16]=0x35E/0x35F, [17..18]/[20..21]/[22..23]/[24..25]=Messfelder (0x2F0/0x2F4/0x2F8/0x2FE), [19]=0x2F2&0x5F, [26..28]=Odometer, [29]=Status, [30]=Wheel, [31]=Pack, [32]=Polpaare, [33]=(Temp−80)/5, [34]=Start-Level, [35]=Gang-Limit, [36]=Power-Limit, [37]=Rear-Strom*
  * `35 27 3B …` (`FUN_08010648`): gleiche Struktur, vereinfachte Statusquelle (0x200002E6…)
* **Keep-Alive:** `FUN_08019B82` sendet einen 10-Byte-Zählerframe zugleich an ESC und Display.
* **Timeouts:** 600 ms ohne Display-Frame ⇒ `0x2000030E`; Zähler sättigen bei 5000 ms.

### 5.4 CAN (BMS)

CAN1 mit 32-Bit-Masken-Filtern initialisiert (`FUN_0801BA4E`/`FUN_0801BDC4`, Beispiele: Masken 0x04030201/0x08070605, 0x01020304/0x05060708, ID 0x12345678). Datenpfad (`FUN_0801C1F8` etc.) filtert Sensor-/Messreihen (10-Sample-Ring, Ausreißerprüfung) mit 16-Bit-Kennlinientabelle @ 0x0801DC78. **CAN-Bitrate und BMS-Frame-IDs offen.**

### 5.5 EEPROM (I2C) & Persistenz

| Block | Adresse | Größe | Inhalt | Zugriff |
|---|---|---|---|---|
| 0 | 0x00 | 80 B | Identität (FIN-Fallback), Frame-Nr. (19 ASCII), HW/SW-Version (03/04/0D), Identity-Bytes | Writer `FUN_0801744C` (Defaults), Loader-Mirror nach 0x2000000C-2C |
| 1 | 0x50 | 56 B | Fahr-Settings (s. §4) | Loader `FUN_0801728A` (liest 0x38 B, XOR-Prüfsumme über 0x34, Halbwort @0x34, bei Mismatch **Werks-Writer `FUN_08017230`**), Save `FUN_08016FC4(Block)`, Read-Primitiv `FUN_08017084` |
| 2/3 | 0x88/0x94 | 12 B | Odometer (wear-levelled Paar) | (Community-dokumentiert) |
| 4 | 0xA0 | 16 B | Motor-Kalibrier-/Modusdaten | (Community-dokumentiert) |

**Fabriktabelle (ROM @ 0x0801DA40):** `90 90 1E 6E 78 64 30 3C 00` (= Flags, Polpaare 30, Wheel 0x6E=11,0″, 120 °C, 100 %, Spannungscode 48, Pack 60 V) + Gangtabelle ab 0x0801DA49 (Gänge 1–5: Limit 20/40/60/80/100; EABS/Start-Nibbles 0x11…0x55; Ströme 15/20/25/30/55).

### 5.6 Update-Pfad (App-Ebene)

* Im R3-App-Image finden sich **keine** Magic-Wörter `0x5A5A5A5A`/`0xA5A5A5A5` und keine 0x0801F000/0x0801F800-Literale ⇒ Das „Enter-Bootloader“-Kommando der R5-Linie ist hier **nicht** implementiert; die App schreibt lediglich über `SCB->AIRCR` (`0xE000ED0C`, Site 0x08016F54) einen System-Reset (Reset-Helfer).
* Das **Display-Oberflächen-/OTA-Relais** der R5-Firmware ist in R3 nicht vorhanden; jedoch existiert eine **3-stufige Datenübernahme** aus Display-0x8A-Frames (`FUN_0800EE76` → `FUN_08018236`) sowie Sonderbefehle aus 0x8B/0x8C-Frames (`FUN_08016EC0`, `FUN_08017E1A`). Deren exakte Funktion (Konfig-Update, Reset, Kalibrierung?) ist **offen**.
* Bootloader/Flash-Mechanik (aus Community-Analyse, Box C): CRC-16-only, App-Valid-Magic, OTA-Kommandos 0x710–0x714, **kein Readback** (Dump nur per SWD/JTAG).

---

## 6. Fahrzeug-State & Regelkreis (VCU-Ebene)

* **`FUN_0800EF96` (State-Machine, 100 ms):** verdichtet Zustände zu `0x20000306` (Statusbyte: Eco/Dual/…), wertet Stand-/Fahrzustände, Display- und ESC-Flags aus, triggert Sende-/Save-Pfade.
* **Motoransteuerung ist zweistufig:** Die VCU **kommandiert** den ESC mit Sollwerten aus den Gang-Tabellen (Limit, Ströme, EABS, Start-Level) und Flags (Scale/Cruise/ABS/Start-Mode); die eigentliche Feldschwächung/PID/Stromregelung liegt **im ESC**, nicht in diesem Image.
* **Begrenzungen der VCU:** Gang-Limit (Byte), Power-Limit (%), Temperaturschwelle, Strom-Grenzen pro Gang (byte-codiert), Display-Clamp-Latch (`0x2000030D`) steuert das Sollwert-Scale-Bit, kein km/h-Clamp in R3.
* **Timeout-Überwachung:** Display 0x2000030E, ESC 0x20000310/11 (je 600 ms), Zähler bis 5000 ms.

---

## 7. Funktions- und Adresstabellen (Auszug der gesicherten Objekte)

| Adresse | Funktion | Bedeutung |
|---|---|---|
| 0x08007144 | Startup | SP→SystemInit→__main |
| 0x08007184 | Clock-Init | HSE/PLL-Setup, SW=PLL |
| 0x08007420 | Literalpool | RCC/FLASH/PWR-Konstanten |
| 0x0800B4F0 | TIM2-IRQ | Tick (Flag clear), Zeitbasis |
| 0x0800B4FE / 5CA / 6CC | USART1/2/3-IRQ | RX-Ringpuffer + Frameparser |
| 0x0800BA8C / BB42 | BLE-AT | AT+FC / AT+LENAME (FIN 0x1F) |
| 0x0800C5B8 / C608 / C276 / C4F4 | BLE-TX-State | 55xx-Sender |
| 0x0800DEEA | Telemetrie-Builder | Settings-Echo + Fahrwerte (55 71/72/73-Quellen) |
| 0x0800DE88 / DEAA / DE4A / DD7C | Queue-/Sendepfade | BLE RX/TX |
| 0x0800EE76 | Display-Sonderframes | 0x8A/0x8B/0x8C-Verarbeitung |
| 0x0800EF96 | Fahrzeug-State | Flags/Mode-Verdichtung |
| 0x0800F4FA | Kommando-Prozessor | ESC-0x71 + Display-0x4C/0x35-Write |
| 0x0800F9AC / F9C6 | Prüfsummen | XOR bzw. Check-Vergleich |
| 0x0800FA94 | RX-Consumer | ESC+Display-Queues, Timeouts |
| 0x0800FE26 | 100-ms-Kette | Consumer→Prozessor→State→Frames |
| 0x0800FE3A | TX-Pump | Display+ESC-Puffer senden |
| 0x0800FE96 / 100AA / 10238 / 103AA / 103AC | ESC-Builder | 4A-Frames (11/14 × 3A/3B) |
| 0x080105A8 | Motor-Scheduler | Round-Robin der ESC-Frames |
| 0x08010648 / 107DA | Display-Builder | 0x35/39 B (3B/3A) |
| 0x08010C50/72/CB4 | Display-Queue | Vollprüfung/Enqueue/Ring-Transfer |
| 0x08016FC4 / 17084 / 17230 / 1728A / 1744C | EEPROM | Save / Read / Werks-Writer / Loader / Block0-Defaults |
| 0x08018236 / 16EC0 / 17E1A | Sonderpfade | Display-8A/8B/8C-Folgen |
| 0x080190E0 / 1914A / 19152 | Zeitbasis | TIM2-Init, Zeitholen |
| 0x080198EC | UART-Init | USART1/2/3 inkl. Baud + DMA |
| 0x08019B1A/3A/4C/5E/82 | UART-TX | generisch/BLE/ESC/Display/Dual-Keepalive |
| 0x0801BA4E / BDC4 / C1F8 | CAN | Init/Filter/Messwertpfad |
| 0x0801C700 | Mainloop | Timer-Scheduler |
| 0x0801C640 / 18718 / 1874C | Init-Steuerung | Phasen 1/3/5 |
| 0x0801876C/78/7A/7C/94/96/AE/BE/D4 | Tasks | 10…5000 ms |

*(529 Funktionen wurden automatisch identifiziert; die Tabelle listet die für Ablauf und Schnittstellen relevanten Objekte. Generic-Namen FUN_xxxx bleiben wo Semantik nicht abschließend belegt ist.)*

---

## 8. Ist jetzt „alles“ analysiert? — Ehrliche Abdeckungsbilanz

**Dekompilat-Stand (letzter Export):** 671 Funktionen · 77.826 von 93.627 Bytes = **83,1 % als Pseudocode** · 21.988 Bytes in 155 Regionen als Byte-Anhang dokumentiert (davon Tabellen/Pools/Konstanten klassifiziert). Hinweis: Mehrere Analyse-Runden mit unterschiedlichen Einsprungpunkten (PE3/PE4/PE5) wurden vereinigt (PE4-Bodies bevorzugt, um Fragmentierung zu vermeiden; PE5 ergänzte blatt-Funktionen ohne Stack-Prolog heuristisch).

**Analysiert & dokumentiert sind:**
* Datei-/Image-Struktur, Trailer/CRC, Boot-Kette, Uhr-/Init-Kette, Mainloop-Scheduler inkl. Task-Perioden
* Alle vier Kommunikationswege im Rahmen (Header/Länge/Prüfsumme/Richtung/Queues/Timeouts) und Baudraten
* BLE-Frameaufbau + AT-Pfad; ESC-Frame-Varianten + Round-Robin; Display-TX/RX-Frames + Kommandoset (Gang/Eco/Dual/Clamp/Settings-Write)
* EEPROM-Blöcke mit Ladepfad, Prüfsumme, Werks-Writer, Fabriktabelle; Persistenz-Flows
* Zustands-/Flagvariablen der VCU-Fahrlogik (soweit für Schnittstellen relevant)

**Noch NICHT vollständig bytegenau analysiert:**
1. **Semantik einzelner Bytes** in Display-TX-Feldern (einige 16-Bit-Messfelder), im Display-0x4C-Frame (Bytes 7-18), in den 0x8A/0x8B/0x8C-Frames (Inhalte), in ESC-0x71-Frames (Felder & Einheiten)
2. **CAN/BMS-Protokoll**: Bitrate, IDs, Datenfeld-Layout
3. **Regel-/Filteralgorithmen**: die mathematischen Funktionen 0x8011000–0x8016000 (Kennlinien, Filter, Rampe) — Struktur erkennbar, Details nicht vollständig rekonstruiert
4. **Sonderpfade** `FUN_08018236` (Display-0x8A-Datenfolge), `FUN_08016EC0`, `FUN_08017E1A` (Zweck nicht abschließend geklärt)
5. **EEPROM-Block 4** (Motor-Kalibrierdaten) und Details der Odometer-Wear-Leveling-Routine
6. Nicht zu diesem Image gehörend: **Bootloader 0x08000000–0x08006FFF**, **Display-Firmware**, **ESC-Firmware** selbst

---

## 9. Machbarkeit: Eigene Firmware / eigenes Modul / VESC-Nachbau

### 9.1 Eigene IVCU-Firmware
**Grundsätzlich machbar.** Alle Schnittstellen (BLE 0xAA-Protokoll, ESC 4A/71, Display 0x35/4C, EEPROM-Schema, CAN-Rolle) sind bekannt genug für eine **kompatible Neuimplementierung** auf gleicher MCU (STM32F1-Klasse, gleiche Pins/Bauds) oder modernerer Basis. Für 1:1-Verhalten wären zusätzlich nötig: exakte Display-Feldbedeutungen (§8), BMS-CAN-Details, und die Regel-/Filterkennlinien (falls die VCU sie für Anzeige/Limits nutzt).

### 9.2 Eigenes IVCU-Modul (Hardware)
**Ja für den Schnittstellenteil:** MCU-Klasse, Pins, Baudraten, EEPROM (externer I2C-Baustein mit 5 Blöcken), CAN-Transceiver, Display-/ESC-/BLE-Anschlüsse sind dokumentiert. Offen: exakte Pinbelegung des Steckverbinders (aus den GPIO-Konfigurationen ableitbar: PA2/3, PA9/10, PC10/11, I2C-Pins, CAN-Pins), Stromversorgung/Level, Signal-Schutzbeschaltung.

### 9.3 IVCU komplett in VESC nachbilden
**Für die Peripherie-Seite ja, mit Einschränkungen.**
* BLE: VESC kann per Lisp UART nutzen (`uart-start/write/read`), ein eigenes BLE-Modul (ISSC-Transparent) anbinden und die 0xAA-App-Frames selbst bedienen — **dann müssten aber die 55xx-Payloads emuliert werden** (vollständig dokumentiert, machbar).
* Display: mit den hier ermittelten Frames (0x35/39 B, XOR; RX 0x4C/19 B etc., 9600 Bd, Keep-Alive, 600-ms-Timeouts) **emulierbar**; Restunsicherheit bei unbekannten Feldern — per Mitschnitt am realen Fahrzeug validierbar.
* Motor: entfällt (VESC übernimmt FOC/Leistungsteil); VCU-seitige Limits (Gang-Tabelle, Power-Limit, Temp) lassen sich im Lisp-Skript abbilden.
* Nicht abbildbar ohne Zusatzhardware: die **12 V/Systemversorgung und das BMS-CAN-Verhalten**, die der VCU obliegen (VCU geht erst an, wenn das BMS „gesund“ meldet).

---

## 10. Vollständigkeitsmatrix der Payloads

| Frame | Richtung | Rahmen bekannt | Bytes vollständig? |
|---|---|---|---|
| 0xAA (BLE-App) | ↔ | ja | ja (öffentlich dokumentiert; RAM-Quellen verifiziert) |
| 55 41–4D, 52–54, 71–73, 79/7A | VCU→App | ja | ja (Community-Referenz) |
| 4A 11/14 3A/3B | VCU→ESC | ja | **teilweise** (Felder zu RAM zugeordnet; Einheiten/Algorithmen im ESC) |
| 71 12 B 3A/3B | ESC→VCU | ja | **teilweise** |
| 35 27 3A/3B (39 B) | VCU→Display | ja | **überwiegend** (2–3 Messfelder unklar) |
| 4C 19 B (Cmd 0x35-Familie) | Display→VCU | ja | **Kommandos 1–9 zugeordnet**, restliche Bytes offen |
| 8A/8B/8C | Display→VCU | ja | **Rahmen+Ziel bekannt**, Inhalte nur teilweise |
| Keep-Alive 10 B | VCU→ESC+Display | ja | ja (Zählerframe) |

---

## 11. Offene Punkte / nächste Schritte

1. **UART-Mitschnitt** Display↔IVCU und ESC↔IVCU am realen Fahrzeug → schließt Feld-/Zeitverhalten (und liefert CAN-Verkehr, falls CAN-Logger vorhanden).
2. **CAN-Sniffing** (BMS): Bitrate bestimmen, IDs/Layout erfassen.
3. Rekonstruktion der **Kennlinien-/Filterfunktionen** (0x8011000–0x8016000) für 1:1-Verhalten.
4. Klärung der **Sonderpfade** `FUN_08018236`/`FUN_08016EC0`/`FUN_08017E1A`.
5. Für VESC-Umbau: Emulationsskript (Lisp) + Display-Testreihenfolge (Boot-Sequenz, Fehlerzustände).

---

## 12. Quellen & Belege

**Community/Web:** Laufbursche42/tr-fw (Firmware-Patcher, Clamp-/EEPROM-/Bootloader-Doku), Laufbursche42/tr-lb-edition (BLE-Protokollreferenz, Updater), escootnow.com.au (IVCU-Taxonomie), Rydology (Firmware-Listings), escooter-stammtisch.de/-treff.de (Reverse-Threads, eKFV), Teverun After-Sale-Guide.

**REA-Evidence (Auswahl, Session 31.10.2026):** Inventar `ev_6d38674f…`; Motor-Builder `ev_4f880bbd…`; Fabrik-Writer `ev_e2b91e5e…`; Block-0-Defaults `ev_ee6d29ad…`; Loader `ev_aefda339…`; USART1-ISR `ev_66194ac5…`; 55 43-Builder `ev_777b4ada…`; AT-FIN `ev_3a9b5a03…`; CAN-Filter `ev_d28f1e90…`; Clock-Init `ev_f3476f3c…`; Display-Consumer `ev_daa1e087…`; TX-Pump `ev_9aae354b…`; Display-Builder `ev_0910e53b…`; UART-Init/Verarbeitung `ev_2ebfac98…`/`ev_911a2166…`.

## 13. Dekompilat & Quellcode-Export (Abschluss-Ergänzung)

**Ziel:** maximal mögliche Dekompilierung des Images + kommentierte Quelle.

| Artefakt | Inhalt |
|---|---|
| `AWIVCU_APP_R3_4_13_decompiled.c` | **Kommentierte Gesamtquelle** (≈802 KB): Kopf mit SHA/Memory-Map/Glossar (RAM-Objekte, Peripherie, Protokolle), 11 thematische Sektionen, 671 Funktions-Banner mit Adresse/Größe/Kurzbeschreibung + Ghidra-Pseudocode, **Byte-Anhang** (Vektortabelle als C-Array, Fabriktabelle, Block-0-Defaults, Parametertabellen, Kennlinientabelle, Deskriptorblock, Strings, alle Restregionen als annotierte Hexdumps) |
| `AWIVCU_APP_R3_4_13_function_index.csv` | Index aller 671 Funktionen (Adresse, Größe, Teile, Annotation) |
| `decomp/`, `decomp2/`, `decomp3/` | REA-Rohdekompilate je Analyse-Runde (je Ordner `functions/<adresse>.c` + `decompile-index.json` + Journal) |
| `AWIVCU_APP_R3_4_13.pe.bin … pe5.bin` | Analyse-Wrapper (PE/ARMNT) mit Stub-Sektion; PE4/PE5 mit sukzessiv mehr Einsprungpunkten |

**Zahlen:** 671 Funktionen (Vereinigung der Runden; PE4 = größte zusammenhängende Bodies, PE5 = heuristische Blatt-Funktionen). 77.826 B = 83,1 % als Pseudocode; 21.988 B Rest in 155 Regionen (Tabellen/Pools/Fragmente/Padding), vollständig im Anhang der C-Datei gelistet.

**Grenzen des Exports:** Pseudocode statt Originalquelltext; generische Namen (`FUN_xxxxxxxx`, `DAT_xxxxxxxx`); keine Garantie auf vollständige CFG in tabellemgesteuerten Bereichen; PE5-Heuristik kann Fragmente erzeugen (deshalb PE4-Body-Vorrang); nicht direkt kompilierbar (Ghidra-Typen). Semantisch weiterhin offen: CAN/BMS-Details, einzelne Frame-Bytes, Kennlinien-/Regelalgorithmen, drei Sonderpfade.

## 14. Kennlinien, Datenbereiche & Näherungsfunktionen (Ergänzung)

Details in **`AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md`**; Code in **`soc_kennlinie.c`**; Plot in **`soc_kennlinie.png`**.

Kurzfassung:
* **Datenbereiche → Funktionen → Wirkung** vollständig zugeordnet (u. a. neu: Block-0-Loader `FUN_08017784` mit **Versions-Migration** und XOR über 0x4E; C-Runtime-Bank 0x0801D2EC–0x0801D8C4 = memcpy/memset/strlen/64-Bit-Helfer/Dekomprimierer; HPRE-Shift-Tabelle = log2(AHB-Teiler) für HCLK-Berechnung; LED-Farb-Records mit je 7 RGB-Werten; SOC-Effekte: BLE/Display, LED-Farben (rot <20 %, gelb <50 %), stufenweise Leistungsfreigabe).
* **SOC-Kennlinie @0x0801DC78** (101 Punkte, 3,000–4,150 mV → 0–100 %): Näherungen mit Fehlermetriken:
  * 21 Stützstellen (5 %-Raster): **max 0,05 %SOC**
  * 5 DP-optimierte Segmente (3000/3100/3200/3511/3898/4150 mV): max 1,10 %
  * Polynom Grad 12: max 0,55 % · Grad 8: 0,86 %
  * Logistik verworfen (Kurve nahezu stücklinear, Fehler ~96 %)
* C-Funktionen: `soc_from_mv_fw/lin/seg/p21/poly`, `mv_from_soc`.

---

## 15. Werkzeuge & Endstand (Abschluss 31.10.2026)

| Artefakt | Zweck | Verifikationsstand |
|---|---|---|
| `ivcu_fw_tool.py` | HEX validieren/patchen (CRC-16 + `:07AAA555`-Trailer-Neuberechnung) | **Selbsttest 3/3 PASS** (Version 3.4.13, CRC 0xE349, Roundtrip byte-identisch, Patch+Datenablage neu berechnet) |
| `ivcu_protocol.py` + `ivcu_sim.py` | Codec aller drei Links + Frame-Simulator | **Selbsttests PASS** (CRC-Vektoren, 14 Build↔Parse-Runden, 55-Frame-Stream reparst) |
| `eeprom_images.py` | EEPROM-Block-0/1-Images (Prüfsummen) | **Selbsttest 22/22 PASS**; Block 1 byte-identisch zur Fabrik-ROM-Tabelle |
| `ghidra_apply_annotations.py`, `build_callgraph.py`, `callgraph.dot`/`_reduced.dot` | Ghidra-Labels, Architektur-Graph | py_compile OK; Graph 555 Knoten/1451 Kanten |
| `ivcu_linker.ld`, `startup_ivcu.c` | Gerüst Eigen-Firmware (STM32F1-Klasse) | – |
| **`ivcu_fw/`** | **Eigene IVCU-Firmware (Weg 1):** Display + BLE + VESC in einem Gerät, ESP32 entfällt; Lisp unverändert | **Kompiliert** (Arm GCC 14.2, beide Linker-Varianten, 0 Warnungen; `build.py` + CI); Vektortabelle verifiziert; **Bench offen** |
| **`ESC_Emulation_VESC.md` + `vesc_esc_emulator.lisp`** | **Weg 2:** Stock-IVCU bleibt; VESC emuliert den Original-ESC (`4A`/`71`, 9600) inkl. Dual-Aufbau (uBox) | Frame-Layouts belegt; Lisp mit `DUAL`/CAN-Spiegelung; **Sniffer/Bench offen** |
| **`ivcu_esc_sniffer.py`** | Dekoder für ESC-UART-Mitschnitte (klärt Byte [1], Einheiten [4..9], Skalierung [10]) | **Selbsttest 7/7 PASS** + Hexdump-Smoketest PASS |
| **`can_sniffer_esp32/`** | Passiver BMS-CAN-Sniffer (ESP32 + SN65HVD230, Listen-Only) | **Kompiliert** (PlatformIO, 0 Warnungen); **am Fahrzeug zu betreiben** |
| **`UBox_Dual_Adapterplan.md`** | Kabelbaum-/Inbetriebnahmeplan UBox-Dual (Weg 2) | Doku-basiert (Spintend-Manual + Foren) |
| `callgraph.svg` / `callgraph_reduced.svg` | Architektur-Graph gerendert (Graphviz 16.1) | aus den `.dot`-Dateien erzeugt |
| `bridge_esp32/` + `Teverun_IO_Bridge_Hardware.md` | ESP32-Bridge: Firmware + Hardware | **Kompiliert** (PlatformIO espressif32 8.0.0 / Arduino 3.3.12, 0 Warnungen; RAM 6,8 % / Flash 22,6 %); **Bench offen** |
| `vesc_ivcu_emulator.lisp` + `VESC_IVCU_Ersatz_Anleitung.md` | VESC-Ersatz (Regelung/Mapping/Hardware) | Code-basiert; **Bench-Validierung offen** |
| `PINOUT.md` | Pinbelegung mit Quellen | USART3-Korrektur eingearbeitet |

**Korrekturen der Endrunde (in allen Dokumenten eingearbeitet):**
* **USART3 = PB10/PB11** (Registerbefund GPIOB-Masken Bit10/11; frühere PC10/PC11-Angabe widerlegt)
* **Display-0x35-Layout korrigiert:** ab Byte 12 um +1 verschoben – `[12]=Spiegelflags`, `[13]=Speed`, `[14]=SOC`, `[26..28]=Odometer`, `[30]=Wheel`, `[31]=Pack`, `[32]=Polpaare`, `[33]=(Temp−80)/5`, `[34]=Start`, `[35]=Limit`, `[36]=Power`, `[37]=Rear-Strom`; Messfelder `[17..18]/[20..21]/[22..23]/[24..25]`
* **ESC→VCU `0x71` = 13 Byte** (11 Daten + Typmarker + XOR; ISR sammelt 13)
* **ESC-TX-Eigenheit 0x11:** auf der Leitung `[0..15]+Checksumme[19]`, XOR aber über alle 19 Pufferbytes

**Weiterhin nur am Fahrzeug/Scope klärbar:** Rotationszeit-Feld endgültig fixieren (Kalibrierlauf), LED-Pins/-Anzahl, CAN-BMS-IDs/-Layout, Semantik `0x8A/0x8B/0x8C`.

---

## 16. Web-Nachtrag (31.10.2026) – Ergänzungen zu offenen Punkten

**Neu ausgewertete Quellen:** tr-fw README (vollständig, inkl. „Chip and hardware access"), tr-lb-edition (Kommandokarte/Implementierungsnotizen), Community-Beiträge.

### 16.1 MCU geklärt
**GD32F303-Klasse (Cortex-M4F, FPU)** – siehe §2. SWDIO/SWCLK-Pads; RDP-/Optionsbyte-Status nicht-destruktiv prüfbar; Firmware-Dump nur per SWD (kein BLE-Readback).

### 16.2 Geschwindigkeits-/Rotationszeit-Kette (verifiziert)
* Formel (VCU und App identisch): `speed_kmh = 287 · wheel / speedRaw`, `wheel = 55 71 t[6] × 0,1` (Zoll-Code), `speedRaw = 55 72 t[15..16]` in **0,1 ms**; `speedRaw ≥ 3000` oder `speed ≤ 0,5` ⇒ 0.
* Das **Display** rechnet ebenfalls `wheel × 287 / rotation_time`; die eKFV-Anzeige-Kompensation skaliert die gesendete Rotationszeit mit `100/W` (W = realer Raddurchmesser in RAM `0x2000029D`; R5-Patchstellen 0x0801078E/0x08010ABA).
* ⇒ Unsere Bridge-/Lisp-Formel `rot = WHEEL_CODE·287 / speed_kmh` ist bestätigt; **das Byte-Feld im `0x35`-Frame bleibt per Kalibrierlauf zu fixieren** (Kandidaten [17..18]/[20..21]/[22..23]/[24..25]).

### 16.3 BLE-Kommandokarte (vollständig; in der Bridge-Firmware umgesetzt)
| Cmd | Zweck | Kern |
|---|---|---|
| 0x01 | Handshake/Keep-Alive (~6,5 s) | `AA 01 10 00 FF…FF`; **0xFF = „keine Änderung"** |
| 0x02 | Deep Sleep | `[11]=1` |
| 0x03 | Lademodus | `[16]=mode` |
| **0x08** | **LED** an/aus, Modus, RGB | `[2]=on, [3]=Mode, [4..6]=RGB, [7]` |
| **0x18** | Settings-Write | a[2]=Modus(0/2), a[3]=Gang bzw. Profil-Index, a[4] Controls, a[5] Polpaare, a[6] Wheel×10, a[7] Temp, a[8]/[9] Assist-Nibbles, a[10] Gang-Limit, a[11] Haupt-Limit, a[12]/[13] Front-/Rear-Strom, a[14] Spannungscode, a[15] Pack V, a[16] Flags, a[17] fControl, a[18] Sleep/PowerOff — gearweise, ~200 ms Abstand |
| 0x1A | Custom-Key-Funktion | `[6]`=1…11 (u. a. Motor-Modus, Kickstart, Cruise auto/manuell, Limit, Lock, TCS, Licht, Lichtmodus, Boost, EABS) |
| 0x1C | RTC-Sync | Jahr%100, Monat, Tag, Std, Min, Sek |
| 0x1F | FIN/Identität | 16 ASCII |
* **Spannungscode-Tabelle (a[14]/Block1[6]): 36 V→30, 48 V→39, 52 V→42, 60 V→48, 72 V→60, 84 V→69 — Code ≠ Volt!** (Fabrik-Code 0x30 = 60-V-Pack.)
* Motor-Modus: Schreiben `a[4]` Bit7 = rearMotorOn, `a[17]` Bit7 = dualMotor; Rückmeldung in `55 72` (t[3] Bit3 dual, t[11] Bit3 rear).

### 16.4 Bootloader / Region (Bestätigungen)
OTA-Fenster `[0x08007000, 0x0801EFFF]`; App-Valid `0x5A5A5A5A` @0x0801F800 (INFO löscht zuerst, FINISH schreibt erst nach CRC-Pass); Update-Request `0xA5A5A5A5` @0x0801F000; CRC-16 (poly 0x8005), keine Signatur. Regions-Write-Protection (TDE) bestätigt; **Front-/Rear-Stromlimits werden auf eKFV zusätzlich im ESC auf 0 gezwungen** — mit VESC entfällt diese Ebene (unsere Mapping-Tabelle nutzt die Werte daher wieder).

### 16.5 Weiterhin offen (keine öffentliche Quelle gefunden)
* **BMS-CAN:** nur „Smart BMS 2.0"/CAN-Bus-Marketing und Community-Hinweise; **keine IDs/Layouts öffentlich** → Sniffer am Fahrzeug nötig.
* **LED-Hardware:** Firmware = adressierbare RGB-Kette (Bit-Bang) + BLE-Cmd 0x08; Community zeigt LED-Streifen mit Steckverbindern; **Anzahl/Zonen/Pins offen**.
* **Stecker-Pinout IVCU (M8):** nur in Bilddiagrammen (eScootNow/Voro) → am Fahrzeug verifizieren.
* **Rotationszeit-Feld:** endgültig per Kalibrierlauf (§5 im VESC-Dokument).

---

## 17. Ausbaustufen 31.10.2026 – eigene IVCU-Firmware & ESC-Emulation (statt ESP32)

Zwei umsetzbare Wege, die Original-IVCU **ohne ESP32-Bridge** mit einem VESC zu betreiben (beide werkbank-vorbereitet, ohne Fahrzeug erstellt):

### 17.1 Weg 1 – `ivcu_fw/` (eigene Firmware auf der IVCU) – empfohlen
Ersetzt den Original-App-Bereich; vereint Display (USART3, 9600), Stock-BLE/App (USART1, 115200) und VESC (USART2, 115200, 8-Byte-Bridge-Protokoll). Das VESC-Lisp (`vesc_ivcu_emulator.lisp`, MODE 0) bleibt **unverändert**. Enthält: Makefile (arm-none-eabi, entschieden), Vollersatz-Linker ab `0x08000000` (Standard) + Bootloader-Fenster-Variante (`0x08007000`, Magic-/CRC-Hinweise), Startup/Vektortabelle, IRQ-UART-Ringe, komplette Protokoll-/State-Machine-Logik (Port der Bridge; BLE-Kommandos 0x08/0x18/0x1A/0x1F enthalten). Status: **kompiliert** (Arm GNU Toolchain 14.2; beide Linker-Varianten, 0 Warnungen; `build.py`/PlatformIO/CI vorhanden), Vektortabellen verifiziert; **Bench-Validierung offen**. Details: `ivcu_fw/README.md`.

### 17.2 Weg 2 – `ESC_Emulation_VESC.md` + `vesc_esc_emulator.lisp`
Stock-IVCU bleibt **100 % Werkszustand** (Display/App/EEPROM/LED unverändert); der VESC hängt am ESC-Port (USART2, 9600) und emuliert den Original-ESC: `0x4A`-Settings (Gang/Limits/Ströme/Flags; Feldtabellen aus `FUN_08010238`/`FUN_0800FE96`/`FUN_080103AC`/`FUN_080100AA`) empfangen, `0x71`-Status (13 B, Subtyp `3A`/`3B`, Alive ≤ 600 ms je Typ; ISR `FUN_0800B5CA`/Consumer `FUN_0800FA94`) senden. **Gas/Bremse hängen nicht an der IVCU (kein ADC in deren Peripherie) ⇒ direkt am VESC-ADC.** Offen: Byte [1] sowie Einheiten/Skalierung der ESC-Felder `[4..10]`; die **Byte-Zuordnung ESC[3..11]→RAM/Anzeige ist jetzt belegt** (`FUN_0800F4FA`; [11] Bit0 = Dual-Flag, steuert die `0x11`/`0x14`-Variantenwahl über `FUN_080105A8`).

---

## 18. GitHub-Upload-Ordner (`teverun-fighter-vesc/`)

Für die Veröffentlichung als Community-Repo wurde ein kompletter Upload-Ordner
angelegt: `teverun-fighter-vesc/` mit README (EN + 🇩🇪 Kurzfassung, Fokus auf
**bislang nicht öffentlich bekannte Punkte**), LICENSE (Docs CC BY-NC-SA 4.0,
Code MIT) und `.gitignore`, dazu:

* `docs/` – alle Tiefendokumente (dieser Text, Analyse, Kennlinien, PINOUT,
  ESC-Emulation, VESC-Anleitung, Bridge-Hardware, uBox-Adapterplan)
* `firmware/` – `ivcu_fw/`, `bridge_esp32/`, `can_sniffer_esp32/` (+ Skelett)
* `lisp/` – beide VESC-Skripte
* `tools/` – Codec/Simulator/Sniffer/HEX-/EEPROM-Werkzeuge + SOC-Dateien
* `analysis/` – Dekompilat, Funktionsindex, Strings, Callgraphs (.dot/.svg)

**Bewusst nicht** enthalten: das Original-Firmware-Image (HEX/BIN) – stattdessen
SHA-256-Verweis im README. Bereit zum `git init && git push` (Stand: ~2,9 MB).

* **Veröffentlicht (31.10.2026):** https://github.com/MarcHelmers/teverun-fighter-vesc (public, Branch `main`)

---

*Alle Angaben: statische Analyse eines vorliegenden Firmware-Images; keine Laufzeitbeobachtung am Fahrzeug. Flashen/Umbauten auf eigenes Risiko. Ergänzung 31.10.2026: vollständiger Dekompilat-Export, kommentierte Gesamtquelle, Werkzeug-/Bridge-/VESC-Paket, Web-Nachtrag §16, Ausbaustufen §17 (Eigen-IVCU-Firmware `ivcu_fw/`, ESC-Emulation), Upload-Ordner §18.*
