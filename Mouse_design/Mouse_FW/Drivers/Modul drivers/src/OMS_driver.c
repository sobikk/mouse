/*
 *  OMS_driver.c
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#include <stdint.h>
#include "OMS_driver.h"
#include "SPI_driver.h"
#include "TIM17_driver.h"
#include "GPIO_driver.h"
#include "OMS_SROMdata.h"

static void OMS_downloadSROM();

void OMS_init(void){
	//NRST high
	GPIO_setMODER(_GPIOB, 13, GPIO_MODE_OUTPUT);
	GPIO_setOTYPER(_GPIOB, 13, GPIO_OTYPE_PP);
	GPIO_setOSPEEDR(_GPIOB, 13, GPIO_OSPEED_HIGH);
	GPIO_setPUPDR(_GPIOB, 13, GPIO_PUPD_NOPULL);
	GPIO_setState(_GPIOB, 13, 1);

	//Power-up sequence
	//1. drive NCS high and low to reset chip SPI
	SPI_freeSlave(SPI_SLAVE_OMS);
	TIM17_delayUs(10000);
	SPI_slaveSelect(SPI_SLAVE_OMS);

	//test
	OMS_pollWriteTOReg(0x0EU, 0x56U);
	TIM17_delayUs(OMS_tWR);
	uint8_t a = OMS_pollReadFromReg(0x0EU);

	//2. write 0x5A to Power-up-reset register
	OMS_pollWriteTOReg(OMS_REG_ADDR_POWER_UP_RESET, 0x5AU);
	TIM17_delayUs(OMS_tWR);

	//3. wait for at least 50ms
	TIM17_delayUs(55000);

	uint8_t d;
	//4. read one time from registers 0x02, 0x03, 0x04, 0x05 and 0x06
	for(uint8_t regAdd = 0x02U; regAdd <= 0x06U ; regAdd++){
		d = OMS_pollReadFromReg(regAdd);
		TIM17_delayUs(OMS_tRR);
	}

	//5. perform SROM download
	OMS_downloadSROM();






	//6. write to register 0x3D with 0x80
	OMS_pollWriteTOReg(0x3DU, 0x80U);

	//7. read register 0x3D with interval of 1ms and repeat until 0xC0 is obtained or up to 55ms


	//8. write to register 0x3D with 0x00


	//9. write to register 0x10 with 0x20



}

static void OMS_downloadSROM(){
	//1. write to register 0x10 with 0x00
	OMS_pollWriteTOReg(0x10U, 0x00U);
	TIM17_delayUs(OMS_tWW);

	//2. write to SROM_enable with 0x1D
	OMS_pollWriteTOReg(OMS_REG_ADDR_SROM_ENABLE, 0x1DU);
	TIM17_delayUs(OMS_tWW);

	//3. wait for 10ms
	TIM17_delayUs(10000);

	//4. write to SROM_enable with 0x18
	OMS_pollWriteTOReg(OMS_REG_ADDR_SROM_ENABLE, 0x18U);
	TIM17_delayUs(OMS_tWW);

	//5. burst write data
	SPI_slaveSelect(SPI_SLAVE_OMS);

	OMS_sendByte(OMS_REG_ADDR_SROM_LOAD_BURST & 0x80U);
	TIM17_delayUs(OMS_tWW);

	for(int i = 0; i < sizeof(OMS_firmware); i++){
		OMS_sendByte(OMS_firmware[i]);
		TIM17_delayUs(20);
	}

	SPI_freeSlave(SPI_SLAVE_OMS);
	TIM17_delayUs(220);

	//resit delay

	//6. read firmware version
	uint8_t FWVersion = OMS_pollReadFromReg(OMS_REG_ADDR_SROM_ID);
	TIM17_delayUs(OMS_tRR);
	FWVersion = OMS_pollReadFromReg(OMS_REG_ADDR_SROM_ID);
}

uint8_t OMS_pollReadFromReg(uint8_t regAddr){
	//transmit address and read redundant byte
	//1. select slave
	SPI_slaveSelect(SPI_SLAVE_OMS);
	//2. wait for free buffer and send address (read)
	while(SPI_TxFifoEmpty(_SPI1) == 0){
	}
	SPI_writeByteTx(_SPI1, regAddr);
	//3. wait for received data and read data to free RxFIFO
	while(SPI_RxFifoEmpty(_SPI1)){
	}
	SPI_readByteRx(_SPI1);

	//wait
	TIM17_delayUs(OMS_tRAD);

	//transmit zero byte and read data
	//1. wait for free buffer and send zero
	while(SPI_TxFifoEmpty(_SPI1) != 1){
	}
	SPI_writeByteTx(_SPI1, 0x00U);
	//2. wait for received data
	while(SPI_RxFifoEmpty(_SPI1) == 1){
	}
	//3. free slave
	SPI_freeSlave(SPI_SLAVE_OMS);
	//4.return data
	return SPI_readByteRx(_SPI1);
}

void OMS_pollWriteTOReg(uint8_t regAddr, uint8_t data){
	//transmit address and read redundant byte
	//1. select slave
	SPI_slaveSelect(SPI_SLAVE_OMS);
	//2. wait for free buffer and send address (write)
	while(SPI_TxFifoEmpty(_SPI1) == 0){
	}
	SPI_writeByteTx(_SPI1, regAddr & 0x80U);
	//3. wait for received data and read data to free RxFIFO
	while(SPI_RxFifoEmpty(_SPI1)){
	}
	SPI_readByteRx(_SPI1);

	//transmit data and read redundant byte
	//1. wait for free buffer and send data
	while(SPI_TxFifoEmpty(_SPI1) != 1){
	}
	SPI_writeByteTx(_SPI1, data);
	//2. wait for received data
	while(SPI_RxFifoEmpty(_SPI1) == 1){
	}
	//3. free slave
	SPI_freeSlave(SPI_SLAVE_OMS);
	//4.read data to free RxFIFO
	SPI_readByteRx(_SPI1);
}

void OMS_sendByte(uint8_t data){
	//transmit address and read redundant byte
	//1. wait for free buffer and send data
	while(SPI_TxFifoEmpty(_SPI1) == 0){
	}
	SPI_writeByteTx(_SPI1, data);
	//2. wait for received data and read data to free RxFIFO
	while(SPI_RxFifoEmpty(_SPI1)){
	}
	SPI_readByteRx(_SPI1);
}















