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
	while( !( UCSR0A & (_BV(UDRE0))) );	// wait for transmit buffer to be empty
}

/**
 *  \brief This function transmits 10bit value through UART
 *  
 *  \param [in] ADC_10_bit uint16_t data-value to transmit
 *  \return void
 *  
 *  \details More details
 */
void UART_tx_10bit(uint16_t ADC_10_bit){
	uint8_t ones = 0, tens = 0, hundreds = 0, thousands = 0;
	uint16_t temp = ADC_10_bit;	//temporary 
	ones = temp % 10;
	temp /= 10;
	tens = temp % 10;
	temp /= 10;
	hundreds = temp % 10;
	thousands = temp/10;
	
	//HEX to ASCII
	ones += 0x30;
	tens += 0x30;
	hundreds += 0x30;
	thousands += 0x30;
	
	//Transmitting
	UART_tx(thousands);
	UART_tx(hundreds);
	UART_tx(tens);
	UART_tx(ones);
	
	UART_tx('\n');
}