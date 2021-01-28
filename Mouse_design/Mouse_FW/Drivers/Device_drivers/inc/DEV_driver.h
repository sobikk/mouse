/*
 * DEV_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef DEV_DRIVER_H_
#define DEV_DRIVER_H_

#include <stdint.h>

#define DEV_BUTTON_RIGHT					0x0U
#define DEV_BUTTON_MIDDLE					0x1U
#define DEV_BUTTON_LEFT						0x2U
#define DEV_POSITION_X						0x0U
#define DEV_POSITION_Y						0x1U
#define DEV_WHEEL							0x2U

//Device report structure
struct DEV_handler{
	uint8_t buttons;
	int8_t x;
	int8_t y;
	int8_t wheel;
};

void DEV_init(void);
void DEV_tick(void);
void DEV_updateButton(uint8_t buttonNum, _Bool state);
void DEV_updatePositionAndWheel(uint8_t byte, int8_t value);

#endif /* DEV_DRIVER_H_ */
