# Pinout -- IVCU (Teverun, Firmware AWIVCU_APP R3.4.13)

Stand: 2026-10-31
Basis: Ghidra-Dekompilat `decomp/` + Analysen `AWIVCU_APP_R3_4_13_Doku_FINAL.md`
MCU: GD32F303-Klasse (ARM Cortex-M4F mit FPU; STM32F1-artige Peripherie-Karte
mit GPIOA-D, USART1/2/3, I2C1, CAN1, DMA1) -- belegt ueber RCC 0x40021000,
AFIO 0x40010004, GPIOA 0x40010800, USART1 0x40013800, USART2 0x40004400,
USART3 0x40004800, I2C1 0x40005400, CAN1 0x40006400, DMA1 0x40020000.
FPU/VFP-Nutzung + Flash-Latenz-Bits jenseits STM32F103; Community-Doku nennt
explizit "GD32F303-class part" (tr-fw README, Chip and hardware access).
SWD-Pads (SWDIO/SWCLK) vorhanden; RDP-/Optionsbyte-Status vor einem
Firmware-Dump nicht-destruktiv pruefbar.

> **Pegel- und Massehinweis:** Alle MCU-Signale sind **3,3-V-CMOS** -- niemals
> 5 V direkt anlegen. **Gemeinsame Masse** aller Teilnehmer (BLE-Modul, Display,
> ESC, EEPROM, CAN-Transceiver, BMS) ist zwingend; fuer 5-V-Geraete
> Pegelwandler verwenden. CAN-Transceiver-Versorgung vor dem Anschluss pruefen.

---

## 1. Signaltabelle

| Signal | MCU-Pin | Richtung | Level | Baud | Angeschlossenes Teil | Quelle (Datei + Adresse) |
|---|---|---|---|---|---|---|
| USART1_TX | **PA9** | Ausgang | 3,3 V | **115200** | BLE-Modul / App (RX des Moduls) | `decomp/functions/0x80198ec.c` -- FUN_080198EC @ 0x080198EC (Zweig 0x40013800, Baud 0x1C200) |
| USART1_RX | **PA10** | Eingang | 3,3 V | 115200 | BLE-Modul / App (TX); RX via DMA1-Kanal 5 (Ringpuffer 200 B @ 0x20001F88) | ebd.; `AWIVCU_APP_R3_4_13_Doku_FINAL.md` Abschn. 2.1 |
| USART2_TX | **PA2** | Ausgang | 3,3 V | **9600** | Motorcontroller / ESC (RX) | `decomp/functions/0x80198ec.c` (Zweig 0x40004400, Baud 0x2580) |
| USART2_RX | **PA3** | Eingang | 3,3 V | 9600 | Motorcontroller / ESC (TX); RX per Interrupt (NVIC IRQ38) | ebd.; NVIC-Setup via FUN_08007462 (`decomp/functions/0x8007462.c`) |
| USART3_TX | **PB10** | Ausgang | 3,3 V | **9600** | Display (RX) | `decomp/functions/0x80198ec.c` (Zweig 0x40004800, GPIOB-Basis 0x40010C00, Maske Bit10, Baud 0x2580), NVIC IRQ39 |
| USART3_RX | **PB11** | Eingang | 3,3 V | 9600 | Display (TX); RX via DMA1-Kanal 7 (Ringpuffer 200 B @ 0x20002118) | ebd. (Maske Bit11); `AWIVCU_APP_R3_4_13_Doku_FINAL.md` Abschn. 2.1 |
| I2C1_SCL | **PB6** *(Default)* **oder PB8** *(I2C1-Remap)* -- **muss am Fahrzeug verifiziert werden** | Takt (Open-Drain) | 3,3 V (Pull-ups nach 3,3 V) | ~100 kHz (typ.) | externes I2C-EEPROM (24Cxx-Klasse), Slave 7-bit 0x50 / Schreibbyte 0xA0 | Adressierung: `decomp/functions/0x80188ba.c` -- FUN_080188BA @ 0x080188BA; **Pinbelegung steht NICHT sicher im Code** |
| I2C1_SDA | **PB7** *(Default)* **oder PB9** *(I2C1-Remap)* -- **muss am Fahrzeug verifiziert werden** | bidirektional (Open-Drain) | 3,3 V | ~100 kHz (typ.) | externes EEPROM (Bloecke bei Wortadresse 0x00/0x50/0x88/0x94/0xA0/0xB0) | wie oben; Blockadressen: `decomp/functions/0x8016fc4.c` (FUN_08016FC4) |
| CAN1_RX | **PB8** *(CAN-Remap; Registerbefund)* **oder PA11** *(Default ohne Remap)* -- **muss am Fahrzeug verifiziert werden** | Eingang | 3,3 V MCU-seitig; Busseite gemaess Transceiver (meist 5 V, CANH/CANL) | nicht statisch ermittelt (CAN1 0x40006400) | BMS ueber CAN-Transceiver | Init: `decomp/functions/0x801ba4e.c` -- FUN_0801BA4E @ 0x0801BA4E (Pinmasken Bit8/Bit9); Filter: FUN_0801BDC4 |
| CAN1_TX | **PB9** *(CAN-Remap; Registerbefund)* **oder PA12** *(Default ohne Remap)* -- **muss am Fahrzeug verifiziert werden** | Ausgang | wie CAN1_RX | wie CAN1_RX | BMS ueber CAN-Transceiver | wie oben |
| TIM2 (intern) | -- (kein Pin) | -- | -- | -- | interne Zeitbasis, NVIC IRQ28 (Handler loescht nur Update-Flag) | `AWIVCU_APP_R3_4_13_Doku_FINAL.md` Abschn. 2.1 |

