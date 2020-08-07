//!
/*!
 *Main file 
 * All the various function are called inside the while loop of the main fucntion
 * The various functions are polled using the Timer at regualr preset intervals set at the beginning of the program.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

#include "LPC17xx.h"
#include "ring.h"
#include "syscalls.h"
#include "global.h"
#include "config.h"
#include "delay_timer.h"

#include "SimpleModbusSlave_1769.h"
#include "state_machine.h"
#include "config_data.h"

#include "SM_Operation.h"

extern "C" {	
	#include "lpc17xx_libcfg.h"
	#include "lpc17xx_ssp.h"
	#include "lpc17xx_spi.h"
	#include "lpc17xx_rtc.h"
	#include "lpc17xx_clkpwr.h"
	#include "lpc17xx_gpio.h"
	#include "lpc17xx_uart.h"
	#include "lpc17xx_pinsel.h"
	#include "debug_frmwrk.h"	
	#include "lpc17xx_nvic.h"
	#include "lpc17xx_emac.h"

	#include "timer.h"
	#include "interrupts.h"
	#include "input_output.h"
	#include "i2c.h"
	#include "i2c_eeprom.h"
	#include "multi-steppers.h"
	#include "usbSerial.h"
	#include "iap_driver.h"
}

/*!
 *Main file!
 *
*/
/**#########################################################################################*/	
extern "C"{	
	uint32_t delay_timer_32 = 0; 
// uint8_t system_io_update();
}
/**#########################################################################################*/
int modbus_exception_handler(int modbus_ret);
int apply_modbus_values(int modbus_cnt);
int set_holding_registers_values(int modbus_cnt);
int start_state_machine(int num);
int stop_state_machine(int num);
void execute_eeprom_write(int flash_write);
int modbus_retVal = 0;

/**#########################################################################################*/

/**#########################################################################################*/

unsigned int holdingRegs[HOLDING_REGS_SIZE]; // function 3 and 16 register array
unsigned int holdingRegs_prev[HOLDING_REGS_SIZE]; // function 3 and 16 register array

int slave_id_select;

int baud_rate_select;
int parity_bit = 0;
int stop_bit = 1;

int input_rise_debounce_time = 20;
int input_fall_debounce_time = 20;

uint32_t baud_value=0;

int flash_write_allowed = 0;
int flash_write_now = 0;

uint8_t fw_major_version;
uint8_t fw_minor_version;
 
SM_OPERATION sm_operation;

