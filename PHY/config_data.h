#ifndef _CONFIG_DATA_H_
#define _CONFIG_DATA_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "config.h"
#include "global.h"

extern "C"{
	#include "i2c_eeprom.h"
	#include "debug_frmwrk.h"
}

#define CONFIG_VERSION_OK	0

typedef struct {
	uint8_t	fw_major_version;
	uint8_t	fw_minor_version;
	
	uint8_t c_MYIP_1;	
	uint8_t c_MYIP_2;	
	uint8_t c_MYIP_3;	
	uint8_t c_MYIP_4;
	
	uint16_t c_sample_rate;
	uint8_t c_scenario_sel_remote;
	uint8_t c_scenario_sel_local;
	uint8_t c_range_sel_1;
	uint8_t c_range_sel_2;
}EepromStorage;


typedef struct {



}EepromStorage1;

typedef struct {



}EepromStorage2;


typedef struct {



}EepromStorage3;

/* read config data from EEPROM...*/
int write_objects_eeprom(	int16_t , 	// address of the eeprom location..
							void * ,	// object to be stored..
							int 		// size of the object to be stored..
						);
						
int read_objects_eeprom(int16_t ,	// address of the eeprom location..
						void *,		// object to be stored..
						int 		// size of the object to be stored..
						);
						
int read_config_version();
int read_config_data(void);
int read_config_version(uint8_t &, uint8_t &);

int write_config_data(void);
int config_set_defaults(uint8_t , uint8_t );

int write_config_data_table_1(void);
int write_config_data_table_2(void);
int write_config_data_table_3(void);
int write_Sequence_to_EEPROM(char *, int , int );
int read_Sequence_from_EEPROM(char *, int , int );

#endif
