/*
 * startup_ivcu.c -- Startcode-Geruest fuer eine kompatible IVCU-Eigen-Firmware
 * ============================================================================
 *
 * Ziel-MCU   : STM32F1-artige Peripherie (Original-IVCU: GD32F303-Klasse, Cortex-M4F)
 * App-Fenster: ab 0x08007000 (siehe ivcu_linker.ld)
 * Referenz   : Firmware AWIVCU_APP R3.4.13 der Original-IVCU
 *              (Reset-Vektor 0x08007161, Startup @0x08007144,
 *               Stack-Top 0x20003B90,
 *               SCB->VTOR = 0x08007000 im SystemInit: _DAT_E000ED08 = 0x08007000)
 *
 * STATUS: GERTUEST / SKELETT -- bewusst CMSIS-frei und mit reinem C geschrieben.
 *         Es ist mit arm-none-eabi-gcc *_nicht* als vollstaendiges Projekt
 *         kompilierbar, wenn kein main() und ivcu_linker.ld verwendet werden;
 *         als Vorlage fuer eine eigene App aber direkt einsetzbar.
 *
 * Hinweise zur Kompatibilitaet mit dem Original-Bootloader:
 *   - Das Image wird bei 0x08007000 verlinkt und gestartet.
 *   - _estack (0x20003B90) wird als Vektoreintrag[0] abgelegt.
 *   - Die Vektortabelle hat 64 Eintraege:
 *       [0]  Initial-MSP
 *       [1]  Reset
 *       [2..6] NMI/HardFault/MemManage/BusFault/UsageFault
 *       [7..10] reserviert
 *       [11] SVCall, [12] DebugMonitor, [13] reserviert
 *       [14] PendSV, [15] SysTick
 *       [16..63] IRQ0..IRQ47 (STM32F1-Nummerierung)
 *   - Als schwach gebundene IRQ-Handler sind nur die vom Original genutzten
 *     vorgesehen: TIM2 (IRQ28) sowie USART1/2/3 (IRQ37/38/39).
 *     Alle uebrigen IRQs verweisen auf Default_Handler.
 */

#include <stdint.h>

/* ==========================================================================
 * 1) Symbole aus dem Linker-Skript (ivcu_linker.ld)
 * ========================================================================== */
extern uint32_t _estack;        /* Stack-Top (0x20003B90)                  */
extern uint32_t __data_load;    /* LMA der .data-Sektion (im Flash)        */
extern uint32_t __data_start;   /* VMA .data im RAM (Start)                */
extern uint32_t __data_end;     /* VMA .data im RAM (Ende)                 */
extern uint32_t __bss_start;    /* .bss Start im RAM                       */
extern uint32_t __bss_end;      /* .bss Ende im RAM                        */

extern int main(void);          /* Anwendungs-Einstiegspunkt (App)         */

/* ==========================================================================
 * 2) Minimaldefinitionen (CMSIS-frei)
 * ========================================================================== */
typedef void (*ivcu_isr_t)(void);

#define IVCU_VECTOR_COUNT   64u
#define IVCU_APP_BASE       0x08007000u
#define IVCU_SCB_VTOR       (*(volatile uint32_t *)0xE000ED08u)   /* Vektor-Offset */
/* RCC / FLASH fuer die SystemInit-Andeutung:
 *   RCC   @ 0x40021000 (CR/CFGR), FLASH @ 0x40022000 (ACR) */

static inline void ivcu_set_msp(uint32_t top)
{
    /* MSP setzen -- ueber den Vektoreintrag[0] initialisierbar. */
    __asm volatile ("msr msp, %0" : : "r" (top));
}

/* ==========================================================================
 * 3) Handler-Deklarationen (vor der Vektortabelle)
 * ========================================================================== */
void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void Default_Handler(void);

/* App-spezifische IRQ-Handler (schwache Geruest-Funktionen, siehe unten) */
void TIM2_IRQHandler(void);      /* IRQ28: Zeitbasis der Original-FW        */
void USART1_IRQHandler(void);    /* IRQ37: BLE/App, 115200 Bd               */
void USART2_IRQHandler(void);    /* IRQ38: Motorcontroller/ESC, 9600 Bd     */
void USART3_IRQHandler(void);    /* IRQ39: Display, 9600 Bd                 */

/* ==========================================================================
 * 4) Vektortabelle (64 Eintraege) -- per Linker-Skript an den Image-Anfang
 * ========================================================================== */
