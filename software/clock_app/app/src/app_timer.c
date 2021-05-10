
#include "../include/app_timer.h"

void handle_timer_interrupts(void* context) {
	*timer_ptr = 0x0;
	increase_time();
}

void init_timer_irq() {
	init_hour(22, 59, 58);
	init_leds();
	turn_off_all();
	turn_off_aled();
	set_alarm(23, 0);
	timer_ptr = (short*)TIMER_BASE;

	alt_ic_isr_register(TIMER_IRQ_INTERRUPT_CONTROLLER_ID,
	TIMER_IRQ, handle_timer_interrupts, 0x0, 0x0);
}
