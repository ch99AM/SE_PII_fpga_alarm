/*
 * app_alarm.h
 *
 *  Created on: 2 de may. de 2021
 *      Author: root
 */

#ifndef APP_INCLUDE_APP_ALARM_H_
#define APP_INCLUDE_APP_ALARM_H_

#include "app_leds_manager.h"

typedef struct Alarm{
	short hour;
	short minute;
	char set;
} Alarm;

Alarm current_alarm;

void set_alarm(short, short);
int check_alarm(short, short);


#endif /* APP_INCLUDE_APP_ALARM_H_ */
