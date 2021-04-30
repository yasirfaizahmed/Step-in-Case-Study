#ifndef UART_DRIVER0_H_INCLUDED
#define UART_DRIVER0_H_INCLUDED

#include <stdint.h>


void UART_init(uint16_t ubrr);	//init function
void UART_tx(uint8_t data);	//tx functin

#endif