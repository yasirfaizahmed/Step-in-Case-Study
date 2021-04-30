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


/************************* function prototyping ***************************/
/**
 *  \brief sets the pin in certain mode
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \param [in] mode INPUT or OUTPUT mode 
 *  \return Return void
 *  
 *  \details More details
 */
void pinMode(char port, short PIN, MODE mode);	//to set the mode of the GPIO pin



/**
 *  \brief Writes Logic HIGH or Logic LOW to the pin
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \param [in] state HIGH or LOW
 *  \return Return void
 *  
 *  \details More details
 */
void digitalWrite(char port, short PIN, STATE state);	//writes HIGH or LOW



/**
 *  \brief Reads the state of the PIN
 *  
 *  \param [in] port Port name, 'B' for portB, 'C' for portC and so on
 *  \param [in] PIN PIN number
 *  \return true if HIGH else false
 *  
 *  \details More details
 */
bool digitalRead(char port, short PIN);	//returns true if PIN is HIGH, else returns false


#endif