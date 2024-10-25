#include "tim_led.h"
#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim2;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim2) // 确保是定时器2的回调
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5); 
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_5); 
        // 切换 LED 状态
    }
}
