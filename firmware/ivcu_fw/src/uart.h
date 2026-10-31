/*
 * uart.h -- UART-Treiber (IRQ-Empfang mit Ringen, blockierender Kurz-TX)
 * ============================================================================
 *  Drei Leitungen: BLE (USART1, 115200), VESC (USART2, 115200), Display
 *  (USART3, 9600). Alle Frames sind kurz (<100 B), daher blockierendes
 *  Senden mit TXE-Polling; Empfang laeuft ausschliesslich per Interrupt in
 *  Ringpuffer, damit keine Bytes verloren gehen (auch waehrend Display-TX).
 * ============================================================================
 */
#pragma once

#include <stdint.h>
#include <stddef.h>

/* Basis-Adressen (siehe ivcu_hw.h) als Leitungs-Handles */
int  uart_tx(uint32_t base, const uint8_t *data, size_t n);  /* 0 = ok */
int  uart_rx_avail(uint32_t base);
int  uart_rx_get(uint32_t base);                             /* -1 = leer */

void uart_common_init(void);      /* Uhren, GPIO, BRR, IRQ-Freigabe */
void uart_rx_irq(uint32_t base);  /* aus den IRQ-Handlern aufrufen */
