/*
 * app_uart.h
 *
 *  Created on: 30 de abr. de 2021
 *      Author: Christian
 */

#ifndef APP_INCLUDE_APP_UART_H_
#define APP_INCLUDE_APP_UART_H_

#include "app_clock_manager.h"
#include "app_alarm.h"
#include "altera_avalon_uart_regs.h"
#include "system.h"
#include "sys/alt_stdio.h"
#include "io.h"
#include "sys/alt_irq.h"

unsigned char* uart_ptr;
short current_pos_conf;
char uart_mode;

struct Conf_msg{
   char  type;
   short  hour;
   short  min;
   short  sec;
}conf_msg;

struct Conf_msg var_conf;

int is_readable();
int is_writable();
unsigned char read_rx();
int write_tx(unsigned char);
void reset_var_conf();

int read_msg();
int write_msg(unsigned char *, int);
int break_check();
int data_check(int, int, int, char);
int time_formart(int, int);

void init_uart();
void handle_uart_irs();
void in_uart_mode(int);

#endif /* APP_INCLUDE_APP_UART_H_ */
