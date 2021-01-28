/*
 * SPI_driver.c
 *
 *  Created on: Dec 30, 2020
 *      Author: sobik
 */

#include "SPI_driver.h"
#include "GPIO_driver.h"
#include "RCC_driver.h"

static void initGPIOs(SPI_handle_t* SPIx);

void SPI_init(SPI_handle_t* SPIx){
	//init PCLK and GPIOs
	RCC_initPCLK(RCC_SPI1_EN, &RCC_SPI1_EN_REG);
	initGPIOs(SPIx);

	//init SPI configuration
	SPIx->CR2 |= 0b1011111000000U;
	SPIx->CR1 |= 0b1101010111U;
}

static void initGPIOs(SPI_handle_t* SPIx){
	if(SPIx == _SPI1){
		GPIO_handle_t* GPIOx = _GPIOA;
		for(int i = 5; i <= 7; i++){
			GPIO_setMODER(GPIOx, i, GPIO_MODE_ALTFUNC);
			GPIO_setOTYPER(GPIOx, i, GPIO_OTYPE_PP);
			GPIO_setOSPEEDR(GPIOx, i, GPIO_OSPEED_HIGH);
			GPIO_setPUPDR(GPIOx, i, GPIO_PUPD_NOPULL);
			GPIO_setALTFUNC(GPIOx, i, GPIO_ALTFUNC_SPI1);
		}
		GPIO_setMODER(GPIOx, 4, GPIO_MODE_OUTPUT);
		GPIO_setOTYPER(GPIOx, 4, GPIO_OTYPE_PP);
		GPIO_setOSPEEDR(GPIOx, 4, GPIO_OSPEED_HIGH);
		GPIO_setPUPDR(GPIOx, 4, GPIO_PUPD_NOPULL);
		GPIO_setState(GPIOx, 4, 1);
	}
}

void SPI_slaveSelect(uint8_t slave){
	switch(slave){
	case SPI_SLAVE_OMS:
		GPIO_setState(_GPIOA, 4, 0);
		break;
	default:
		break;
	}
}

void SPI_freeSlave(uint8_t slave){
	switch(slave){
	case SPI_SLAVE_OMS:
		GPIO_setState(_GPIOA, 4, 1);
		break;
	default:
		break;
	}
}

_Bool SPI_TxFifoEmpty(SPI_handle_t* SPIx){
	return (((SPIx->SR >> 11) & 11U) == 0U);
}

_Bool SPI_RxFifoEmpty(SPI_handle_t* SPIx){
	return (((SPIx->SR >> 9) & 11U) == 0U);
}


uint8_t SPI_readByteRx(SPI_handle_t* SPIx){
	return *(volatile uint8_t*)&SPIx->DR;
}

void SPI_writeByteTx(SPI_handle_t* SPIx, uint8_t data){
	*(volatile uint8_t*)&SPIx->DR = data;
}


