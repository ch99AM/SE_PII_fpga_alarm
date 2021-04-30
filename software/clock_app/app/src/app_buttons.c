/*
 * app_buttons.c
 *
 *  Created on: Apr 29, 2021
 *      Author: este0
 */


#include "../include/app_timer.h"

void handle_btn_conf_irs()
{
	alt_putstr("Conf!\n");
}

void handle_btn_up_irs()
{
	alt_putstr("Up!\n");
}

void handle_btn_down_irs()
{
	alt_putstr("Down!\n");
}

void handle_btn_next_irs()
{
	alt_putstr("Next!\n");
}

void init_btns_irqs()
{
	alt_ic_isr_register(
			REG_BCONF_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BCONF_IRQ,
			handle_btn_conf_irs,
			0x0,
			0x0
	);

	alt_ic_isr_register(
			REG_BUP_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BUP_IRQ,
			handle_btn_up_irs,
			0x0,
			0x0
	);

	alt_ic_isr_register(
			REG_BDOWN_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BDOWN_IRQ,
			handle_btn_down_irs,
			0x0,
			0x0
	);

	alt_ic_isr_register(
			REG_BNEXT_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BNEXT_IRQ,
			handle_btn_next_irs,
			0x0,
			0x0
	);
}
