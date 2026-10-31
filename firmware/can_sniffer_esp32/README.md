# can_sniffer_esp32 – passiver BMS-CAN-Mitschnitt

**Zweck:** Die CAN-IDs und das Datenlayout des Teverun-BMS-Busses klären – der
letzte große offene Punkt der Analyse („Smart BMS" spricht CAN mit der IVCU;
öffentlich ist kein Protokoll dokumentiert). Der Sniffer läuft **Listen-Only**:
Er sendet **nichts** und kann den Roller-Bus nicht stören.

## Hardware

| Teil | Bemerkung |
|---|---|
| ESP32 DevKit (beliebig, z. B. esp32dev) | PlatformIO-Projekt in diesem Ordner |
| SN65HVD230-Modul (3,3-V-CAN-Transceiver) | direkt am ESP32; VCC = 3,3 V |
| 4 Jumperleitungen | CTX/CRX + Versorgung |
| 2 Adern zum Bus | CANH/CANL am BMS-Stecker abgreifen (parallel) |

**Verkabelung (SN65HVD230):**

```
SN65HVD230        ESP32            Roller (BMS-Bus, parallel)
  VCC   ────────── 3V3
  GND   ────────── GND ─────────── GND (gemeinsame Masse!)
  CTX   ────────── GPIO5
  CRX   ────────── GPIO4
  CANH  ─────────────────────────── CANH
  CANL  ─────────────────────────── CANL
```

> Der Roller-Bus ist an BMS- und IVCU-Seite bereits mit 120 Ω terminiert –
> in der Regel **keine** zusätzliche Terminierung nötig. Bei Stichleitungen
> > 30 cm ggf. einen 120-Ω-Widerstand am Sniffer testen.

## Bauen & Starten

```
cd can_sniffer_esp32
pio run -t upload        # flashen (USB)
pio device monitor -b 115200
```

Bitrate: Teverun-BMS-Rate ist **unbekannt** → in `platformio.ini`
(`-DCAN_BITRATE=…`) **250000** und **500000** durchprobieren; kommt nichts an,
auch 125000/1000000 testen. Bei falscher Rate erscheinen keine gültigen Frames.

## Ausgabe interpretieren

```
# BMS-CAN-Sniffer aktiv (Listen-Only), Bitrate 500000
t=5231  id=0x123  ext=0  dlc=8  data=00 11 22 33 44 55 66 77
```

Vorgehen am Fahrzeug:
1. Sniffer am BMS-Bus anschließen, **Zündung an** (BMS muss wach sein).
2. 2–3 Minuten loggen (Terminal-Mitschnitt in Datei speichern).
3. IDs und Perioden sichten: BMS-Broadcast ist typisch mit 100–1000 ms Takt;
   Ladezustand/Zellen/Strom ändern sich bei Last (Licht an, Motor am Prüfstand).
4. Für die Zuordnung: Spannung (Pack 60 V), Strom (Vorzeichen!), SOC (~80 %),
   Temperaturen, Zellzahl (16) als Zahlenmuster in den Payloads suchen –
   danach ggf. ein kleines Decoder-Tool wie `ivcu_esc_sniffer.py` bauen.

## Grenzen

* Nur Mitschnitt – keine Deutung. Ein Decoder entsteht erst, wenn die IDs
  bekannt sind (kann danach als Python-/Lisp-Tool ergänzt werden).
* Den UART-ESC-Bus (9600) loggt dieses Gerät **nicht** – dafür gibt es
  `../ivcu_esc_sniffer.py` (arbeitet auf Logic-Analyzer-/UART-Logs).

*Statische Analyse-Grundlage: AWIVCU_APP R3.4.13 (CAN1 0x40006400, Filter
FUN_0801BDC4); alles auf eigene Verantwortung.*
