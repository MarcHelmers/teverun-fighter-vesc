// ============================================================================
//  bridge_config.h  -  Konfiguration der Teverun-IO-Bridge (ESP32)
//  Teil des Projekts "bridge_esp32" (PlatformIO / Arduino-ESP32)
//  Alle Werte an das eigene Fahrzeug anpassen. 3,3-V-Logik!
// ============================================================================
#pragma once

// ---------------------------------------------------------------------------
// 1) UART-BELEGUNG (ESP32 hat 3 UARTs; alle Pins frei mappbar)
//    Default: VESC=UART0 (GPIO1/3), Display=UART1, BLE-Modul=UART2
//    HINWEIS: Fuer VESC auf UART0 das USB-Kabel des DevKits abziehen!
//    Alternative Boards mit 3+ UARTs (ESP32-S3, STM32F4) moeglich.
// ---------------------------------------------------------------------------
#define VESC_BAUD        115200      // Bridge<->VESC (Lisp-Skript)
#define DISPLAY_BAUD     9600        // Stock-Display (USART3-Emulation)
#define BLEMOD_BAUD      115200      // originales BLE-Modul (USART1-Emulation)

#define PIN_VESC_RX      1           // ESP32 RX  <- VESC TX
#define PIN_VESC_TX      3           // ESP32 TX  -> VESC RX
#define PIN_DISP_RX      25          // ESP32 RX  <- Display TX
#define PIN_DISP_TX      26          // ESP32 TX  -> Display RX
#define PIN_BLE_RX       16          // ESP32 RX  <- BLE-Modul TX
#define PIN_BLE_TX       17          // ESP32 TX  -> BLE-Modul RX

#define PIN_STATUS_LED   2           // Onboard-LED / Status
#define PIN_WS2812       27          // optional: LED-Datenleitung (-1 = aus)
#define WS2812_COUNT     0           // Anzahl LEDs (0 = deaktiviert!)
#define WS2812_BRIGHT    96          // Helligkeit 0..255

// ---------------------------------------------------------------------------
// 2) FAHRZEUG-KONSTANTEN (aus der IVCU-Firmware R3.4.13)
// ---------------------------------------------------------------------------
#define WHEEL_CODE       100         // Raddurchmesser-Code (10.0" = 100)
#define POLE_PAIRS       15          // Motor-Polpaare (Werk-Rohwert 30 pruefen!)
#define FW_VER_MAJ       3
#define FW_VER_MIN       4
#define FW_VER_PAT       13           // wir melden uns als 3.4.13
#define HW_VER_A         1
#define HW_VER_B         1
#define PACK_S           16          // 13/14/16/20 fuer 48/52/60/72 V

// Gangtabelle (wie Original-Fabrik: Limit / Strom)
static const uint8_t GEAR_LIMIT_KMH[5] = { 15, 20, 25, 35, 45 };
static const uint8_t GEAR_CUR_A[5]     = { 15, 20, 25, 30, 55 };

// Display-Frame: Clamp/Scale-Bit in Byte 4 (R3 = 0 offen; eKFV-aehnlich = 0x02)
#define CLAMP_SCALE_BIT  0x00

// ROTATIONSZEIT: [8..9] (u16 BE) -- VERIFIZIERT per Display-Firmware-Analyse
// (31.10.2026): Display rechnet speed = wheel([30]) * 287 / rot (rot in 0,1 ms);
//   rot < 5 => 0x640, rot > 2999 => 0.  => rot = WHEEL_CODE*287/speed_kmh.
// Die frueheren Kandidatenfelder tragen ANDERE u16-Daten (ESC-Messwerte) und
// bleiben standardmaessig aus.
#define ROT_FIELD_17_18  0           // Bytes [17..18] (Alt-Kandidat)
#define ROT_FIELD_20_21  0           // Bytes [20..21] (Alt-Kandidat)
#define ROT_FIELD_22_23  0           // Bytes [22..23] (Alt-Kandidat)
#define ROT_FIELD_24_25  0           // Bytes [24..25] (Alt-Kandidat)
#define ROT_MAX          0xFFFF

// ---------------------------------------------------------------------------
// 3) TIMING
// ---------------------------------------------------------------------------
#define MS_DISPLAY_TX    100         // 0x35-Frame
#define MS_KEEPALIVE     100         // 10-Byte-Zaehler
#define MS_BLE_TELEMETRY 200         // 55xx-Stream
#define BLE_GREET_TIMEOUT_MS 8000    // ohne App-Traffic: Stream stoppen

// ---------------------------------------------------------------------------
// 4) DEBUG (kein Serial-Log im Normalbetrieb, da UART0 = VESC!)
// ---------------------------------------------------------------------------
#define BRIDGE_DEBUG     0           // 1 = Diagnose ueber Status-LED-Blinkcodes
