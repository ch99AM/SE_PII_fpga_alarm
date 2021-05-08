/*
 * app_bcd.h
 *
 *  Created on: 1 de may. de 2021
 *      Author: root
 */

#ifndef APP_INCLUDE_APP_BCD_DISPLAY_H_
#define APP_INCLUDE_APP_BCD_DISPLAY_H_

#include "sys/alt_stdio.h"
#include "system.h"
#include "altera_avalon_pio_regs.h"

int *seg_h2;
int *seg_h1;
int *seg_m1;
int *seg_m2;
int *seg_s2;
int *seg_s1;

void display_hour(int, char);
void display_minute(int, char);
void display_second(int, char);
void display_zeros();
void init_display();

#endif /* APP_INCLUDE_APP_BCD_DISPLAY_H_ */
