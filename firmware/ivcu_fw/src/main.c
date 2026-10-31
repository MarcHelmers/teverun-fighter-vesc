/*
 * main.c -- Anwendungslogik der eigenen IVCU-Firmware (Weg 1)
 * ============================================================================
 *  Die eigene Firmware vereint Original-IVCU und ESP32-Bridge in EINEM Geraet:
 *
 *    USART3 9600   <-> Stock-Display : 0x35-Frames (39 B) + 10-B-Keepalive,
 *                                      RX 0x4C-Kommandos (Gang/Eco)
 *    USART1 115200 <-> BLE-Modul     : 0xAA-Kommandos (0x01/0x08/0x18/0x1A/
 *                                      0x1F), 0x55-Telemetrie (43/42/52/71/72/73)
 *    USART2 115200 <-> VESC          : 8-Byte-Bridge-Protokoll '54 cmd p0..p4 XOR'
 *
 *  VESC-Seite: vesc_ivcu_emulator.lisp MODE 0 (unveraendert!).
 *  Protokolle verifiziert in ../AWIVCU_APP_R3_4_13_Kennlinien_und_Datenbereiche.md
 *  + ivcu_protocol.py. ALLES VOR DEM FAHREN AUF DER WERKBANK TESTEN.
 * ============================================================================
 */
#include <string.h>
#include "ivcu_hw.h"
#include "ivcu_config.h"
#include "uart.h"

/* ---------------------------------------------------------------------------
 * 1) ZUSTAND
 * ------------------------------------------------------------------------- */
typedef struct {
    uint8_t  speed_kmh, soc, pack_v, gear, eco;
    uint8_t  t_mot, t_fet, cur;
    uint16_t odo_km;
    uint32_t last_ms;
} vesc_state_t;
static vesc_state_t vs;

typedef struct { uint8_t greeted; uint32_t last_rx_ms; } ble_state_t;
static ble_state_t ble;

/* Laufzeit-Settings (Defaults = Werks-/Config-Werte; von App-Cmd 0x18 ersetzt) */
typedef struct {
    uint8_t  limit[5], cur[5];
    uint8_t  startF[5], startR[5], eabs[5];
    uint16_t wheel;
    uint8_t  poles, temp, main_limit, vcode, custom_key;
    uint8_t  ctrl4, ctrl17, flags16;
} rt_settings_t;
static rt_settings_t rt;

static void rt_defaults(void)
{
    static const uint8_t lim[5] = CFG_GEAR_LIMIT_KMH;
    static const uint8_t cur[5] = CFG_GEAR_CUR_A;
    for (int i = 0; i < 5; i++) {
        rt.limit[i] = lim[i];  rt.cur[i]  = cur[i];
        rt.startF[i] = (uint8_t)(i + 1);
        rt.startR[i] = (uint8_t)(i + 1);
        rt.eabs[i]   = (uint8_t)(i + 1);
    }
    rt.wheel = CFG_WHEEL_CODE; rt.poles = CFG_POLE_PAIRS;
    rt.temp = CFG_TEMP_LIMIT;  rt.main_limit = lim[4]; rt.vcode = 0x30;
    rt.custom_key = 0; rt.ctrl4 = 0; rt.ctrl17 = 0x80; rt.flags16 = 0;
}

/* ---------------------------------------------------------------------------
 * 2) ZEITBASIS (SysTick 1 ms @ 48 MHz)
 * ------------------------------------------------------------------------- */
static volatile uint32_t g_ms;
void SysTick_Handler(void) { g_ms++; }
static uint32_t millis(void) { return g_ms; }

/* ---------------------------------------------------------------------------
 * 3) CLOCK-SETUP
 *    HSE 8 MHz -> /2 -> PLL x12 = 48 MHz (wie Original, abgeleitet);
 *    Fallback HSI/2 x12 = 48 MHz (quarzunabhaengig, ungenauer).
 *    APB1 = /4 = 12 MHz, APB2 = /2 = 24 MHz (BRR-Werte passen dazu).
 * ------------------------------------------------------------------------- */
