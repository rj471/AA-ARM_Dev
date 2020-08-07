//!
/*!
 *The Board COnfiguraton file has all the data that assign the various pins to the varius functions 
 */
#ifndef _IMARK6_0_ 
#define _IMARK6_0_ 

// stepper ports definitions..

#define MOTOR1_PULSE_PORT	0
#define MOTOR1_PULSE_PIN	19 //MOTOR_1 PULSE
#define MOTOR1_DIR_PORT		0
#define MOTOR1_DIR_PIN		20 //MOTOR_1 DIRECTION

#define MOTOR2_PULSE_PORT	0
#define MOTOR2_PULSE_PIN	21 //MOTOR_2 PULSE
#define MOTOR2_DIR_PORT		0
#define MOTOR2_DIR_PIN		22 //MOTOR_2 DIRECTION

#define MOTOR3_PULSE_PORT	0
#define MOTOR3_PULSE_PIN	23 //MOTOR_3 PULSE
#define MOTOR3_DIR_PORT		0
#define MOTOR3_DIR_PIN		24 //MOTOR_3 DIRECTION

#define MOTOR4_PULSE_PORT	0
#define MOTOR4_PULSE_PIN	25 //MOTOR_4 PULSE
#define MOTOR4_DIR_PORT		0
#define MOTOR4_DIR_PIN		26 //MOTOR_4 DIRECTION

#define MOTOR_PORT1_SET		LPC_GPIO1 -> FIOSET
#define MOTOR_PORT1_CLR		LPC_GPIO1 -> FIOCLR
#define MOTOR_PORT1_DIR		LPC_GPIO1 -> FIODIR

#define MOTOR_PORT0_SET		LPC_GPIO0 -> FIOSET
#define MOTOR_PORT0_CLR		LPC_GPIO0 -> FIOCLR
#define MOTOR_PORT0_DIR		LPC_GPIO0 -> FIODIR

#if 0
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

// #define LCD_CONFIGURE		LPC_GPIO3->FIODIR
// #define LCD_BACKLIGHT_ON	LPC_GPIO3->FIOSET
// #define LCD_BACKLIGHT_OFF	LPC_GPIO3->FIOCLR
// #define LCD_PIN				(1 << 25)
#endif
/* defines the number of inputs */
/* {port_num, pin_num, input=0 or output=1} */
// Inputs... {Port, pin, 1 (for input)}

#define INPUT_NUM			4

#define INPUT0				{0,0,0}
#define INPUT1				{0,1,0}
#define INPUT2				{0,4,0}
#define INPUT3				{0,5,0}
#define INPUT4				{0,6,0}
#define INPUT5				{0,7,0}
#define INPUT6				{0,8,0}
#define INPUT7				{0,9,0}

/*
	MCP23s17 is used for getting the inputs
	look at the SM_SPI statemachine
*/

#define OUTPUT_NUM			8
#if 1

#define OUTPUT0				{0,19,1}
#define OUTPUT1				{0,20,1}
#define OUTPUT2				{0,21,1}
#define OUTPUT3				{0,22,1}
#define OUTPUT4				{0,23,1}
#define OUTPUT5				{0,24,1}
#define OUTPUT6				{0,25,1}
#define OUTPUT7				{0,26,1}

#endif

/* 	Outputs given on SPI lines...  
	Check the spi implementation for further information...
*/

// Keyboard...(6x4) this keypad is for the snapkeys bord
#define BOARD_MAX_KEY_ROWS 2
#define BOARD_MAX_KEY_COLS 2
#define KEYPAD_PORT 0
#define KEYPAD_INPUT_NIBBLE 5
#define KEYPAD_OUTPUT_NIBBLE 4 

#define GPIO_PIN_COL0	{1,28,1}
#define GPIO_PIN_COL1	{1,29,1}
#define GPIO_PIN_COL2	{1,19,1}
#define GPIO_PIN_COL3	{3,26,1}

#define GPIO_PIN_ROW0	{1,26,0}
#define GPIO_PIN_ROW1	{1,27,0}
#define GPIO_PIN_ROW2	{0,04,0}
#define GPIO_PIN_ROW3	{4,28,0}
#define GPIO_PIN_ROW4	{4,29,0}
#define GPIO_PIN_ROW5	{1,25,0}

// Seven Segment... {Port,pin, 0( for output)}
#define SEVENSEGMENT_ENABLE		1
#define SEGMENT_LINES			5
#define SEGMENT_NUM				8
#define SEGMENT_ROWS			1

#define SEGMENT_A		{2,07,1}
#define SEGMENT_B		{2,00,1}
#define SEGMENT_C		{2,01,1}
#define SEGMENT_D		{2,02,1}
#define SEGMENT_E		{2,03,1}
#define SEGMENT_F		{2,04,1}
#define SEGMENT_G		{2,05,1}
#define SEGMENT_H		{2,06,1}

#define SEGMENT_1		{2,8,1}
#define SEGMENT_2		{2,9,1}
#define SEGMENT_3		{2,11,1}
#define SEGMENT_4		{2,12,1}
#define SEGMENT_5		{2,13,1}

// #define S7SEGMENT_VAL   (1<<11 | 1<<12 | 1<<13 | 1<<14 | 1<<15 | 1<<16 | 1<<17 | 1<<19)	// uses pin14 of port0
#define S7SEGMENT_VAL   (1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<4 | 1<<5 | 1<<6 | 1<<7)		// uses pin18 of port0
#define S7LINE_0 	(1 << 8 | 1 << 9 | 1 << 11 | 1 << 12 | 1 << 13)
// #define S7LINE_CLR_1 	()

// #define S7CLR GPIO_ClearValue(2,S7SEGMENT_VAL);

#define S7SEGMENT_CLR_PORT0  FIO0CLR

#define S7SEGMENT_SET_PORT0  FIO0SET

#define S7SEGMENT_CLR_PORT1  FIO1CLR
#define S7SEGMENT_SET_PORT1  FIO1SET

#define S7SEGMENT_LINE1		(1 << 20)
#define S7SEGMENT_LINE2		(1 << 31)
#define S7SEGMENT_LINE3		(1 << 24)
#define S7SEGMENT_LINE4		(1 << 25)
#define S7SEGMENT_LINE5		(1 << 31)
// LCD segment definitions. 
// These will need to be changed depending on the 
// wiring of your output port to the segements.
#define segment_a 0x80L
#define segment_b 0x01L
#define segment_c 0x02L
#define segment_d 0x04L
#define segment_e 0x08L
#define segment_f 0x10L
#define segment_g 0x20L
#define segment_h 0x40L


#endif


