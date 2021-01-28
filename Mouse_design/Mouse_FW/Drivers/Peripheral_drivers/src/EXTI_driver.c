/*
 *  EXTI_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "EXTI_driver.h"
#include "NVIC_driver.h"
#include "BUTTON_driver.h"

//activates interrupt
void EXTI_setInterrupt(uint8_t lineNum, uint8_t srValue){
	_EXTI->IMR &= ~(0x1U << lineNum);
	_EXTI->IMR |= (srValue << lineNum);
}

//set rising edge detection
void EXTI_setRisingEdge(uint8_t lineNum, uint8_t srValue){
	_EXTI->RTSR &= ~(0x1U << lineNum);
	_EXTI->RTSR |= (srValue << lineNum);
}

//set rising falling detection
void EXTI_setFallingEdge(uint8_t lineNum, uint8_t srValue){
	_EXTI->FTSR &= ~(0x1U << lineNum);
	_EXTI->FTSR |= (srValue << lineNum);
}

void EXTI_resetPendingBit(uint8_t lineNum){
	_EXTI->PR = (0x1U << lineNum);
}

//check which line calls interrupt
uint8_t EXTI_getPendingBit(uint8_t lineNum){
	uint8_t value;
	value = (_EXTI->PR >> lineNum) & 0x1U;
	return value;
}

void EXTI_interruptHandler(uint8_t NVIC_line){
	if(NVIC_line == NVIC_LINE_EXTI4_15){
		//which line
		uint8_t line = 0;
		for(int i = 4; i <= 15; i++){
			if(EXTI_getPendingBit(i)){
				EXTI_resetPendingBit(i);
				line = i;
				break;
			}
		}
		BUTTON_interruptHandler(line);
	}
}












