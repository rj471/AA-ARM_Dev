#ifndef _MULTI_STEPPER_PORTS_H_
#define _MULTI_STEPPER_PORTS_H_

#include "board.h"

#define MULTI_STEPPERS_DIFFERENT_PORTS
	#ifdef MULTI_STEPPERS_DIFFERENT_PORTS
/**#########################################################################################*/	
			#define PULSE_PORT1 		MOTOR1_PULSE_PORT
			#define PULSE_PIN_OFFSET1	MOTOR1_PULSE_PIN
			#define PULSE_PIN_SHIFT1   	(1<<MOTOR1_PULSE_PIN)
			#define DIR_PORT1			MOTOR1_DIR_PORT
			#define DIR_PIN_OFFSET1		MOTOR1_DIR_PIN
			#define DIR_PIN_SHIFT1     	(1<<MOTOR1_DIR_PIN)		
			
		#if PULSE_PORT1
			#define PULSE_PORT_SET1		MOTOR_PORT1_SET
			#define PULSE_PORT_CLEAR1	MOTOR_PORT1_CLR
			#define PULSE_PORT_DIR1		MOTOR_PORT1_DIR
		#else
			#define PULSE_PORT_SET1		MOTOR_PORT0_SET
			#define PULSE_PORT_CLEAR1	MOTOR_PORT0_CLR
			#define PULSE_PORT_DIR1		MOTOR_PORT0_DIR
		#endif
		
		#if DIR_PORT1
			#define DIR_PORT_SET1		MOTOR_PORT1_SET
			#define DIR_PORT_CLEAR1		MOTOR_PORT1_CLR
			#define DIR_PORT_DIR1		MOTOR_PORT1_DIR
		#else
			#define DIR_PORT_SET1		MOTOR_PORT0_SET
			#define DIR_PORT_CLEAR1		MOTOR_PORT0_CLR
			#define DIR_PORT_DIR1		MOTOR_PORT0_DIR		
		#endif	
/**#########################################################################################*/
			#define PULSE_PORT2 		MOTOR2_PULSE_PORT
			#define PULSE_PIN_OFFSET2	MOTOR2_PULSE_PIN
			#define PULSE_PIN_SHIFT2   	(1<<MOTOR2_PULSE_PIN)
			#define DIR_PORT2			MOTOR2_DIR_PORT
			#define DIR_PIN_OFFSET2		MOTOR2_DIR_PIN
			#define DIR_PIN_SHIFT2     	(1<<MOTOR2_DIR_PIN)		
			
		#if PULSE_PORT2
			#define PULSE_PORT_SET2		MOTOR_PORT1_SET
			#define PULSE_PORT_CLEAR2	MOTOR_PORT1_CLR
			#define PULSE_PORT_DIR2		MOTOR_PORT1_DIR
		#else
			#define PULSE_PORT_SET2		MOTOR_PORT0_SET
			#define PULSE_PORT_CLEAR2	MOTOR_PORT0_CLR
			#define PULSE_PORT_DIR2		MOTOR_PORT0_DIR
		#endif
		
		#if DIR_PORT2
			#define DIR_PORT_SET2		MOTOR_PORT1_SET
			#define DIR_PORT_CLEAR2		MOTOR_PORT1_CLR
			#define DIR_PORT_DIR2		MOTOR_PORT1_DIR
		#else
			#define DIR_PORT_SET2		MOTOR_PORT0_SET
			#define DIR_PORT_CLEAR2		MOTOR_PORT0_CLR
			#define DIR_PORT_DIR2		MOTOR_PORT0_DIR		
		#endif		
