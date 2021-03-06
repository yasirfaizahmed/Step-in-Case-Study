#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdint.h>

/************************* Bit definitions ********************************/
// Voltage Reference Selections for ADC
#define Internal_Vref_off   (uint8_t) 0x00
#define AVcc_external_AREF	(uint8_t) 0x40
#define internal_1V_AREF    (uint8_t) 0xC0

//ADC Prescaler Selections
#define PRE_2   (uint8_t) 0x01
#define PRE_4   (uint8_t) 0x02
#define PRE_8   (uint8_t) 0x03
#define PRE_16  (uint8_t) 0x04
#define PRE_32  (uint8_t) 0x05
#define PRE_64  (uint8_t) 0x06
#define PRE_128 (uint8_t) 0x07

//custom definitions
#define POT 10000


/************************* function prototyping ***************************/
/**
 *  \brief initializes the ADC 
 *  
 *  \param [in] ADC_prescalar Prescalar value for ADC clock, ranges from 2 to 128
 *  \param [in] Vref to select the Vref value
 *  \return void
 *  
 *  \details More details
 */
void ADC_init(uint8_t ADC_prescalar, uint8_t Vref);	//to set the ADC ready to start conversion



/**
 *  \brief reads the analog value, converts it to 10bit value (uint16_t in our case)
 *  
 *  \param [in] channel Channel number
 *  \return ADC value
 *  
 *  \details More details
 */
uint16_t ADC_read(uint8_t channel);	//takes ADC_channel number, does the conversion, returns 16bit value (10bit significant only)

#endif