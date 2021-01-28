/*
 *  DEV_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include "DEV_driver.h"
#include "LED_driver.h"
#include "BUTTON_driver.h"
#include "RCC_driver.h"
#include "TIM17_driver.h"
#include "ADC_driver.h"
#include "AD8556_driver.h"
#include "TIM16_driver.h"
#include "SPI_driver.h"
#include "OMS_driver.h"
#include "GPIO_driver.h"
#include "SYSCFG_driver.h"
//#include "usbd_hid.h"

struct DEV_handler DEV_state = {0};
struct DEV_handler DEV_stateOld = {0};

//extern USBD_HandleTypeDef hUsbDeviceFS;

#define BUTTONS_CHANGED				(DEV_state.buttons != DEV_stateOld.buttons)
#define X_CHANGED					(DEV_state.x != DEV_stateOld.x)
#define Y_CHANGED					(DEV_state.y != DEV_stateOld.y)
#define WHEEL_CHANGED				(DEV_state.wheel != DEV_stateOld.wheel)

static void updateOld(void);
static _Bool stateChanged(void);
static void sendReport(void);

void DEV_init(void){
	RCC_initClockSystem();
	SYSCFG_init();
	GPIO_init();
	LED_init();
	BUTTON_init();
	TIM17_init();						//must be before AD8556_init
	AD8556_init();
	TIM16_init(20);						//20 us tick
	SPI_init(_SPI1);
	OMS_init();
}

static _Bool stateChanged(void){
	if(BUTTONS_CHANGED || X_CHANGED || Y_CHANGED || WHEEL_CHANGED){
		return 1;
	}else{
		return 0;
	}
}

static void sendReport(void){
	//uint8_t* report = (uint8_t*)&DEV_state.buttons;
	//USBD_HID_SendReport(&hUsbDeviceFS, report, 4);
	DEV_state.x = 0;
	DEV_state.y = 0;
	DEV_state.wheel = 0;
	updateOld();
}

static void updateOld(void){
	DEV_stateOld.buttons = DEV_state.buttons;
	DEV_stateOld.x = DEV_state.x;
	DEV_stateOld.y = DEV_state.y;
	DEV_stateOld.wheel = DEV_state.wheel;
}

void DEV_tick(void){
	if(stateChanged()){
		sendReport();
	}
}

void DEV_updateButton(uint8_t buttonNum, _Bool state){
	if(state){
		DEV_state.buttons |= (0x1U << buttonNum);
	}else{
		DEV_state.buttons &= ~(0x1U << buttonNum);
	}
}

void DEV_updatePositionAndWheel(uint8_t byte, int8_t value){
	if(byte == DEV_POSITION_X){
		DEV_state.x += value;
	}else if(byte == DEV_POSITION_Y){
		DEV_state.y += value;
	}else if(byte == DEV_WHEEL){
		DEV_state.wheel += value;
	}
}