int main(void) {
	uint32_t i,modbus_count=0;
	int toggle = 0;

	// memcpy(TCP_TX_BUF,transfer_accel_table,sizeof(transfer_accel_table));

	// printf("\n hi=%d",sizeof(transfer_accel_table));
	/* Initialize debug via UART0
		* – 115200bps
		* – 8 data bit
		* – No parity
		* – 1 stop bit
		* – No flow control
	*/
	// sprintf(data_string,"20.0,20.0,40.0,10.0,50.0,60.0,70.0,80.0");
	debug_frmwrk_init();
	
	
	LPC_SC->PCONP |= ( 1 << 15 ); // power up GPIO		
	printf("\nPACMAC SystemCoreClock = %d Hz\n", SystemCoreClock);
/**#########################################################################################*/		
	dt_set_delay(DELAY_HEARTBEAT, 5000);
	// dt_set_delay(DELAY_IO_UPDATE, 100);
	// dt_set_delay(DATA_RATE, 1000);
	// dt_set_delay(DELAY_LSM6DS3, delay_val);

/**#########################################################################################*/		
#if 1
	if(CONFIG_VERSION_OK != read_config_version(fw_major_version,fw_minor_version)){	
		// now fw_major and fw_minor contain the config version...
		fw_major_version=CURRENT_CONFIG_MAJOR_VERSION;
		fw_minor_version=CURRENT_CONFIG_MINOR_VERSION;
		// printf("\nread onfig data");
		config_set_defaults(fw_major_version, fw_minor_version);
	}else{	
		// now fw_major and fw_minor contain the config version...
		printf("\nread onfig data");
		read_config_data();
	}
	printf("\nout of config read %d\n",TRUE);
	// config_set_defaults(fw_major_version, fw_minor_version);
#endif
/**#########################################################################################*/
	// config_set_defaults(6,9);
	// read_config_data();
	unsigned int baud_val[5]={1200,9600,19200,38400,57600};
	// printf("\n%d",baud_rate_select);
	baud_rate_select = 1;
	baud_value=baud_val[baud_rate_select];
	// UART_Init2(baud_value);
	usbSerialInit();


	// modbus_configure(&modbus2,(long)baud_value,slave_id_select,HOLDING_REGS_SIZE,holdingRegs); // MODBUS setup

#ifdef MOD_USB
	modbus_configure(&modbusUSB,115200,1,HOLDING_REGS_SIZE,holdingRegs);
#endif
	
/**#########################################################################################*/
	dt_init();
	stepper_init();	
	init_timers();
	stepper_update_freq();
	io_init();
	iap_init();
	// stepper_update_freq();
/**#########################################################################################*/		
	/*Required for multi-steppers library*/
	RESET_MODBUS_TIMER;
	start_timers();

/**#########################################################################################*/		
	//SSP master init
	// ssp_master_init();
	// GPIO_SetDir(0, (1<<6), 1);
	// GPIO_SetValue(0, (1<<6));
	// GPIO_SetValue(0, (1<<6));
/**#########################################################################################*/			

	for(i=0;i<DELAY_TOTAL_NUM;i++){
		dt_reset(i);
	}

/**#########################################################################################*/
	toggle = 0;
	
	// for(i=0;i<HOLDING_REGS_SIZE;i++){
	// 	holdingRegs[i]=100;
	// }
	
	// for(modbus_count=0;modbus_count<HOLDING_REGS_SIZE;modbus_count++){
	// 	set_holding_registers_values(modbus_count);
	// }


	int mySlaveID = 1;
	/**#########################################################################################*/	
#if 0
	//TCP_INIT
	printf("\nTCP init started %d",1);

	int init_val = TCPLowLevelInit();
	printf("\n init_val = %d",init_val);
	// EMAC_Init_New();
	HTTPStatus = 0;                                // clear HTTP-server's flag register
	// modbusserver_init(holdingRegs,HOLDING_REGS_SIZE);
	// TCPLocalPort = TCP_PORT_HTTP;                  // set port we want to listen to
	TCPLocalPort = TCP_PORT_MODBUS;                  // set port we want to listen to
	// CodeRed - added info message
	// LPC_GPIO0->FIODIR |= TEST_LED;
	LPC_GPIO3->FIODIR |= (1<<25);
#endif
/**#########################################################################################*/
	printf("\nwhil is starting 1");
	uint8_t done=0;

	// LPC_GPIO1->FIOSET = (1<<27);
	// memcpy(TCP_TX_BUF,transfer_accel_table,sizeof(transfer_accel_table));
	// LPC_GPIO1->FIOCLR = (1<<27);
	// stepper_set_new_profile(0,10,1,1);
	// stepper_set_final_pos(0,5000);
	io_set_output(YELLOW_LED,1);

	while(1){

		if(input_rise_flag[MOTOR_ON]){
			input_rise_flag[MOTOR_ON] = 0;
			stepper_set_new_profile(MOTOR0,10.0,0.5,0.5);
			stepper_set_final_pos(MOTOR0,0xFFFFFFF);
		}

		if(input_fall_flag[MOTOR_ON]){
			input_fall_flag[MOTOR_ON] = 0;
			stepper_stop_motor(MOTOR0);
		}

		if(input_rise_flag[HOPPER_ON]){
			input_rise_flag[HOPPER_ON] = 0;
			io_set_output(HOPPER,1);
		}

		if(input_fall_flag[HOPPER_ON]){
			input_fall_flag[HOPPER_ON] = 0;
			io_set_output(HOPPER,0);
		}

				
		if(flash_write_now){
			// printf("\n write eeprom");
			execute_eeprom_write(flash_write_now);
		}

		// printf("\nwhil is starting 1");

		/* update function for the modbus operation*/
		// modbus_retVal = modbus_update(&modbus2);		
		modbus_retVal = modbus_update(&modbusUSB);		
				

		if(dt_is_timeup(DELAY_HEARTBEAT)){
			dt_reset(DELAY_HEARTBEAT);

			if(toggle){
				toggle = 0;
				// printf("\ntog = 0 ");
				// io_set_output(0,0);
				// io_set_output(1,0);
				// io_set_output(2,0);
				// io_set_output(3,0);
			}else{
				toggle = 1;
				// printf("\ntog = 1");
				// io_set_output(0,1);
				// io_set_output(1,1);
				// io_set_output(2,1);
				// io_set_output(3,1);

			}		
		}		
	}
	return 0;
}

