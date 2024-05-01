#ifndef GPS_H_
#define GPS_H_

#include "stdint.h"

#include "UART_prv.h"
#include "UART_cfg.h"
#include "UART_int.h"

uint8_t parse_GPS_data(char* GPS_Sentence,UART_ConfigType * cfg, float * latitude, float * longitude);
uint8_t HAL_GPS_Read(UART_ConfigType * cfg, float * latitude, float * longitude);


#endif