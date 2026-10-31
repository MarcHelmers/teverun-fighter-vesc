/*
 * ivcu_config.h -- Konfiguration der eigenen IVCU-Firmware
 * ============================================================================
 *  Alle fahrzeug-/anlagenspezifischen Werte. 3,3-V-Logik! Kein Originalcode.
 *
 *  Hardware (aus der Analyse AWIVCU_APP R3.4.13, siehe ../PINOUT.md):
 *    USART1 PA9/PA10   115200  <-> Stock-BLE-Modul (Teverun-App, 0xAA/0x55)
 *    USART2 PA2/PA3    115200  <-> VESC (Bridge-Protokoll 54 cmd ... XOR)
 *                              ^ Original: 9600 zum Stock-ESC; hier bewusst
 *                                115200, damit das bestehende Lisp-Skript
 *                                (vesc_ivcu_emulator.lisp, MODE 0) passt.
 *    USART3 PB10/PB11  9600    <-> Stock-Display (0x35-Frames, 0x4C/8A/8B/8C)
 * ============================================================================
 */
#pragma once

#include <stdint.h>

/* ---------------------------------------------------------------------------
 * 1) BAUTRATEN (abgeleitete Uhren: SYSCLK 48 MHz, APB1 12 MHz, APB2 24 MHz;
 *    BRR-Werte siehe uart.c -- bei anderem Takt anpassen!)
 * ------------------------------------------------------------------------- */
#define CFG_BAUD_BLE      115200u
#define CFG_BAUD_VESC     115200u
#define CFG_BAUD_DISPLAY  9600u

/* ---------------------------------------------------------------------------
 * 2) FAHRZEUG-KONSTANTEN (Werkswerte R3.4.13; je Modell anpassen!)
 * ------------------------------------------------------------------------- */
#define CFG_WHEEL_CODE    100       /* Raddurchmesser-Code: 10.0" = 100 */
#define CFG_POLE_PAIRS    15        /* Werk-Rohwert 30 -> 15 Paare (kalibrieren) */
#define CFG_TEMP_LIMIT    120       /* Schutz-Temperatur (0x78) */
#define CFG_FW_VER_MAJ    3
#define CFG_FW_VER_MIN    4
#define CFG_FW_VER_PAT    13        /* wir melden uns als 3.4.13 */
#define CFG_HW_VER_A      1
#define CFG_HW_VER_B      1
#define CFG_PACK_S        16        /* 13/14/16/20 fuer 48/52/60/72 V */

/* Gangtabelle Werksdefault (wird zur Laufzeit durch App-Settings 0x18 ersetzt) */
#define CFG_GEAR_LIMIT_KMH  { 15, 20, 25, 35, 45 }
#define CFG_GEAR_CUR_A      { 15, 20, 25, 30, 55 }

/* ---------------------------------------------------------------------------
 * 3) DISPLAY-FRAME (0x35)
 * ------------------------------------------------------------------------- */
/* Clamp/Scale-Bit in Byte [4], Bit1: R3 = offen (0x00); eKFV-aehnlich = 0x02 */
#define CFG_CLAMP_SCALE_BIT   0x00

/* Rotationszeit: [8..9] (u16 BE) -- VERIFIZIERT per Display-Firmware-Analyse:
 *   Display rechnet speed = wheel([30]) * 287 / rot (rot in 0,1 ms);
 *   rot < 5 => 0x640, rot > 2999 => 0. => rot = WHEEL_CODE*287/speed_kmh.
 * Alt-Kandidatenfelder (tragen andere ESC-u16-Daten) bleiben aus. */
#define CFG_ROT_FIELD_17_18   0
#define CFG_ROT_FIELD_20_21   0
#define CFG_ROT_FIELD_22_23   0
#define CFG_ROT_FIELD_24_25   0
#define CFG_ROT_MAX           0xFFFFu   /* Stillstands-Marker (>=3000 genuegt) */

/* ---------------------------------------------------------------------------
 * 4) TIMING (ms)
 * ------------------------------------------------------------------------- */
#define CFG_MS_DISPLAY_TX     100
#define CFG_MS_KEEPALIVE      100
#define CFG_MS_BLE_TELEMETRY  200
#define CFG_BLE_GREET_TIMEOUT 8000      /* ohne App-Traffic: Stream stoppen */
#define CFG_VESC_TIMEOUT      1000      /* ohne VESC-Frame: Speed -> 0 */

/* ---------------------------------------------------------------------------
 * 5) VERSIONSAUSGABEN (optional)
 * ------------------------------------------------------------------------- */
/* 0 = still (empfohlen, USARTs sind belegt); 1 = Kennzeichen via Status-LED */
#define CFG_HEARTBEAT_LED     0
