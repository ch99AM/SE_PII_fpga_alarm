/*
 * button_controller.h
 *
 *  Created on: May 3, 2021
 *      Author: este0
 */

#ifndef APP_INCLUDE_BUTTON_CONTROLLER_H_
#define APP_INCLUDE_BUTTON_CONTROLLER_H_

#include "app_timer.h"

typedef struct Time_s {
	int hour;
	int minute;
	int second;
} Time_s;

int mode;
int id;
Time_s current_time;
Time_s current_alarm;
Time_s* current_var;

void init_status();
void change_mode();
void next_var();
void add_time();
void substract_time();
void set_time();
void set_alarm();

#endif /* APP_INCLUDE_BUTTON_CONTROLLER_H_ */
