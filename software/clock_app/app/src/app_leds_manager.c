/*
 * app_leds_manager.c
 *
 *  Created on: 3 de may. de 2021
 *      Author: root
 */

#include "../include/app_leds_manager.h"
#include "system.h"

void turn_on_cled() {
	*led_clock = '1';
}
void turn_off_cled() {
	*led_clock = '0';
}
void turn_on_aled() {
	*led_alarm = '1';
}
void turn_off_aled() {
	*led_alarm = '0';
}
void turn_on_alarm() {
	turn_on_cled();
	turn_on_aled();
}
void turn_off_alarm() {
	turn_off_cled();
	turn_off_aled();
}

void init_leds() {

	led_clock = (char*) (REG_LEDCONFTIME_BASE);
	led_alarm = (char*) (REG_CONFALARM_BASE);

}
