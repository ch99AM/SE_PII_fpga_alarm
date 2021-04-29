

#include "../include/app_timer.h"

void handle_timer_interrupts(void* context)
{
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);
	alt_putstr("Interrupts!\n");
}

void init_timer_irq()
{
	/* Register the ISR. */
	alt_ic_isr_register(TIMER_IRQ_INTERRUPT_CONTROLLER_ID,
			TIMER_IRQ,
			handle_timer_interrupts,
			0x0,
			0x0);
}
