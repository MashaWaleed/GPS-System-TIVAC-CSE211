/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : APP.c                      *****************/
/****************************************************************/

/*****************************< APP >*****************************/
#include "APP.h"
#include <stdint.h>

// Global variables
float deltaLat, deltaLong;

/*****************************< Functions Implementations >******************/

float APP_To_Degree(float angle) // convert NEMA format [DDDMM.MMMM] to deciaml degree
{
   short degree = angle / 100;
   float minuite = angle - degree * 100.0;
   return degree + minuite / 60.0;
}

float APP_To_Radian(float angle)
{
   return angle * (M_PI / 180.0);
}

float APP_Compute_Distance(float lat1, float long1, float lat2, float long2)
{
   lat1 = APP_To_Radian(APP_To_Degree(lat1));
   long1 = APP_To_Radian(APP_To_Degree(long1));
   lat2 = APP_To_Radian(APP_To_Degree(lat2));
   long2 = APP_To_Radian(APP_To_Degree(long2));

   deltaLat = (lat2) - (lat1);

   deltaLong = long2 - long1;

   // computing distance between two points using Haversine formula that take earth curvature in consideration.
   float a = pow(sin(deltaLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLong / 2), 2);
   float c = 2 * atan2(sqrt(a), sqrt(1 - a));
   float distance = (EARTH_RADIUS * c) * 0.1;

   // float distance= 0;
   // distance = sqrt(pow(lat2-lat1,2)+pow(long2-long1,2));

   return distance;
}

void APP_Destination_Reached(UART_ConfigType *cfg)
{
	// Open Red LED and stop when destination is reached
	HAL_LED_SET(RED);
	MCAL_STK_Delay_ms(1000);
	
	// LCD visual assurance
	APP_LCD_Clear_Write("Destination Reached", 0, 0);
	MCAL_STK_Delay_ms(5000);
	
	// Dumping prompt 
   APP_LCD_Write("Dump Log : U", 0, 1);
	
      
   if(MCAL_UART_Receive_Byte_Poll(cfg) == 'U')
   {
      APP_LCD_Clear_Write("Dumping.....", 0, 0);
      
      //test_send_sentences();
      APP_Send_Sentences(cfg);
      
      APP_LCD_Clear_Write("Finished Dump", 0, 0);
      MCAL_STK_Delay_ms(5000);
   }
}


void APP_System_Init(UART_ConfigType *cfg1, UART_Type * instance1, UART_ConfigType *cfg2, UART_Type * instance2)
{
   HAL_LEDS_INIT();
	APP_UART_INIT(cfg1, instance1);
	APP_UART_INIT(cfg2, instance2);
	MCAL_EEPROM_INIT();
	HAL_LCD_Init();
}



/*****************************< End of APP.c >***************************/
