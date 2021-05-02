/*
 * app_uart.c
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#include "../include/app_uart.h"


bool is_readable(){
    unsigned char *prddy = (unsigned char*)UART_BASE1;
    prddy += 0x2;
    if(*prddy & 0x80){
        return true;
    }
    return false;
}

bool is_writable(){
    unsigned char *ptddy = (unsigned char*)UART_BASE1;
    ptddy += 0x2;
    if(*ptddy & 0x40){
        return true;
    }
    return false;
}

unsigned char* read_rx(){
	while(!is_readable());
	if(is_readable()){
		unsigned char *pto_read = (unsigned char*)UART_BASE1;
		//*pto_read = IORD(UART_BASE1, 0);
		alt_putchar(*pto_read);
		write_tx(pto_read);
		return pto_read;
	}
	return NULL;
}

int write_tx(unsigned char *msg){
	while(!is_writable());
	if(is_writable()){
		unsigned char *pto_write = (unsigned char*)UART_BASE1;
		*pto_write = *msg;
		//IOWR(UART_BASE1, 1, *msg);
		return 1;
	}
	return 0;
}
