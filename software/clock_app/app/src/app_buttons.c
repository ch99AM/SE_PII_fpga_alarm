/*
 * app_buttons.c
 *
 *  Created on: Apr 29, 2021
 *      Author: este0
 */


#include "../include/app_buttons.h"

void handle_btn_conf_irs()
{
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BCONF_BASE, 0);
	change_mode();
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(REG_BCONF_BASE);
}

void handle_btn_up_irs()
{
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BUP_BASE, 0);
	add_time();
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(REG_BUP_BASE);
}

void handle_btn_down_irs()
{
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BDOWN_BASE, 0);
	substract_time();
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(REG_BDOWN_BASE);
}

void handle_btn_next_irs()
{
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BNEXT_BASE, 0);
	next_var();
	IORD_ALTERA_AVALON_PIO_EDGE_CAP(REG_BNEXT_BASE);
}

void init_btns_irqs()
{
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(REG_BCONF_BASE, 0xf);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BCONF_BASE, 0x0);
	alt_ic_isr_register(
			REG_BCONF_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BCONF_IRQ,
			handle_btn_conf_irs,
			0x0,
			0x0
	);

    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(REG_BUP_BASE, 0xf);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BUP_BASE, 0x0);
	alt_ic_isr_register(
			REG_BUP_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BUP_IRQ,
			handle_btn_up_irs,
			0x0,
			0x0
	);

    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(REG_BDOWN_BASE, 0xf);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BDOWN_BASE, 0x0);
	alt_ic_isr_register(
			REG_BDOWN_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BDOWN_IRQ,
			handle_btn_down_irs,
			0x0,
			0x0
	);

    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(REG_BNEXT_BASE, 0xf);
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(REG_BNEXT_BASE, 0x0);
	alt_ic_isr_register(
			REG_BNEXT_IRQ_INTERRUPT_CONTROLLER_ID,
			REG_BNEXT_IRQ,
			handle_btn_next_irs,
			0x0,
			0x0
	);
}
