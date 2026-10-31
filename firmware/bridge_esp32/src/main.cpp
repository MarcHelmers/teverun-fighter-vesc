// ============================================================================
//  Teverun-IO-Bridge  -  ESP32-Firmware (Arduino-ESP32 / PlatformIO)
//  ---------------------------------------------------------------------------
//  Ersetzt die Peripherie-Aufgaben der Teverun-IVCU (Box C, R3.4.13):
//    UART0 <-> VESC (Lisp: vesc_ivcu_emulator.lisp, 8-Byte-Bridge-Protokoll)
//    UART1 <-> Stock-Display  (9600; 0x35/39B TX, 0x4C/8A/8B/8C RX, Keep-Alive)
//    UART2 <-> originales BLE-Modul (115200; 0xAA RX / 0x55-Telemetrie TX)
//    optional: WS2812-LED-Ausgang (PWM-Farben der IVCU)
//
//  Protokolle aus der Firmware-Analyse (siehe Kennlinien-/Doku-Dateien).
//  ALLES VOR DEM FAHREN AUF DER WERKBANK TESTEN. Kein Originalcode.
// ============================================================================
#include <Arduino.h>
#include "bridge_config.h"
#if WS2812_COUNT > 0
  #include <driver/rmt.h>
#endif

// ---------------------------------------------------------------------------
//  Hilfsfunktionen: Checksummen
// ---------------------------------------------------------------------------
static uint8_t crc8_atm(const uint8_t *d, size_t n) {      // BLE-Frames
  uint8_t c = 0;
  for (size_t i = 0; i < n; i++) {
    c ^= d[i];
    for (int b = 0; b < 8; b++) c = (c & 0x80) ? (uint8_t)((c << 1) ^ 0x07) : (uint8_t)(c << 1);
  }
  return c;
}
static uint8_t xor_buf(const uint8_t *d, size_t n) {       // ESC/Display-Frames
  uint8_t x = 0; for (size_t i = 0; i < n; i++) x ^= d[i]; return x;
}

// ---------------------------------------------------------------------------
//  Zustand
// ---------------------------------------------------------------------------
struct VescState {
  uint8_t  speed_kmh = 0;
  uint8_t  soc       = 80;
  uint8_t  pack_v    = 60;
  uint8_t  gear      = 2;         // wie Original: Start 40%
  uint8_t  eco       = 0;
  uint8_t  t_mot     = 30, t_fet = 30, cur = 0;
  uint16_t odo_km    = 0;
  uint32_t lastMs    = 0;         // letzter gueltiger VESC-Frame
} vesc;

struct BleState {
  bool     greeted   = false;
  uint32_t lastRxMs  = 0;
} ble;

// Laufzeit-Settings (aus BLE-Cmd 0x18); Defaults = Config-Werte
struct RtSettings {
  uint8_t  limit[5];   // Gang-Limits km/h
  uint8_t  cur[5];     // Gang-Stroeme A (Rear bevorzugt)
  uint8_t  startF[5];  // Front-Start-Level 1..5
  uint8_t  startR[5];  // Rear-Start-Level 1..5
  uint8_t  eabs[5];    // EABS-Level 1..5
  uint16_t wheel;      // Zoll-Code (10.0" = 100)
  uint8_t  poles;      // Polpaare
  uint8_t  temp;       // Schutz-Temperatur
  uint8_t  mainLimit;  // Haupt-Limit
  uint8_t  vcode;      // Spannungscode (48 = 60-V-Pack!)
  uint8_t  customKey;  // Custom-Key-Funktion (55 73 t[17])
  uint8_t  ctrl4, ctrl17, flags16;
} rt;
static void rtDefaults() {
  for (int i = 0; i < 5; i++) {
    rt.limit[i] = GEAR_LIMIT_KMH[i]; rt.cur[i] = GEAR_CUR_A[i];
    rt.startF[i] = (uint8_t)(i + 1); rt.startR[i] = (uint8_t)(i + 1);
    rt.eabs[i]  = (uint8_t)(i + 1);
  }
  rt.wheel = WHEEL_CODE; rt.poles = POLE_PAIRS; rt.temp = 120;
  rt.mainLimit = GEAR_LIMIT_KMH[4]; rt.vcode = 0x30; rt.customKey = 0;
  rt.ctrl4 = 0; rt.ctrl17 = 0x80; rt.flags16 = 0;
}
// LED-Steuerung (App-Cmd 0x08)
static bool    ledOn = true;
static uint8_t ledR = 0, ledG = 0, ledB = 0;
static bool    ledOverride = false;