enum getSerialCommand
{
	Set_Byte=0x23,
	Valid_Byte=0x24,
	Set_Word=0x25,
	Reset_All=0x26,
	Init_Ptr=0x27,
	Turn_On_GPIO=0x28,
	Turn_Off_GPIO=0x29,
	Set_Flag=0x2A,
	Clear_Flag=0x2B,
	Read_byte=0x2C,
    Trig_Cam=0x2E,
	Set_Delay=0x2F,
	Read_Mem=0x30    
};

void Check_RX_Data(uint16_t *frameArray)
{
  int i=0;
  if(frameArray[i]==Valid_Byte)
  {
  	switch(frameArray[++i])
  	{
  	 case Set_Byte:
  	   if(frameArray[++i]==\0) return;
  	   break;
  	 case Set_Word:
  	  if(frameArray[++i]==\0) return;
  	  	break;
  	 case Reset_All:
  	  	break;
  	 case Init_Ptr:
  	  	break;
  	 case Turn_On_GPIO:
      if(frameArray[++i]==\0) return;
      	break;
     case Turn_Off_GPIO:
      if(frameArray[++i]==\0) return;
      	break;
     case Set_Flag:
      if(frameArray[++i]==\0) return;
      	break;
     case Clear_Flag:
      if(frameArray[++i]==\0) return;
      	break;
     case Read_byte:
      if(frameArray[++i]==\0) return;
      	break;
     case Trig_Cam:
      if(frameArray[++i]==\0) return;
		break;
     case Set_Delay:
      if(frameArray[++i]==\0) return;
      	break;
     case Read_Mem:
      if(frameArray[++i]==\0) return;

     default:
       	break;

  	}
  }
 else
 {

 //implement result checking logic
 }


}





// extern "C"{
int modbus_exception_handler(int modbus_ret){
	switch(modbus_ret){
		case MB_OVERFLOW:
			// do something here..
		break;
		case MB_DATA_WRITTEN:{
			// printf("\n MB_DATA_WRITTEN");
			// int modbus_count;
			// copy the received data to local variables..
			// for(modbus_count=0;modbus_count<HOLDING_REGS_SIZE;modbus_count++){
				// apply_modbus_values(modbus_count);
			// }
			break;
		}
		case MB_CORRUPT_PACKET:
			// printf("\n MB_CORRUPT_PACKET");
			// do something here..
		break;
		case MB_CHECKSUM_FAILED:
			// printf("\n MB_CHECKSUM_FAILED");
			// do something here..
		break;
		case MB_INCORRECT_ID:
			// printf("\n MB_INCORRECT_ID");
			// do something here..
		break;
		case MB_DATA_READ:
			// printf("\n MB_DATA_READ");
			// do something here..
		break;
	}
	return 1;
}

int set_holding_registers_values_accel_table(int modbus_cnt , int index_offset){
	unsigned int temp_int=0;
	switch(modbus_cnt){

		case MB_X_ACCEL:
			// temp_int = (unsigned int)(accel_table[index_offset].read_datax);
			// if(temp_int != holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))]){
			// 	holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))] = temp_int;
			// }
			break;

		case MB_Y_ACCEL:
			// temp_int = (unsigned int)(accel_table[index_offset].read_datay);
			// if(temp_int != holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))]){
			// 	holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))] = temp_int;
			// }
			break;
			
		case MB_Z_ACCEL:
			// temp_int = (unsigned int)(accel_table[index_offset].read_dataz);
			// if(temp_int != holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))]){
			// 	holdingRegs[(modbus_cnt+(index_offset*ACCEL_REG_NUM))] = temp_int;
			// }
			break;		
	}
}

