//!
/*!
 *The Board COnfiguraton file has all the data that assign the various pins to the varius functions 
 */
#ifndef _INCEPTION_1_0_ 
#define _INCEPTION_1_0_ 

// stepper ports definitions..

#define MOTOR1_PULSE_PORT	0
#define MOTOR1_PULSE_PIN	25 //MOTOR_1 PULSE
#define MOTOR1_DIR_PORT		0
#define MOTOR1_DIR_PIN		23 //MOTOR_1 DIRECTION

#define MOTOR2_PULSE_PORT	0
#define MOTOR2_PULSE_PIN	24 //MOTOR_2 PULSE
#define MOTOR2_DIR_PORT		0
#define MOTOR2_DIR_PIN		11 //MOTOR_2 DIRECTION

#define MOTOR3_PULSE_PORT	0
#define MOTOR3_PULSE_PIN	22 //MOTOR_3 PULSE
#define MOTOR3_DIR_PORT		0
#define MOTOR3_DIR_PIN		21 //MOTOR_3 DIRECTION

#define MOTOR4_PULSE_PORT	0
#define MOTOR4_PULSE_PIN	20 //MOTOR_4 PULSE
#define MOTOR4_DIR_PORT		0
#define MOTOR4_DIR_PIN		19 //MOTOR_4 DIRECTION

#define MOTOR_PORT1_SET		LPC_GPIO1 -> FIOSET
#define MOTOR_PORT1_CLR		LPC_GPIO1 -> FIOCLR
#define MOTOR_PORT1_DIR		LPC_GPIO1 -> FIODIR

#define MOTOR_PORT0_SET		LPC_GPIO0 -> FIOSET
#define MOTOR_PORT0_CLR		LPC_GPIO0 -> FIOCLR
#define MOTOR_PORT0_DIR		LPC_GPIO0 -> FIODIR

// LCD Definitions...

#define KS0108_DATA_PIN		LPC_GPIO2->FIOPIN
#define KS0108_DATA_DIR		LPC_GPIO2->FIODIR
#define KS0108_DATA_SET		LPC_GPIO2->FIOSET
#define KS0108_DATA_CLR		LPC_GPIO2->FIOCLR

#define KS0108_D0       0 //2.0 to 2.7 are used as the data pins for the LCD

// control port
#define KS0108_CTRL_DIR		LPC_GPIO2->FIODIR
#define KS0108_CTRL_SET		LPC_GPIO2->FIOSET
#define KS0108_CTRL_CLR		LPC_GPIO2->FIOCLR

// control signals
#define KS0108_RS			(1 << 11)
#define KS0108_RW			// permanently grounded			
#define KS0108_EN			(1 << 8)

// Port change for CS1 and CS2 as they are on different ports
#define KS01018_CS1_CS2_DIR		LPC_GPIO2->FIODIR
#define KS01018_CS1_CS2_SET		LPC_GPIO2->FIOSET
#define KS01018_CS1_CS2_CLR		LPC_GPIO2->FIOCLR

#define KS0108_CS1			(1 << 12)
#define KS0108_CS2			(1 << 9)

/* defines the number of inputs */
/* {port_num, pin_num, input=0 or output=1} */
#define INPUT_NUM			8

/*
	MCP23s17 is used for getting the inputs
	look at the SM_SPI statemachine
*/

#define OUTPUT_NUM			8

#define OUTPUT0				{0,25,1}
#define OUTPUT1				{0,23,1}
#define OUTPUT2				{0,24,1}
#define OUTPUT3				{0,11,1}
#define OUTPUT4				{0,22,1}
#define OUTPUT5				{0,21,1}
#define OUTPUT6				{0,20,1}
#define OUTPUT7				{0,19,1}

/* 	Outputs given on SPI lines...  
	Check the spi implementation for further information...
*/

// Keyboard...(6x4) this keypad is for the snapkeys bord
#define BOARD_MAX_KEY_ROWS 6
#define BOARD_MAX_KEY_COLS 4
#define KEYPAD_PORT 0
#define KEYPAD_INPUT_NIBBLE 5
#define KEYPAD_OUTPUT_NIBBLE 4 

#define GPIO_PIN_COL0	{3,26,1}
#define GPIO_PIN_COL1	{1,25,1}
#define GPIO_PIN_COL2	{1,26,1}
#define GPIO_PIN_COL3	{1,28,1}

#define GPIO_PIN_ROW0	{0,10,0}
#define GPIO_PIN_ROW1	{0,5,0}
#define GPIO_PIN_ROW2	{0,4,0}
#define GPIO_PIN_ROW3	{4,28,0}
#define GPIO_PIN_ROW4	{4,29,0}
#define GPIO_PIN_ROW5	{1,29,0}

// #define GPIO_PIN_COL0	{4,28,1}
// #define GPIO_PIN_COL1	{1,28,1}
// #define GPIO_PIN_COL2	{4,29,1}
// #define GPIO_PIN_COL3	{1,29,1}

// #define GPIO_PIN_ROW0	{0,10,0}
// #define GPIO_PIN_ROW1	{3,26,0}
// #define GPIO_PIN_ROW2	{0,5,0}
// #define GPIO_PIN_ROW3	{1,25,0}
// #define GPIO_PIN_ROW4	{0,4,0}
// #define GPIO_PIN_ROW5	{1,26,0}

#endif


