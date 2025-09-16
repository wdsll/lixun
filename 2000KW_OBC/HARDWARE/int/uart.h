#ifndef __UART_H__
#define __UART_H__

#include <gd32f30x.h>

void uart0_init(void);
void uart0_send_string(uint8_t *str);
void uart0_send_data(uint8_t *data, int len);
void uart0_send_byte(uint8_t ch);

void uart2_init(void);

#endif


