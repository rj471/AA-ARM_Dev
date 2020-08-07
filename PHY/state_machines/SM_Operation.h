#ifndef SM_OPERATION_H_
#define SM_OPERATION_H_


#include "state_machine.h"
#include "lpc_types.h"


extern "C"{
	#include "input_output.h"
	// #include "multi-steppers.h"
}

class SM_OPERATION: public State_Machine{
	public:

	SM_OPERATION();
	int update(void);
	int stop_now();
	int retval;
	uint32_t queued_object_count_01;
	uint32_t queued_object_count_12;
	uint32_t queued_object_count_23;
	uint32_t queued_object_count_34;

	uint32_t completed_objects;

	uint8_t cam1_on;
	uint8_t cam2_on;
	uint8_t cam3_on;
	uint8_t cam4_on;

	uint8_t used_timer_array1[MAX_TIM_NUM];
	uint8_t used_timer_array2[MAX_TIM_NUM];
	uint8_t used_timer_array3[MAX_TIM_NUM];
	uint8_t used_timer_array4[MAX_TIM_NUM];

	enum SM_OPERATION_STATES{
		SM_OPERATION_RESET = 0,
	};

    enum SM_RET_STATES{
    	SMH_RESET = 0,
		SMH_STARTED = 1,
		SMH_DONE = 2,
		SMH_ERROR = -1,
    };

};
#endif