uint32_t lastDispTx = 0, lastKeep = 0, lastTel = 0, kaCnt = 0;
uint8_t  statusLedState = 0;
uint32_t lastLed = 0;

// ---------------------------------------------------------------------------
//  Display-Link (USART3-Emulation, 9600)
// ---------------------------------------------------------------------------
static uint16_t rot_time() {                       // 0,1-ms-Einheiten
  if (vesc.speed_kmh < 1) return ROT_MAX;
  uint32_t r = (uint32_t)rt.wheel * 287u / vesc.speed_kmh;
  return (uint16_t)(r > ROT_MAX ? ROT_MAX : r);
}

static void sendDisplay35(uint8_t subtype) {
  uint8_t f[39];
  memset(f, 0, sizeof(f));
  f[0] = 0x35; f[1] = 0x27; f[2] = subtype;
  f[3] = 0x00;                                     // Status1
  f[4] = CLAMP_SCALE_BIT;                          // Flagbyte (Bit1 = Clamp/Scale)
  uint16_t rot = rot_time();
  /* VERIFIZIERTES Layout (ivcu_protocol.py, ROM-abgeglichen):
     [12]=Spiegelflags, [13]=Speed, [14]=SOC, [15]/[16]=0x35E/0x35F,
     Rotationskandidaten [17..18]/[20..21]/[22..23]/[24..25],
     [19]=0x2F2&0x5F, [26..28]=Odometer, [29]=Status, [30]=Wheel... */
  f[11] = vesc.gear;
  f[12] = 0x00;                                    // Spiegelflags (0x2A3/A2 & 0xFE)
  f[13] = vesc.speed_kmh;                          // Speed-Feld
  f[14] = vesc.soc;                                // SOC
  f[15] = 0; f[16] = 0;                            // 0x35E / 0x35F
  if (ROT_FIELD_17_18) { f[17] = (uint8_t)(rot >> 8); f[18] = (uint8_t)rot; }
  f[19] = 0x00;                                    // 0x2F2 & 0x5F
  if (ROT_FIELD_20_21) { f[20] = (uint8_t)(rot >> 8); f[21] = (uint8_t)rot; }
  if (ROT_FIELD_22_23) { f[22] = (uint8_t)(rot >> 8); f[23] = (uint8_t)rot; }
  if (ROT_FIELD_24_25) { f[24] = (uint8_t)(rot >> 8); f[25] = (uint8_t)rot; }
  // Odometer 3B BE (/10-Einheiten -> hier km/10)
  uint32_t odo = (uint32_t)vesc.odo_km * 100u;
  f[26] = (uint8_t)(odo >> 16); f[27] = (uint8_t)(odo >> 8); f[28] = (uint8_t)odo;
  f[29] = 0x09;                                    // Statusbyte
  uint8_t gk = (vesc.gear >= 1 && vesc.gear <= 5) ? (uint8_t)(vesc.gear - 1) : 0;
  f[30] = (uint8_t)rt.wheel;
  f[31] = vesc.pack_v;
  f[32] = rt.poles;
  f[33] = (vesc.t_mot > 80) ? (uint8_t)((vesc.t_mot - 80) / 5) : 0;
  f[34] = rt.startF[gk];                           // Start-Level
  f[35] = rt.limit[gk];                            // Gang-Limit
  f[36] = 100;                                     // Power-Limit %
  f[37] = vesc.cur;                                // Rear-Strom
  f[38] = xor_buf(f, 38);
  Serial1.write(f, 39);
}

static void sendKeepalive() {                      // 10 Byte, 0..9
  uint8_t k[10];
  for (uint8_t i = 0; i < 10; i++) k[i] = i;
  Serial1.write(k, 10);
}
static void __attribute__((unused)) sendKeepaliveEsc(void)
{
  /* Platzhalter: im Original geht der 10-Byte-Zaehler auch an den ESC;
     in der Bridge uebernimmt der VESC-Link eigene Timeouts. */
}

