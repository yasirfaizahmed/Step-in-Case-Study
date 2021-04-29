#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdint.h>

void loop(void);	//loop for real-time responses

void ADC_init(void);	//to set the ADC ready to start conversion

uint16_t ADC_read(short int channel);	//takes ADC_channel number, does the conversion, returns 16bit value (10bit significant only)

#endif