__attribute__((section(".isr_vector"), used))
const ivcu_isr_t g_ivcu_vector_table[IVCU_VECTOR_COUNT] =
{
    (ivcu_isr_t)(uintptr_t)&_estack,    /* [ 0] 0x00: Initial-MSP (0x20003B90) */
    Reset_Handler,                      /* [ 1] 0x04: Reset                    */
    NMI_Handler,                        /* [ 2] 0x08: NMI                      */
    HardFault_Handler,                  /* [ 3] 0x0C: HardFault                */
    MemManage_Handler,                  /* [ 4] 0x10: MemManage                */
    BusFault_Handler,                   /* [ 5] 0x14: BusFault                 */
    UsageFault_Handler,                 /* [ 6] 0x18: UsageFault               */
    0, 0, 0, 0,                         /* [ 7..10] reserviert                */
    SVC_Handler,                        /* [11] 0x2C: SVCall                   */
    DebugMon_Handler,                   /* [12] 0x30: DebugMonitor             */
    0,                                  /* [13] 0x34: reserviert               */
    PendSV_Handler,                     /* [14] 0x38: PendSV                   */
    SysTick_Handler,                    /* [15] 0x3C: SysTick                  */

    /* ---- IRQ0..IRQ47 (Tabellenindex 16..63) ---------------------------- */
    Default_Handler,                    /* [16] IRQ0 : WWDG                    */
    Default_Handler,                    /* [17] IRQ1 : PVD                     */
    Default_Handler,                    /* [18] IRQ2 : TAMPER                  */
    Default_Handler,                    /* [19] IRQ3 : RTC                     */
    Default_Handler,                    /* [20] IRQ4 : FLASH                   */
    Default_Handler,                    /* [21] IRQ5 : RCC                     */
    Default_Handler,                    /* [22] IRQ6 : EXTI0                   */
    Default_Handler,                    /* [23] IRQ7 : EXTI1                   */
    Default_Handler,                    /* [24] IRQ8 : EXTI2                   */
    Default_Handler,                    /* [25] IRQ9 : EXTI3                   */
    Default_Handler,                    /* [26] IRQ10: EXTI4                   */
    Default_Handler,                    /* [27] IRQ11: DMA1_Channel1           */
    Default_Handler,                    /* [28] IRQ12: DMA1_Channel2           */
    Default_Handler,                    /* [29] IRQ13: DMA1_Channel3           */
    Default_Handler,                    /* [30] IRQ14: DMA1_Channel4           */
    Default_Handler,                    /* [31] IRQ15: DMA1_Channel5  (UART-RX DMA) */
    Default_Handler,                    /* [32] IRQ16: DMA1_Channel6           */
    Default_Handler,                    /* [33] IRQ17: DMA1_Channel7  (UART-RX DMA) */
    Default_Handler,                    /* [34] IRQ18: ADC1_2                  */
    Default_Handler,                    /* [35] IRQ19: USB_HP_CAN1_TX          */
    Default_Handler,                    /* [36] IRQ20: USB_LP_CAN1_RX0         */
    Default_Handler,                    /* [37] IRQ21: CAN1_RX1                */
    Default_Handler,                    /* [38] IRQ22: CAN1_SCE                */
    Default_Handler,                    /* [39] IRQ23: EXTI9_5                 */
    Default_Handler,                    /* [40] IRQ24: TIM1_BRK                */
    Default_Handler,                    /* [41] IRQ25: TIM1_UP                 */
    Default_Handler,                    /* [42] IRQ26: TIM1_TRG_COM            */
    Default_Handler,                    /* [43] IRQ27: TIM1_CC                 */
    TIM2_IRQHandler,                    /* [44] IRQ28: TIM2  (Zeitbasis)       */
    Default_Handler,                    /* [45] IRQ29: TIM3                    */
    Default_Handler,                    /* [46] IRQ30: TIM4                    */
    Default_Handler,                    /* [47] IRQ31: I2C1_EV (EEPROM)        */
    Default_Handler,                    /* [48] IRQ32: I2C1_ER (EEPROM)        */
    Default_Handler,                    /* [49] IRQ33: I2C2_EV                 */
    Default_Handler,                    /* [50] IRQ34: I2C2_ER                 */
    Default_Handler,                    /* [51] IRQ35: SPI1                    */
    Default_Handler,                    /* [52] IRQ36: SPI2                    */
    USART1_IRQHandler,                  /* [53] IRQ37: USART1 (BLE/App)        */
    USART2_IRQHandler,                  /* [54] IRQ38: USART2 (ESC)            */
    USART3_IRQHandler,                  /* [55] IRQ39: USART3 (Display)        */
    Default_Handler,                    /* [56] IRQ40: EXTI15_10               */
    Default_Handler,                    /* [57] IRQ41: RTCAlarm                */
    Default_Handler,                    /* [58] IRQ42: USBWakeUp               */
    Default_Handler,                    /* [59] IRQ43: TIM8_BRK                */
    Default_Handler,                    /* [60] IRQ44: TIM8_UP                 */
    Default_Handler,                    /* [61] IRQ45: TIM8_TRG_COM            */
    Default_Handler,                    /* [62] IRQ46: TIM8_CC                 */
    Default_Handler                     /* [63] IRQ47: ADC3                    */
};

/* ==========================================================================
 * 5) Standard-Handler und schwache Kern-/IRQ-Handler
 * ========================================================================== */
__attribute__((noreturn))
void Default_Handler(void)
{
    /* Alle nicht benutzten Ausnahmen/IRQs landen hier.
     * Fuer die Fehlersuche kann hier ein Breakpoint gesetzt werden. */
    for (;;)
    {
    }
}

/* Kern-Ausnahmen: schwach an Default_Handler gebunden; die App kann sie
 * durch eine eigene (starke) Definition ersetzen. */