// Display-RX: 0x4C (19) Kommandos, 0x8A/0x8B/0x8C konsumieren
static void handleDisplay4C(const uint8_t *f) {
  if (f[2] != 0x35) return;                        // Kommandoframe
  uint8_t cmd = f[3];
  if (cmd == 1) {                                  // Gangwahl
    uint8_t g = f[4]; if (g >= 1 && g <= 5) vesc.gear = g;
  } else if (cmd == 3) {                           // Eco
    vesc.eco = (f[6] & 0x01) ? 1 : 0;
  } else if (cmd == 4) {                           // Dual/TCS (an VESC weiterreichen)
    /* erweitertes Bridge-Protokoll: siehe Doku; hier nur Zustand merken */
  } else if (cmd == 5) {
    /* Settings-Write des Displays: aktuell verworfen (Wheel/Limits kommen vom VESC) */
  }
}

// ---------------------------------------------------------------------------
//  VESC-Link (UART0): 8-Byte 0x54-Frames
// ---------------------------------------------------------------------------
static void sendVesc(uint8_t cmd, uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4) {
  uint8_t f[8] = { 0x54, cmd, p0, p1, p2, p3, p4, 0 };
  f[7] = xor_buf(f, 7);
  Serial.write(f, 8);
}

static void handleVesc(const uint8_t *f) {
  switch (f[1]) {
    case 0x01: vesc.speed_kmh = f[2]; vesc.soc = f[3]; vesc.pack_v = f[4];
               vesc.gear = (f[5] >= 1 && f[5] <= 5) ? f[5] : vesc.gear; vesc.eco = f[6]; break;
    case 0x05: vesc.t_mot = f[2]; vesc.t_fet = f[3]; vesc.cur = f[4];
               vesc.odo_km = ((uint16_t)f[5] << 8) | f[6]; break;
    case 0x04: break;                              // Heartbeat
    default: break;
  }
  vesc.lastMs = millis();
}

// ---------------------------------------------------------------------------
//  BLE/App-Link (UART2): 0xAA-RX (Telefon -> VCU), 0x55-TX (VCU -> Telefon)
// ---------------------------------------------------------------------------
static void send55(uint8_t cmd, const uint8_t *payload17) {
  uint8_t f[20];
  f[0] = 0x55; f[1] = cmd;
  memcpy(&f[2], payload17, 17);
  f[19] = crc8_atm(f, 19);
  Serial2.write(f, 20);
}
static void build5543(uint8_t *p) {
  memset(p, 0, 17);
  p[0] = FW_VER_MAJ; p[1] = FW_VER_MIN; p[2] = FW_VER_PAT;   // [2..4]
  p[4] = HW_VER_A; p[5] = HW_VER_B;                           // [6..7]
}
static void build5542(uint8_t *p) {                              // Rahmen-Nr. (19 ASCII)
  memset(p, 0, 17);
  const char *id = "AWPE-VCU-220212";
  for (int i = 0; i < 15 && i < 17; i++) p[i] = id[i];
}
static void build5552(uint8_t *p) {
  memset(p, 0, 17);
  uint16_t v10 = (uint16_t)vesc.pack_v * 10;
  p[0] = (uint8_t)(v10 >> 8); p[1] = (uint8_t)v10;             // Pack-Spannung 0,1 V
  p[2] = p[0]; p[3] = p[1];                                    // Polspannung (angenaehert)
  uint16_t cur = (uint16_t)(1000 + vesc.cur);                  // Strom m. +1000-Offset
  p[4] = (uint8_t)(cur >> 8); p[5] = (uint8_t)cur;
  p[6] = vesc.soc;                                             // SOC %
  p[7] = 100;                                                  // SOH
  p[8] = (uint8_t)(vesc.t_mot + 40);                           // Temp-Offset -40
  p[15] = (uint8_t)(vesc.t_mot + 40);
  p[16] = (uint8_t)(vesc.t_fet + 40);
}
static void build5571(uint8_t *p) {
  memset(p, 0, 17);
  uint8_t k = (vesc.gear >= 1 && vesc.gear <= 5) ? (uint8_t)(vesc.gear - 1) : 0;
  p[1] = vesc.gear;                                            // t[3]
  p[2] = rt.ctrl4;                                             // t[4] Control-Status
  p[3] = rt.poles;                                             // t[5]
  p[4] = (uint8_t)rt.wheel;                                    // t[6]
  p[5] = rt.temp;                                              // t[7] Temp-Schwelle
  p[6] = (uint8_t)(rt.startF[k] & 0x0F);                       // t[8] Front-Start (low nibble)
  p[7] = (uint8_t)(((rt.eabs[k] & 0x0F) << 4) | (rt.startR[k] & 0x0F)); // t[9]
  p[8] = rt.limit[k];                                          // t[10] Gang-Limit
  p[9] = rt.mainLimit;                                         // t[11] Haupt-Limit
  p[10] = rt.cur[k];                                           // t[12] Front-Strom
  p[11] = rt.cur[k];                                           // t[13] Rear-Strom
  p[13] = vesc.pack_v;                                         // t[15] Pack nominal
  p[14] = rt.flags16;                                          // t[16] Flags
  p[15] = (uint8_t)((vesc.eco ? 0x01 : 0x00) | (rt.ctrl17 & 0x80)); // t[17] System-Status
  p[16] = 0;                                                   // t[18] Timer (0 = wie Original-Bug)
}
static void build5572(uint8_t *p) {
  memset(p, 0, 17);
  uint16_t cur10 = (uint16_t)vesc.cur * 10;
  p[2] = (uint8_t)(cur10 >> 8); p[3] = (uint8_t)cur10;         // Front-Strom 0,1 A
  p[7] = (uint8_t)(vesc.t_mot + 40);                           // Front-Temp
  p[10] = (uint8_t)(cur10 >> 8); p[11] = (uint8_t)cur10;       // Rear-Strom
  uint16_t raw = rot_time();                        // speedRaw = Rotationszeit (0,1 ms)
  p[13] = (uint8_t)(raw >> 8); p[14] = (uint8_t)raw;
  p[15] = (uint8_t)(vesc.t_mot + 40);                          // Rear-Temp
}
static void build5573(uint8_t *p) {
  memset(p, 0, 17);
  // avg/max/trip werden derzeit nicht mitgefuehrt -> 0; Odometer 3B BE
  p[6] = 0; p[7] = 0;
  p[8] = (uint8_t)((vesc.odo_km >> 16) & 0xFF);
  p[9] = (uint8_t)((vesc.odo_km >> 8) & 0xFF);
  p[10] = (uint8_t)(vesc.odo_km & 0xFF);
  p[15] = rt.customKey;                              // t[17] Custom-Key
}