static void clock_init(void)
{
    FLASH_ACR = FLASH_ACR_LATENCY_1 | FLASH_ACR_PRFTBE;

    RCC_CR |= RCC_CR_HSEON;
    for (volatile uint32_t t = 0; t < 400000u && !(RCC_CR & RCC_CR_HSERDY); t++) { }

    uint32_t cfgr = RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV4
                  | RCC_CFGR_PPRE2_DIV2 | RCC_CFGR_PLLMUL12;
    if (RCC_CR & RCC_CR_HSERDY) cfgr |= RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE; /* HSE/2 */
    /* sonst: PLLSRC=0 -> HSI/2 (8 MHz /2 = 4 -> x12 = 48 MHz) */
    RCC_CFGR = cfgr;

    RCC_CR |= RCC_CR_PLLON;
    for (volatile uint32_t t = 0; t < 400000u && !(RCC_CR & RCC_CR_PLLRDY); t++) { }

    RCC_CFGR = cfgr | RCC_CFGR_SW_PLL;
    for (volatile uint32_t t = 0; t < 400000u
            && ((RCC_CFGR & RCC_CFGR_SWS) != (2u << 2)); t++) { }
}

/* ---------------------------------------------------------------------------
 * 4) HILFSFUNKTIONEN
 * ------------------------------------------------------------------------- */
static uint8_t crc8_atm(const uint8_t *d, size_t n)   /* BLE-Frames */
{
    uint8_t c = 0;
    for (size_t i = 0; i < n; i++) {
        c ^= d[i];
        for (int b = 0; b < 8; b++)
            c = (uint8_t)((c << 1) ^ ((c & 0x80u) ? 0x07u : 0x00u));
    }
    return c;
}
static uint8_t xor_buf(const uint8_t *d, size_t n)
{
    uint8_t x = 0;
    for (size_t i = 0; i < n; i++) x ^= d[i];
    return x;
}

/* Rotationszeit in 0,1 ms (community-verifizierte Kette: 287*Wheel/rot) */
static uint16_t rot_time(void)
{
    if (vs.speed_kmh < 1u) return CFG_ROT_MAX;
    uint32_t r = (uint32_t)rt.wheel * 287u / vs.speed_kmh;
    return (uint16_t)((r > CFG_ROT_MAX) ? CFG_ROT_MAX : r);
}

/* ---------------------------------------------------------------------------
 * 5) DISPLAY-LINK (USART3):  0x35-Frame (39 B) + Keep-Alive (10 B)
 * ------------------------------------------------------------------------- */
