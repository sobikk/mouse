/*
 *  BUTTON_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "stm32f042c4.h"
#include "GPIO_driver.h"
#include "EXTI_driver.h"
#include "SYSCFG_driver.h"
#include "NVIC_driver.h"
#include "BUTTON_driver.h"
#include "DEV_driver.h"
#include "OMS_driver.h"
#include "LED_driver.h"

static void initButtonPin(GPIO_handle_t* GPIOx, uint8_t lineNum);
static void scrollHandler(uint8_t lineNum);
static void changeButtonState(uint8_t button, _Bool state);
static void scroll(uint8_t value);

void BUTTON_init(void){
	//left button PA8
	initButtonPin(_GPIOA, BUTTON_PIN_LEFT);

	//right button PA9
	initButtonPin(_GPIOA, BUTTON_PIN_RIGHT);

	//middle button PA10
	initButtonPin(_GPIOA, BUTTON_PIN_MIDDLE);

	//encoder PB14, PB15
	initButtonPin(_GPIOB, BUTTON_PIN_ENCODER_UP);
	initButtonPin(_GPIOB, BUTTON_PIN_ENCODER_DOWN);
}

void BUTTON_interruptHandler(uint8_t lineNum){
	//verify transition rising x falling
	_Bool transition;
	if(lineNum <= 10){
		if(GPIO_getState(_GPIOA, lineNum) == 1){
			transition = RISING;
		}else{
			transition = FALLING;
		}
		switch(lineNum){
			case 8:
				changeButtonState(DEV_BUTTON_RIGHT,transition);
				break;
			case 9:
				changeButtonState(DEV_BUTTON_MIDDLE,transition);
				break;
			default:
				changeButtonState(DEV_BUTTON_LEFT,transition);
				break;
		}
	}else{
		scrollHandler(lineNum);
	}
}


static void scrollHandler(uint8_t lineNum){
	static uint8_t scrollBuffer = 0;

	//detects first transition after stable state
	if(scrollBuffer == 0){
		if(lineNum == BUTTON_LINENUM_ENCODER_UP){
			scrollBuffer = BUTTON_PIN_ENCODER_UP;
		}else{
			scrollBuffer = BUTTON_PIN_ENCODER_DOWN;
		}
	}
	//detects second transition after stable state (to new state or the first one)
	else{
		if((lineNum == BUTTON_LINENUM_ENCODER_UP) && (scrollBuffer == BUTTON_PIN_ENCODER_DOWN)){
			scroll(1);
		}else if((lineNum == BUTTON_LINENUM_ENCODER_DOWN) && (scrollBuffer == BUTTON_PIN_ENCODER_UP)){
			scroll(-1);
		}
	}

	//buffer reset and fault protection
	if(GPIO_getState(_GPIOB, BUTTON_PIN_ENCODER_UP) == GPIO_getState(_GPIOB, BUTTON_PIN_ENCODER_DOWN)){
		scrollBuffer = 0;
	}
}

static void initButtonPin(GPIO_handle_t* GPIOx, uint8_t lineNum){
	GPIO_setMODER(GPIOx, lineNum, GPIO_MODE_INPUT_);
	GPIO_setPUPDR(GPIOx, lineNum, GPIO_PUPD_NOPULL);
	EXTI_setFallingEdge(lineNum, 1);
	EXTI_setRisingEdge(lineNum, 1);
	SYSCFG_setEXTIConfig(lineNum, GPIOx);
	EXTI_setInterrupt(lineNum, 1);
	NVIC_setEXTILine(lineNum, 1);
}

static void changeButtonState(uint8_t button, _Bool state){
	DEV_updateButton(button, state);
}

static void scroll(uint8_t value){
	DEV_updatePositionAndWheel(DEV_WHEEL, value);
}










