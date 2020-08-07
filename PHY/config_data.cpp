#include "config_data.h"
// #include "input_output.h"
#include "delay_timer.h"
#include "delay.h"
EepromStorage eepromStorage;
EepromStorage1 eepromStorage1;
EepromStorage2 eepromStorage2;
EepromStorage3 eepromStorage3;

int write_objects_eeprom(int16_t addr, void *obj, int size){
	// we can write 32 bytes at a time..
	int ret=0;
	int id=0;
	int length=0;
	int arr_idx=0;
	int chunkSize=16;
	float buf_size=16.0;
	int csize = 16;
		
	uint8_t *ptr=(uint8_t *) obj;	
	length=ceil((double)(size/buf_size));
	// length=4;
	for(id=0;id<length;id++){
		arr_idx=id*chunkSize;
		csize = chunkSize;
		if (size - arr_idx < chunkSize){
			csize = size - arr_idx;
		}
		ret=i2cEEPROM_write8(addr,&(ptr[arr_idx]),csize);	
		addr+=chunkSize;
		// addr++;
		if(ret!=0){
			printf("WRITE ERROR\n");
		}

		// my_delay(50);
		_delay_ms(10);
	}	
	I2CDeinit();
	return 1;
}

int read_objects_eeprom(int16_t addr, void *obj, int size){	
	int ret=0;
	int id=0;
	int length=0;
	int arr_idx=0;
	int chunkSize=16;
	float buf_size=16.0;
	int csize = 16;
	
	uint8_t *ptr=(uint8_t *) obj;
	length=ceil((double)(size/buf_size));
	for(id=0;id<length;id++){
		arr_idx=id*chunkSize;
		csize = chunkSize;
		if (size - arr_idx < chunkSize){
			csize = size - arr_idx;
		}
		ret=i2cEEPROM_read8(addr,&ptr[arr_idx],csize);
		addr+=chunkSize;
		// addr++;
		if(ret!=0){
			printf("READ ERROR\n");
		}	
		// my_delay(50);
	}	
	I2CDeinit();
	return 1;
}

#if 1
int read_config_version(){	
	int ret=0;
	int id=0;
	int length=0;
	int arr_idx=0;
	int chunkSize=16;
	float buf_size=16.0;
	int csize = 16;
	int16_t addr=0;
	EepromStorage obj;
	int size=sizeof(EepromStorage);
	
	uint8_t *ptr=(uint8_t *) (&obj);
	length=ceil((double)(size/buf_size));
	for(id=0;id<length;id++){
		arr_idx=id*chunkSize;
		csize = chunkSize;
		if (size - arr_idx < chunkSize){
			csize = size - arr_idx;
		}
		ret=i2cEEPROM_read8(addr,&ptr[arr_idx],csize);
		addr+=chunkSize;
		// addr++;		
		if(ret!=0){
			printf("READ ERROR\n");
		}
	}
	I2CDeinit();
	EepromStorage *es= &obj;
	if(fw_major_version!=es->fw_major_version)
		return 1;
	if(fw_minor_version!=es->fw_minor_version)
		return 2;	
	return 0;
}
#endif

int read_config_version(uint8_t &major, uint8_t &minor){	
	int ret=0;
	int id=0;
	int length=0;
	int arr_idx=0;
	int chunkSize=16;
	float buf_size=16.0;
	int csize = 16;
	int16_t addr=0;
	EepromStorage obj;
	int size=sizeof(EepromStorage);

	uint8_t *ptr=(uint8_t *) (&obj);
	length=ceil((double)(size/buf_size));
	for(id=0;id<length;id++){
		arr_idx=id*chunkSize;
		csize = chunkSize;
		if (size - arr_idx < chunkSize){
			csize = size - arr_idx;
		}
		ret=i2cEEPROM_read8(addr,&ptr[arr_idx],csize);
		addr+=chunkSize;
		// addr++;
		if(ret!=0){
			printf("READ ERROR\n");
		}		
	}
	I2CDeinit();
	EepromStorage *es= &obj;
	major=es->fw_major_version;
	minor=es->fw_minor_version;
	if(CURRENT_CONFIG_MAJOR_VERSION!=major)
		return 1;
	if(CURRENT_CONFIG_MINOR_VERSION!=minor)
		return 2;	
	return 0;
}

int read_config_data(void){
	EepromStorage eeps;
	EepromStorage1 eeps1;
	EepromStorage2 eeps2;
	EepromStorage3 eeps3;
	printf("Reading config data%d\n",sizeof(eeps));
	read_objects_eeprom(0,&eeps,sizeof(eeps));
	
	fw_major_version=eepromStorage.fw_major_version;
	fw_minor_version=eepromStorage.fw_minor_version;
	


	// copy config_daa into their respective sructs...
	
/**#########################################################################################*/	
	// copy config_daa into their respective sructs...			

/**#########################################################################################*/
	
	// final_motor_ppr_per_pt_mm		= eeps.c_final_motor_ppr_per_pt_mm;
	// motor_ppr_num					= eeps.c_motor_ppr_num;

	return 1;
}