static void display_send35(uint8_t subtype)
{
    uint8_t f[39];
    memset(f, 0, sizeof(f));
    f[0] = 0x35; f[1] = 0x27; f[2] = subtype;
    f[3] = 0;                                     /* Status1 (Original: ESC-Daten) */
    f[4] = CFG_CLAMP_SCALE_BIT;                   /* Flagbyte, Bit1 = Clamp/Scale */
    uint16_t rot = rot_time();
    /* Verifiziertes Layout (Kennlinien-Doku Teil C):
     * [12]=Spiegelflags [13]=Speed [14]=SOC; Rotations-Kandidaten unten;
     * [26..28]=Odometer; [30]=Wheel [31]=Pack [32]=Polpaare [34..37]=Gangfelder */
    f[11] = vs.gear;
    f[12] = 0;
    f[13] = vs.speed_kmh;
    f[14] = vs.soc;
    f[15] = 0; f[16] = 0;                         /* 0x35E / 0x35F */
#if CFG_ROT_FIELD_17_18
    f[17] = (uint8_t)(rot >> 8); f[18] = (uint8_t)rot;
#endif
    f[19] = 0;
#if CFG_ROT_FIELD_20_21
    f[20] = (uint8_t)(rot >> 8); f[21] = (uint8_t)rot;
#endif
#if CFG_ROT_FIELD_22_23
    f[22] = (uint8_t)(rot >> 8); f[23] = (uint8_t)rot;
#endif
#if CFG_ROT_FIELD_24_25
    f[24] = (uint8_t)(rot >> 8); f[25] = (uint8_t)rot;
#endif
    uint32_t odo = (uint32_t)vs.odo_km * 100u;    /* /10-Einheiten, 3 B BE */
    f[26] = (uint8_t)(odo >> 16); f[27] = (uint8_t)(odo >> 8); f[28] = (uint8_t)odo;
    f[29] = 0x09;
    {
        uint8_t gk = (vs.gear >= 1u && vs.gear <= 5u) ? (uint8_t)(vs.gear - 1u) : 0u;
        f[30] = (uint8_t)rt.wheel;
        f[31] = vs.pack_v;
        f[32] = rt.poles;
        f[33] = (vs.t_mot > 80u) ? (uint8_t)((vs.t_mot - 80u) / 5u) : 0u;
        f[34] = rt.startF[gk];
        f[35] = rt.limit[gk];
        f[36] = 100;
        f[37] = vs.cur;
    }
    f[38] = xor_buf(f, 38);
    uart_tx(USART3_BASE, f, sizeof(f));
}

static void display_keepalive(void)
{
    uint8_t k[10];
    for (uint8_t i = 0; i < 10u; i++) k[i] = i;
    uart_tx(USART3_BASE, k, sizeof(k));
}

/* 0x4C-Kommandos des Displays */
static void display_handle_4c(const uint8_t *f)
{
    if (f[2] != 0x35) return;
    uint8_t cmd = f[3];
    if (cmd == 1u) {
        uint8_t g = f[4];
        if (g >= 1u && g <= 5u) vs.gear = g;
    } else if (cmd == 3u) {
        vs.eco = (f[6] & 0x01u) ? 1u : 0u;
    }
    /* cmd 4/5 (Dual/TCS, Settings-Write): v1 bewusst verworfen */
}

/* ---------------------------------------------------------------------------
 * 6) BLE/APP-LINK (USART1):  0x55-Telemetrie, 0xAA-Kommandos
 * ------------------------------------------------------------------------- */
static void ble_send55(uint8_t cmd, const uint8_t *payload17)
{
    uint8_t f[20];
    f[0] = 0x55; f[1] = cmd;
    memcpy(&f[2], payload17, 17);
    f[19] = crc8_atm(f, 19);
    uart_tx(USART1_BASE, f, sizeof(f));
}

