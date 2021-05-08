/*
 * button_controller.h
 *
 *  Created on: May 3, 2021
 *      Author: este0
 */

#ifndef APP_INCLUDE_BUTTON_CONTROLLER_H_
#define APP_INCLUDE_BUTTON_CONTROLLER_H_

#include "app_uart.h"
#include "app_bcd_display.h"
#include "app_clock_manager.h"
#include "app_alarm.h"

int mode;
int id;
Time var_time;
Time var_alarm;
Time* current_var;
char changed;

void init_status();
void change_mode();
void next_var();
void add_time();
void substract_time();

#endif /* APP_INCLUDE_BUTTON_CONTROLLER_H_ */
