/*
 * ADC_driver.h
 *
 *  Created on: Jan 1, 2021
 *      Author: sobik
 */

#ifndef PERIPHERAL_DRIVERS_ADC_DRIVER_H_
#define PERIPHERAL_DRIVERS_ADC_DRIVER_H_

#include "stm32f042c4.h"
#include "GPIO_driver.h"

//define bit positions
#define ADC_CALIBRATION					31
#define ADC_AD_EN						0
#define ADC_CHSEL_8						8
#define ADC_END_OF_CONVERSION_INT		2
#define ADC_START_CONVERSION			2
#define ADC_AD_RDY						0

//sampling times -> x+12.5 x ADC clock
#define ADC_SAMPLING_1_5					0U
#define ADC_SAMPLING_7_5					1U
#define ADC_SAMPLING_13_5					2U
#define ADC_SAMPLING_28_5					3U
#define ADC_SAMPLING_41_5					4U
#define ADC_SAMPLING_55_5					5U
#define ADC_SAMPLING_71_5					6U
#define ADC_SAMPLING_239_5					7U


//ADC registers structure definition
typedef struct
{
	volatile uint32_t ISR;					//Interrupt mask register
	volatile uint32_t IER;					//Event mask register
	volatile uint32_t CR;					//Rising trigger selection register
	volatile uint32_t CFGR1;				//Falling trigger selection register
	volatile uint32_t CFGR2;				//Software interrupt event register
	volatile uint32_t SMPR;					//Sampling time register
	volatile uint32_t RESERVED1[2];
	volatile uint32_t TR;					//Watchdog threshold register
	volatile uint32_t RESERVED2;
	volatile uint32_t CHSELR;				//Channel selection register
	volatile uint32_t RESERVED3[5];
	volatile uint32_t DR;					//Data register
} ADC_handle_t;

//ADC typecasted base addresses to EXTI_handle_t*
#define _ADC								((ADC_handle_t*)ADC_BASEADDR)

#define ADC_CCR_BASEADDRE					(ADC_BASEADDR + 0x308U)

//func prototypes
void ADC_init(void);
void ADC_startConversion(void);
void ADC_interruptHandler(void);
_Bool ADC_valueUpdated(void);
uint16_t getPressureRaw(void);


#endif /* PERIPHERAL_DRIVERS_ADC_DRIVER_H_ */
