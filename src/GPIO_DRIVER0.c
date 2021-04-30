#include "../inc/GPIO_DRIVER0.h"
#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
/**
 *  \brief sets the pin in certain mode
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \param [in] mode INPUT or OUTPUT mode 
 *  \return Return void
 *  
 *  \details More details
 */
void pinMode(char port, short PIN, MODE mode){	//to set the mode of the GPIO pin
	
	switch(port){
		case 'B':
			if(mode == OUTPUT)  DDRB |= (_BV(PIN));
			if(mode == INPUT)   DDRB &= ~(_BV(PIN));
			break;
		case 'C':
			if(mode == OUTPUT)  DDRC |= (_BV(PIN));
			if(mode == INPUT)   DDRC &= ~(_BV(PIN));
			break;
		case 'D':
			if(mode == OUTPUT)  DDRD |= (_BV(PIN));
			if(mode == INPUT)   DDRD &= ~(_BV(PIN));
			break;
			
		default:
			break;
	}
	
}

/**
 *  \brief Writes Logic HIGH or Logic LOW to the pin
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \param [in] state HIGH or LOW
 *  \return Return void
 *  
 *  \details More details
 */
void digitalWrite(char port, short PIN, STATE state){	//writes HIGH or LOW
	switch(port){
		case 'B':
			if(state == HIGH)  PORTB |= (_BV(PIN));
			if(state == LOW)   PORTB &= ~(_BV(PIN));
			break;
		case 'C':
			if(state == HIGH)  PORTC |= (_BV(PIN));
			if(state == LOW)   PORTC &= ~(_BV(PIN));
			break;
		case 'D':
			if(state == HIGH)  PORTD |= (_BV(PIN));
			if(state == LOW)   PORTD &= ~(_BV(PIN));
			break;
			
		default:
			break;
	}

}

/**
 *  \brief Reads the state of the PIN
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \return true if HIGH else false
 *  
 *  \details More details
 */
bool digitalRead(char port, short PIN){	//returns true if PIN is HIGH, else returns false
	switch(port){
		case 'B':
			return ( (PINB&(_BV(PIN))) >> PIN );
			break;
		case 'C':
			return ( (PINC&(_BV(PIN))) >> PIN );
			break;
		case 'D':
			return ( (PIND&(_BV(PIN))) >> PIN );
			break;
		default:
			break;
	}
	
	
}


