/*
 * uart.c -- UART-Treiber der eigenen IVCU-Firmware
 * ============================================================================
 *  USART1 = BLE-Modul (APB2, 115200)   USART2 = VESC (APB1, 115200)
 *  USART3 = Display  (APB1,  9600)
 *  RX: IRQ -> Ringpuffer (verlustfrei). TX: blockierend per TXE-Polling
 *  (Frames <= 40 B; laengster Fall 39 B @9600 = ~41 ms, siehe README-Hinweis).
 *  Uhren: SYSCLK 48 MHz / APB1 12 MHz / APB2 24 MHz (siehe main.c).
 * ============================================================================
 */
#include "ivcu_hw.h"
#include "uart.h"

#define RING_BLE   512u
#define RING_VESC  128u
#define RING_DISP  128u

static volatile uint16_t rx_head[3], rx_tail[3];
static uint8_t rx_ring[3][RING_BLE];      /* einheitliche Maximalgroesse */
static const uint16_t rx_size[3] = { RING_BLE, RING_VESC, RING_DISP };

static int uart_idx(uint32_t base)
{
    if (base == USART1_BASE) return 0;
    if (base == USART2_BASE) return 1;
    return 2;                              /* USART3 */
}

void uart_rx_irq(uint32_t base)
{
    uint32_t sr = USART_SR(base);
    if (sr & USART_SR_RXNE) {
        uint8_t b = (uint8_t)USART_DR(base);
        int i = uart_idx(base);
        uint16_t h = rx_head[i];
        uint16_t next = (uint16_t)((h + 1u) % rx_size[i]);
        if (next != rx_tail[i]) {          /* voll -> Byte verwerfen */
            rx_ring[i][h] = b;
            rx_head[i] = next;
        }
    } else if (sr & USART_SR_ORE) {
        (void)USART_DR(base);              /* Overrun quittieren */
    }
}

int uart_rx_avail(uint32_t base)
{
    int i = uart_idx(base);
    return (int)((rx_head[i] + rx_size[i] - rx_tail[i]) % rx_size[i]);
}

int uart_rx_get(uint32_t base)
{
    int i = uart_idx(base);
    if (rx_head[i] == rx_tail[i]) return -1;
    uint8_t b = rx_ring[i][rx_tail[i]];
    rx_tail[i] = (uint16_t)((rx_tail[i] + 1u) % rx_size[i]);
    return (int)b;
}

int uart_tx(uint32_t base, const uint8_t *data, size_t n)
{
    for (size_t k = 0; k < n; k++) {
        uint32_t guard = 0;
        while (!(USART_SR(base) & USART_SR_TXE)) {
            if (++guard > 2000000u) return -1;   /* Takt-/Pinproblem */
        }
        USART_DR(base) = data[k];
    }
    return 0;
}

/* ---------------------------------------------------------------------------
 *  Gemeinsame Initialisierung (nach dem Clock-Setup in main())
 * ------------------------------------------------------------------------- */
void uart_common_init(void)
{
    /* Takte: GPIOA/B, AFIO, USART1 (APB2); USART2/3 (APB1) */
    RCC_APB2ENR |= RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN
                 | RCC_APB2ENR_USART1EN;
    RCC_APB1ENR |= RCC_APB1ENR_USART2EN | RCC_APB1ENR_USART3EN;

    /* Pinbelegung (Original-IVCU, siehe PINOUT.md):
     *   PA9  = USART1_TX (AF Push-Pull 50MHz -> CRH-Nibble 0xB)
     *   PA10 = USART1_RX (Floating Input      -> CRH-Nibble 0x4)
     *   PA2  = USART2_TX (0xB), PA3 = USART2_RX (0x4)
     *   PB10 = USART3_TX (0xB), PB11 = USART3_RX (0x4)
     * SWD (PA13/PA14) bleibt unangetastet! */
    GPIOA_CRL = (GPIOA_CRL & ~((0xFu << 8) | (0xFu << 12)))
              | (0xBu << 8) | (0x4u << 12);                 /* PA2 TX, PA3 RX */
    GPIOA_CRH = (GPIOA_CRH & ~((0xFu << 4) | (0xFu << 8)))
              | (0xBu << 4) | (0x4u << 8);                  /* PA9 TX, PA10 RX */
    GPIOB_CRH = (GPIOB_CRH & ~((0xFu << 8) | (0xFu << 12)))
              | (0xBu << 8) | (0x4u << 12);                 /* PB10 TX, PB11 RX */

    /* Baudraten (Werte siehe ivcu_hw.h; Uhrenannahme s.o.) */
    USART_BRR(USART1_BASE) = USART_BRR_115200_APB2_24M;
    USART_BRR(USART2_BASE) = USART_BRR_115200_APB1_12M;
    USART_BRR(USART3_BASE) = USART_BRR_9600_APB1_12M;

    /* RX-Interrupts: IRQ37/38/39 -> NVIC ISER1 (Bits 5/6/7) */
    NVIC_ISER[1] = (1u << (IRQ_USART1 - 32u))
                 | (1u << (IRQ_USART2 - 32u))
                 | (1u << (IRQ_USART3 - 32u));

    USART_CR1(USART1_BASE) = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
    USART_CR1(USART2_BASE) = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
    USART_CR1(USART3_BASE) = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
}

/* ---------------------------------------------------------------------------
 *  IRQ-Einsprungpunkte (Vektortabelle: startup.c)
 * ------------------------------------------------------------------------- */
void USART1_IRQHandler(void) { uart_rx_irq(USART1_BASE); }
void USART2_IRQHandler(void) { uart_rx_irq(USART2_BASE); }
void USART3_IRQHandler(void) { uart_rx_irq(USART3_BASE); }
