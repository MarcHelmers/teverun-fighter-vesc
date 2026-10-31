/*
 * ivcu_full.ld -- Vollersatz-Linker-Skript (EMPFOHLEN fuer v1)
 * ============================================================================
 *
 *   FLASH : 0x08000000 .. 0x0801FFFF   (128 KiB, GD32F303CB-Klasse; bei
 *           groesserem Flash (CC/256K, CE/512K) LENGTH anpassen)
 *   RAM   : 0x20000000 .. 0x20003FFF   (16 KiB; bei 32-KiB-Teilen erweiterbar)
 *
 * Strategie: KOMPLETTES Image ab Flash-Anfang. Der Original-Bootloader
 * (App-Fenster 0x08007000, Flag-Pages 0x0801F000/0x0801F800) wird dabei
 * ueberschrieben -> einfachster, robustester Bring-up. Das Original-HEX liegt
 * als Restore-Backup vor (SWD-Dump/flashen jederzeit moeglich).
 *
 * Alternative (Original-Bootloader behalten): ld/ivcu_app_boot.ld.
 *
 * Hinweise:
 *  - _estack = 0x20004000 (16-KiB-SRAM-Ende). Die Original-FW nutzte
 *    0x20003B90 (Datenbereich darunter); wir ersetzen die App komplett und
 *    duerfen das volle RAM verwenden.
 *  - __vectors = ORIGIN(FLASH): startup.c setzt SCB->VTOR darauf.
 *    (Im Original: VTOR = 0x08007000.)
 */

ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 0x20000   /* 128 KiB */
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x4000    /* 16 KiB */
}

_estack  = ORIGIN(RAM) + LENGTH(RAM);     /* 0x20004000 */
__vectors = ORIGIN(FLASH);

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
