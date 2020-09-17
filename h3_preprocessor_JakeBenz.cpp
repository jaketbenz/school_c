/*
====================================================================================
Course: Harper CSC211-248 by Mr. Jin Guo, Summer 2019
Student Name: <Jake Benz>

Program Name: Play with preprocessors
Program Description:
	This program is for you to understand C preprocessros such as macros with or 
	without arguments. 

Instructions: 
	1. First, try to understand and run the given program without any change.
	2. The given program is C++ style code. You are required to:
		1) Change all the functions to macros with argument(s).
		2) Chnage any constant variables to macro without argument.
		3) Use printf/scanf to replace cout/cin.
		4) Split the given .cpp file into two files: one is .h and the other .cpp
			which includes the .h. 
		5) When it's done, your changed program should behave the same as the 
			given program.
	3. Refer to "Chapter 8 Preprocessor" of the C textbook.
	4. Submit both your .h and .cpp. Name your files properly with your login 
		as usual.                        

Created: 	6/26/2019 by Jin Guo.
=====================================================================================
*/
#include <stdio.h>
#include <iostream>
#include <cmath>	// for pow()
#include <iomanip>	// for setprecision()
#include "h3_preprocessor_JakeBenz.h"

using namespace std;

int main()
{
	printf ("=============================================================\n");
    printf ("Harper CSC211-248 by Mr. Jin Guo: Program #3, Summer 2019\n");
    printf ("Student: Jake Benz \n\n");
    printf ("This program will convert some functions into macros.\n");
	printf ("=============================================================\n\n");
    
    float r;
	int a, b, c;
    int temp;

	printf ("Input a radius (e.g., 2.456) ==> ");
    scanf ("%f", &r);
    printf ("\nFor radius of %.2f \n", r);
    printf ("The cicle area is: %.2f \n" , circleArea(r));
    printf ("The circumference is: %.2f \n", circumference(r));
    printf ("The sphere volume is: %.2f \n", sphereVolume(r));

	printf ("\nInput 3 integers saperated by space ==> ");
    scanf ("%i %i %i", &a, &b, &c);
	printf ("The smaller of the first two is: %i \n", smallerOf2Ints);
    temp = minOf3Ints(a, b, c);
	printf ("The smallest of the three is: %i \n", temp);
	
    return 0;
}
