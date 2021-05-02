/*
 * app_clock_manager.h
 *
 *  Created on: 29 de abr. de 2021
 *      Author: root
 */

#ifndef APP_INCLUDE_APP_CLOCK_MANAGER_H_
#define APP_INCLUDE_APP_CLOCK_MANAGER_H_

typedef struct Time {
	short hour;
	short minute;
	short second;
} Time;

Time current_time;

void set_hour(short);
void set_minute(short);
void set_second(short);
void increase_time();
void init_hour(short, short, short);

Time get_hour();

#endif /* APP_INCLUDE_APP_CLOCK_MANAGER_H_ */
