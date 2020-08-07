/***********************************************************************//**
 * @file		ssp_master.c
 * @purpose		This example describes how to use SPP in master mode
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
#include "ssp_master.h"

/* Example group ----------------------------------------------------------- */
/** @defgroup SSP_Master	Master
 * @ingroup SSP_Examples
 * @{
 */

/************************** PRIVATE DEFINTIONS ************************/
// PORT number that /CS pin assigned on
#define CS_PORT_NUM				0
// PIN number that  /CS pin assigned on
#define CS_PIN_NUM				6

// Define macro used in command when using SSP with SC16IS740
#define SC16IS740_WR_CMD(x)		((uint8_t) (x << 3))
#define SC16IS740_RD_CMD(x)		((uint8_t) ((x << 3) | 0x80))

// Define register address of SC16IS740
#define SC16IS740_IODIR_REG		0x0A
#define SC16IS740_IOSTATE_REG	0x0B
#define SC16IS740_IOCON_REG		0x0E

// SSP Configuration structure variable
SSP_CFG_Type SSP_ConfigStruct;

uint8_t iocon_cfg[2] = {SC16IS740_WR_CMD(SC16IS740_IOCON_REG), 0x00};
uint8_t iodir_cfg[2] = {SC16IS740_WR_CMD(SC16IS740_IODIR_REG), 0xFF};
uint8_t iostate_on[2] = {SC16IS740_WR_CMD(SC16IS740_IOSTATE_REG), 0x00};
uint8_t iostate_off[2] = {SC16IS740_WR_CMD(SC16IS740_IOSTATE_REG), 0xFF};
uint8_t sspreadbuf[2];
/*-------------------------PRIVATE FUNCTIONS------------------------------*/
/*********************************************************************//**
 * @brief 		Initialize CS pin as GPIO function to drive /CS pin
 * 				due to definition of CS_PORT_NUM and CS_PORT_NUM
 * @param		None
 * @return		None
 ***********************************************************************/
void SSP_CS_Init(void){
	GPIO_SetDir(CS_PORT_NUM, (1<<CS_PIN_NUM), 1);
	GPIO_SetValue(CS_PORT_NUM, (1<<CS_PIN_NUM));
}

/*********************************************************************//**
 * @brief 		Drive CS output pin to low/high level to select slave device
 * 				via /CS pin state
 * @param[in]	state State of CS output pin that will be driven:
 * 				- 0: Drive CS pin to low level
 * 				- 1: Drive CS pin to high level
 * @return		None
 ***********************************************************************/
void SSP_CS_Force(int32_t state){
	if (state){
		GPIO_SetValue(CS_PORT_NUM, (1<<CS_PIN_NUM));
	}else{
		GPIO_ClearValue(CS_PORT_NUM, (1<<CS_PIN_NUM));
	}
}

/*-------------------------MAIN FUNCTION------------------------------*/
/*********************************************************************//**
 * @brief		c_entry: Main SSP program body
 * @param[in]	None
 * @return 		int
 **********************************************************************/
int ssp_master_init(void){
	PINSEL_CFG_Type PinCfg;	
	SSP_DATA_SETUP_Type xferConfig;
	uint32_t tmp;
	/*
	 * Initialize SPI pin connect
	 * P0.15 - SCK;
	 * P0.16 - SSEL
	 * P0.17 - MISO
	 * P0.18 - MOSI
	 */
	PinCfg.Funcnum = 2;
	PinCfg.OpenDrain = 0;
	PinCfg.Pinmode = 0;
	PinCfg.Portnum = SSP_PORTNUM;
	PinCfg.Pinnum = SSP_CLK;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = SSP_MISO;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Pinnum = SSP_MOSI;
	PINSEL_ConfigPin(&PinCfg);
	PinCfg.Funcnum = 0;
	PinCfg.Pinnum = SSP_CS;
	PINSEL_ConfigPin(&PinCfg);

	// initialize SSP configuration structure to default
	SSP_ConfigStructInit(&SSP_ConfigStruct);
	// Initialize SSP peripheral with parameter given in structure above
	SSP_Init(LPC_SSP1, &SSP_ConfigStruct);
	
	// Initialize /CS pin to GPIO function
	SSP_CS_Init();
	
	// Enable SSP peripheral
	SSP_Cmd(LPC_SSP1, ENABLE);
	SSP_CS_Force(1);
	
    return 1;
}
