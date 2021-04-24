#ifndef GPIO_DRIVER0_H_INCLUDED
#define GPIO_DRIVER0_H_INCLUDED

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

#endif