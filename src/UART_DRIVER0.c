#include "../inc/UART_DRIVER0.h"
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

/**
 *  \brief initializes the UART 
 *  
 *  \param [in] ubrr ubrr is the calcutated value to set the baudrate to IEEE standard baudrates, 103 for 9600
 *  \return Return void
 *  
 *  \details More details
 */
void UART_init(uint16_t ubrr){	//init function
    UBRR0L = (uint8_t)(ubrr & 0xFF);	//for 9600 baudrate
    UBRR0H = (uint8_t)(ubrr >> 8);

    UCSR0B |= _BV(RXEN0) | _BV(TXEN0);	// enable the transmitter and receiver
}

/**
 *  \brief Transmitts the uint8_t data 
 *  
 *  \param [in] data data 
 *  \return Return void
 *  
 *  \details More details
 */
void UART_tx(uint8_t data){	//tx functin
    UDR0 = data;	//send data
	_delay_ms(100);	// wait for transmit buffer to be empty
}