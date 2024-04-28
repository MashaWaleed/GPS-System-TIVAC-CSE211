#include "UART_int.h"
#include "GPS.h"
#include "APP.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

UART_ConfigType cfg;

float current_latitude = 0;
float current_longitude = 0;

float first_latitude = 0;
float first_longitude = 0;

float distance = 0;

void UART2_INIT()
{
	// Initialising the UART instance that communicated with GPS system
	cfg.Instance = UART2;
	cfg.BaudRate = 9600;
	cfg.Data_Bit = Data_Bit_8;
	cfg.Parity = Parity_None;
	cfg.Stop_Bit = Stop_bit_1;
	MCAL_UART_Init(&cfg);
}




int main(){
		
		// 	Initializing UART for GPS 
		UART2_INIT();
		
		//	Poll untill a valid first GPS reading is found
		HAL_GPS_Read(&cfg,&first_latitude, &first_longitude);

    while(1){
			
			// Get the distance every GPS tick
			distance = computeDistance(current_latitude,current_longitude, first_latitude,first_longitude);
			HAL_GPS_Read(&cfg,&current_latitude, &current_longitude);
			
    }
}