int write_config_data(void){
	
	// copy all data to the config_data struct ..	
	eepromStorage.fw_major_version = CURRENT_CONFIG_MAJOR_VERSION;
	eepromStorage.fw_minor_version = CURRENT_CONFIG_MINOR_VERSION;


	// printf("\n my write=%d",eepromStorage.c_MYIP_1);
	// eepromStorage.c_motor_ppr_num					= motor_ppr_num;

/**#########################################################################################*/	
	
/**#########################################################################################*/	
	

	// write config_data to flash
	write_objects_eeprom(0,&eepromStorage,sizeof(eepromStorage));
	// write_objects_eeprom(0,&eepromStorage,1);
	// printf("Writing config data%d\n",sizeof(eepromStorage));
	return 1;
}

int write_config_data_table_1(void){

	// for(int i=0; i<15;i++){
	// 	eepromStorage1.c_value_table[i]		= value_table[i];
	// }
	// // printf("\n write=value_table[0].pre_val=%f",value_table[0].pre_val);
	// write_objects_eeprom(256,&eepromStorage1,sizeof(eepromStorage1));

	return 1;
}


int write_config_data_table_2(void){

	// for(int i=0; i<15;i++){
	// 	eepromStorage2.c_value_table2[i]	= value_table[i+15];
	// }
	// write_objects_eeprom(512,&eepromStorage2,sizeof(eepromStorage2));

	return 1;
}


int write_config_data_table_3(void){

	// for(int i=0; i<15;i++){
	// 	eepromStorage3.c_value_table3[i]	= value_table[i+30];
	// }
	// write_objects_eeprom(768,&eepromStorage3,sizeof(eepromStorage3));

	return 1;
}


int config_set_defaults(uint8_t, uint8_t){
	printf("Setting defaults %d\n",TRUE);
	fw_major_version = CURRENT_CONFIG_MAJOR_VERSION;
	fw_minor_version = CURRENT_CONFIG_MINOR_VERSION;
	write_config_data();
	return 1;
}

int write_Sequence_to_EEPROM(char *p, int size, int seq_num){
	// seqnum is the num of the sequence to write to...
	//Start breaking the data into 32byte chunks
	// unsigned int i = 0;
	int id = 0;
	int chunkSize = 32;
	int arr_idx = 0;
	int retval = 0;
	char temp_str[33] = {0};
	char read_str[33] = {0};
	
	unsigned char chunk_size = 32;
	unsigned int seq_eeprom_start_offset = 0;
	unsigned int seq_size = 512;
	unsigned int seq_addr = seq_num*seq_size + seq_eeprom_start_offset;
	// printf("SeqAddr: %d\n",seq_addr);
	
	unsigned int write_addr = seq_addr;
	
	// memset(recvd,'0',sizeof(p));
	// sprintf(I2C_recvd,"%s",s);
	
	for (id = 0;id < 16;id++){
		arr_idx = id *chunkSize;
		memcpy(temp_str,&p[arr_idx],chunk_size);
		temp_str[chunk_size] = '\0';
		// printf("Wr%d:%s\n",id,temp_str);
		write_addr = seq_addr + arr_idx;
		retval = i2cEEPROM_write32(write_addr,temp_str);
		if (retval !=0){			
			// printf("Wrong: %d\n",id);
			break;
		}
		//read it back...
		// my_delay(50);
		i2cEEPROM_read32(write_addr,read_str,chunk_size);
		read_str[chunk_size] = '\0';
		// printf("Rd%d:%s\n",id,read_str);
	}	
	I2CDeinit();
	// my_delay(10);
	return retval;
}

int read_Sequence_from_EEPROM(char *p, int size, int seq_num){
	// seq_num is the num of the seq to load...
	// start getting the data for the sequence in chunks of 32 bytes..
	// unsigned int i = 0;
	int id = 0;
	int chunkSize = 32;
	int arr_idx = 0;
	int retval = 0;
	char recvd_str[32];
	char *data = recvd_str;
	
	unsigned char chunk_size = 32;
	unsigned int seq_eeprom_start_offset = 0;
	unsigned int seq_size = 512;
	unsigned int seq_addr = seq_num*seq_size + seq_eeprom_start_offset;
	
	unsigned int read_addr = seq_addr;
	
	memset(p,'0',size);
	p[0] = '\0';
	for (id = 0;id < 16;id++){
		arr_idx = id *chunkSize;		
		read_addr = seq_addr + arr_idx;
		memset(data,'0',sizeof(recvd_str));
		retval = i2cEEPROM_read32(read_addr,recvd_str,chunk_size); 
		if (retval != 0){			
			// printf("Wrong: %d\n",id);
			break;
		}		
		//read it back...		
		recvd_str[chunk_size] = '\0';
		// printf("Rd%d:%s\n",id,recvd_str);
		strcat(p,recvd_str);
	}
	// for(i=0;i<seq_size;i++){
		// printf("RECVD[%d]: %d\n",i,(s[i])-48);
	// }
	// printf("final string = %s",s);
	I2CDeinit();
	// my_delay(10);
	return retval;
	
}
