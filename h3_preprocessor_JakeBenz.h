#ifndef h3_preprocessor_JakeBenz_h
#define h3_preprocessor_JakeBenz_h

#include <cmath>    // for pow()

#define PI 3.141592653
#define circleArea(r)       (PI * pow(r,2.0))
#define circumference(r)    (2 * PI * r)
#define sphereVolume(r)     (3.0 * PI * pow(r, 3.0) / 4.0)
#define smallerOf2Ints      ((a < b) ? a : b)
#define minOf2Ints(a,b)     ((a < b) ? a : b)
#define minOf3Ints(a,b,c)   (minOf2Ints(minOf2Ints(a,b),c))

#endif