__attribute__((weak, alias("Default_Handler"))) void NMI_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void HardFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void MemManage_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void BusFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void UsageFault_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SVC_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void DebugMon_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void PendSV_Handler(void);
__attribute__((weak, alias("Default_Handler"))) void SysTick_Handler(void);

/* App-IRQ-Handler (Geruest, absichtlich leer): nur TIM2 und USART1/2/3 sind
 * als weak-Implementierungen vorgesehen -- alle anderen IRQs bleiben
 * Default_Handler. Eigene Firmware ueberschreibt diese Funktionen einfach
 * mit einer starken Definition (ohne __attribute__((weak))). */
__attribute__((weak)) void TIM2_IRQHandler(void)
{
    /* TODO: Update-Interrupt-Flag loeschen und Zeitbasis bedienen.
     * Original (FUN_0800B4F0) loescht nur das Update-Flag (TIM2->SR). */
}

__attribute__((weak)) void USART1_IRQHandler(void)
{
    /* TODO: BLE/App-Kanal (115200 Bd; Original nutzt DMA-Kanal 5 fuer RX). */
}

__attribute__((weak)) void USART2_IRQHandler(void)
{
    /* TODO: Motorcontroller/ESC (9600 Bd, RX per IRQ in der Original-FW). */
}

__attribute__((weak)) void USART3_IRQHandler(void)
{
    /* TODO: Display (9600 Bd; Original nutzt DMA-Kanal 7 fuer RX). */
}

/* ==========================================================================
 * 6) SystemInit -- minimale Systemkonfiguration
 * ========================================================================== */
void SystemInit(void)
{
    /* Vektor-Offset auf das App-Fenster umbiegen; der Original-Bootloader
     * springt zwar bei 0x08007000 an, setzt VTOR aber nicht selbst. */
    IVCU_SCB_VTOR = IVCU_APP_BASE;

    /* RCC-Andeutung (im Geruest bewusst nur Kommentar):
     * Die Original-Firmware arbeitet mit HSE + PLL, PPRE2 = /2 (APB2) und
     * PPRE1 = /4 (APB1). Typischer F1-Ablauf fuer eine eigene Uhr (48..72 MHz):
     *
     *   RCC->CR   |= (1u << 16);                     // HSEON
     *   while ((RCC->CR & (1u << 17)) == 0) { }      // HSERDY abwarten
     *   FLASH->ACR = (FLASH->ACR & ~7u) | 2u;        // 2 Waitstates ab 48 MHz
     *   RCC->CFGR |= (1u << 16);                     // PLLSRC = HSE
     *   RCC->CFGR = (RCC->CFGR & ~0x003C0000u) | (9u << 18);  // PLLMUL = x9
     *   RCC->CFGR = (RCC->CFGR & ~0x00000700u) | (5u << 8);   // PPRE1 = /4 (0b101)
     *   RCC->CFGR = (RCC->CFGR & ~0x00003800u) | (4u << 11);  // PPRE2 = /2 (0b100)
     *   RCC->CR   |= (1u << 24);                     // PLLON
     *   while ((RCC->CR & (1u << 25)) == 0) { }      // PLLRDY abwarten
     *   RCC->CFGR = (RCC->CFGR & ~3u) | 2u;          // SYSCLK = PLL
     *   while ((RCC->CFGR & (3u << 2)) != (2u << 2)) { }  // SWS abwarten
     *
     * (RCC @ 0x40021000, FLASH-IF @ 0x40022000; in dieser minimalen Vorlage
     *  absichtlich nicht ausprogrammiert.) */
}

/* ==========================================================================
 * 7) Reset_Handler
 * ========================================================================== */
void Reset_Handler(void)
{
    /* Stackpointer aus dem ersten Vektoreintrag laden. Die Hardware setzt
     * MSP beim Reset bereits daraus; hier explizit, damit der Ablauf auch bei
     * abweichendem Bootpfad/Remap eindeutig ist. */
    ivcu_set_msp((uint32_t)(uintptr_t)g_ivcu_vector_table[0]);

    /* Systemkonfiguration (VTOR + Uhr-Andeutung) */
    SystemInit();

    /* -- .data: Initialwerte aus dem Flash nach RAM kopieren --------------- */
    {
        const uint32_t *src = &__data_load;
        uint32_t *dst = &__data_start;
        while (dst < &__data_end)
        {
            *dst++ = *src++;
        }
    }

    /* -- .bss: mit 0 initialisieren ---------------------------------------- */
    {
        uint32_t *dst = &__bss_start;
        while (dst < &__bss_end)
        {
            *dst++ = 0u;
        }
    }

    /* Optional: newlib/glibc-Konstruktoren (nur bei C++/ _init-Modulen noetig)
     *   extern void __libc_init_array(void);
     *   __libc_init_array();
     */

    /* -- Anwendung starten -------------------------------------------------- */
    (void)main();

    /* Falls main() zurueckkehrt: hier bleiben (kein Bootloader-Ruecksprung). */
    for (;;)
    {
    }
}
