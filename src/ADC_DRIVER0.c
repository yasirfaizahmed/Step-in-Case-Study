#include "../inc/ADC_DRIVER0.h"
#include <stdint.h>

void ADC_init(void){	//to set the ADC ready to start conversion
	//ADMUX |= _BV(MUX0);	//ADC0 is selected as input
	ADMUX |= _BV(REFS0);	//AVCC with external capacitor at AREF pin
	ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);	//ADC prescalar = sys_clock/128 (lowest possible speed)
	ADCSRA |= _BV(ADEN);	//finally enable the ADC
	
}

uint16_t ADC_read(short int channel){	////takes ADC_channel number, does the conversion, returns 16bit value (10bit significant only)
	
	
}