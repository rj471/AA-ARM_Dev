#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "board.h"

typedef struct{
	char port_num;
	char pin_num;
	char io;		// tells if this pin is configured as an input=1 or output=0..
}GPIOPin;

#define GPIOpin_t GPIOPin

#define PI 3.141592654

#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

#define CURRENT_CONFIG_MAJOR_VERSION 	1
#define CURRENT_CONFIG_MINOR_VERSION 	0

// #define gear_ratio 1

// this is the seconds multiplier..
#define SEC_MUL		(1000)

#define READ_TABLE_SIZE 		128
#define TOTAL_SENSOR_NUMBER 	45
#define ACCEL_REG_NUM			3

#define TRANSFER_BUF_SIZE 		100

#define MOTOR0 	0
#define MOTOR1 	1
#define MOTOR2  2
#define MOTOR3 	3

#if BOARD == IMARK_7_1
#define ENABLE485_CONFIGURE_2		UART2_ENABLE_PORT->FIODIR 	|= UART2_ENABLE_PIN
#define ENABLE485_ON_2			UART2_ENABLE_PORT->FIOSET 	|= UART2_ENABLE_PIN
#define ENABLE485_OFF_2			UART2_ENABLE_PORT->FIOCLR	|= UART2_ENABLE_PIN

#else
//as there was no enable pin in lower version of pcb
#define ENABLE485_CONFIGURE_2	0	
#define ENABLE485_ON_2			0
#define ENABLE485_OFF_2			0

#define LOCAL_SENSOR			1
#define REMOTE_SENSOR 			2

#endif

#define HOST_BAUD           (115200)

#define SLAVE_ID				1

//input
#define MOTOR_ON 	0 	//Push button
#define HOPPER_ON 	1//Push button
#define OBJECT_SNSR	2
#define SNSR_1		3
#define SNSR_2		4
#define SNSR_3		5
#define SNSR_4		6
#define SNSR_5		7

//Output
#define CAM1_TRIGGER 		0
#define CAM2_TRIGGER 		1
#define CAM3_TRIGGER 		2
#define CAM4_TRIGGER 		3

#define HOPPER 				4
#define GREEN_LED 			5
#define YELLOW_LED 			6
#define RED_LED 			7

#define MAX_SIMUL_OBJ 10

#define BASE_T1		0
#define BASE_T2 	10
#define BASE_T3		20
#define BASE_T4 	30

#define MAX_TIM_NUM 	10

#define CAM_ON_TIME 100

enum MODBUS_REGISTER_ADDRESS {
	MB_MY_IP1 = 400,  			//400
	MB_MY_IP2,					//401
	MB_MY_IP3,					//402
	MB_MY_IP4,					//403
	SM_DELAY_SET,				//404
	MB_READ_REQUEST,			//405
	SM_READ_DATA,				//406
	MB_WRITE_REQUEST = 407,		//407
	MB_START_ACCEL_READ = 409,	//409
	MB_STOP_ACCEL_READ,			//410
	MB_RESET_DEFAULTS,			//411
	HOLDING_REGS_SIZE	
};

enum MODBUS_ACCEL_STORE_ADDRESS{
	MB_X_ACCEL = 0,
	MB_Y_ACCEL = 1,
	MB_Z_ACCEL = 2
};

enum DELAY_TYPES {
	CAM1_DELAY_1 = 0x00,
	CAM1_DELAY_2,
	CAM1_DELAY_3,
	CAM1_DELAY_4,
	CAM1_DELAY_5,
	CAM1_DELAY_6,
	CAM1_DELAY_7,
	CAM1_DELAY_8,
	CAM1_DELAY_9,
	CAM1_DELAY_10,

	CAM2_DELAY_1,
	CAM2_DELAY_2,
	CAM2_DELAY_3,
	CAM2_DELAY_4,
	CAM2_DELAY_5,
	CAM2_DELAY_6,
	CAM2_DELAY_7,
	CAM2_DELAY_8,
	CAM2_DELAY_9,
	CAM2_DELAY_10,

	CAM3_DELAY_1,
	CAM3_DELAY_2,
	CAM3_DELAY_3,
	CAM3_DELAY_4,
	CAM3_DELAY_5,
	CAM3_DELAY_6,
	CAM3_DELAY_7,
	CAM3_DELAY_8,
	CAM3_DELAY_9,
	CAM3_DELAY_10,

	CAM4_DELAY_1,
	CAM4_DELAY_2,
	CAM4_DELAY_3,
	CAM4_DELAY_4,
	CAM4_DELAY_5,
	CAM4_DELAY_6,
	CAM4_DELAY_7,
	CAM4_DELAY_8,
	CAM4_DELAY_9,
	CAM4_DELAY_10,

	CAM1_ON_DELAY,
	CAM2_ON_DELAY,
	CAM3_ON_DELAY,
	CAM4_ON_DELAY,

	DELAY_HEARTBEAT,
	DELAY_IO_UPDATE,
	DELAY_TOTAL_NUM,
};

enum EEPS_WRITE {
	EEP_WRITE1 = 1,
	EEP_WRITE2 = 2,
	EEP_WRITE3 = 3,
	EEP_WRITE4 = 4,
};



#endif
