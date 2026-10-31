/*
 * ivcu_app_boot.ld -- Alternative: Original-Bootloader behalten
 * ============================================================================
 *
 *   FLASH-App-Fenster : 0x08007000 .. 0x0801EFFF  (LENGTH 0x18000)
 *   Flag-Pages        : 0x0801F000 (Update-Request) / 0x0801F800 (App-Valid)
 *   RAM               : 0x20000000 .. 0x20003FFF
 *
 * WICHTIG (aus der Community-/Firmware-Analyse, am Fahrzeug zu verifizieren):
 *   - App-Valid-Magic 0x5A5A5A5A @0x0801F800; Update-Request 0xA5A5A5A5
 *     @0x0801F000; CRC-16 (poly 0x8005) ueber den App-Bereich, FINISH
 *     restauriert das Valid-Flag erst nach CRC-Pass.
 *   - Dieses Skript laesst die Flag-Pages unberuehrt; sie muessen nach dem
 *     Flashen per Tool/SWD gesetzt werden (oder Original-Bootloader umgehen).
 *   - VTOR = 0x08007000 erledigt startup.c automatisch ueber __vectors.
 *
 * Nutzung:  make LDSCRIPT=ld/ivcu_app_boot.ld
 */

ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08007000, LENGTH = 0x18000   /* App-Fenster */
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x4000    /* 16 KiB */
}

_estack   = ORIGIN(RAM) + LENGTH(RAM);    /* 0x20004000 */
__vectors = ORIGIN(FLASH);                /* 0x08007000 */

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH

    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(4);
        _etext = .;
    } > FLASH

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

    /DISCARD/ :
    {
        *(.comment)
        *(.note*)
    }
}
