#include <avr/io.h>
#include <util/delay.h>


#define Display_CDD     DDB5
#define Button_Sensor   DDB4
#define Heater          DDB3
#define Temp_Sensor     DDB2


int main(void)
{
    DDRB |= _BV(Display_CDD); // Configuring PB5 as Output
    DDRB &= ~(_BV(Button_Sensor)); // Configuring PB4 as Input
	DDRB &= ~(_BV(Heater));	// Configuring PB3 as Output
    
    while (1)
    {
        if ( ((PINB&(_BV(Button_Sensor)))>>Button_Sensor) == 1 ){
			if( ((PINB&(_BV(Heater)))>>Heater) == 1 ) PORTB |= (_BV(Display_CDD)); // Writing HIGH to glow LED
		}
        else PORTB &= ~(_BV(Display_CDD)); // Writing LOW 
    }
} 