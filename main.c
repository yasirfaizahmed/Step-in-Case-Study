#include <avr/io.h>
#include <util/delay.h>
#include "inc/GPIO_DRIVER0.h"
#include "inc/ADC_DRIVER0.h"
#include "inc/UART_DRIVER0.h"

#define LED_Actuator    DDB5	//builtin-led @ pin13
#define Button_Sensor   DDB3	//Button sensor
#define Heater          DDB2	//Heater button 
#define Temp_Sensor     DDC0	//Analog o/pting temp sensor to uC analog pin
#define PWM_op			DDD3 	//PWM o/p depending on the temp_sensor value 

uint16_t potval  = 0;	//global var for temp value

void loop(void);	//main loop prototyping



/**
 *  \brief main function
 *  
 *  \return returns 1
 *  
 *  \details hadles all the calling of other functions and the main loop
 */
int main(void){	//main 
	pinMode('B', LED_Actuator, OUTPUT);	//as output
	pinMode('B', Button_Sensor, INPUT);	//as input
	pinMode('B', Heater, INPUT);	//as input
	//PORTB &= ~(_BV(Button_Sensor));  // no internal pull-up
	//PORTB &= ~(_BV(Heater));	//no internal pull-up
    //MCUCR |= (_BV(PUD));	//tri-state
	pinMode('D', PWM_op, OUTPUT);	//as output
	
	ADC_init(PRE_128, AVcc_external_AREF);	//slowest speed sys_clock/128 and external Vref pin 
	
	UART_init(103);	//9600 BR
	
	//timer setup
	TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
	TCCR2B = _BV(CS22);
	OCR2A = 1000;
	OCR2B = 100;
	
	///////////main loop 

					loop();	//calling the loop
					
	///////////main loop 
 
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
		if ( digitalRead('B', Button_Sensor) && digitalRead('B', Heater) ) digitalWrite('B', LED_Actuator, HIGH);	//if both the buttons are pressed 
		else digitalWrite('B', LED_Actuator, LOW); 	//else 
		
		potval = ADC_read(0);
		
		
		
		UART_tx_10bit(potval);
		
	}
}