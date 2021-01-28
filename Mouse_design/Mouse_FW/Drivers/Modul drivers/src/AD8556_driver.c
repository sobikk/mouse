/*
 * AD8556_driver.c
 *
 *  Created on: Dec 30, 2020
 *      Author: sobik
 */

#include "AD8556_driver.h"
#include "TIM17_driver.h"
#include "ADC_driver.h"

static void setBuffer(uint32_t buffer[2], uint8_t parameter, uint8_t value);
static void sendBit(uint8_t bit);
static void initGPIOs(void);
static void setInAmp(uint8_t parameter, uint8_t value);

void AD8556_init(void){
	initGPIOs();
	AD8556_DIGIN_GPIO->BSRR = (0x1U << AD8556_DIGIN_PINNUM);
	TIM17_delayUs(20);
	setInAmp(AD8556_PARAM_FIRST_STAGE_GAIN, AD8556_FIRST_STAGE_GAIN_4_016);
	setInAmp(AD8556_PARAM_SECOND_STAGE_GAIN, AD8556_SECOND_STAGE_GAIN_10);


	//init ADC settings
	ADC_init();
}

static void setInAmp(uint8_t parameter, uint8_t value){
	uint32_t buffer[2] = {0};
	uint32_t comp = (0x1U << 5);

	setBuffer(buffer, parameter, value);
	for(int i = 37; i >= 0; i--){
		if(i == 31){
			comp = (0x1U << i);
		}
		sendBit((comp & buffer[i / 32]) != 0);
		comp >>= 1;
	}
}

static void initGPIOs(void){
	//set digin
	GPIO_setMODER(AD8556_DIGIN_GPIO, AD8556_DIGIN_PINNUM, GPIO_MODE_OUTPUT);
	GPIO_setPUPDR(AD8556_DIGIN_GPIO, AD8556_DIGIN_PINNUM, GPIO_PUPD_NOPULL);
	GPIO_setOSPEEDR(AD8556_DIGIN_GPIO, AD8556_DIGIN_PINNUM, GPIO_OSPEED_MEDIUM);
	GPIO_setOTYPER(AD8556_DIGIN_GPIO, AD8556_DIGIN_PINNUM, GPIO_OTYPE_PP);

	//set analog pin
	GPIO_setMODER(AD8556_AOUT_GPIO, AD8556_AOUT_PINNUM, GPIO_MODE_ANALOG_);
	GPIO_setPUPDR(AD8556_AOUT_GPIO, AD8556_AOUT_PINNUM, GPIO_PUPD_NOPULL);
}

//custom AD8556 protocol sentence
static void setBuffer(uint32_t buffer[2], uint8_t parameter, uint8_t value){
	buffer[0] = AD8556_CONST_START_OF_PACKET;
	buffer[0] <<= AD8556_SIZEOF_FUNC_SEQ;
	buffer[0] |= AD8556_FUNC_SIMULATE_PARAMETER;
	buffer[0] <<= AD8556_SIZEOF_PARAMETER_SEQ;
	buffer[0] |= parameter;
	buffer[0] <<= AD8556_SIZEOF_MIDDLE_SEQ;
	buffer[0] |= AD8556_CONST_MIDDLE_OF_PACKET;
	buffer[0] <<= AD8556_SIZEOF_VALUE_SEQ;
	buffer[0] |= value;
	buffer[0] <<= AD8556_SIZEOF_END_SEQ;
	buffer[0] |= AD8556_CONST_END_OF_PACKET;

	buffer[1] |= (AD8556_CONST_START_OF_PACKET >> (6));
}

static void sendBit(uint8_t bit){
	//output STM32 has inverted value than AD8556
	if(bit){
		AD8556_DIGIN_GPIO->BRR = (0x1U << AD8556_DIGIN_PINNUM);
		TIM17_delayUs(55);												//pro 1
		AD8556_DIGIN_GPIO->BSRR = (0x1U << AD8556_DIGIN_PINNUM);
	}else{
		AD8556_DIGIN_GPIO->BRR = (0x1U << AD8556_DIGIN_PINNUM);
		TIM17_delayUs(8);												//pro 0
		AD8556_DIGIN_GPIO->BSRR = (0x1U << AD8556_DIGIN_PINNUM);
	}
	TIM17_delayUs(12);
}

uint16_t AD8556_getValue(void){
	while(ADC_valueUpdated() == 0){
	}
	return ADC_getPressureRaw();
}

void AD8556_startADCConversion(void){
	ADC_startConversion();
}

