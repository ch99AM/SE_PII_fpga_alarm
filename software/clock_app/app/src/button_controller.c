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
				display_zeros();
				turn_on_cled();
				break;
			case 2:
				display_zeros();
				turn_on_uled();
				turn_off_cled();
				break;
			case 3:
				set_time_mode_on();
				turn_on_cled();
				read_msg();
				break;
			default:
				break;
		}

		if (mode == 2)
		{
			if(changed == '1')
				init_hour(var_time.hour, var_time.minute, var_time.second);
			current_var = &var_alarm;
		}
		else if (mode == 3)
		{
			if(changed == '1')
				set_alarm(var_time.hour, var_time.minute);
			current_var = &var_time;
		}

		changed = '0';
	}
}

void next_var()
{
	if(mode == 1 || mode == 2)
		{
		id++;
		if (id > 2)
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
				if (current_var->hour > 59)
					current_var->hour = 0;
				changed = '1';
				break;
			case 1:
				current_var->minute++;
				if (current_var->minute > 59)
					current_var->minute = 0;
				changed = '1';
				break;
			case 2:
				current_var->second++;
				if (current_var->second > 59)
					current_var->second = 0;
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
				changed = '1';
				break;
			case 1:
				current_var->minute--;
				if (current_var->minute < 0)
					current_var->minute = 59;
				changed = '1';
				break;
			case 2:
				current_var->second--;
				if (current_var->second < 0)
					current_var->second = 59;
				changed = '1';
				break;
			default:
				break;
		}
	}
}
