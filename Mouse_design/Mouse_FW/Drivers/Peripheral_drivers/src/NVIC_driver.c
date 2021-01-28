/*
 *  NVIC_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "NVIC_driver.h"
#include "EXTI_driver.h"
#include "ADC_driver.h"
#include "TIM16_driver.h"

void NVIC_setTIM16Line(uint8_t srValue){
	uint32_t* reg;

	if(srValue == 1){
		reg = (uint32_t*)NVIC_ISER_BASEADDR;
	}else{
		reg = (uint32_t*)NVIC_ICER_BASEADDR;
	}
	*reg = (0x1U << NVIC_LINE_TIM16);
}

void NVIC_setADCLine(uint8_t srValue){
	uint32_t* reg;

	if(srValue == 1){
		reg = (uint32_t*)NVIC_ISER_BASEADDR;
	}else{
		reg = (uint32_t*)NVIC_ICER_BASEADDR;
	}
	*reg = (0x1U << NVIC_LINE_ADC);
}

void NVIC_setEXTILine(uint8_t lineNum, uint8_t srValue){
	uint8_t index;
	uint32_t* reg;
	switch(lineNum){
			case 0:
			case 1:
				index = 5;
				break;
			case 2:
			case 3:
				index = 6;
				break;
			case 16:
			case 31:
				index = 1;
				break;
			case 17:
			case 19:
			case 20:
				index = 2;
				break;
			case 21:
			case 22:
				index = 12;
				break;
			case 23:
				index = 23;
				break;
			case 25:
				index = 27;
				break;
			case 26:
				index = 28;
				break;
			case 28:
				index = 29;
				break;
			case 27:
				index = 30;
				break;
			case 18:
				index = 31;
				break;
			default:
				index = 7;
				break;
		}

	if(srValue == 1){
		reg = (uint32_t*)NVIC_ISER_BASEADDR;
	}else{
		reg = (uint32_t*)NVIC_ICER_BASEADDR;
	}

	*reg = (0x1U << index);
}

void EXTI4_15_IRQHandler(void){
	EXTI_interruptHandler(NVIC_LINE_EXTI4_15);
}

void ADC_COMP_IRQHandler(void){
	ADC_interruptHandler();
}

void TIM16_IRQHandler(void){
	TIM16_interruptHandler();
}












