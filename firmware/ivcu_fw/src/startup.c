/*
 * startup.c -- Startcode der eigenen IVCU-Firmware
 * ============================================================================
 *  - Vektortabelle (64 Eintraege, STM32F1-Nummerierung) am Flash-Anfang
 *    des jeweiligen Linker-Fensters (__vectors aus ivcu_full.ld /
 *    ivcu_app_boot.ld; im Original: 0x08007000).
 *  - Reset_Handler: .data kopieren, .bss nullen, VTOR setzen, main() rufen.
 *  - Nur die genutzten IRQs sind verdrahtet: SysTick, USART1/2/3.
 *    Alles andere -> Default_Handler (Endlosschleife, wie Original-IAR).
 *  CMSIS-frei; bewusst minimal gehalten.
 * ============================================================================
 */
#include <stdint.h>
#include "ivcu_hw.h"

/* Symbole aus dem Linker-Skript */
extern uint32_t _estack;
extern uint32_t __data_load, __data_start, __data_end;
extern uint32_t __bss_start, __bss_end;
extern uint32_t __vectors[];

int main(void);

void Reset_Handler(void);
void Default_Handler(void) { for (;;) { } }

/* Schwache Standard-Handler; uart.c/main.c ueberschreiben die genutzten. */
void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));

/* IRQ-Nummer -> Vektorindex: Index = 16 + IRQ */

__attribute__((section(".isr_vector"), used))
const uint32_t vector_table[64] = {
    (uint32_t)&_estack,              /* [0]  Initial-MSP        */
    (uint32_t)Reset_Handler,         /* [1]  Reset              */
    (uint32_t)NMI_Handler,           /* [2]                     */
    (uint32_t)HardFault_Handler,     /* [3]                     */
    (uint32_t)MemManage_Handler,     /* [4]                     */
    (uint32_t)BusFault_Handler,      /* [5]                     */
    (uint32_t)UsageFault_Handler,    /* [6]                     */
    0, 0, 0, 0,                      /* [7..10] reserviert      */
    (uint32_t)SVC_Handler,           /* [11]                    */
    (uint32_t)DebugMon_Handler,      /* [12]                    */
    0,                               /* [13] reserviert         */
    (uint32_t)PendSV_Handler,        /* [14]                    */
    (uint32_t)SysTick_Handler,       /* [15]                    */

    /* IRQ0..IRQ36 (Vektor 16..52): Default */
    [16 ... 52] = (uint32_t)Default_Handler,
    /* Genutzte IRQs: USART1/2/3 = IRQ37/38/39 (Vektor 53/54/55) */
    [53] = (uint32_t)USART1_IRQHandler,  /* IRQ37: USART1 (BLE)     */
    [54] = (uint32_t)USART2_IRQHandler,  /* IRQ38: USART2 (ESC/VESC)*/
    [55] = (uint32_t)USART3_IRQHandler,  /* IRQ39: USART3 (Display) */
    /* IRQ40..IRQ47 (Vektor 56..63): Default */
    [56 ... 63] = (uint32_t)Default_Handler
};

void Reset_Handler(void)
{
    uint32_t *src = &__data_load;
    uint32_t *dst = &__data_start;
    while (dst < &__data_end) { *dst++ = *src++; }

    for (dst = &__bss_start; dst < &__bss_end; ) { *dst++ = 0u; }

    /* Vektor-Basis: 0x08000000 (Vollersatz) bzw. 0x08007000 (Bootloader-Fenster) */
    SCB_VTOR = (uint32_t)__vectors;

    (void)main();
    for (;;) { }
}
