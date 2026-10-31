/*
 * can_sniffer_config.h -- Pins und Bitrate des BMS-CAN-Sniffers
 * ============================================================================
 *  Hardware: ESP32 + SN65HVD230 (3,3-V-CAN-Transceiver) ODER TJA1050 mit
 *  Pegel-/Versorgungshinweis. WIR NUR PARALLEL AM BUS MITLESEN (Listen-Only)!
 *
 *  Verkabelung (SN65HVD230):
 *    VCC  -> 3,3 V (ESP32)
 *    GND  -> GND (gemeinsame Masse mit Roller!)
 *    CTX  -> GPIO5 (ESP32 TX)
 *    CRX  -> GPIO4 (ESP32 RX)
 *    CANH -> BMS-Bus CANH (parallel, am besten am BMS-Stecker abgreifen)
 *    CANL -> BMS-Bus CANL
 *  Terminierung: der Roller-Bus ist bereits terminiert (BMS+IVCU-Seite);
 *  zusaetzliche 120 Ohm nur bei Bedarf/kurzen Stichleitungen.
 * ============================================================================
 */
#pragma once

#define PIN_CAN_TX   5
#define PIN_CAN_RX   4

#ifndef CAN_BITRATE
#define CAN_BITRATE  500000      /* Teverun-BMS-Rate unbekannt: 250k/500k testen */
#endif

#define SNIFFER_SERIAL_BAUD 115200
