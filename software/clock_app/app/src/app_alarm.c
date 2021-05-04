/*
 * app_alarm.c
 *
 *  Created on: 2 de may. de 2021
 *      Author: root
 */

#include "../include/app_alarm.h"

void set_alarm(short hour, short minute) {
	if (current_alarm.set != '1')
		current_alarm.set = '1';

	current_alarm.hour = hour;
	current_alarm.minute = minute;
}

int check_alarm(short hour, short minute) {
	if (current_alarm.set == '1') {
		if (current_alarm.minute == minute && current_alarm.hour == hour){
			turn_on_alarm();
			return 0;
		}
		return -1;
	}
	return -2;
}
