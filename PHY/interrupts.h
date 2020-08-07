#ifndef _INTERRUPTS_H_
#define _INTERRUPTS_H_

#include <stdint.h>
#include <math.h>
#include "types.h"
#include "config.h"
#include "debug_frmwrk.h"

#define ONE_MS_TIMER_TIME	(999)		// 1MS
#define ONE_MS_TIMER_FREQ	(1000)		// in Hz

#define MODBUS_TIMER_TIME	(49)		// 50us
#define MODBUS_TIMER_FREQ	(20000)		//

#define SAMPLE_RATE_TIME	(149)		
#define SAMPLE_RATE_FREQ	(6600)		//


#define	Modbus_Timeout_ISR		TIMER0_IRQHandler
#define Make_Pulses_ISR			TIMER1_IRQHandler
#define Pulse_Clear_ISR			TIMER2_IRQHandler
#define	TIMER_1MS_ISR			TIMER3_IRQHandler


#define START_MODBUS_TIMER					enable_timer(LPC_TIM0)		// 100kHz modbus timer start
#define START_SAMPLE_TIMER					enable_timer(LPC_TIM1)		// 100kHz modbus timer start
#define STOP_MODBUS_TIMER					disable_timer(LPC_TIM0)		// 100kHz modbus timer stop

#define RESET_MODBUS_TIMER					reset_timer(LPC_TIM0)		// reset modbus timer

#define RESET_SAMPLE_TIMER					reset_timer(LPC_TIM1)		// reset modbus timer

int init_timers(void);
void start_timers(void);
int freq_change(int sample_rate);

extern uint32_t delay_timer_32;
extern uint32_t spi_sample_rate;
//struct declaration


#endif
