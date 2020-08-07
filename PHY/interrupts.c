#include <stdlib.h>
#include "interrupts.h"
#include "timer.h"
#include "input_output.h"
#include "uart.h"
#include "multi-steppers.h"

void TIMER_1MS_ISR(void){	//this invoking on 1mSEC

	delay_timer_32++;
	io_update();
	update_sm_operation_every_1ms();
	Move_Motor();

	TIM_ClearIntPending(LPC_TIM3, TIM_MR0_INT);
	
}

void Make_Pulses_ISR(void){

	Make_Pulses();
	TIM_ClearIntPending(LPC_TIM1, TIM_MR0_INT);
}

void Pulse_Clear_ISR(void){ ////this invoking on 5uSEC

	Pulse_Clear();
	TIM_ClearIntPending(LPC_TIM1, TIM_MR0_INT);	
}

void Modbus_Timeout_ISR(void){
	
#ifdef MOD_UART2	

	if( (Uart_ChkRcv2() == 0) && ((&modbus2)->modbus_data_complete == 0) ) { // some data available on Uart and last frame analysis complete
		(&modbus2)->modbusTimerCount++;
		if( ( ( ((&modbus2)->modbusTimerCount)*(MODBUS_TIMER_TIME+1) ) ) > ((&modbus2)->modbus_timeout) ){
			(&modbus2)->ring_slaveID = Uart_GetC2(); // store slaveId here
			if((&modbus2)->ring_slaveID != (&modbus2)->slaveID){ //not my data...  clear ring
				ring_clear((&modbus2)->ring_address);
			}else{ //my data
				(&modbus2)->modbus_data_complete = 1;
			}
		}
	}
	
#endif

#ifdef MOD_USB

	if( (VCOM_ChkRcv() == 0) && ((&modbusUSB)->modbus_data_complete == 0) ) { // some data available on Uart and last frame analysis complete
		(&modbusUSB)->modbusTimerCount++;
		if( ( ( ((&modbusUSB)->modbusTimerCount)*(MODBUS_TIMER_TIME+1) ) ) > ((&modbusUSB)->modbus_timeout) ){
			(&modbusUSB)->ring_slaveID = VCOM_GetCh(); //store slaveId here
			if((&modbusUSB)->ring_slaveID != (&modbusUSB)->slaveID){ //not my data...  clear ring
				ring_clear((&modbusUSB)->ring_address);
				
			}else{ //my data
				(&modbusUSB)->modbus_data_complete = 1;
			}
		}
	}
	
#endif

	TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT);
}

/* both the timers of the LPC2148 are used */
/* initialise each of them with their appropriate ISR */
/* and with their appropriate match compare values here*/
int init_timers(void)
{
	// This runs every 1MS
	init_timer0_freq(MODBUS_TIMER_TIME);

	// we want the timer1 to run at 50Khz
	init_timer1_freq(MAKE_PULSES_TIME);


	init_timer2_freq(PULSE_CLEAR_TIME);

	init_timer3_freq(ONE_MS_TIMER_TIME);
	
	// This runs every 1MS
	return 1;
}


void start_timers(void){
    enable_timer(LPC_TIM0);
    enable_timer(LPC_TIM1);
    enable_timer(LPC_TIM2);
    enable_timer(LPC_TIM3);
}
