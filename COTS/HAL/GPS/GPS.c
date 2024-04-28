#include "GPS.h"
#include "string.h"
#include "stdlib.h"

uint8_t GPS_Sentence[100];

void parse_GPS_data(char *GPS_Sentence, UART_ConfigType *cfg, float *latitude, float *longitude)
{
	char *token;
	char *rest = GPS_Sentence;
	int comma_count = 0;
	char status;

	while ((token = strtok_r(rest, ",", &rest))) // split string into tokens by comma
	{
		comma_count++;
		if (comma_count == 2) // status (A or V) is after the second comma
		{
			status = token[0];
			if (status == 'V')
			{
				HAL_GPS_Read(cfg, latitude, longitude); // recall the GPS_READ function
				return;
			}
		}
		else if (comma_count == 3) // latitude is after the third comma
		{
			*latitude = atof(token);
		}
		else if (comma_count == 5) // longitude is after the fifth comma
		{
			*longitude = atof(token);
			break; // no need to parse the rest of the data
		}
	}
}

void HAL_GPS_Read(UART_ConfigType *cfg, float *latitude, float *longitude)
{
	uint8_t rec = 0;
	uint8_t ReadCounter = 0;
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
				while (rec != '*')
				{
					GPS_Sentence[ReadCounter] = rec;
					rec = MCAL_UART_Receive_Byte_Poll(cfg);
					ReadCounter++;
				}
				parse_GPS_data(GPS_Sentence, cfg, latitude, longitude);
				checkIndex = 0; // Reset for next sentence
			}
		}
		else
		{
			checkIndex = 0; // Reset if any character does not match
		}
	} while (ReadCounter == 0);

	ReadCounter = 0;
}
