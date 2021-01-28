/*
 * RCC_driver.h
 *
 *  Created on: Dec 29, 2020
 *      Author: sobik
 */

#ifndef RCC_DRIVER_H_
#define RCC_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

//RCC register structure definition
typedef struct
{
	volatile uint32_t CR;					//Clock control register
	volatile uint32_t CFGR;					//Clock configuration register
	volatile uint32_t CIR;					//Clock interrupt register
	volatile uint32_t APB2RSTR;				//APB peripheral reset register 2
	volatile uint32_t APB1RSTR;				//APB peripheral reset register 1
	volatile uint32_t AHBENR;				//AHB peripheral clock enable register
	volatile uint32_t APB2ENR;				//APB peripheral clock enable register 2
	volatile uint32_t APB1ENR;				//APB peripheral clock enable register 1
	volatile uint32_t BDCR;					//RTC domain control register
	volatile uint32_t CSR;					//Control/status register
	volatile uint32_t AHBRSTR;				//AHB peripheral reset register
	volatile uint32_t CFGR2;				//Clock configuration register 2
	volatile uint32_t CFGR3;				//Clock configuration register 3
	volatile uint32_t CR2;					//Clock control register 2
} RCC_handle_t;


//RCC typecasted base addresses to RCC_handle_t*
#define _RCC									((RCC_handle_t*)RCC_BASEADDR)


//define used bits
#define RCC_GPIOA_EN						17
#define RCC_GPIOB_EN						18

#define RCC_SYSCFG_EN						0
#define RCC_ADC_EN							9
#define RCC_SPI1_EN							12
#define RCC_TIM16_EN						17
#define RCC_TIM17_EN						18

#define RCC_HSI48_ON						16
#define RCC_HSI48_RDY						17
#define RCC_SWS								2
#define RCC_SW								0

//define some register names for PCLK init
#define RCC_GPIOs_EN_REG					_RCC->AHBENR
#define RCC_SPI1_EN_REG						_RCC->APB2ENR
#define RCC_TIM16_EN_REG					_RCC->APB2ENR
#define RCC_TIM17_EN_REG					_RCC->APB2ENR
#define RCC_ADC_EN_REG						_RCC->APB2ENR
#define RCC_SYSCFG_EN_REG					_RCC->APB2ENR

//define values
#define RCC_SOURCE_HSI48					0x3U
#define RCC_SOURCE_HSI48_SELECTED			0x3U

//func prototypes
void RCC_initPCLK(uint8_t bit, volatile uint32_t* reg);
void RCC_initClockSystem(void);

#endif /* RCC_DRIVER_H_ */
