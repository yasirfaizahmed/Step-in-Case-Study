#ifndef UART_DRIVER0_H_INCLUDED
#define UART_DRIVER0_H_INCLUDED

#include <stdint.h>


/************************* function prototyping ***************************/
/**
 *  \brief initializes the UART 
 *  
 *  \param [in] ubrr ubrr is the calcutated value to set the baudrate to IEEE standard baudrates, 103 for 9600
 *  \return Return void
 *  
 *  \details More details
 */
void UART_init(uint16_t ubrr);	//init function



/**
 *  \brief Transmitts the uint8_t data 
 *  
 *  \param [in] data data 
 *  \return Return void
 *  
 *  \details More details
 */
void UART_tx(uint8_t data);	//tx functin



/**
 *  \brief This function transmits 10bit value through UART
 *  
 *  \param [in] ADC_10_bit uint16_t data-value to transmit
 *  \return void
 *  
 *  \details More details
 */
void UART_tx_10bit(uint16_t ADC_10_bit);
#endif