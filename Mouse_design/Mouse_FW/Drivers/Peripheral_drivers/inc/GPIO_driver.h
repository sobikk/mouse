/*
 * GPIO_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

//GPIO registers structure definition
typedef struct
{
	volatile uint32_t MODER;				//GPIO port mode register
	volatile uint32_t OTYPER;				//GPIO port output type register
	volatile uint32_t OSPEEDR;				//GPIO port output speed register
	volatile uint32_t PUPDR;				//GPIO port pull-up/pull-down register
	volatile uint32_t IDR;					//GPIO port input data register
	volatile uint32_t ODR;					//GPIO port output data register
	volatile uint32_t BSRR;					//GPIO port bit set/reset register
	volatile uint32_t LCKR;					//GPIO port configuration lock register
	volatile uint32_t AFR[2];				//AFR[0] - GPIO alternate function low register, AFR[1] - GPIO alternate function high register
	volatile uint32_t BRR;					//GPIO port bit reset register
} GPIO_handle_t;

//GPIO typecasted base addresses to GPIO_handle_t*
#define _GPIOA								((GPIO_handle_t*)GPIOA_BASEADDR)
#define _GPIOB								((GPIO_handle_t*)GPIOB_BASEADDR)
#define _GPIOC								((GPIO_handle_t*)GPIOC_BASEADDR)
#define _GPIOD								((GPIO_handle_t*)GPIOD_BASEADDR)
#define _GPIOE								((GPIO_handle_t*)GPIOE_BASEADDR)
#define _GPIOF								((GPIO_handle_t*)GPIOF_BASEADDR)

//define MODER values
#define GPIO_MODE_INPUT_ 				0x0U
#define GPIO_MODE_OUTPUT 				0x1U
#define GPIO_MODE_ALTFUNC 				0x2U
#define GPIO_MODE_ANALOG_ 				0x3U

//define OTYPER values
#define GPIO_OTYPE_PP					0x0U
#define GPIO_OTYPE_OD					0x1U

//define OSPEEDR values
#define GPIO_OSPEED_LOW					0x0U
#define GPIO_OSPEED_MEDIUM				0x1U	
#define GPIO_OSPEED_HIGH				0x3U

//define PUPDR values
#define GPIO_PUPD_NOPULL				0x0U
#define GPIO_PUPD_PULLUP 				0x1U
#define GPIO_PUPD_PULLDOWN 				0x2U

//define altFuncs
#define GPIO_ALTFUNC_SPI1				0x0U

//fenc prototypes
void GPIO_init(void);
void GPIO_setMODER(GPIO_handle_t* GPIOx_h, uint8_t pinNum, uint8_t mode);
void GPIO_setOTYPER(GPIO_handle_t* GPIOx_h, uint8_t pinNum, uint8_t otype);
void GPIO_setOSPEEDR(GPIO_handle_t* GPIOx_h, uint8_t pinNum, uint8_t ospeed);
void GPIO_setPUPDR(GPIO_handle_t* GPIOx_h, uint8_t pinNum, uint8_t pupd);
void GPIO_setState(GPIO_handle_t* GPIOx_h, uint8_t pinNum, uint8_t value);
uint8_t GPIO_getState(GPIO_handle_t* GPIOx_h, uint8_t pinNum);
void GPIO_setALTFUNC(GPIO_handle_t* GPIOx, uint8_t pinNum, uint8_t func);

#endif /* GPIO_DRIVER_H_ */
