#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define EARTH_RADIUS 6371000 // in meter

float to_degree(float angle);
float to_radian(float angle);
float computeDistance(float lat1, float long1, float lat2, float long2);