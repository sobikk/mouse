/*
 * NVIC_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef NVIC_DRIVER_H_
#define NVIC_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

#define NVIC_LINE_EXTI4_15							7U
#define NVIC_LINE_ADC								12U
#define NVIC_LINE_TIM16								21U

//NVIC registers base address definitions
#define NVIC_ISER_BASEADDR							(NVIC_BASEADDR + 0U)
#define NVIC_ICER_BASEADDR							(NVIC_BASEADDR + 0x80U)
#define NVIC_ISPR_BASEADDR							(NVIC_BASEADDR + 0x100U)
#define NVIC_ICPR_BASEADDR							(NVIC_BASEADDR + 0x180U)
#define NVIC_IPRn_BASEADDR							(NVIC_BASEADDR + 0x300U)

//func prototypes
void NVIC_setEXTILine(uint8_t lineNum, uint8_t srValue);
void EXTI4_15_IRQHandler(void);
void ADC_COMP_IRQHandler(void);
void NVIC_setADCLine(uint8_t srValue);
void TIM16_IRQHandler(void);

#endif /* EXTI_DRIVER_H_ */
