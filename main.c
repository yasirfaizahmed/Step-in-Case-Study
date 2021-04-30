#include <avr/io.h>
#include <util/delay.h>
#include "inc/GPIO_DRIVER0.h"
#include "inc/ADC_DRIVER0.h"
#include "inc/UART_DRIVER0.h"

#define Display_CDD     DDB5
#define Button_Sensor   DDB3	//something is wrong with my PORTB PIN4, so had to take PIN3
#define Heater          DDB2
#define Temp_Sensor     DDB1

uint16_t val = 0;
void loop(void);

/**
 *  \brief main function
 *  
 *  \return returns 1
 *  
 *  \details hadles all the calling of other functions and the main loop
 */
int main(void){	//main 
	pinMode('B', Display_CDD, OUTPUT);	//as output
	pinMode('B', Button_Sensor, INPUT);	//as input
	pinMode('B', Heater, INPUT);	//as input
	//PORTB &= ~(_BV(Button_Sensor));  // no internal pull-up
	//PORTB &= ~(_BV(Heater));	//no internal pull-up
    //MCUCR |= (_BV(PUD));	//tri-state
	
	ADC_init(PRE_128, AVcc_external_AREF);	//slowest speed sys_clock/128 and external Vref pin 
	
	UART_init(103);	//9600 BR
	
	loop();	//calling the loop
 
} 

/**
 *  \brief main loop
 *  
 *  \return void
 *  
 *  \details handles all the real-time updating data streams 
 */
void loop(void){	//driver loop
	while(1){
		//both Button_Sensor and Heater must be on to turn on the actual heater
		if ( digitalRead('B', Button_Sensor) && digitalRead('B', Heater) ) digitalWrite('B', Display_CDD, HIGH);	//if both the buttons are pressed 
		else digitalWrite('B', Display_CDD, LOW); 	//else 
		
		val = ADC_read(0);	//reading from channel 0
		
		uint8_t data = 0x69;
		UART_tx(data);
		
	}
}