### Fussnoten zur Ableitung

* **USART3-Pins (korrigiert 31.10.2026):** Der USART3-Zweig konfiguriert im
  Dekompilat die GPIO-Basis `0x40010C00` (GPIOB) mit Pin-Masken Bit10/Bit11
  (decomp/functions/0x80198ec.c, Zeilen 101/105). Nach STM32F1-Standardlayout
  ergibt das **PB10/PB11** (USART3 ohne Remap; PB10=TX, PB11=RX). Eine
  fruehere Annahme PC10/PC11 stammte aus einem Basis-Adress-Irrtum und ist
  widerlegt (GPIOC 0x40011000 wird im gesamten UART-Init nicht verwendet).
  Am Fahrzeug trotzdem einmal per Durchgang/Mitschnitt bestaetigen.
* **USART1-Zusatzpins:** Der USART1-Zweig konfiguriert zusaetzlich Pin-Masken
  Bit11/Bit12 (PA11/PA12; in der Original-FW z. B. fuer CTS/RTS-Funktionen
  denkbar) -- fuer eine Nachbildung nicht zwingend erforderlich.
* **I2C1/CAN1-Remap-Konflikt:** PB8/PB9 koennen (je nach AFIO_MAPR) entweder
  fuer I2C1-Remap **oder** fuer CAN1-Remap genutzt werden -- beide gleichzeitig
  sind auf denselben Pins nicht moeglich. Der Registerbefund fuer CAN1
  (Pinmasken Bit8/Bit9) spricht fuer PB8/PB9; dann verbleiben fuer I2C1
  tendenziell PB6/PB7. **Beides vor Rekonstruktion durchmessen.**
* **EEPROM (extern):** Transfers laufen ueber I2C1; Slave-Schreibadresse 0xA0
  (7-bit 0x50), 16-bit Wortadresse (Hi, Lo), Schreibseiten <= 32 Byte
  (decomp/functions/0x80188ba.c und 0x8018ffe.c). Blockbelegung:
  0x00/80 B, 0x50/56 B, 0x88/12 B, 0x94/12 B, 0xA0/16 B, 0xB0/6 B.

## 2. Quellen

| Quelle | Inhalt |
|---|---|
| `decomp/functions/0x80198ec.c` (FUN_080198EC @ 0x080198EC) | UART-Init: Clocks, GPIO, Baud, NVIC fuer USART1/2/3 |
| `decomp/functions/0x8007462.c` (FUN_08007462) | NVIC-Prioritaet/Enable (IRQ37/38/39 fuer USART1/2/3) |
| `decomp/functions/0x80188ba.c`, `0x8018ffe.c`, `0x8018a0e.c` | I2C1-Datenpfad und EEPROM-Adressierung |
| `decomp/functions/0x801ba4e.c`, `0x801ba92.c`, `0x801bdc4.c` | CAN1-Init und -Filter |
| `decomp/functions/0x8016fc4.c`, `0x8017230.c`, `0x801744c.c`, `0x8017784.c`, `0x8017cde.c` | EEPROM-Bloecke, Werksdefaults, Pruefsummen |
| `AWIVCU_APP_R3_4_13_Doku_FINAL.md` (Abschn. 2/2.1) | Zusammenfassung Kanaele, Baudraten, DMA-Zuordnung |
