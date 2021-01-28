/*
 * BUTTON_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include <stdint.h>

#define SCROLL_PIN_A							1
#define SCROLL_PIN_B							2

#define BUTTON_PIN_LEFT							8
#define BUTTON_PIN_RIGHT						9
#define BUTTON_PIN_MIDDLE						10
#define BUTTON_PIN_ENCODER_UP					14
#define BUTTON_PIN_ENCODER_DOWN					15

#define BUTTON_LINENUM_LEFT							8
#define BUTTON_LINENUM_RIGHT						9
#define BUTTON_LINENUM_MIDDLE						10
#define BUTTON_LINENUM_ENCODER_UP					14
#define BUTTON_LINENUM_ENCODER_DOWN					15

void BUTTON_init(void);
void BUTTON_interruptHandler(uint8_t lineNum);

#endif /* BUTTON_DRIVER_H_ */
