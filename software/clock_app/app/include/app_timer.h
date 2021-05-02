/*
 * app_timer.h
 *
 *  Created on: 28 de abr. de 2021
 *      Author: Christian
 */

#ifndef APP_INCLUDE_APP_TIMER_H_
#define APP_INCLUDE_APP_TIMER_H_

#include "sys/alt_stdio.h"
#include "system.h"
#include "alt_types.h"
#include "sys/alt_irq.h"
#include "altera_avalon_timer_regs.h"

void init_timer_irq();

#endif /* APP_INCLUDE_APP_TIMER_H_ */
