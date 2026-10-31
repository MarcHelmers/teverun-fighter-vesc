# UBox-Dual-Adapterplan (Weg 2) – Kabelbaum & Inbetriebnahme

**Ziel:** Spintend **UBOX ALU Lite 100V 100A ×2** am Teverun-Roller betreiben,
während die Original-IVCU (Weg 2, ESC-Emulation) unverändert bleibt.
Überblick/Belegung: `ESC_Emulation_VESC.md` §5. Skript: `vesc_esc_emulator.lisp`.

## 1. Teileliste (vorbereiten)

| # | Teil | Menge | Hinweis |
|---|---|---|---|
| 1 | Spintend UBOX ALU Lite 100V 100A – **Dual-Kit** (Main + Second) | 1 | inkl. Dual-Verbindungsleitung (8-Pin-UART/Transfer) |
| 2 | Stecker-Set passend zum Roller (Motor-Phase 4 mm, Hall, Gas, Bremse, Akku) | 1 | **am Fahrzeug ablesen** – Steckertypen nicht öffentlich dokumentiert |
| 3 | 3-adrige Leitung Gas/Bremse → ADC (0,25 mm²) | ~1 m | verdrillt, verpolsicher crimpen |
| 4 | ggf. **E-wheel ADC Adapter V3** | 1 | sicherste Option bei 5-V-Gebern; Bremslicht/Hupe inkl. |
| 5 | Alternativ: Widerstände 10 k/20 k für Teiler | – | je Signalleitung (falls ohne Adapter) |
| 6 | Step-Down 28–90 V → 12 V (nur falls Licht/Hupe) | 1 | Lite-Boards haben **keine** 12-V-Ports |
| 7 | XT90-Stecker/Buchse, Sicherung passend | 1 | zwischen Pack und Main |
| 8 | Schrumpfschlauch, Aderendhülsen, Kabelbinder | – | – |

## 2. Kabelbaum (Reihenfolge des Aufbaus)

1. **Akku:** Pack → Sicherung → XT90 → **Main**; vom Main weiter zum **Second**
   (gemeinsame Plus/Masse-Leitung des Dual-Kits). Querschnitt wie Original.
2. **Motoren:** Heckmotor an einem ESC, Frontmotor am anderen – **je** Motor
   Phase U/V/W (4-mm-Bullet, Reihenfolge egal) + Hallkabel
   (Rot=5 V, Schwarz=GND, Weiß=Temp, H1–H3). Motor-Temp-Leitung mit aufstecken!
3. **Gas** → Main-ADC-Port: **3,3 V / GND / ADC1** (Geber bevorzugt mit 3,3 V
   versorgen). **Bremse** → **GND / ADC2**.
   ⚠️ ADC strikt ≤ 3,3 V – bei 5-V-Gebern Adapter (Umschalter auf 5 V) oder
   Teiler verwenden und **vorher messen**.
4. **IVCU-Link:** IVCU-ESC-Stecker (USART2, PA2/PA3) → **COMM** des Main:
   **TX↔RX kreuzen**, GND verbinden. (9600 Bd setzt das Lisp-Skript.)
5. **Dual-Verbindung:** CAN/Transfer-Leitung Main ↔ Second gemäß Kit.
6. **Zündung:** **Ignite**-Port brücken ODER PWR.BTN-Taster als Roller-Zündtaster
   – **niemals beides**.
7. Optional: NRF-Dongle (BLE) am Main; USB-C bleibt für VESC Tool frei.

## 3. Konfiguration (VESC Tool, USB am Main)

1. Firmware: Stand **≥ 6.05** (LispBM); Modell-FW von Spintend verwenden –
   **nie blind updaten**.
2. Motors FOC: beide Kanäle einzeln detektieren; **Polpaare = 15**, Rad 254 mm
   (10"). Second ESC: gleiche Settings, **App = „None"**.
3. App Main: **„None"** (das Lisp regelt); UART-Baud **9600**;
   „Enable Permanent UART" prüfen.
4. `vesc_esc_emulator.lisp` hochladen, Konfig oben anpassen:
   **DUAL = 1**, `CAN_SLAVE_ID` = Controller-ID des Second (eindeutig setzen!).
5. Spannung/Limits: 16S-Pack (3,0/3,4/4,25 V je Zelle), Temperaturgrenzen wie
   im Skript.

## 4. Inbetriebnahme-Checkliste (ohne Fahren)

- [ ] ADC-Mapping in VESC Tool **ohne Motor**: Gas/Bremse-Balken laufen sauber
- [ ] Display bootet ohne „ESC-Fehler" (0x71-Alive der 3A/3B-Frames läuft)
- [ ] Gangwechsel im Display ändert das Limit im Lisp-Log (4A-Frames kommen an)
- [ ] Dual-Spiegelung: Strom am Second steigt synchron (CAN prüfen)
- [ ] Erst dann: Antrieb am Prüfstand, dann Straße

*Quellen: Spintend UBOX User Manual (manuals.plus), VESC-Forum, eigene Analyse
AWIVCU_APP R3.4.13. Stand 31.10.2026 – vor dem Anschluss Fahrzeugdatenblätter
und Steckerbelegungen verifizieren.*
