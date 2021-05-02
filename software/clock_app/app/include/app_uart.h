/*
 * app_uart.h
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#ifndef APP_INCLUDE_APP_UART_H_
#define APP_INCLUDE_APP_UART_H_


#include "stdbool.h"
#include "system.h"
#include "sys/alt_stdio.h"
#include "stdio.h"
#include "io.h"

#define UART_BASE1 0x3000;

unsigned char *read_buffer;
unsigned char *write_buffer;

bool is_readable();
bool is_writable();
unsigned char* read_rx();
int write_tx(unsigned char *);



#endif /* APP_INCLUDE_APP_UART_H_ */
