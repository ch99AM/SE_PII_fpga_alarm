/*
 * app_uart.h
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#ifndef APP_INCLUDE_APP_UART_H_
#define APP_INCLUDE_APP_UART_H_


#include "altera_avalon_uart_regs.h"
#include "system.h"
#include "sys/alt_stdio.h"
#include "io.h"


unsigned char *read_buffer;
unsigned char *write_buffer;


int is_readable();
int is_writable();
unsigned char read_rx();
int write_tx(unsigned char);

int read_msg();
int write_msg(unsigned char *, int);
int break_check();
int data_check(int, int, int, char);
int time_formart(int, int);


#endif /* APP_INCLUDE_APP_UART_H_ */