static void build_5543(uint8_t *p)          /* Version/Hardware */
{
    memset(p, 0, 17);
    p[0] = CFG_FW_VER_MAJ; p[1] = CFG_FW_VER_MIN; p[2] = CFG_FW_VER_PAT;
    p[4] = CFG_HW_VER_A;   p[5] = CFG_HW_VER_B;
}
static void build_5542(uint8_t *p)          /* Rahmen-Nr./Identitaet (ASCII) */
{
    static const char id[] = "AWPE-VCU-220212";
    memset(p, 0, 17);
    for (int i = 0; i < 15 && i < 17; i++) p[i] = (uint8_t)id[i];
}
static void build_5552(uint8_t *p)          /* BMS/Batterie */
{
    memset(p, 0, 17);
    uint16_t v10 = (uint16_t)vs.pack_v * 10u;
    p[0] = (uint8_t)(v10 >> 8); p[1] = (uint8_t)v10;
    p[2] = p[0]; p[3] = p[1];                       /* Polspannung (genaehert) */
    uint16_t cur = (uint16_t)(1000u + vs.cur);      /* Strom mit +1000-Offset */
    p[4] = (uint8_t)(cur >> 8); p[5] = (uint8_t)cur;
    p[6] = vs.soc; p[7] = 100;                      /* SOC / SOH */
    p[8]  = (uint8_t)(vs.t_mot + 40u);
    p[15] = (uint8_t)(vs.t_mot + 40u);
    p[16] = (uint8_t)(vs.t_fet + 40u);
}
static void build_5571(uint8_t *p)          /* Settings/Gang */
{
    memset(p, 0, 17);
    uint8_t k = (vs.gear >= 1u && vs.gear <= 5u) ? (uint8_t)(vs.gear - 1u) : 0u;
    p[1]  = vs.gear;                                     /* t[3] */
    p[2]  = rt.ctrl4;                                    /* t[4] */
    p[3]  = rt.poles;                                    /* t[5] */
    p[4]  = (uint8_t)rt.wheel;                           /* t[6] */
    p[5]  = rt.temp;                                     /* t[7] */
    p[6]  = (uint8_t)(rt.startF[k] & 0x0Fu);             /* t[8] */
    p[7]  = (uint8_t)(((rt.eabs[k] & 0x0Fu) << 4) | (rt.startR[k] & 0x0Fu)); /* t[9] */
    p[8]  = rt.limit[k];                                 /* t[10] */
    p[9]  = rt.main_limit;                               /* t[11] */
    p[10] = rt.cur[k];                                   /* t[12] */
    p[11] = rt.cur[k];                                   /* t[13] */
    p[13] = vs.pack_v;                                   /* t[15] */
    p[14] = rt.flags16;                                  /* t[16] */
    p[15] = (uint8_t)((vs.eco ? 0x01u : 0x00u) | (rt.ctrl17 & 0x80u)); /* t[17] */
    p[16] = 0;                                           /* t[18] (Original-Bug) */
}
static void build_5572(uint8_t *p)          /* Motor/ECU */
{
    memset(p, 0, 17);
    uint16_t cur10 = (uint16_t)vs.cur * 10u;
    p[2] = (uint8_t)(cur10 >> 8); p[3] = (uint8_t)cur10;         /* Front 0,1 A */
    p[7] = (uint8_t)(vs.t_mot + 40u);
    p[10] = (uint8_t)(cur10 >> 8); p[11] = (uint8_t)cur10;       /* Rear 0,1 A */
    uint16_t raw = rot_time();                                   /* speedRaw */
    p[13] = (uint8_t)(raw >> 8); p[14] = (uint8_t)raw;
    p[15] = (uint8_t)(vs.t_mot + 40u);
}
static void build_5573(uint8_t *p)          /* Fahrt/Odometer */
{
    memset(p, 0, 17);
    p[6] = 0; p[7] = 0;                                          /* avg/max offen */
    p[8] = 0;                                                    /* 3 B BE */
    p[9] = (uint8_t)(vs.odo_km >> 8);
    p[10] = (uint8_t)vs.odo_km;
    p[15] = rt.custom_key;                                       /* t[17] */
}

static void ble_send_at_lename(const uint8_t *name16)
{
    uint8_t out[40];
    static const char pfx[] = "AT+LENAME=";
    size_t n = 0;
    while (pfx[n] != '\0') { out[n] = (uint8_t)pfx[n]; n++; }
    for (int i = 0; i < 16; i++) {
        if (name16[i] == 0u) break;
        out[n++] = name16[i];
    }
    out[n++] = '\r'; out[n++] = '\n';
    uart_tx(USART1_BASE, out, n);
}

