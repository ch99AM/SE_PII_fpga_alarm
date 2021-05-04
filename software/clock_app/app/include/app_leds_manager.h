/*
 * app_leds_manager.h
 *
 *  Created on: 3 de may. de 2021
 *      Author: root
 */

#ifndef APP_INCLUDE_APP_LEDS_MANAGER_H_
#define APP_INCLUDE_APP_LEDS_MANAGER_H_

char *led_clock;
char *led_alarm;

// To turn on and off the clock led mode
void turn_on_cled();
void turn_off_cled();

// To turn on and off the alarm led mode
void turn_on_aled();
void turn_off_aled();

// To turn on and off the alarm alert led
void turn_on_alarm();
void turn_off_alarm();

void init_leds();
#endif /* APP_INCLUDE_APP_LEDS_MANAGER_H_ */
