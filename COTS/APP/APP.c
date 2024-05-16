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