static void ble_handle_command(const uint8_t *f)
{
    uint8_t cmd = f[1];
    if (cmd == 0x1Fu) {                                  /* FIN umbenennen */
        const uint8_t *name = &f[2];
        if (name[0] == 'T' ||
            (name[0] == 'B' && name[1] == 'T' && name[2] == '0' && name[3] == '4')) {
            ble_send_at_lename(name);
        }
    } else if (cmd == 0x08u) {                           /* LED (v1: nur merken) */
        rt.flags16 = (uint8_t)((f[2] != 0u) ? (rt.flags16 | 0x02u)
                                            : (rt.flags16 & ~0x02u));
    } else if (cmd == 0x18u) {                           /* Settings-Write */
        uint8_t mode = f[2];
        uint8_t gi   = f[3];                             /* Gang bzw. Profil */
        if (gi >= 1u && gi <= 5u) {
            uint8_t k = (uint8_t)(gi - 1u);
            if (f[5]  != 0xFFu) rt.poles = f[5];
            if (f[6]  != 0xFFu) rt.wheel = f[6];        /* Zoll-Code (10.0" = 100) */
            if (f[7]  != 0xFFu) rt.temp = f[7];
            if (f[8]  != 0xFFu) rt.startF[k] = f[8] & 0x0Fu;
            if (f[9]  != 0xFFu) { rt.startR[k] = f[9] & 0x0Fu; rt.eabs[k] = (f[9] >> 4) & 0x0Fu; }
            if (f[10] != 0xFFu) rt.limit[k] = f[10];
            if (f[11] != 0xFFu) rt.main_limit = f[11];
            if (f[12] != 0xFFu) rt.cur[k] = f[12];       /* Front als Fallback */
            if (f[13] != 0xFFu) rt.cur[k] = f[13];       /* Rear bevorzugt */
            if (f[14] != 0xFFu) rt.vcode = f[14];
            if (f[16] != 0xFFu) rt.flags16 = f[16];
            if (f[17] != 0xFFu) rt.ctrl17 = f[17];
            if (f[4]  != 0xFFu) rt.ctrl4 = f[4];
            if (mode == 0u) {                            /* aktueller Gang -> VESC */
                vs.gear = gi;
                /* an VESC melden (Cmd 0x02), siehe Abschnitt 7 */
            }
        }
    } else if (cmd == 0x1Au) {                           /* Custom-Key */
        rt.custom_key = f[6];
    }
    /* 0x01/0x02/0x03/0x1C: bewusst nur quasi "quittiert" (greet bereits oben) */
}

/* ---------------------------------------------------------------------------
 * 7) VESC-LINK (USART2):  8-Byte '54 cmd p0..p4 XOR'
 * ------------------------------------------------------------------------- */
static void vesc_send(uint8_t cmd, uint8_t p0, uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4)
{
    uint8_t f[8] = { 0x54, cmd, p0, p1, p2, p3, p4, 0 };
    f[7] = xor_buf(f, 7);
    uart_tx(USART2_BASE, f, sizeof(f));
}
static void vesc_handle(const uint8_t *f)
{
    switch (f[1]) {
        case 0x01u:
            vs.speed_kmh = f[2]; vs.soc = f[3]; vs.pack_v = f[4];
            if (f[5] >= 1u && f[5] <= 5u) vs.gear = f[5];
            vs.eco = f[6];
            break;
        case 0x05u:
            vs.t_mot = f[2]; vs.t_fet = f[3]; vs.cur = f[4];
            vs.odo_km = (uint16_t)(((uint16_t)f[5] << 8) | f[6]);
            break;
        default: break;
    }
    vs.last_ms = millis();
}

/* ---------------------------------------------------------------------------
 * 8) PARSER (aus den RX-Ringen)
 * ------------------------------------------------------------------------- */
static void poll_display(void)
{
    static uint8_t hdr = 0, want = 0, idx = 0, buf[24];
    int b;
    while ((b = uart_rx_get(USART3_BASE)) >= 0) {
        if (want == 0) {
            if (b == 0x4C)             { want = 19; hdr = 0x4C; }
            else if (b == 0x8A)        { want = 11; hdr = 0x8A; }
            else if (b == 0x8B || b == 0x8C) { want = 8; hdr = (uint8_t)b; }
            else continue;
            buf[0] = (uint8_t)b; idx = 1;
        } else {
            buf[idx++] = (uint8_t)b;
            if (idx >= want) {
                if (hdr == 0x4C && xor_buf(buf, 18) == buf[18]) display_handle_4c(buf);
                /* 0x8A/0x8B/0x8C: konsumieren (Inhalt unbekannt) */
                want = 0; idx = 0;
            }
        }
    }
}

