/*
 * app_clock_manager.c
 *
 *  Created on: 29 de abr. de 2021
 *      Author: root
 */

#include "../include/app_clock_manager.h"
#include "../include/app_bcd_display.h"
#include "../include/app_alarm.h"

void set_hour(short hour) {
	current_time.hour = hour;
}

void set_minute(short minute) {
	current_time.minute = minute;
}

void set_second(short second) {
	current_time.second = second;
}

void increase_time() {
	if (current_time.second + 1 >= 60) {
		if (current_time.minute + 1 >= 60) {
			if (current_time.hour + 1 >= 24) {
				set_hour(0);
				set_minute(0);
				set_second(0);
			} else {
				set_hour(current_time.hour + 1);
				set_minute(0);
				set_second(0);
			}
			display_hour(current_time.hour);
		} else {
			set_minute(current_time.minute + 1);
			set_second(0);
		}
		display_minute(current_time.minute);
		check_alarm(current_time.hour, current_time.minute);
	} else {
		set_second(current_time.second + 1);
	}
	display_second(current_time.second);

}

void init_hour(short hour, short minute, short second) {
	set_hour(hour);
	set_minute(minute);
	set_second(second);
	init_display();
	display_hour(current_time.hour);
	display_minute(current_time.minute);
	display_second(current_time.second);
}

Time get_hour() {
	return current_time;
}
