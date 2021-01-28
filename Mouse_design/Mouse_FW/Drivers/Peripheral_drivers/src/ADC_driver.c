/*
 * ADC_driver.c
 *
 *  Created on: Jan 1, 2021
 *      Author: sobik
 */

#include "ADC_driver.h"
#include "NVIC_driver.h"
#include "RCC_driver.h"

static uint16_t pressureRaw = 0;
static uint8_t dataUpdated = 0;

void ADC_init(void){
	//init PCLK
	RCC_initPCLK(RCC_ADC_EN, &RCC_ADC_EN_REG);

	//calibration
	_ADC->CR |= (0x1U << ADC_CALIBRATION);
	while(((_ADC->CR >> ADC_CALIBRATION) & 0x1U) == 0x1U){			//waiting for calibration end
	}

	_ADC->CR |= (0x1U << ADC_AD_EN);								//ADC enable
	while(((_ADC->ISR >> ADC_AD_RDY) & 0x1U) == 0x1U){				//waiting for adc ready
	}
	_ADC->ISR |= (0x1U << ADC_AD_RDY);								//delete ADC ready flag (by writing 1)
	_ADC->CHSELR = (0x1 << ADC_CHSEL_8);				//init ADC IN 8
	_ADC->SMPR = ADC_SAMPLING_28_5;						//cca 3us per sample (28.5 + 12.5 ADC clock at 14MHz)

	//set NVIC
	NVIC_setADCLine(1);

	//enable interrupt
	_ADC->IER |= (0x1U << ADC_END_OF_CONVERSION_INT);
}

void ADC_startConversion(void){
	_ADC->CR |= (0X1U << ADC_START_CONVERSION);
}

void ADC_interruptHandler(void){
	pressureRaw = (uint16_t)_ADC->DR;
	dataUpdated = 1;
}

_Bool ADC_valueUpdated(void){
	if(dataUpdated){
		dataUpdated = 0;
		return 1;
	}else{
		return 0;
	}
}

uint16_t getPressureRaw(void){
	return pressureRaw;
}
