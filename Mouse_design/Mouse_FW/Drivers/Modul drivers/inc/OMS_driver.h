/*
 * OMS_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef OMS_DRIVER_H_
#define OMS_DRIVER_H_

#include <stdint.h>

//registers
#define OMS_REG_ADDR_PRODUCT_ID					0x00U
#define OMS_REG_ADDR_REVISION_ID				0x01U
#define OMS_REG_ADDR_MOTION						0x02U
#define OMS_REG_ADDR_DELTA_XL					0x03U
#define OMS_REG_ADDR_DELTA_XH					0x04U
#define OMS_REG_ADDR_DELTA_YL					0x05U
#define OMS_REG_ADDR_DELTA_YH					0x06U
#define OMS_REG_ADDR_SQUAL						0x07U
#define OMS_REG_ADDR_RAWDATA_SUM				0x08U
#define OMS_REG_ADDR_MAXIMUM_RAWDATA			0x09U
#define OMS_REG_ADDR_MINIMUM_RAWDATA			0x0AU
#define OMS_REG_ADDR_SHUTTER_LOWER				0x0BU
#define OMS_REG_ADDR_SHUTTER_UPPER				0x0CU
#define OMS_REG_ADDR_RIPPLE_CTRL				0x0DU
#define OMS_REG_ADDR_RESOLUTION_L				0x0EU
#define OMS_REG_ADDR_RESOLUTION_H				0x0FU
#define OMS_REG_ADDR_CONFIG2					0x10U
#define OMS_REG_ADDR_ANGLE_TUNE					0x11U
#define OMS_REG_ADDR_FRAME_CAPTURE				0x12U
#define OMS_REG_ADDR_SROM_ENABLE				0x13U
#define OMS_REG_ADDR_RUN_DOWNSHIFT				0x14U

#define OMS_REG_ADDR_SROM_ID					0x2AU
#define OMS_REG_ADDR_SROM_LOAD_BURST		 	0x62U


#define OMS_REG_ADDR_POWER_UP_RESET				0x3AU
#define OMS_REG_ADDR_SHUTDOWN					0x3BU
#define OMS_REG_ADDR_INVERSE_PRODUCT_ID			0x3FU


#define OMS_REG_ADDR_MOTION_BURST				0x50U

//sensor orientation with ripple control set
#define OMS_ORIENTATION_0D						0x07U
#define OMS_ORIENTATION_90D						0xC7U
#define OMS_ORIENTATION_180D					0x67U
#define OMS_ORIENTATION_270D					0x97U

//define delays in us
#define OMS_tRAD								170		//min 160
#define OMS_tRR									25		//min 20
#define OMS_tRW									25		//min 20
#define OMS_tWR									190		//min 180
#define OMS_tWW									190		//min 180

//

void OMS_init(void);
uint8_t OMS_pollReadFromReg(uint8_t regAddr);
void OMS_pollWriteTOReg(uint8_t regAddr, uint8_t data);
void OMS_sendByte(uint8_t data);

#endif /* OMS_DRIVER_H_ */
