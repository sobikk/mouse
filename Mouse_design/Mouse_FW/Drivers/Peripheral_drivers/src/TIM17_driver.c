/*
 * TIM17_driver.c
 *
 *  Created on: Dec 31, 2020
 *      Author: sobik
 */


/*
 * for us poll delays
 */

#include "TIM17_driver.h"
#include "RCC_driver.h"

static uint16_t prescaler = 0;

#define TIM17_CNT_EN						0

void TIM17_init(void){
	//init PCLK
	RCC_initPCLK(RCC_TIM17_EN, &RCC_TIM17_EN_REG);
	_TIM17->PSC = TIM17_PRESCALER_1US; 							//Set prescaler
	prescaler = TIM17_PRESCALER_1US;
	_TIM17->CR1 |= (0x1U << TIM17_CNT_EN);						//enable counter
	_TIM17->ARR = 0xFFFFU;										//max auto reaload value
}

//funguje az od 8 us
void TIM17_delayUs(uint16_t delay){
	_TIM17->CNT = 0x0U;											//null counter
	_TIM17->SR &= ~(0x1U >> TIM17_EVENT_FLAG);					//clear event flag
	_TIM17->CNT = 0xFFFFU - delay + 1;							//set delay
	while((_TIM17->SR & 0x1U) == 0){							//wait for event
	}
}

