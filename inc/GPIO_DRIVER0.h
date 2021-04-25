#ifndef GPIO_DRIVER0_H_INCLUDED
#define GPIO_DRIVER0_H_INCLUDED

#include <stdbool.h>

typedef enum{
	INPUT = 0,
	OUTPUT = 1,
}MODE;

typedef enum{
	LOW = 0,
	HIGH = 1,
}STATE;

void pinMode(char port, short PIN, MODE mode);	//to set the mode of the GPIO pin
void digitalWrite(char port, short PIN, STATE state);	//writes HIGH or LOW
bool digitalRead(char port, short PIN);	//returns true if PIN is HIGH, else returns false


#endif