static void bleHandleCommand(const uint8_t *f) {
  uint8_t cmd = f[1];
  if (cmd == 0x1F) {                                  // FIN umbenennen
    char name[20]; memset(name, 0, sizeof(name));
    memcpy(name, &f[2], 16);
    if (name[0] == 'T' || (name[0]=='B'&&name[1]=='T'&&name[2]=='0'&&name[3]=='4')) {
      char at[48];
      snprintf(at, sizeof(at), "AT+LENAME=%.19s\r\n", name);
      Serial2.write((const uint8_t *)at, strlen(at)); // Modul muss mitspielen
    }
  } else if (cmd == 0x08) {                           // LED an/aus, Modus, RGB
    ledOn = (f[2] != 0);
    if (f[4] != 0xFF) ledR = f[4];
    if (f[5] != 0xFF) ledG = f[5];
    if (f[6] != 0xFF) ledB = f[6];
    ledOverride = true;
  } else if (cmd == 0x18) {                           // Settings-Write (0xFF = unveraendert)
    uint8_t mode = f[2];
    uint8_t gi   = f[3];                              // Gang bzw. Profil-Index (1..5)
    if (gi >= 1 && gi <= 5) {
      uint8_t k = (uint8_t)(gi - 1);
      if (f[5]  != 0xFF) rt.poles = f[5];
      if (f[6]  != 0xFF) rt.wheel = f[6];             // Zoll-Code (10.0" = 100)
      if (f[7]  != 0xFF) rt.temp  = f[7];
      if (f[8]  != 0xFF) rt.startF[k] = f[8] & 0x0F;
      if (f[9]  != 0xFF) { rt.startR[k] = f[9] & 0x0F; rt.eabs[k] = (f[9] >> 4) & 0x0F; }
      if (f[10] != 0xFF) rt.limit[k] = f[10];
      if (f[11] != 0xFF) rt.mainLimit = f[11];
      if (f[12] != 0xFF) rt.cur[k] = f[12];           // Front-Strom als Fallback
      if (f[13] != 0xFF) rt.cur[k] = f[13];           // Rear-Strom bevorzugt
      if (f[14] != 0xFF) rt.vcode = f[14];
      if (f[16] != 0xFF) rt.flags16 = f[16];
      if (f[17] != 0xFF) rt.ctrl17 = f[17];
      if (f[4]  != 0xFF) rt.ctrl4  = f[4];
      if (mode == 0) {                                // aktueller Gang -> an VESC melden
        vesc.gear = gi;
        sendVesc(0x02, gi, 0, 0, 0, 0);
      }
    }
  } else if (cmd == 0x1A) {                           // Custom-Key-Funktion
    rt.customKey = f[6];
  } else if (cmd == 0x01 || cmd == 0x02 || cmd == 0x03 || cmd == 0x1C) {
    /* Handshake/Sleep/Lademodus/RTC: bewusst nur loggen */
  }
}

