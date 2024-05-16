/****************************************************************/
/******* Author    : ASU_EMBEDDED_TEAM_NO 3     *****************/
/******* Date      : 10 May 2024             	*****************/
/******* Version   : 0.1                        *****************/
/******* File Name : GPS.c                      *****************/
/****************************************************************/

#include "GPS.h"
#include "string.h"
#include "stdlib.h"

uint8_t GPS_Sentence[100];

/*****************************< Functions Implementations >******************/

uint8_t parse_GPS_data(char* GPS_Sentence,UART_ConfigType * cfg, float * latitude, float * longitude)
{
		char* token;
    char* rest = GPS_Sentence;
    int comma_count = 0;
    char status;


    while ((token = strtok_r(rest, ",", &rest))) // split string into tokens by comma
    {
        comma_count++;
        if (comma_count == 2) // status (A or V) is after the second comma
        {
            status = token[0];
            if (status != 'A')
            {
                //HAL_GPS_Read(cfg,latitude,longitude); // recall the GPS_READ function
                return 0;
            }
        }
        else if (comma_count == 3) // latitude is after the third comma
        {
            *latitude = atof(token);
        }
        else if (comma_count == 5) // longitude is after the fifth comma
        {
            *longitude = atof(token);
            return 1; // no need to parse the rest of the data
        }
    }
		return 0;
}


uint8_t HAL_GPS_Read(UART_ConfigType * cfg, float * latitude, float * longitude)
{
	uint8_t rec = 0;
	uint8_t ReadCounter  = 0;
	uint8_t Pattern[] = "$GPRMC,";
	uint8_t checkIndex = 0;
	uint8_t status = 0;

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
				status = parse_GPS_data(GPS_Sentence,cfg,latitude,longitude);
				checkIndex = 0; // Reset for next sentence
			}
		}
		else
		{
			checkIndex = 0; // Reset if any character does not match
			return status;
		}
	} while(ReadCounter == 0);

	ReadCounter = 0;
	return status;
}

