/*
 * TIM17_driver.h
 *
 *  Created on: Dec 31, 2020
 *      Author: sobik
 */

#ifndef TIM17_DRIVER_H_
#define TIM17_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

#define TIM17_PRESCALER_1US					47U			//with 48Mhz -> 1us interval

//TIM17 registers structure definition
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
} TIM17_handle_t;

//TIM17 typecasted base addresses to TIM17_handle_t*
#define _TIM17								((TIM17_handle_t*)TIM17_BASEADDR)

//define bit positions
#define TIM17_EVENT_FLAG					0

//func prototypes
void TIM17_init(void);
void TIM17_delayUs(uint16_t delay);

#endif /* TIM17_DRIVER_H_ */
