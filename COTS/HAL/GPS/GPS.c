#include "GPS.h"
#include "string.h"
#include "stdlib.h"

uint8_t GPS_Sentence[100];





void HAL_GPS_Read(UART_ConfigType * cfg, float * latitude, float * longitude)
{
	uint8_t rec = 0;
	uint8_t ReadCounter  = 0;
	uint8_t Pattern[] = "$GPRMC,";
	uint8_t checkIndex = 0;

	do
	{
		rec = MCAL_UART_Receive_Byte_Poll(cfg);
		if (rec == Pattern[checkIndex])
		{
			checkIndex++;
			if (checkIndex == 7) // All characters in "$GPRMC," matched
			{
				while(rec != '*')
				{
					GPS_Sentence[ReadCounter] = rec;
					rec = MCAL_UART_Receive_Byte_Poll(cfg);
					ReadCounter++;
				}
				parse_GPS_data(GPS_Sentence,cfg,latitude,longitude);
				checkIndex = 0; // Reset for next sentence
			}
		}
		else
		{
			checkIndex = 0; // Reset if any character does not match
		}
	} while(ReadCounter == 0);

	ReadCounter = 0;
}

