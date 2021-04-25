#include <avr/io.h>
#include <util/delay.h>
#include "inc/GPIO_DRIVER0.h"

#define Display_CDD     DDB5
#define Button_Sensor   DDB3	//something is wrong with my PORTB PIN4, so had to take PIN3
#define Heater          DDB2
#define Temp_Sensor     DDB1


int main(void)
{
	pinMode('B', Display_CDD, OUTPUT);
	pinMode('B', Button_Sensor, INPUT);
	pinMode('B', Heater, INPUT);
	//PORTB &= ~(_BV(Button_Sensor));  // no internal pull-up
	//PORTB &= ~(_BV(Heater));	//no internal pull-up
    //MCUCR |= (_BV(PUD));	//tri-state
    while (1)
    {
        if ( digitalRead('B', Button_Sensor) && digitalRead('B', Heater) ) digitalWrite('B', Display_CDD, HIGH);

        else digitalWrite('B', Display_CDD, LOW); 
    }
} 