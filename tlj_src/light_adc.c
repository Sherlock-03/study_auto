#include "light_adc.h"
#include "stm32f1xx_hal.h"
#include "string.h"

uint32_t adc_value = 0;

void light_value_get()
{
if (HAL_ADC_PollForConversion(&hadc3, HAL_MAX_DELAY) == HAL_OK)
        {
            adc_value = HAL_ADC_GetValue(&hadc3); // 获取ADC值

            // 将ADC值转换为字符串并通过USART发送
            char msg[20];
            snprintf(msg, sizeof(msg), "ADC: %lu\r\n", adc_value);
            HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
        }

}
