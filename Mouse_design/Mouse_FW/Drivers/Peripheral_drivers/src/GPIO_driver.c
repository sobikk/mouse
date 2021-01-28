/*
 *  GPIO_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "GPIO_driver.h"
#include "RCC_driver.h"

void GPIO_init(){
	//init PCLKs
	RCC_initPCLK(RCC_GPIOA_EN, &RCC_GPIOs_EN_REG);
	RCC_initPCLK(RCC_GPIOB_EN, &RCC_GPIOs_EN_REG);
}

void GPIO_setMODER(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t mode){
	GPIOx->MODER &= ~(0x3U << (pinNum * 2));
	GPIOx->MODER |= (mode << (pinNum * 2));
}

void GPIO_setOTYPER(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t otype){
	GPIOx->OTYPER &= ~(0x3U << pinNum);
	GPIOx->OTYPER |= (otype << pinNum);
}

void GPIO_setOSPEEDR(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t ospeed){
	GPIOx->OSPEEDR &= ~(0x3U << (pinNum * 2));
	GPIOx->OSPEEDR |= (ospeed << (pinNum * 2));
}

void GPIO_setPUPDR(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t pupd){
	GPIOx->PUPDR &= ~(0x3U << (pinNum * 2));
	GPIOx->PUPDR |= (pupd << (pinNum * 2));
}

void GPIO_setALTFUNC(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t func){
	uint8_t value;
	switch(func){
		case GPIO_ALTFUNC_SPI1:
			value = 0;
			break;
		default:
			break;
	}
	GPIOx->AFR[pinNum / 8] &= ~(0xFFU << (pinNum % 8) * 4);
	GPIOx->AFR[pinNum / 8] |= (value << (pinNum % 8) * 4);
}

void GPIO_setState(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t value){
	GPIOx->BSRR = (0x1U << (pinNum + (16 * (1 - value))));
}

uint8_t GPIO_getState(GPIO_handle_t* GPIOx, uint8_t pinNum){
	return (uint8_t)((GPIOx->IDR >> pinNum) & 0x1U);
}










