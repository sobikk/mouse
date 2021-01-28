/*
 * stm32f042c4.h
 *
 *  Created on: Dec 17, 2020
 *      Author: sobik
 */

#ifndef STM32F042C4_H_
#define STM32F042C4_H_

#include <stdint.h>


/*
 * Processor peripherals base addresses
 */

#define NVIC_BASEADDR						0xE000E100U

/*
 * Base addresses - flash and SRAM
 */

#define FLASH_BASEADDR						0x08000000U
#define SRAM_BASEADDR						0x20000000U
#define ROM_BASEADDR						0x1FFFC400U
#define OPTION_BYTE_BASEADDR				0x1FFFF800U

#define SRAM_SIZE							6								//6kB
#define FLASH_SIZE							16								//16kB

/*
 * Base addresses - buses
 */

#define PERIPHERAL_BASEADDR					0x40000000U
#define AHB1_BASEADDR						0x40020000U
#define AHB2_BASEADDR						0x48000000U
#define APB1_BASEADDR						PERIPHERAL_BASEADDR
#define APB2_BASEADDR						0x40010000U

/*
 * Base addresses - AHB2 peripherals
 */

#define GPIOA_BASEADDR						(AHB2_BASEADDR + (0 * 0x0400U))
#define GPIOB_BASEADDR						(AHB2_BASEADDR + (1 * 0x0400U))
#define GPIOC_BASEADDR						(AHB2_BASEADDR + (2 * 0x0400U))
#define GPIOD_BASEADDR						(AHB2_BASEADDR + (3 * 0x0400U))
#define GPIOE_BASEADDR						(AHB2_BASEADDR + (4 * 0x0400U))
#define GPIOF_BASEADDR						(AHB2_BASEADDR + (5 * 0x0400U))

/*
 * Base addresses - AHB1 peripherals
 */

#define DMA_BASEADDR						AHB1_BASEADDR
#define DMA2_BASEADDR						(AHB1_BASEADDR + 0x0400U)
#define RCC_BASEADDR						(AHB1_BASEADDR + 0x1000U)
#define CRC_BASEADDR						(AHB1_BASEADDR + 0x3000U)

/*
 * Base addresses - APB peripherals
 */

#define TIM1_BASEADDR						(APB2_BASEADDR + 0x2C00U)
#define TIM2_BASEADDR						APB1_BASEADDR
#define TIM3_BASEADDR						(APB1_BASEADDR + 0x0400U)
#define TIM6_BASEADDR						(APB1_BASEADDR + 0x1000U)
#define TIM7_BASEADDR						(APB1_BASEADDR + 0x1400U)
#define TIM14_BASEADDR						(APB1_BASEADDR + 0x2000U)
#define TIM15_BASEADDR						(APB2_BASEADDR + 0x4000U)
#define TIM16_BASEADDR						(APB2_BASEADDR + 0x4400U)
#define TIM17_BASEADDR						(APB2_BASEADDR + 0x4800U)

#define RTC_BASEADDR						(APB1_BASEADDR + 0x2800U)
#define WWDG_BASEADDR						(APB1_BASEADDR + 0x2C00U)
#define IWDG_BASEADDR						(APB1_BASEADDR + 0x3000U)
#define CRS_BASEADDR						(APB1_BASEADDR + 0x6C00U)

#define SPI1_BASEADDR						(APB2_BASEADDR + 0x3000U)
#define SPI2_BASEADDR						(APB1_BASEADDR + 0x3800U)

#define USB_BASEADDR						(APB1_BASEADDR + 0x5C00U)
#define USB_SRAM_BASEADDR					(APB1_BASEADDR + 0x6000U)

#define ADC_BASEADDR						(APB2_BASEADDR + 0x2400U)

#define EXTI_BASEADDR						(APB2_BASEADDR + 0x0400U)

#define SYSCFG_BASEADDR						APB2_BASEADDR
#define DBGMCU_BASEADDR						(APB2_BASEADDR + 0x5800U)
#define PWR_BASEADDR						(APB1_BASEADDR + 0x7000U)

#endif /* STM32F042C4_H_ */
