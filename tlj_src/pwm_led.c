#include "pwm_led.h"
#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim3;
uint8_t pwm_value = 0;
uint8_t pwm_flag = 0;

void pwm_led_on()
{
    
    if(pwm_flag == 0){
    __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, pwm_value++);
        pwm_flag = (pwm_value > 100) ? 1:0; 
        HAL_Delay(20);
    }
       else if(pwm_flag==1){
   __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2, pwm_value--);
   pwm_flag=(pwm_value<1)?0:1;
           HAL_Delay(20);
  }
    
    }
    