// ---------------------------------------------------------------------------
//  WS2812 (optional) - RMT-basiert
// ---------------------------------------------------------------------------
#if WS2812_COUNT > 0
static rmt_channel_t rmtCh = RMT_CHANNEL_0;
static void ws2812Init() {
  rmt_config_t cfg = RMT_DEFAULT_CONFIG_TX((gpio_num_t)PIN_WS2812, rmtCh);
  cfg.clk_div = 2;                                   // 80 MHz / 2 = 40 MHz
  rmt_config(&cfg);
  rmt_driver_install(rmtCh, 0, 0);
}
static void ws2812Send(const uint8_t *rgb, size_t leds) {
  size_t n = leds * 24;
  rmt_item32_t *items = (rmt_item32_t *)malloc(n * sizeof(rmt_item32_t));
  if (!items) return;
  for (size_t i = 0; i < n; i++) {
    bool bit = (rgb[i / 24 * 3 + (i % 24) / 8] >> (7 - (i % 8))) & 1;
    items[i].level0 = 1; items[i].duration0 = bit ? 32 : 16;
    items[i].level1 = 0; items[i].duration1 = bit ? 16 : 32;
  }
  rmt_write_items(rmtCh, items, n, true);
  free(items);
}
static void ledUpdate() {
  static uint32_t last = 0;
  if (millis() - last < 250) return;
  last = millis();
  uint8_t r = 0, g = 0, b = 0;
  if (ledOverride) {                                 // App-Cmd 0x08
    if (ledOn) { r = ledR; g = ledG; b = ledB; }
  }
  else if (vesc.soc < 20)      { r = 255; }          // rot
  else if (vesc.soc < 50) { r = 255; g = 255; }      // gelb
  else if (vesc.soc < 99) { b = 255; g = 96; }       // hellblau (0x0099FF)
  else                    { g = 255; }               // gruen
  uint8_t buf[WS2812_COUNT * 3];
  for (int i = 0; i < WS2812_COUNT; i++) {
    buf[i * 3 + 0] = (uint8_t)(g * WS2812_BRIGHT / 255);
    buf[i * 3 + 1] = (uint8_t)(r * WS2812_BRIGHT / 255);   // typische WS2812-Reihenfolge GRB
    buf[i * 3 + 2] = (uint8_t)(b * WS2812_BRIGHT / 255);
  }
  ws2812Send(buf, WS2812_COUNT);
}
#endif

// ---------------------------------------------------------------------------
//  UART-Parser (nicht blockierend; je Link eigener Zustand!)
// ---------------------------------------------------------------------------
struct Parser { uint8_t buf[64]; uint8_t idx = 0; uint8_t want = 0; uint8_t hdr = 0; };
static Parser prDisp, prVesc, prBle;

