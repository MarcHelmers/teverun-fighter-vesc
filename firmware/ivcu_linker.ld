/*
 * ivcu_linker.ld -- Linker-Skript-Geruest fuer eine kompatible
 *                   IVCU-Eigen-Firmware (STM32F1-artige Peripherie; Original: GD32F303-Klasse)
 * ============================================================================
 *
 * Ziel: App-Image fuer das Original-Bootloader-Fenster der IVCU
 *       (Firmware AWIVCU_APP R3.4.13).
 *
 *   FLASH-App-Fenster : 0x08007000 .. 0x0801EFFF  (LENGTH 0x18000)
 *   RAM               : 0x20000000 .. 0x20003FFF  (16 KiB)
 *   Stack-Top (_estack): 0x20003B90 (entspricht Vektoreintrag[0] der Original-FW;
 *                        darunter liegen in der Original-FW Datenbereiche)
 *
 * WICHTIG (Bootloader-Konvention, aus der Analyse abgeleitet):
 *   - Das Image wird bei 0x08007000 verlinkt; der Bootloader springt dorthin.
 *   - Vektoreintrag[0] (Initial-MSP) und [1] (Reset) liegen bei 0x08007000/04.
 *   - SystemInit() setzt SCB->VTOR auf 0x08007000 (siehe startup_ivcu.c).
 *   - Flag-Pages des Bootloaders (0x0801F000 Update-Request, 0x0801F800 App-Valid)
 *     sind NICHT Teil dieses Images und werden hier nicht angefasst.
 *
 * Status: GERTUEST -- mit arm-none-eabi-gcc + startup_ivcu.c verwendbar,
 *         aber ohne Anspruch auf Vollstaendigkeit (kein Heap, kein C++).
 */

ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08007000, LENGTH = 0x18000   /* App-Fenster bis 0x0801EFFF */
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x4000    /* 16 KiB SRAM */
}

/* Initialer Stackpointer = Vektoreintrag[0] (siehe startup_ivcu.c). */
_estack = 0x20003B90;

SECTIONS
{
    /* ------------------------------------------------------------------
     * Vektortabelle: MUSS absolut am Anfang des App-Fensters liegen,
     * damit 0x08007000 als Vektor-Basis (VTOR) funktioniert.
     * ------------------------------------------------------------------ */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH

    /* ------------------------------------------------------------------
     * Code
     * ------------------------------------------------------------------ */
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.glue_7)          /* ARM/Thumb-Interworking */
        *(.glue_7t)
        *(.eh_frame)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    /* ------------------------------------------------------------------
     * Konstanten / Nur-Lese-Daten
     * ------------------------------------------------------------------ */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    .ARM.extab :
    {
        . = ALIGN(4);
        *(.ARM.extab*)
        *(.gnu.linkonce.armextab.*)
        . = ALIGN(4);
    } > FLASH

    .ARM.exidx :
    {
        . = ALIGN(4);
        __exidx_start = .;
        *(.ARM.exidx*)
        *(.gnu.linkonce.armexidx.*)
        __exidx_end = .;
        . = ALIGN(4);
    } > FLASH

    /* ------------------------------------------------------------------
     * Initialisierte Daten: LMA im Flash, VMA im RAM.
     * Reset_Handler kopiert von __data_load nach __data_start..__data_end.
     * ------------------------------------------------------------------ */
    .data :
    {
        . = ALIGN(4);
        __data_start = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        __data_end = .;
    } > RAM AT> FLASH
    __data_load = LOADADDR(.data);

    /* ------------------------------------------------------------------
     * Null-initialisierte Daten: Reset_Handler loescht __bss_start..__bss_end.
     * ------------------------------------------------------------------ */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        __bss_start = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > RAM

    /* ------------------------------------------------------------------
     * Nicht verwendete Info-Sektionen verwerfen.
     * ------------------------------------------------------------------ */
    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
    }
}
