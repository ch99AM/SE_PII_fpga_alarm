/*
 * app_buttons.c
 *
 *  Created on: Apr 29, 2021
 *      Author: este0
 */


#include "../include/app_buttons.h"

void handle_btn_conf_irs()
{
	*(conf_ptr + 3) = 0x0;
	change_mode();
}

void handle_btn_up_irs()
{
	*(up_ptr + 3) = 0x0;
	add_time();
}

void handle_btn_down_irs()
{
	*(down_ptr + 3) = 0x0;
	substract_time();
}

void handle_btn_next_irs()
{
	*(next_ptr + 3) = 0x0;
	next_var();
}

void init_btns_irqs()
{
	conf_ptr = (int*)REG_BCONF_BASE;
	up_ptr = (int*)REG_BUP_BASE;
	down_ptr = (int*)REG_BDOWN_BASE;
	next_ptr = (int*)REG_BNEXT_BASE;

	*(conf_ptr + 2) = 0x1;
	*(conf_ptr + 3) = 0x0;
	alt_ic_isr_register(
			REG_BCONF_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BCONF_IRQ,
			handle_btn_conf_irs,
			0x0,
			0x0
	);

	*(up_ptr + 2) = 0x1;
	*(up_ptr + 3) = 0x0;
	alt_ic_isr_register(
			REG_BUP_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BUP_IRQ,
			handle_btn_up_irs,
			0x0,
			0x0
	);

	*(down_ptr + 2) = 0x1;
	*(down_ptr + 3) = 0x0;
	alt_ic_isr_register(
			REG_BDOWN_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BDOWN_IRQ,
			handle_btn_down_irs,
			0x0,
			0x0
	);

	*(next_ptr + 2) = 0x1;
	*(next_ptr + 3) = 0x0;
	alt_ic_isr_register(
			REG_BNEXT_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BNEXT_IRQ,
			handle_btn_next_irs,
			0x0,
			0x0
	);
}
