/*
 * ivcu_hw.h -- Registerkarte der IVCU (STM32F1-artig, GD32F303-Klasse)
 * ============================================================================
 *  Bewusst CMSIS-frei: nur die vom Projekt benoetigten Register/Bits.
 *  Adressen aus der Firmware-Analyse (siehe ../AWIVCU_APP_R3_4_13_Doku_FINAL.md):
 *    RCC 0x40021000, FLASH-IF 0x40022000, GPIOA/B 0x40010800/0x40010C00,
 *    USART1 0x40013800, USART2 0x40004400, USART3 0x40004800.
 *  NVIC/SCB/SysTick (Cortex-M): 0xE000E000-Bereich.
 * ============================================================================
 */
#pragma once

#include <stdint.h>

#define REG32(a)  (*(volatile uint32_t *)(uintptr_t)(a))
#define REG16(a)  (*(volatile uint16_t *)(uintptr_t)(a))

/* ---------------------------------------------------------------------------
 * RCC (Reset & Clock Control)
 * ------------------------------------------------------------------------- */
#define RCC_BASE      0x40021000u
#define RCC_CR        REG32(RCC_BASE + 0x00u)
#define RCC_CFGR      REG32(RCC_BASE + 0x04u)
#define RCC_APB2ENR   REG32(RCC_BASE + 0x18u)
#define RCC_APB1ENR   REG32(RCC_BASE + 0x1Cu)

#define RCC_CR_HSEON      (1u << 16)
#define RCC_CR_HSERDY     (1u << 17)
#define RCC_CR_HSION      (1u << 0)
#define RCC_CR_HSIRDY     (1u << 1)
#define RCC_CR_PLLON      (1u << 24)
#define RCC_CR_PLLRDY     (1u << 25)

/* CFGR: PLL: PLLSRC=1 (HSE), PLLXTPRE=1 (HSE/2), PLLMUL=1010 (x12)
 *       -> 8 MHz / 2 * 12 = 48 MHz; HSI-Fallback: PLLSRC=0 (HSI/2 = 4 MHz).
 *       Achtung F1-Codierung: PLLMUL x12 = 1010b (NICHT 12!). */
#define RCC_CFGR_SW       (3u << 0)
#define RCC_CFGR_SWS      (3u << 2)
#define RCC_CFGR_SW_PLL    (2u << 0)     /* SW=10b: PLL als Systemtakt */
#define RCC_CFGR_HPRE_DIV1   (0u << 4)
#define RCC_CFGR_PPRE1_DIV4  (5u << 8)   /* 101b = /4 -> APB1 12 MHz */
#define RCC_CFGR_PPRE2_DIV2  (4u << 11)  /* 100b = /2 -> APB2 24 MHz */
#define RCC_CFGR_PLLSRC      (1u << 16)
#define RCC_CFGR_PLLXTPRE    (1u << 17)
#define RCC_CFGR_PLLMUL12    (10u << 18) /* 1010b = x12 */

#define RCC_APB2ENR_AFIOEN   (1u << 0)
#define RCC_APB2ENR_IOPAEN   (1u << 2)
#define RCC_APB2ENR_IOPBEN   (1u << 3)
#define RCC_APB2ENR_IOPCEN   (1u << 4)
#define RCC_APB2ENR_IOPDEN   (1u << 5)
#define RCC_APB2ENR_USART1EN (1u << 14)
#define RCC_APB2ENR_ADC1EN   (1u << 9)   /* nur Doku: IVCU nutzt KEIN ADC */
#define RCC_APB1ENR_USART2EN (1u << 17)
#define RCC_APB1ENR_USART3EN (1u << 18)

/* ---------------------------------------------------------------------------
 * FLASH-Interface
 * ------------------------------------------------------------------------- */
#define FLASH_ACR     REG32(0x40022000u)
#define FLASH_ACR_LATENCY_1  (1u << 0)   /* 48 MHz: 1 Wait-State (konservativ) */
#define FLASH_ACR_PRFTBE     (1u << 4)

/* ---------------------------------------------------------------------------
 * GPIO (nur A und der fuer uns noetige B-Teil)
 * ------------------------------------------------------------------------- */
#define GPIOA_BASE    0x40010800u
#define GPIOB_BASE    0x40010C00u
#define GPIOA_CRL     REG32(GPIOA_BASE + 0x00u)
#define GPIOA_CRH     REG32(GPIOA_BASE + 0x04u)
#define GPIOB_CRL     REG32(GPIOB_BASE + 0x00u)
#define GPIOB_CRH     REG32(GPIOB_BASE + 0x04u)
#define GPIOB_ODR     REG32(GPIOB_BASE + 0x0Cu)

/* ---------------------------------------------------------------------------
 * USARTs
 * ------------------------------------------------------------------------- */
#define USART1_BASE   0x40013800u
#define USART2_BASE   0x40004400u
#define USART3_BASE   0x40004800u

#define USART_SR(base)    REG32((base) + 0x00u)
#define USART_DR(base)    REG32((base) + 0x04u)
#define USART_BRR(base)   REG32((base) + 0x08u)
#define USART_CR1(base)   REG32((base) + 0x0Cu)

#define USART_SR_RXNE   (1u << 5)
#define USART_SR_ORE    (1u << 3)
#define USART_SR_TXE    (1u << 7)
#define USART_SR_TC     (1u << 6)
#define USART_CR1_RE    (1u << 2)
#define USART_CR1_TE    (1u << 3)
#define USART_CR1_RXNEIE (1u << 5)
#define USART_CR1_UE    (1u << 13)

/* BRR-Werte = Registerinhalt (Mantisse[15:4] | Fraktion[3:0]):
 *   USART1 (APB2 24 MHz, 115200): 208.33 -> (208<<4)|5  = 0xD05
 *   USART2 (APB1 12 MHz, 115200): 104.17 -> (104<<4)|3  = 0x683
 *   USART3 (APB1 12 MHz,  9600): 1250.0 -> (1250<<4)|0 = 0x4E20 */
#define USART_BRR_115200_APB2_24M  0xD05u
#define USART_BRR_115200_APB1_12M  0x683u
#define USART_BRR_9600_APB1_12M    0x4E20u

/* ---------------------------------------------------------------------------
 * Cortex-M Kern: SysTick, NVIC, SCB
 * ------------------------------------------------------------------------- */
#define SYSTICK_CTRL  REG32(0xE000E010u)
#define SYSTICK_LOAD  REG32(0xE000E014u)
#define SYSTICK_VAL   REG32(0xE000E018u)
#define SYSTICK_CTRL_ENABLE    (1u << 0)
#define SYSTICK_CTRL_TICKINT   (1u << 1)
#define SYSTICK_CTRL_CLKSOURCE (1u << 2)   /* 1 = Prozessortakt (kein /8) */

#define NVIC_ISER     ((volatile uint32_t *)0xE000E100u)
#define SCB_VTOR      REG32(0xE000ED08u)

/* STM32F1-IRQ-Nummern (Vektortabelle: IRQ0 = Eintrag 16) */
#define IRQ_USART1    37u
#define IRQ_USART2    38u
#define IRQ_USART3    39u
