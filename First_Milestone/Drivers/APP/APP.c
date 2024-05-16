#include "APP.h"

// The change in coordinates between 2 contingous samples.
float deltaLat,deltaLong ;
float to_degree(float angle) // Convert NEMA format [DDDMM.MMMM] to deciaml degree
{
   short degree = angle / 100;
   float minuite = angle - degree * 100.0;
   return degree + minuite / 60.0;
}

float to_radian(float angle)
{
   return angle * (M_PI / 180.0);
}

float computeDistance(float lat1, float long1, float lat2, float long2)
{
   lat1 = to_radian(to_degree(lat1));
   long1 = to_radian(to_degree(long1));
   lat2 = to_radian(to_degree(lat2));
   long2 = to_radian(to_degree(long2));

    deltaLat = (lat2) - (lat1);
	 
    deltaLong = long2 - long1;

   // Computing distance between two points using Haversine formula that takes earth curvature in consideration.
   float a = pow(sin(deltaLat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLong / 2), 2);
   float c = 2 * atan2(sqrt(a), sqrt(1 - a));
   float distance = (EARTH_RADIUS * c) * 0.1;  			// Final distance is scaled by a weighing factor to adjust sensitivity and reduce the GPS noise in coordinates.
	
	/*  @brief This calculates the Euclidean distance ignoring the curvature of the Earth.
	//float distance= 0;
	//distance = sqrt(pow(lat2-lat1,2)+pow(long2-long1,2));
	*/

   return distance;
}
