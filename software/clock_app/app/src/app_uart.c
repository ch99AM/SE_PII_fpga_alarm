/*
 * app_uart.c
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#include "../include/app_uart.h"
#include "sys/alt_stdio.h"

int is_readable(){
    if(*(uart_ptr + 2) & 0x80){
        return 1;
    }
    return 0;
}

unsigned char read_rx(){
	char temp_read = *uart_ptr;
	write_tx(temp_read);
	*(uart_ptr + 2) = 0x0;
	return temp_read;
}

void write_tx(unsigned char cmsg){
	*(uart_ptr + 2) = 0x0;
	*(uart_ptr + 1) = cmsg;
}

int data_check(int hora, int min, int seg, char conf_type){
	if(0 > hora || hora > 23){
		return 0;
	}
	if(0 > min || min > 59){
		return 0;
	}
	if(conf_type == 'H' || conf_type == 'h'){
		if(0 > seg || seg > 59){
			return 0;
		}
	}
	return 1;
}

int format_time(int result, int number_char){
	if (result != -1){
		result = result*10;
		result += number_char-48;
		current_pos_conf++;
	}else{
		result = number_char-48;
	}
	return result;
}

int read_msg(){
	char temp_read = read_rx();
	if (temp_read == 'H' || temp_read == 'A'){
		reset_var_conf();
	}
	if(current_pos_conf == 0){
		reset_var_conf();
		write_tx('\n');
		var_conf.type = temp_read;
		current_pos_conf  = 1;
	}
	else if(current_pos_conf == 1){
		if (temp_read >= 48 && temp_read <= 57){
			var_conf.hour = (short)format_time((int)var_conf.hour, (int)temp_read);
		}
	}
	else if(current_pos_conf == 2){
		if (temp_read >= 48 && temp_read <= 57){
			var_conf.min = (short)format_time((int)var_conf.min, (int)temp_read);
		}
	}
	else if(current_pos_conf == 3){
		if (temp_read >= 48 && temp_read <= 57){
			var_conf.sec = (short)format_time((int)var_conf.sec, (int)temp_read);
		}
	}
	if(var_conf.type == 'A' && current_pos_conf == 3){
		if (data_check((int)var_conf.hour,(int)var_conf.min,-1, var_conf.type)){
			set_alarm(var_conf.hour, var_conf.min);
			reset_var_conf();
			write_tx('\n');
			return 1;//Alarma
		}
		return 0;
	}
	if(var_conf.type == 'H' && current_pos_conf == 4){
		if (data_check((int)var_conf.hour,(int)var_conf.min,(int)var_conf.sec, var_conf.type)){
			set_clock_time(var_conf.hour, var_conf.min, var_conf.sec);
			reset_var_conf();
			write_tx('\n');
			return 1;//Hora
		}
		return 0;
	}
	return 0; //Sin configuracion
}

void reset_var_conf(){
	var_conf.hour = -1;
	var_conf.min = -1;
	var_conf.sec = -1;
	current_pos_conf = 0;
}

void init_uart() {
	uart_ptr = (int*)UART_BASE;
	reset_var_conf();

	*(uart_ptr + 3) = 0x80;

	alt_ic_isr_register(
			UART_IRQ_INTERRUPT_CONTROLLER_ID,
			UART_IRQ,
			handle_uart_irs,
			0x0,
			0x0
	);
	uart_mode = '0';
}

void handle_uart_irs(){
	if(uart_mode == '1' && is_readable()) {
		read_msg();
	}
	*(uart_ptr + 2) = 0x0;
}

void set_uart_mode(int mode){
	if(mode == 3)
		uart_mode = '1';
	else
		uart_mode = '0';
}
