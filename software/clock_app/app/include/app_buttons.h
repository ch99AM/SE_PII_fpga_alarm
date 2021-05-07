/*
 * app_buttons.h
 *
 *  Created on: Apr 29, 2021
 *      Author: este0
 */

#ifndef APP_INCLUDE_APP_BUTTONS_H_
#define APP_INCLUDE_APP_BUTTONS_H_

#include "app_timer.h"
#include "button_controller.h"
#include "altera_avalon_pio_regs.h"

void handle_btn_conf_irs();
void handle_btn_up_irs();
void handle_btn_down_irs();
void handle_btn_next_irs();
void init_btns_irqs();

int* conf_ptr;
int* up_ptr;
int* down_ptr;
int* next_ptr;

#endif /* APP_INCLUDE_APP_BUTTONS_H_ */