static void poll_ble(void)
{
    static uint8_t want = 0, idx = 0, buf[20];
    int b;
    while ((b = uart_rx_get(USART1_BASE)) >= 0) {
        if (want == 0) {
            if (b == 0xAA) { want = 20; buf[0] = 0xAA; idx = 1; }
            else continue;
        } else {
            buf[idx++] = (uint8_t)b;
            if (idx >= want) {
                if (crc8_atm(buf, 19) == buf[19]) {
                    ble.greeted = 1; ble.last_rx_ms = millis();
                    ble_handle_command(buf);
                }
                want = 0; idx = 0;
            }
        }
    }
}

static void poll_vesc(void)
{
    static uint8_t want = 0, idx = 0, buf[8];
    int b;
    while ((b = uart_rx_get(USART2_BASE)) >= 0) {
        if (want == 0) {
            if (b == 0x54) { want = 8; buf[0] = 0x54; idx = 1; }
            else continue;
        } else {
            buf[idx++] = (uint8_t)b;
            if (idx >= want) {
                if (xor_buf(buf, 7) == buf[7]) vesc_handle(buf);
                want = 0; idx = 0;
            }
        }
    }
}

/* ---------------------------------------------------------------------------
 * 9) HAUPTFUNKTION
 * ------------------------------------------------------------------------- */
int main(void)
{
    clock_init();
    uart_common_init();

    SYSTICK_LOAD = 48000u - 1u;                     /* 1 ms @ 48 MHz */
    SYSTICK_VAL  = 0;
    SYSTICK_CTRL = SYSTICK_CTRL_ENABLE | SYSTICK_CTRL_TICKINT | SYSTICK_CTRL_CLKSOURCE;

    rt_defaults();
    vs.pack_v = 60; vs.soc = 80; vs.gear = 2; vs.last_ms = millis();

    uint32_t last_disp = 0, last_tel = 0;
    uint8_t  vesc_gear_sent = 0;

    for (;;) {
        uint32_t now = millis();

        poll_display();
        poll_ble();
        poll_vesc();

        /* Display: 0x35-Frame + Keep-Alive alle 100 ms */
        if (now - last_disp >= CFG_MS_DISPLAY_TX) {
            last_disp = now;
            display_send35(0x3A);
            display_keepalive();
        }

        /* BLE-Telemetrie alle 200 ms, nur wenn App frisch verbunden */
        if (ble.greeted && (now - ble.last_rx_ms < CFG_BLE_GREET_TIMEOUT)
            && (now - last_tel >= CFG_MS_BLE_TELEMETRY)) {
            last_tel = now;
            uint8_t p[17];
            build_5543(p); ble_send55(0x43u, p);
            build_5542(p); ble_send55(0x42u, p);
            build_5552(p); ble_send55(0x52u, p);
            build_5571(p); ble_send55(0x71u, p);
            build_5572(p); ble_send55(0x72u, p);
            build_5573(p); ble_send55(0x73u, p);
        }

        /* Gangwechsel (durch App/0x18 oder Display/0x4C) an den VESC melden */
        if (vs.gear != vesc_gear_sent) {
            vesc_gear_sent = vs.gear;
            vesc_send(0x02u, vs.gear, 0, 0, 0, 0);
        }

        /* VESC-Watchdog: ohne gueltige Frames > 1 s -> Speed 0 anzeigen */
        if (now - vs.last_ms > CFG_VESC_TIMEOUT) vs.speed_kmh = 0;

#if CFG_HEARTBEAT_LED
        /* Status: 1 Hz = VESC frisch, 5 Hz = VESC stumm (nur wenn LED verfuegbar) */
#endif
    }
}
