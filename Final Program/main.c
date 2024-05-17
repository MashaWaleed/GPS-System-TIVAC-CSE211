#include "../COTS/APP/APP.h"

/*Struct holding UART Configurations for our custom UART Driver*/

// GPS config
UART_ConfigType cfg1;

// Bluetooth config
UART_ConfigType cfg2;

/*Global Variables*/

// GPS read function returns
float current_latitude = 0;
float current_longitude = 0;
float prev_latitude = 0;
float prev_longitude = 0;

// Get Distance return
float distance = 0;

// Holder for PC command 'U' or something else
uint8_t cmd = 0;

int counter = 1;

int main()
{
	// 	Initializing Flashing LED and UART for GPS, PC ,LCD and EEPROM
	APP_System_Init(&cfg1, UART2, &cfg2, UART5);

	// Dump prompt for previous travel
	cmd = APP_Prompt_Dump_Read(&cfg2);

	// Dump it
	if (cmd == 'U')
	{
		APP_LCD_Clear_Write("Dumping ....", 0, 0);
		APP_Send_Sentences(&cfg2);
		APP_LCD_Clear_Write("Finished Dump", 0, 0);
		MCAL_STK_Delay_ms(5000);
	}

	// Dont dump it and just start a new travel
	else
	{
		APP_LCD_Clear_Write("Ok Starting ....", 0, 0);
		MCAL_STK_Delay_ms(5000);
	}

	APP_LCD_Clear_Write("Started", 0, 0);
	APP_LCD_Write("Distance: ", 0, 1);

	//	Poll untill a valid first GPS reading is found
	while ((HAL_GPS_Read(&cfg1, &prev_latitude, &prev_longitude)) == 0)
		;

	current_latitude = prev_latitude;
	current_longitude = prev_longitude;

	// Make this a function that takes lat and log and a counter perhaps that logs for you
	// This is a resued block and looks ugly
	APP_Write_Point(&counter, APP_Float_To_Int(current_latitude), APP_Float_To_Int(current_longitude));

	// Holder value to check if the last distance calculated was less that 0.8 meters
	// The GPS tends to hop around when we are standing still so this kind of prevents it
	// TESTED
	float distance_new = 0;

	while (1)
	{
		// Get the distance every GPS tick
		distance_new = APP_Compute_Distance(current_latitude, current_longitude, prev_latitude, prev_longitude);

		// its valid if its more than that (we are actually movings)
		if (distance_new >= 0.8)
		{
			distance += distance_new;
		}

		// Display the distance on the LCD
		HAL_LCD_XY(10, 1);
		HAL_LCD_Send_Number(distance);

		prev_latitude = current_latitude;
		prev_longitude = current_longitude;

		while ((HAL_GPS_Read(&cfg1, &current_latitude, &current_longitude)) == 0)
			;

		APP_Write_Point(&counter, APP_Float_To_Int(current_latitude), APP_Float_To_Int(current_longitude));

		// If the distance reaches 100m, we stop reading and light LED
		if (distance >= 100 || HAL_SWITCH_GET(SW_2) == 0)
		{
			APP_Destination_Reached(&cfg2);
			while (1)
				;
		}
	}
}
