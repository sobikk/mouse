/*
 * LED_driver.h
 *
 *  Created on: Dec 25, 2020
 *      Author: sobik
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include <stdint.h>

#define GPIO_LED_PIN_NUM					8

void LED_init(void);
void LED_on(void);
void LED_off(void);

#endif /* LED_DRIVER_H_ */