// Display: Header 0x4C=19 / 0x8A=11 / 0x8B=8 / 0x8C=8
static void pollDisplay() {
  while (Serial1.available()) {
    uint8_t b = (uint8_t)Serial1.read();
    if (prDisp.want == 0) {
      if (b == 0x4C)      { prDisp.want = 19; prDisp.hdr = b; prDisp.buf[0] = b; prDisp.idx = 1; }
      else if (b == 0x8A) { prDisp.want = 11; prDisp.hdr = b; prDisp.buf[0] = b; prDisp.idx = 1; }
      else if (b == 0x8B || b == 0x8C) { prDisp.want = 8; prDisp.hdr = b; prDisp.buf[0] = b; prDisp.idx = 1; }
    } else {
      prDisp.buf[prDisp.idx++] = b;
      if (prDisp.idx >= prDisp.want) {
        if (prDisp.hdr == 0x4C && xor_buf(prDisp.buf, 18) == prDisp.buf[18]) handleDisplay4C(prDisp.buf);
        else if (prDisp.hdr == 0x8A || prDisp.hdr == 0x8B || prDisp.hdr == 0x8C) { /* konsumieren */ }
        prDisp.want = 0; prDisp.idx = 0;
      }
    }
  }
}
// VESC: 0x54-Frames (8 Byte, XOR)
static void pollVesc() {
  while (Serial.available()) {
    uint8_t b = (uint8_t)Serial.read();
    if (prVesc.want == 0) {
      if (b == 0x54) { prVesc.want = 8; prVesc.hdr = b; prVesc.buf[0] = b; prVesc.idx = 1; }
    } else {
      prVesc.buf[prVesc.idx++] = b;
      if (prVesc.idx >= prVesc.want) {
        if (xor_buf(prVesc.buf, 7) == prVesc.buf[7]) handleVesc(prVesc.buf);
        prVesc.want = 0; prVesc.idx = 0;
      }
    }
  }
}
// BLE/App: 0xAA-Frames (20 Byte, CRC-8)
static void pollBle() {
  while (Serial2.available()) {
    uint8_t b = (uint8_t)Serial2.read();
    if (prBle.want == 0) {
      if (b == 0xAA) { prBle.want = 20; prBle.hdr = b; prBle.buf[0] = b; prBle.idx = 1; }
    } else {
      prBle.buf[prBle.idx++] = b;
      if (prBle.idx >= prBle.want) {
        if (crc8_atm(prBle.buf, 19) == prBle.buf[19]) {
          ble.greeted = true; ble.lastRxMs = millis();
          bleHandleCommand(prBle.buf);
        }
        prBle.want = 0; prBle.idx = 0;
      }
    }
  }
}

// ---------------------------------------------------------------------------
//  Setup / Loop
// ---------------------------------------------------------------------------
void setup() {
  rtDefaults();
  pinMode(PIN_STATUS_LED, OUTPUT);
  Serial.begin(VESC_BAUD, SERIAL_8N1, PIN_VESC_RX, PIN_VESC_TX);       // UART0=VESC
  Serial1.begin(DISPLAY_BAUD, SERIAL_8N1, PIN_DISP_RX, PIN_DISP_TX);   // Display
  Serial2.begin(BLEMOD_BAUD, SERIAL_8N1, PIN_BLE_RX, PIN_BLE_TX);      // BLE-Modul
#if WS2812_COUNT > 0
  ws2812Init();
#endif
  vesc.lastMs = millis();
}

void loop() {
  pollDisplay();
  pollVesc();
  pollBle();

  uint32_t now = millis();

  // Display-Frames + Keep-Alive (100 ms)
  if (now - lastDispTx >= MS_DISPLAY_TX) {
    lastDispTx = now;
    sendDisplay35(0x3A);
    sendKeepalive();
  }
  // BLE-Telemetrie (200 ms), nur wenn App verbunden/greet + kuerzlich aktiv
  if (ble.greeted && (now - ble.lastRxMs < BLE_GREET_TIMEOUT_MS) &&
      now - lastTel >= MS_BLE_TELEMETRY) {
    lastTel = now;
    uint8_t p[17];
    build5543(p); send55(0x43, p);
    build5542(p); send55(0x42, p);
    build5552(p); send55(0x52, p);
    build5571(p); send55(0x71, p);
    build5572(p); send55(0x72, p);
    build5573(p); send55(0x73, p);
  }
  // VESC-Watchdog: ohne Heartbeat/Tel. > 1 s -> Geschwindigkeit 0 anzeigen
  if (now - vesc.lastMs > 1000) vesc.speed_kmh = 0;

#if WS2812_COUNT > 0
  ledUpdate();
#endif

  // Status-LED: 1 Hz = ok, 5 Hz = VESC stumm
  uint32_t period = (now - vesc.lastMs > 1000) ? 100 : 500;
  if (now - lastLed >= period) {
    lastLed = now; statusLedState ^= 1;
    digitalWrite(PIN_STATUS_LED, statusLedState);
  }
}
