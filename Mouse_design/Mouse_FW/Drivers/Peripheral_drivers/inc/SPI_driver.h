/*
 * SPI_driver.h
 *
 *  Created on: Dec 30, 2020
 *      Author: sobik
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include <stdint.h>
#include "stm32f042c4.h"

/*
 * SPI registers structure definition
 */

typedef struct
{
	volatile uint32_t CR1;							//SPI control register 1
	volatile uint32_t CR2;							//SPI control register 2
	volatile uint32_t SR;							//SPI status register
	volatile uint32_t DR;							//SPI data register
	volatile uint32_t CRCPR;						//SPI CRC polynomial register
	volatile uint32_t RXCRCR;						//SPI Rx CRC register
	volatile uint32_t TXCRCR;						//SPI Tx CRC register
	volatile uint32_t I2SCFGR;						//SPIx_I2S configuration register
	volatile uint32_t I2SPR;						//SPIx_I2S prescaler register
} SPI_handle_t;

/*
 * SPI typecasted base addresses to SPI_handle_t*
 */

#define _SPI1										((SPI_handle_t*)SPI1_BASEADDR)
#define _SPI2										((SPI_handle_t*)SPI2_BASEADDR)

#define SPI_PCLK_2								0x0U
#define SPI_PCLK_4								0x1U
#define SPI_PCLK_8								0x2U
#define SPI_PCLK_16								0x3U
#define SPI_PCLK_32								0x4U
#define SPI_PCLK_64								0x5U
#define SPI_PCLK_128							0x6U
#define SPI_PCLK_256							0x7U

//define slaves
#define SPI_SLAVE_OMS							0U

void SPI_init(SPI_handle_t* SPIx);
void SPI_slaveSelect(uint8_t slave);
void SPI_freeSlave(uint8_t slave);
_Bool SPI_TxFifoEmpty(SPI_handle_t* SPIx);
_Bool SPI_RxFifoEmpty(SPI_handle_t* SPIx);
uint8_t SPI_readByteRx(SPI_handle_t* SPIx);
void SPI_writeByteTx(SPI_handle_t* SPIx, uint8_t data);

#endif /* SPI_DRIVER_H_ */
