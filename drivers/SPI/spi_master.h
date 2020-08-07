#ifndef _SPI_MASTER_H_
#define _SPI_MASTER_H_

#include "lpc17xx_spi.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"
	
void spi_senddata(uint16_t data);	
int spi_master_init(void);
int spi_master_test();
void CS_Force(int32_t state);
int check_transfer_status();
	
#endif
