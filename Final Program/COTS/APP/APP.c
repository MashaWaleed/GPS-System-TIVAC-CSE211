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

int APP_Float_To_Int(float x)
{
   return (int)(x * 100000);
}

float APP_Int_To_Float(int x)
{
   return (float)x / 100000;
}

void APP_Write_Point(int *counter, int latitude, int longitude)
{
   // Write the point as <lat, long> to the EEPROM
   MCAL_EEPROM_Write(*counter, latitude);
   MCAL_EEPROM_Write(*counter + 1, longitude);

   // Increment the counter
   MCAL_EEPROM_Write(0, *counter + 1);
   *counter += 2;
}

void APP_Read_Point(int *address, int *latitude, int *longitude)
{
   // Read the point from the EEPROM
   *latitude = MCAL_EEPROM_Read(*address);
   *longitude = MCAL_EEPROM_Read(*address + 1);
   *address += 1;
}

void APP_UART_INIT(UART_ConfigType *cfg, UART_Type * instance)
{

   // Initialising the UART instance that communicates with GPS system
   (*cfg).Instance = instance;
   (*cfg).BaudRate = 9600;
   (*cfg).Data_Bit = Data_Bit_8;
   (*cfg).Parity = Parity_None;
   (*cfg).Stop_Bit = Stop_bit_1;

   MCAL_UART_Init(cfg);
}

void APP_Send_Sentences(UART_ConfigType *cfg)
{
   volatile int counter = MCAL_EEPROM_Read(0);
   volatile int i = 0;
   float read_lat, read_long;

   char str[30] = {0};
   char countStr[6] = {0};

   snprintf(countStr, sizeof(countStr), "%d\n\r", counter / 2);
   MCAL_UART_Send_String(cfg, countStr);
   for (i = 1; i <= counter; i++)
   {
      APP_Read_Point(&i, &read_lat, &read_long);
      snprintf(str, sizeof(str), "$%.5f,%.5f\n\r", read_lat, read_long);
      MCAL_UART_Send_String(cfg, str);
   }
}

void APP_LCD_Write(char *str, int x, int y)
{
   HAL_LCD_XY(x, y);
   HAL_LCD_Send_String(str);
}
void APP_LCD_Write_Number(int number, int x, int y)
{
   HAL_LCD_XY(x, y);
   HAL_LCD_Send_Number(number);
}

void APP_LCD_Clear_Write(char *str, int x, int y)
{
   HAL_LCD_Clear();
   APP_LCD_Write(str, x, y);
}

uint8_t APP_Prompt_Dump_Read(UART_ConfigType *cfg)
{

   APP_LCD_Clear_Write("Dump Prev Data?", 0, 0);
   APP_LCD_Write("Send U", 0, 1);
   return MCAL_UART_Receive_Byte_Poll(cfg);
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