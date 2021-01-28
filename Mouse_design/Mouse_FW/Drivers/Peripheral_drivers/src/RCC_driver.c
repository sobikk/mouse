/*
 * RCC_driver.c
 *
 *  Created on: Dec 29, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "RCC_driver.h"

void RCC_initPCLK(uint8_t bit, volatile uint32_t* reg){
	//enable clock
	*reg |= (0x1U << bit);
}

void RCC_initClockSystem(void){
	//enable HSI48
	_RCC->CR2 |= (0x1U << RCC_HSI48_ON);

	//wait until HSI48 is ready
	while(((_RCC->CR2 >> RCC_HSI48_RDY) & 0x01U) != 0x01U){
	}

	//set HSI48 as clock source
	_RCC->CFGR |= (RCC_SOURCE_HSI48 << RCC_SW);

	//check bits 2:3 which source is selected (Ob11 is HSI48)
	while(((_RCC->CFGR >> RCC_SWS) & 0x3U) != RCC_SOURCE_HSI48_SELECTED){
	}

	//disable HSI
	_RCC->CR = 0x0U;
}