/**#########################################################################################*/
			#define PULSE_PORT3 		MOTOR3_PULSE_PORT
			#define PULSE_PIN_OFFSET3	MOTOR3_PULSE_PIN
			#define PULSE_PIN_SHIFT3   	(1<<MOTOR3_PULSE_PIN)
			#define DIR_PORT3			MOTOR3_DIR_PORT
			#define DIR_PIN_OFFSET3		MOTOR3_DIR_PIN
			#define DIR_PIN_SHIFT3     	(1<<MOTOR3_DIR_PIN)		
			
		#if PULSE_PORT3
			#define PULSE_PORT_SET3		MOTOR_PORT1_SET
			#define PULSE_PORT_CLEAR3	MOTOR_PORT1_CLR
			#define PULSE_PORT_DIR3		MOTOR_PORT1_DIR
		#else
			#define PULSE_PORT_SET3		MOTOR_PORT0_SET
			#define PULSE_PORT_CLEAR3	MOTOR_PORT0_CLR
			#define PULSE_PORT_DIR3		MOTOR_PORT0_DIR
		#endif
		
		#if DIR_PORT3
			#define DIR_PORT_SET3		MOTOR_PORT1_SET
			#define DIR_PORT_CLEAR3		MOTOR_PORT1_CLR
			#define DIR_PORT_DIR3		MOTOR_PORT1_DIR
		#else
			#define DIR_PORT_SET3		MOTOR_PORT0_SET
			#define DIR_PORT_CLEAR3		MOTOR_PORT0_CLR
			#define DIR_PORT_DIR3		MOTOR_PORT0_DIR		
		#endif		
/**#########################################################################################*/
			#define PULSE_PORT4 		MOTOR4_PULSE_PORT
			#define PULSE_PIN_OFFSET4	MOTOR4_PULSE_PIN
			#define PULSE_PIN_SHIFT4   	(1<<MOTOR4_PULSE_PIN)
			#define DIR_PORT4			MOTOR4_DIR_PORT
			#define DIR_PIN_OFFSET4		MOTOR4_DIR_PIN
			#define DIR_PIN_SHIFT4     	(1<<MOTOR4_DIR_PIN)		
			
		#if PULSE_PORT4
			#define PULSE_PORT_SET4		MOTOR_PORT1_SET
			#define PULSE_PORT_CLEAR4	MOTOR_PORT1_CLR
			#define PULSE_PORT_DIR4		MOTOR_PORT1_DIR
		#else
			#define PULSE_PORT_SET4		MOTOR_PORT0_SET
			#define PULSE_PORT_CLEAR4	MOTOR_PORT0_CLR
			#define PULSE_PORT_DIR4		MOTOR_PORT0_DIR
		#endif
		
		#if DIR_PORT4
			#define DIR_PORT_SET4		MOTOR_PORT1_SET
			#define DIR_PORT_CLEAR4		MOTOR_PORT1_CLR
			#define DIR_PORT_DIR4		MOTOR_PORT1_DIR
		#else
			#define DIR_PORT_SET4		MOTOR_PORT0_SET
			#define DIR_PORT_CLEAR4		MOTOR_PORT0_CLR
			#define DIR_PORT_DIR4		MOTOR_PORT0_DIR		
		#endif		
/**#########################################################################################*/
		
	#else
/**#########################################################################################*/
			#define PULSE_PORT			MOTOR1_PULSE_PORT
			#define PULSE_PIN_OFFSET	MOTOR1_PULSE_PIN
			#define PULSE_PIN_SHIFT	   	(1<<MOTOR1_PULSE_PIN)
			#define DIR_PORT			MOTOR1_DIR_PORT
			#define DIR_PIN_OFFSET		MOTOR1_DIR_PIN
			#define DIR_PIN_SHIFT		(1<<MOTOR1_DIR_PIN)		
			
		#if PULSE_PORT
			#define PULSE_PORT_SET		MOTOR_PORT1_SET
			#define PULSE_PORT_CLEAR	MOTOR_PORT1_CLR
			#define PULSE_PORT_DIR		MOTOR_PORT1_DIR
		#else
			#define PULSE_PORT_SET		MOTOR_PORT0_SET
			#define PULSE_PORT_CLEAR	MOTOR_PORT0_CLR
			#define PULSE_PORT_DIR		MOTOR_PORT0_DIR
		#endif
		
		#if DIR_PORT
			#define DIR_PORT_SET		MOTOR_PORT1_SET
			#define DIR_PORT_CLEAR		MOTOR_PORT1_CLR
			#define DIR_PORT_DIR		MOTOR_PORT1_DIR
		#else
			#define DIR_PORT_SET		MOTOR_PORT0_SET
			#define DIR_PORT_CLEAR		MOTOR_PORT0_CLR
			#define DIR_PORT_DIR		MOTOR_PORT0_DIR		
		#endif		
	#endif
/**#########################################################################################*/	
#endif
