/*
 *  LED_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "GPIO_driver.h"
#include "LED_driver.h"
#include "RCC_driver.h"

void LED_init(void){
	//init PCLK
	RCC_initPCLK(RCC_GPIOB_EN, RCC_GPIOs_EN_REG);

	//left button PB8, push-pull, no-pull, medium speed
	GPIO_setMODER(_GPIOB, GPIO_LED_PIN_NUM, GPIO_MODE_OUTPUT);
	GPIO_setOTYPER(_GPIOB, GPIO_LED_PIN_NUM, GPIO_OTYPE_PP);
	GPIO_setOSPEEDR(_GPIOB, GPIO_LED_PIN_NUM, GPIO_OSPEED_MEDIUM);
	GPIO_setPUPDR(_GPIOB, GPIO_LED_PIN_NUM, GPIO_PUPD_NOPULL);
}

void LED_on(void){
	GPIO_setState(_GPIOB, GPIO_LED_PIN_NUM, 1);
}

void LED_off(void){
	GPIO_setState(_GPIOB, GPIO_LED_PIN_NUM, 0);
}














