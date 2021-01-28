/*
 * EXTI_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef EXTI_DRIVER_H_
#define EXTI_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

#define RISING								1
#define FALLING								0

//EXTI registers structure definition
typedef struct
{
	volatile uint32_t IMR;					//Interrupt mask register
	volatile uint32_t EMR;					//Event mask register
	volatile uint32_t RTSR;					//Rising trigger selection register
	volatile uint32_t FTSR;					//Falling trigger selection register
	volatile uint32_t SWIER;				//Software interrupt event register
	volatile uint32_t PR;					//Pending register
} EXTI_handle_t;

//EXTI typecasted base addresses to EXTI_handle_t*
#define _EXTI								((EXTI_handle_t*)EXTI_BASEADDR)

//func prototypes
void EXTI_setInterrupt(uint8_t lineNum, uint8_t srValue);
void EXTI_setRisingEdge(uint8_t lineNum, uint8_t srValue);
void EXTI_setFallingEdge(uint8_t lineNum, uint8_t srValue);
void EXTI_resetPendingBit(uint8_t lineNum);
uint8_t EXTI_getPendingBit(uint8_t lineNum);
void EXTI_interruptHandler(uint8_t NVIC_line);

#endif /* EXTI_DRIVER_H_ */
