#ifndef _SSP_MASTER_H_
#define _SSP_MASTER_H_

#include "lpc17xx_ssp.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"

#define CHIP_SELECT_SETUP()		SSP_CS_Init()
#define CHIP_SELECT()   		SSP_CS_Force(0)
#define CHIP_DESELECT() 		SSP_CS_Force(1)

#define SSP_CS    16		//SSP DataFlash Chip Select
#define SSP_MOSI  18		//SSP Master Out Pin
#define SSP_MISO  17		//SSP Master In  Pin
#define SSP_CLK   15		//SSP Clock

#define SSP_PORTNUM		0

void SSP_CS_Init(void);
void SSP_CS_Force(int32_t state);	
int ssp_master_init(void);
	
#endif
