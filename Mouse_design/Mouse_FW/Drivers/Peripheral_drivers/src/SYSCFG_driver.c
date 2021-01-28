/*
 *  SYSCFG_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "SYSCFG_driver.h"
#include "RCC_driver.h"

void SYSCFG_init(){
	//init PCLK and GPIOs
	RCC_initPCLK(RCC_SYSCFG_EN, &RCC_SYSCFG_EN_REG);
}

void SYSCFG_setEXTIConfig(uint8_t lineNum, GPIO_handle_t* GPIOx){
	uint8_t value = 0;

	switch((uint32_t)GPIOx){
		case (uint32_t)_GPIOA:
			value = 0;
			break;
		case (uint32_t)_GPIOB:
			value = 1;
			break;
		default:
			break;
	}
	_SYSCFG->EXTICR[lineNum / 4] &= ~(0xFU << (lineNum % 4));
	_SYSCFG->EXTICR[lineNum / 4] |= (value << (lineNum % 4) * 4);
}












