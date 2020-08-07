/***********************************************************************//**
 * @file		spi_master.c
 * @purpose		This example describes how to use SPI in master mode
 * @version		2.0
 * @date		21. May. 2010
 * @author		NXP MCU SW Application Team
 *---------------------------------------------------------------------
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **********************************************************************/

 #include "spi_master.h"

/* Example group ----------------------------------------------------------- */
/** @defgroup SPI_Master	Master
 * @ingroup SPI_Examples
 * @{
 */

/************************** PRIVATE DEFINITIONS *********************/
// PORT number that /CS pin assigned on
#define CS_PORT_NUM				0
// PIN number that  /CS pin assigned on
#define CS_PIN_NUM				(1<<16)

// SPI Configuration structure variable
SPI_CFG_Type SPI_ConfigStruct;

/************************** PRIVATE FUNCTIONS *************************/
void CS_Init(void);
// void CS_Force(int32_t state);

/*-------------------------PRIVATE FUNCTIONS------------------------------*/
/*********************************************************************//**
 * @brief 		Initialize CS pin as GPIO function to drive /CS pin
 * 				due to definition of CS_PORT_NUM and CS_PORT_NUM
 * @param		None
 * @return		None
 ***********************************************************************/
void CS_Init(void){
	GPIO_SetDir(CS_PORT_NUM,CS_PIN_NUM, 1);
	GPIO_SetValue(CS_PORT_NUM,CS_PIN_NUM);
}


/*********************************************************************//**
 * @brief 		Drive CS output pin to low/high level to select slave device
 * 				via /CS pin state
 * @param[in]	state State of CS output pin that will be driven:
 * 				- 0: Drive CS pin to low level
 * 				- 1: Drive CS pin to high level
 * @return		None
 ***********************************************************************/
void CS_Force(int32_t state){
	if (state){
		GPIO_SetValue(CS_PORT_NUM,CS_PIN_NUM);
	}else{
		GPIO_ClearValue(CS_PORT_NUM,CS_PIN_NUM);
	}
}

/*********************************************************************//**
 * @brief		Transmit a single data through SPIx peripheral 
 * @param[in]	Data	Data to transmit (must be 16 or 8-bit long,
 * 						this depend on SPI data bit number configured)
 * @return 		none
 **********************************************************************/
void spi_senddata(uint16_t data){
	SPI_SendData(LPC_SPI, data);	
}

int check_transfer_status(){
	uint32_t tmp_status = 0;
	tmp_status = LPC_SPI->SPSR;
	return (SPI_CheckStatus(tmp_status,SPI_STAT_SPIF));
}

/*-------------------------INIT FUNCTION------------------------------*/
int spi_master_init(){
	PINSEL_CFG_Type PinCfg;	
	/*
	 * Initialize SPI pin connect
	 * P0.15 - SCK;
	 * P0.16 - SSEL - used as GPIO
	 * P0.17 - MISO
	 * P0.18 - MOSI
	 */
	PinCfg.Funcnum = 3;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 15;
	PINSEL_ConfigPin(&PinCfg);	
	PinCfg.Pinnum = 18;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 16;
	PinCfg.Funcnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	/* Initialize debug via UART0
	 * – 115200bps
	 * – 8 data bit
	 * – No parity
	 * – 1 stop bit
	 * – No flow control
	 */
	
	SPI_ConfigStruct.CPHA = SPI_CPHA_SECOND;
	SPI_ConfigStruct.CPOL = SPI_CPOL_LO;
	SPI_ConfigStruct.ClockRate = 1000;
	SPI_ConfigStruct.DataOrder = SPI_DATA_MSB_FIRST;
	SPI_ConfigStruct.Databit = 8;
	SPI_ConfigStruct.Mode = SPI_MASTER_MODE;
	// Initialize SPI peripheral with parameter given in structure above
	SPI_Init(LPC_SPI, &SPI_ConfigStruct);	
	CS_Init();
	CS_Force(1);
	return 1;
}

/*-------------------------TEST FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief		c_entry: SPI test program body
 * @param[in]	None
 * @return 		int
 **********************************************************************/
int spi_master_test(void){
	PINSEL_CFG_Type PinCfg;	
	uint32_t tmp, tmp_status = 0;

	/*
	 * Initialize SPI pin connect
	 * P0.15 - SCK;
	 * P0.16 - SSEL - used as GPIO
	 * P0.17 - MISO
	 * P0.18 - MOSI
	 */
	PinCfg.Funcnum = 3;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = 0;
	PinCfg.Pinnum = 15;
	PINSEL_ConfigPin(&PinCfg);	
	PinCfg.Pinnum = 18;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = 16;
	PinCfg.Funcnum = 0;
	PINSEL_ConfigPin(&PinCfg);

	/* Initialize debug via UART0
	 * – 115200bps
	 * – 8 data bit
	 * – No parity
	 * – 1 stop bit
	 * – No flow control
	 */
	
	SPI_ConfigStruct.CPHA = SPI_CPHA_SECOND;
	SPI_ConfigStruct.CPOL = SPI_CPOL_LO;
	SPI_ConfigStruct.ClockRate = 1000;
	SPI_ConfigStruct.DataOrder = SPI_DATA_MSB_FIRST;
	SPI_ConfigStruct.Databit = 8;
	SPI_ConfigStruct.Mode = SPI_MASTER_MODE;
	// Initialize SPI peripheral with parameter given in structure above
	SPI_Init(LPC_SPI, &SPI_ConfigStruct);	
	CS_Init();
	CS_Force(0);
	// delay for a while
	for (tmp = 1000000; tmp; tmp--);	
	// SPI_SendData(LPC_SPI, 0xAA);
	SPI_SendData(LPC_SPI, 0x55);
	do
	{
		tmp_status = SPI_GetStatus(LPC_SPI);
	}while(!(SPI_CheckStatus(tmp_status,SPI_STAT_SPIF)));
	// delay for a while
	for (tmp = 1000000; tmp; tmp--);
	CS_Force(1);
	
    return 1;
}

/*
 * @}
 */
