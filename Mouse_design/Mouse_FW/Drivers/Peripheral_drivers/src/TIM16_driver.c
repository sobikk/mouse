/*
 * TIM16_driver.c
 *
 *  Created on: Jan 3, 2021
 *      Author: sobik
 */

/*
 * for us periodic ticker
 */

#include "TIM16_driver.h"
#include "DEV_driver.h"
#include "NVIC_driver.h"
#include "RCC_driver.h"

void TIM16_init(uint16_t periodUs){
	//init PCLK
	RCC_initPCLK(RCC_TIM16_EN, &RCC_TIM16_EN_REG);

	_TIM16->PSC = TIM16_PRESCALER_1US; 						//Set prescaler
	_TIM16->ARR = periodUs;									//set delay

	//enable interrupt
	NVIC_setTIM16Line(1);
	_TIM16->DIER |= (0x1U << TIM16_UPDATE_INT_EN);			//enable update interrupt flag

	//enable timer
	_TIM16->CR1 |= (0x1U << TIM16_COUNTER_EN);
}

//periodic device report
void TIM16_interruptHandler(void){
	_TIM16->SR &= ~(0x1U << TIM16_UPDATE_INT_FLAG);			//clear event flag
	DEV_tick();
}