int set_holding_registers_values(int modbus_cnt){
	unsigned int temp_int=0;
	switch(modbus_cnt){
		case MB_MY_IP1:
			// temp_int = (unsigned int)MYIP_1;
			// if(temp_int != holdingRegs[MB_MY_IP1]){
			// 	holdingRegs[MB_MY_IP1] = temp_int;
			// }
			
			break;

		case MB_MY_IP2:
			// temp_int = (unsigned int)MYIP_2;
			// if(temp_int != holdingRegs[MB_MY_IP2])
			// 	holdingRegs[MB_MY_IP2] = temp_int;
			break;		

		case MB_MY_IP3:
			// temp_int = (unsigned int)MYIP_3;
			// if(temp_int != holdingRegs[MB_MY_IP3])
			// 	holdingRegs[MB_MY_IP3] = temp_int;
			break;	

		case MB_MY_IP4:
			// temp_int = (unsigned int)MYIP_4;
			// if(temp_int != holdingRegs[MYIP_4]){
			// 	holdingRegs[MB_MY_IP4] = temp_int;
			// }

			break;

		case SM_DELAY_SET:
			// temp_int = (unsigned int)delay_val;
			// if(temp_int != holdingRegs[SM_DELAY_SET])
			// 	holdingRegs[SM_DELAY_SET] = temp_int;
			break;			
			
		case SM_READ_DATA:
			// temp_int = (unsigned int)read_data_lsm;
			// if(temp_int != holdingRegs[SM_READ_DATA])
			// 	holdingRegs[SM_READ_DATA] = temp_int;
			
		break;

		default:

			break;
	}
	return 1;

}

void execute_eeprom_write(int flash_write){
	switch(flash_write){
		case EEP_WRITE1:
			// printf("\n write 1");
			flash_write_now = 0;
			write_config_data();		
			break;

		case EEP_WRITE2:
			// printf("\n write 2");
			flash_write_now = 0;
			write_config_data_table_1();	
			break;

		case EEP_WRITE3:
			// printf("\n write 3");
			flash_write_now = 0;
			write_config_data_table_2();	
			break;
			
		case EEP_WRITE4:
			flash_write_now = 0;
			write_config_data_table_3();	
			break;
		
		default:
			flash_write_now = 0;
			break;
	}

}


#if 1
int apply_modbus_values(int modbus_cnt){
	// if(holdingRegs_prev[modbus_cnt]!=holdingRegs[modbus_cnt]){
		
		switch(modbus_cnt){
			case MB_MY_IP1:{
				// MYIP_1 = (uint8_t)(holdingRegs[MB_MY_IP1]);
				// flash_write_now = 1;		
				break;
			}	
			case MB_MY_IP2:{
				// MYIP_2 = (uint8_t)(holdingRegs[MB_MY_IP2]);
				// flash_write_now = 1;
				break;
			}

			case MB_MY_IP3:{
				// MYIP_3 = (uint8_t)(holdingRegs[MB_MY_IP3]);
				// flash_write_now = 1;				
				break;
			}
		
			case MB_MY_IP4:{
				// MYIP_4 = (uint8_t)(holdingRegs[MB_MY_IP4]);
				// flash_write_now = 1;
			break;
			}

			case SM_DELAY_SET:{
				// delay_val = (uint16_t)(holdingRegs[SM_DELAY_SET]);
				// dt_set_delay(DELAY_LSM6DS3, delay_val);
				// flash_write_now = 1;
			break;	
			}

			case MB_READ_REQUEST:{
				// addr_read = (uint8_t)(holdingRegs[MB_READ_REQUEST]);
				// read_request = 1; 
				
			break;
			}

			case MB_WRITE_REQUEST:{
				// addr_write = (uint8_t)(holdingRegs[MB_WRITE_REQUEST]);
				// data_to_write = (uint8_t)(holdingRegs[MB_WRITE_REQUEST+ 1]);
				// write_request = 1;

			break;	
			}

			case MB_START_ACCEL_READ:{
				// start_reading_acc = (uint8_t)(holdingRegs[MB_START_ACCEL_READ]);
			break;
			}

			case MB_STOP_ACCEL_READ:{
				// stop_reading_acc = (uint8_t)(holdingRegs[MB_STOP_ACCEL_READ]);
			break;
			}
			
		}
	// }
	return 1;
}
#endif
	
extern "C"{
	int take_samples(){
		return 1;
	}

	int update_sm_operation_every_1ms(){
		if(SM_START == sm_operation.SM_started()){
			sm_operation.update();
		}
	}
}





// call this to start state machine
int start_state_machine(){
	if(SM_START != sm_operation.SM_started()){
		sm_operation.SM_start();
		io_set_output(GREEN_LED,1);
		io_set_output(YELLOW_LED,0);
	}
}

int stop_state_machine(){
	if(SM_START == sm_operation.SM_started()){
		sm_operation.stop_now();
		io_set_output(GREEN_LED,0);
		io_set_output(YELLOW_LED,1);
	}
}