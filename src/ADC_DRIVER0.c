#include <avr/io.h>
#include "../inc/ADC_DRIVER0.h"
#include <stdint.h>
#include <util/delay.h>

/**
 *  \brief initializes the ADC 
 *  
 *  \param [in] ADC_prescalar Prescalar value for ADC clock, ranges from 2 to 128
 *  \param [in] Vref to select the Vref value
 *  \return void
 *  
 *  \details More details
 */
void ADC_init(uint8_t ADC_prescalar, uint8_t Vref){	//to set the ADC ready to start conversion
	ADMUX |= _BV(MUX0);	//ADC0 is selected as input
	ADMUX |= Vref;	//AVCC with external capacitor at AREF pin
	ADCSRA |= ADC_prescalar;	//ADC prescalar 
	ADCSRA |= _BV(ADEN);	//finally enable the ADC
	
}

/**
 *  \brief reads the analog value, converts it to 10bit value (uint16_t in our case)
 *  
 *  \param [in] channel Channel number
 *  \return ADC value
 *  
 *  \details More details
 */
uint16_t ADC_read(uint8_t channel){	
	//uint8_t ADC_Low_Byte = 0;
	//uint8_t ADC_High_Byte = 0;
	uint16_t ADC_10bit = 0;
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);	//last 4bits are for channel selection
	ADCSRA |= _BV(ADSC);	//single conversion mode
	while( !(ADCSRA & (1<<ADIF)) );	//wait till the ADSC bit gets cleared 
	_delay_ms(100);
	//ADC_Low_Byte =  ADCL;
	//ADC_High_Byte = ADCH;
	ADCSRA |= _BV(ADIF);
	ADC_10bit = ADC;	//in our case, ADCH reg holds the 10bit value
	return ADC_10bit;
	
	
	
}