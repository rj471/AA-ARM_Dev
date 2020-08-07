#include "SM_Operation.h"
#include "delay_timer.h"
#include "config.h"
#include "global.h"
#include "state_machine.h"
#include "input_output.h"
#include "config_data.h"

#define MOTOR_STOPPED 0 
#define HOME_DIST 0X7FFFFF

SM_OPERATION::SM_OPERATION():State_Machine(){
	SM_stop();
	
	state = SM_OPERATION_RESET;
}

int SM_OPERATION::update(void){

	if(SM_START == SM_started()){	
		if(input_rise_flag[OBJECT_SNSR]){
			input_rise_flag[OBJECT_SNSR] = 0;
			int mod = (queued_object_count_01 % MAX_TIM_NUM) + BASE_T1;
			if(used_timer_array1[mod-BASE_T1] == 0){
				used_timer_array1[mod-BASE_T1] = 1;
				dt_reset(mod);
				queued_object_count_01++;
			}else{
				//run time error
			}
	    }

	 // }

	    // arrived at 1st cam
		for(int mod = BASE_T1; mod < (BASE_T1 + MAX_TIM_NUM); mod++){
			if(dt_is_timeup(mod) && used_timer_array1[mod-BASE_T1] == 1){
				used_timer_array1[mod-BASE_T1] = 0;
				cam1_on = 1;
				dt_set_delay(CAM1_ON_DELAY,CAM_ON_TIME);
				io_set_output(CAM1_TRIGGER,1);
				dt_reset(CAM1_ON_DELAY);
			}
		}

		// 1st cam over
		if(cam1_on == 1 && dt_is_timeup(CAM1_ON_DELAY)){
			io_set_output(CAM1_TRIGGER,0);
			cam1_on = 0;
			int mod = (queued_object_count_12 % MAX_TIM_NUM) + BASE_T2;
			if(used_timer_array2[mod-BASE_T2] == 0){
				used_timer_array2[mod-BASE_T2] = 1;
				dt_reset(mod);
				queued_object_count_12++;
			}else{
					//run time error
			}
		}

		// arrived at cam 2
		for(int mod = BASE_T2; mod < (BASE_T2 + MAX_TIM_NUM); mod++){
			if(dt_is_timeup(mod) && used_timer_array2[mod-BASE_T2] == 1){
				used_timer_array2[mod-BASE_T2] = 0;
				cam2_on = 1;
				dt_set_delay(CAM2_ON_DELAY,CAM_ON_TIME);
				io_set_output(CAM2_TRIGGER,1);
				dt_reset(CAM2_ON_DELAY);
			}
		}

		// 2nd cam over
		if(cam2_on == 1 && dt_is_timeup(CAM2_ON_DELAY)){
			io_set_output(CAM2_TRIGGER,0);
			cam2_on = 0;
			int mod = (queued_object_count_23 % MAX_TIM_NUM) + BASE_T3;
			if(used_timer_array3[mod-BASE_T3] == 0){
				used_timer_array3[mod-BASE_T3] = 1;
				dt_reset(mod);
				queued_object_count_23++;
			}else{
				//run time error
			}
		}

		// arrived at cam 3
		for(int mod = BASE_T3; mod < (BASE_T3 + MAX_TIM_NUM); mod++){
			if(dt_is_timeup(mod) && used_timer_array3[mod-BASE_T3] == 1){
				used_timer_array3[mod-BASE_T3] = 0;
				cam3_on = 1;
				dt_set_delay(CAM3_ON_DELAY,CAM_ON_TIME);
				io_set_output(CAM3_TRIGGER,1);
				dt_reset(CAM3_ON_DELAY);
			}
		}

		// 3rd cam over
		if(cam3_on == 1 && dt_is_timeup(CAM3_ON_DELAY)){
			io_set_output(CAM3_TRIGGER,0);
			cam3_on = 0;
			int mod = (queued_object_count_34 % MAX_TIM_NUM) + BASE_T4;
			if(used_timer_array4[mod-BASE_T4] == 0){
				used_timer_array4[mod-BASE_T4] = 1;
				dt_reset(mod);
				queued_object_count_34++;
			}else{
				//run time error
			}
		}

		// arrived at cam 4
		for(int mod = BASE_T4; mod < (BASE_T4 + MAX_TIM_NUM); mod++){
			if(dt_is_timeup(mod) && used_timer_array4[mod-BASE_T4] == 1){
				used_timer_array4[mod-BASE_T4] = 0;
				cam4_on = 1;
				dt_set_delay(CAM4_ON_DELAY,CAM_ON_TIME);
				io_set_output(CAM4_TRIGGER,1);
				dt_reset(CAM4_ON_DELAY);
			}
		}

		// 4th cam over
		if(cam4_on == 1 && dt_is_timeup(CAM4_ON_DELAY)){
			io_set_output(CAM4_TRIGGER,0);
			cam4_on = 0;
			completed_objects ++;
			// now one need to implement ejector logic
		}
	}
   
    return retval;
}

int SM_OPERATION::stop_now(){
	SM_stop();
		
	return 1;
}
