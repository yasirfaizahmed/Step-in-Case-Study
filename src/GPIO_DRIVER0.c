#include "../inc/GPIO_DRIVER0.h"
#include <avr/io.h>
#include <stdint.h>

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


void digitalWrite(char port, short PIN, STATE state){	//writes HIGH or LOW
	switch(port){
		case 'B':
			if(state == HIGH)  PORTB |= (_BV(PIN));
			if(state == LOW)   PORTB &= ~(_BV(PIN));
			break;
			
		default:
			break;
	}

}