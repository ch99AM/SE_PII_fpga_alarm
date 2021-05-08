/*
 * button_controller.c
 *
 *  Created on: May 3, 2021
 *      Author: este0
 */

#include "../include/button_controller.h"

void init_status()
{
	mode = 0;
	id = 0;
	changed = '0';
	var_time.hour = 0;
	var_time.minute = 0;
	var_time.second = 0;
	var_alarm.hour = 0;
	var_alarm.minute = 0;
	var_alarm.second = 0;
	current_var = &var_time;
}

void change_mode()
{
	if(is_alarm_on() == 0x1)
		turn_off_aled();
	else
	{
		mode++;
		if (mode > 3)
			mode = 0;

		id = 0;
		switch (mode)
		{
			case 0:
				turn_off_all();
				break;
			case 1:
				set_time_mode_off();
				display_hour(var_time.hour, '1');
				display_minute(var_time.minute, '1');
				display_second(var_time.second, '1');
				turn_on_cled();
				break;
			case 2:
				if(changed == '1')
				{
					set_clock_time(var_time.hour, var_time.minute, var_time.second);
					set_time_mode_off();
				}
				display_hour(var_alarm.hour, '1');
				display_minute(var_alarm.minute, '1');
				display_second(var_alarm.second, '1');
				turn_on_uled();
				turn_off_cled();
				current_var = &var_alarm;
				break;
			case 3:
				set_time_mode_on();
				turn_on_cled();
				if(changed == '1')
					set_alarm(var_time.hour, var_time.minute);
				current_var = &var_time;
				read_msg();
				break;
			default:
				break;
		}

		changed = '0';
	}
}

void next_var()
{
	id++;
	if(mode == 1)
	{
		if (id > 2)
		{
			id = 0;
		}
	}
	else if(mode == 2)
	{
		if (id > 1)
		{
			id = 0;
		}
	}
}

void add_time()
{
	if(mode == 1 || mode == 2)
	{
		switch(id)
		{
			case 0:
				current_var->hour++;
				if (current_var->hour > 23)
					current_var->hour = 0;
				display_hour(current_var->hour, '1');
				changed = '1';
				break;
			case 1:
				current_var->minute++;
				if (current_var->minute > 59)
					current_var->minute = 0;
				display_minute(current_var->minute, '1');
				changed = '1';
				break;
			case 2:
				current_var->second++;
				if (current_var->second > 59)
					current_var->second = 0;
				display_second(current_var->second, '1');
				changed = '1';
				break;
			default:
				break;
		}
	}
}

void substract_time()
{
	if(mode == 1 || mode == 2)
	{
		switch(id)
		{
			case 0:
				current_var->hour--;
				if (current_var->hour < 0)
					current_var->hour = 23;
				display_hour(current_var->hour, '1');
				changed = '1';
				break;
			case 1:
				current_var->minute--;
				if (current_var->minute < 0)
					current_var->minute = 59;
				display_minute(current_var->minute, '1');
				changed = '1';
				break;
			case 2:
				current_var->second--;
				if (current_var->second < 0)
					current_var->second = 59;
				display_second(current_var->second, '1');
				changed = '1';
				break;
			default:
				break;
		}
	}
}
