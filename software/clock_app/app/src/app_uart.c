/*
 * app_uart.c
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#include "../include/app_uart.h"


int is_readable(){
    unsigned char *prddy = (unsigned char*)UART_BASE;
    prddy += 0x2;
    if(*prddy & 0x80){
        return 1;
    }
    return 0;
}

int is_writable(){
    unsigned char *ptddy = (unsigned char*)UART_BASE;
    ptddy += 0x2;
    if(*ptddy & 0x40){
        return 1;
    }
    return 0;
}

int break_check(){
    unsigned char *ptddy = (unsigned char*)UART_BASE;
    ptddy += 0x2;
    if(*ptddy & 0x04){
        return 1;
    }
    return 0;
}

unsigned char read_rx(){
	while(is_readable()==0);
	if(is_readable()==1){
		unsigned char cto_read;
		//*pto_read = IORD(UART_BASE, 0);
		//*pto_read = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE1)
		//alt_putchar(*pto_read);
		cto_read = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
		write_tx(cto_read);
		IOWR_ALTERA_AVALON_UART_STATUS(UART_BASE, '0');
		return cto_read;
	}
	return 0;
}

int write_tx(unsigned char cmsg){
	while(is_writable()==0);
	if(is_writable()==1){
		//unsigned char *pto_write = (unsigned char*)UART_BASE1;
		//IOWR(UART_BASE, 1, msg);
		IOWR_ALTERA_AVALON_UART_RXDATA(UART_BASE, cmsg);
		return 1;
	}
	return 0;
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
	}else{
		result = number_char-48;
	}
	return result;
}

int read_msg(){
	char conf_type = read_rx();
	int hora = -1; int min = -1; int seg = -1;
	int temp_read; int current_position = 0;
	while(1){
		if(break_check()){
			break;
		}
		temp_read = (int)read_rx();
		if (temp_read >= 48 && temp_read <= 57){
		    switch(current_position)
		    {
		        case 0:
		            hora = format_time(hora, temp_read);
		            break;
		        case 1:
		        	min = format_time(min, temp_read);
		        	break;
		        case 2:
		        	seg = format_time(seg, temp_read);
		        	break;
		        default:
		        	alt_putstr("Error! Position don't found");
		        	break;
		    }
		}else if(temp_read == 58){
			current_position++;
		}
	}
	if (!data_check(hora, min, seg, conf_type)){
		return 0;
	}
	if(conf_type == 'H' || conf_type == 'h'){
		//Llamar a cambiar la hora
		return 1;
	}else if(conf_type == 'A' || conf_type == 'a'){
		//Llamar a configurar alarma
		return 1;
	}
	return 0; //Error
}

int write_msg(unsigned char *msg, int len){
	for (int var = 0; var < len; ++var) {
		if (!write_tx(msg[var])){
			return 0; //Error
		}
	}
	return 1;
}
