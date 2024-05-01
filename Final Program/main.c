/*Driver Includes*/
#include "UART_int.h"
#include "GPS.h"
#include "APP.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/*Struct holding UART Configurations for our custom UART Driver*/
UART_ConfigType cfg;

/*Global Variables*/
float current_latitude = 0;
float current_longitude = 0;

float first_latitude = 0;
float first_longitude = 0;

float distance = 0;



void UART2_INIT()
{
	// Initialising the UART instance that communicates with GPS system
	cfg.Instance = UART2;
	cfg.BaudRate = 9600;
	cfg.Data_Bit = Data_Bit_8;
	cfg.Parity = Parity_None;
	cfg.Stop_Bit = Stop_bit_1;
	
	MCAL_UART_Init(&cfg);
}

void RED_led_Init()
{
	// Initilaising indicator LED for when we reach distination
	MCAL_GPIO_INIT(PortF,GPIO_PORTF);
	MCAL_GPIO_SetPinMode(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_INPUT_PULL_DOWN_MOD);
	MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_LOW);
}

void Distination_Reached()
{
	// Open Red LED and stop when distination is reached
	MCAL_GPIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_HIGH);
	while(1);
}



int main(){
		
		// 	Initializing Flashing LED and UART for GPS 
		RED_led_Init();
		UART2_INIT();
		
		//	Poll untill a valid first GPS reading is found
		while((HAL_GPS_Read(&cfg,&first_latitude, &first_longitude)) == 0);

    while(1){
			
			// Get the distance every GPS tick
			distance = computeDistance(current_latitude,current_longitude, first_latitude,first_longitude);
			while((HAL_GPS_Read(&cfg,&current_latitude, &current_longitude)) == 0);
			
			// If the distance reaches 100m, we stop reading and light LED
			if(distance >= 100)
			{
					Distination_Reached();
			}
    }
}



