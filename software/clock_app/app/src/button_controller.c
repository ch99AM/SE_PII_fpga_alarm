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
	current_time.hour = 0;
	current_time.minute = 0;
	current_time.second = 0;
	current_alarm.hour = 0;
	current_alarm.minute = 0;
	current_alarm.second = 0;
	current_var = &current_time;
}

void change_mode()
{
	mode++;
	if (mode > 3)
		mode = 0;
	if (mode == 2)
	{
		set_time();
		current_var = &current_alarm;
		id = 0;
	}
	else if (mode == 3)
	{
		set_alarm();
		current_var = &current_time;
		id = 0;
	}
	switch (mode)
	{
		case 0:
			alt_putstr("Modo 0!\n");
			break;
		case 1:
			alt_putstr("Modo 1!\n");
			break;
		case 2:
			alt_putstr("Modo 2!\n");
			break;
		case 3:
			alt_putstr("Modo 3!\n");
			break;
		default:
			break;
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
		switch (id)
		{
			case 0:
				alt_putstr("Horas!\n");
				break;
			case 1:
				alt_putstr("Minutos!\n");
				break;
			case 2:
				alt_putstr("Segundos!\n");
				break;
			default:
				break;
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
				alt_putstr("Hora ++!\n");
				break;
			case 1:
				current_var->minute++;
				if (current_var->minute > 59)
					current_var->minute = 0;
				alt_putstr("Minuto ++!\n");
				break;
			case 2:
				current_var->second++;
				if (current_var->second > 59)
					current_var->second = 0;
				alt_putstr("Segundo ++!\n");
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
				alt_putstr("Hora --!\n");
				break;
			case 1:
				current_var->minute--;
				if (current_var->minute < 0)
					current_var->minute = 59;
				alt_putstr("Minuto --!\n");
				break;
			case 2:
				current_var->second--;
				if (current_var->second < 0)
					current_var->second = 59;
				alt_putstr("Segundo --!\n");
				break;
			default:
				break;
		}
	}
}

void set_time()
{
//	return; // 'Transacción'
	alt_putstr("Hora establecida!\n");
}

void set_alarm()
{
//	return; // 'Transacción'
	alt_putstr("Alarma establecida!\n");
}
