/*
 * SYSCFG_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef SYSCFG_DRIVER_H_
#define SYSCFG_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"
#include "GPIO_driver.h"

//SYSCFG registers structure definition
typedef struct
{
	volatile uint32_t CFGR1;				//SYSCFG configuration register 1
	volatile uint32_t RESERVED;
	volatile uint32_t EXTICR[4];			//SYSCFG external interrupt configuration register (1,2,3,4)
	volatile uint32_t CFGR2;				//SYSCFG configuration register 2

} SYSCFG_handle_t;

//SYSCFG typecasted base addresses to SYSCFG_handle_t*
#define _SYSCFG								((SYSCFG_handle_t*)SYSCFG_BASEADDR)

//func prototypes
void SYSCFG_init();
void SYSCFG_setEXTIConfig(uint8_t lineNum, GPIO_handle_t* GPIOx_h);

#endif /* SYSCFG_DRIVER_H_ */
