/*
 * TIM16_driver.h
 *
 *  Created on: Jan 3, 2021
 *      Author: sobik
 */

#ifndef DRIVERS_TIM16_DRIVER_H_
#define DRIVERS_TIM16_DRIVER_H_


#include <stdint.h>
#include "stm32f042c4.h"

#define TIM16_PRESCALER_1US					47U			//with 48Mhz -> 1us interval

//define bit positions
#define TIM16_COUNTER_EN							0
#define TIM16_UPDATE_INT_EN							0
#define TIM16_UPDATE_INT_FLAG						0

//TIM16 registers structure definition
typedef struct
{
	volatile uint32_t CR1;					//control register 1
	volatile uint32_t CR2;					//control register 2
	volatile uint32_t RESERVED1;
	volatile uint32_t DIER;					//DMA/Interrupt enable register
	volatile uint32_t SR;					//status register
	volatile uint32_t EGR;					//event generation register
	volatile uint32_t CCMR1;				//capture/compare mode register 1
	volatile uint32_t RESERVED2;
	volatile uint32_t CCER;					//capture/compare enable register
	volatile uint32_t CNT;					//counter
	volatile uint32_t PSC;					//prescaler
	volatile uint32_t ARR;					//auto-reload register
	volatile uint32_t RCR;					//repetition counter register
	volatile uint32_t CCR1;					//capture/compare register 1
	volatile uint32_t RESERVED3[3];
	volatile uint32_t BDTR;					//break and dead-time register
	volatile uint32_t DCR;					//DMA control register
	volatile uint32_t DMAR;					//DMA address for full transfer
} TIM16_handle_t;

//TIM16 typecasted base addresses to TIM16_handle_t*
#define _TIM16								((TIM16_handle_t*)TIM16_BASEADDR)

//func prototypes
void TIM16_init(uint16_t periodUs);
void TIM16_interruptHandler(void);


#endif /* DRIVERS_TIM16_DRIVER_H_ */
