#include "UART_int.h"
#include "GPS.h"
#include "APP.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

UART_ConfigType cfg;
uint8_t rec = 0;


void UART2_INIT()
{
	// Initialising the UART instance
	cfg.Instance = UART2;
	cfg.BaudRate = 9600;
	cfg.Data_Bit = Data_Bit_8;
	cfg.Parity = Parity_None;
	cfg.Stop_Bit = Stop_bit_1;
	MCAL_UART_Init(&cfg);
}




int main(){
		
		// 	Initializing UART2 for test 
		UART2_INIT();
		
		//	Test Sending API
		MCAL_UART_Send_String(&cfg, "Hello This is a Test For Uart");

    while(1){
			// Test for Receiving
			rec = MCAL_UART_Receive_Byte_Poll(&cfg);
    }
}



