#include "rtc_test.h"
#include "stm32f1xx_hal.h"
#include "rtc.h"
#include "stdio.h"

RTC_DateTypeDef GetData;  //获取日期结构体

RTC_TimeTypeDef GetTime;   //获取时间结构体

void rtc_time_get()
{
    	  /* Get the RTC current Time */
	  HAL_RTC_GetTime(&hrtc, &GetTime, RTC_FORMAT_BIN);
      /* Get the RTC current Date */
      HAL_RTC_GetDate(&hrtc, &GetData, RTC_FORMAT_BIN);

      /* Display date Format : yy/mm/dd */
      printf("%02d/%02d/%02d\r\n",2000 + GetData.Year, GetData.Month, GetData.Date);
      /* Display time Format : hh:mm:ss */
      printf("%02d:%02d:%02d\r\n",GetTime.Hours, GetTime.Minutes, GetTime.Seconds);

      printf("\r\n");

      HAL_Delay(100);

    
}
