/*
 * app_leds_manager.c
 *
 *  Created on: 3 de may. de 2021
 *      Author: root
 */

#include "../include/app_leds_manager.h"
#include "system.h"

void turn_on_cled() {
	*led_clock = 0x1;
}
void turn_off_cled() {
	*led_clock = 0x0;
}
void turn_on_aled() {
	*led_alarm = 0x1;
}
void turn_off_aled() {
	*led_alarm = 0x0;
}
void turn_on_uled(){
	*led_uart = 0x1;
}
void turn_off_uled(){
	*led_uart = 0x0;
}
void turn_on_all() {
	turn_on_cled();
	turn_on_uled();
}
void turn_off_all() {
	turn_off_cled();
	turn_off_uled();
}

void init_leds() {

	led_clock = (char*) (REG_LEDCONFTIME_BASE);
	led_alarm = (char*) (REG_CONFALARM_BASE);
	led_uart = (char*) (REG_CONFUART_BASE);
}

char is_alarm_on() {
	return *led_alarm;
}
