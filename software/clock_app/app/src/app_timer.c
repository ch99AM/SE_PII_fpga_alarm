
#include "../include/app_timer.h"

void handle_timer_interrupts(void* context) {
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_BASE, 0);
	increase_time();
	alt_putstr("Interrupts!\n");
}

void init_timer_irq() {
	init_hour(22, 59, 58);
	init_leds();
	set_alarm(23, 0);
	/* Register the ISR. */
	alt_ic_isr_register(TIMER_IRQ_INTERRUPT_CONTROLLER_ID,
	TIMER_IRQ, handle_timer_interrupts, 0x0, 0x0);
}
