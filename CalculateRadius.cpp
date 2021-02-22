// CalculateRadius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******************************************************************************

							  Online C++ Debugger.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <corecrt_math_defines.h>

char getOption(int option) {
	int Factor1 = (1 / option);  //  equals 1 when option = 1, else zero
	//int Factor2 = (-1) * ((2 / option[i]) * ((1 / option[i]) - 1));  //  equals 1 when option = 2, else zero
	//int Factor3 = (int)( (double)(option[i] / 3) * (double)(5.0 / option[i])   );

	int Factor2A = 2 / option;
	int Factor2B = 1 / option;
	int Factor2C = Factor2B - 1;
	int Factor2 = (-1) * (Factor2A * Factor2C);
	//printf("Factor2A - %d\tFactor2b - %d\tFactor2C - %d\tFactor2 - %d\n", Factor2A, Factor2B, Factor2C, Factor2);

	int Factor3A = option / 3;  // zero when option is less than 3, 1 or greater  when 3 or greater 
	double Factor3B = 5.0 / option;  //  greater than 1 when option is <5 , 1 when 5, < 1 when greater than 5
	int Factor3 = (int)(Factor3A * Factor3B); //  equals 1 when option[i] >= 3, else zero
	//printf("Factor3A - %d\tFactor3B - %lf\tFactor3 - %d\n", Factor3A, Factor3B, Factor3);
	//printf("Factor1 - %d\tFactor2 - %d\tFactor3 - %d\t\n", Factor1, Factor2, Factor3);

	return 'T' * Factor1 + 'S' * Factor2 + 'C' * Factor3;
}
void testGetOption() {
	int options[] = { 1,2,3,4,5,6,15,10,30,200,_CRT_INT_MAX };
	const char const results[] = { 'T', 'S', 'C', 'C','C', 'C', 'C', 'C', 'C', 'C', 'C' };
	for (int i = 0; i < sizeof(options) / sizeof(int); i++) {
		printf("*********************     i = %d     ********************* \n", options[i]);
		char result = getOption(options[i]);
		if (result != results[i])
			printf("*****  ERROR !!  *****\t Received - %c Expected - %c\n\n", result, results[i]);
	}//  end for
}

int Exam1() {
	//Declare Varibales
	int option = 0; //Initializes the option chosen
	int Factor1 = 0;
	int Factor2 = 0;
	int Factor3 = 0;
	double AreaGiven = 0.00; //Initializes the given area
	double RadiusCalc = 0.00; //Initializes the calculated radius
	double AreaCalc = 0.00; //Initializes the calculated area

	//Input Statements
	printf("Enter desired option -> ");
	scanf_s("%d", &option);
	printf("Enter area of figure -> ");
	scanf_s("%lf", &AreaGiven);

	//Calculations
	Factor1 = (1 / option);
	Factor2 = (-1) * ((2 / option) * ((1 / option) - 1));
	Factor3 = (int)(((double)(option / 3) * (double)(5.0 / option)));
	RadiusCalc = sqrt(AreaGiven / M_PI) * Factor1 +
		sqrt(AreaGiven / M_PI) * Factor2 +
		sqrt((AreaGiven / option / tan(M_PI / ((double)option + Factor1)))) * Factor3;
	AreaCalc = (RadiusCalc * cos(M_PI / 6)) * (RadiusCalc + RadiusCalc * sin(M_PI / 6)) *
		Factor1 + (2 * pow(RadiusCalc, 2)) *
		Factor2 + (M_PI * pow(RadiusCalc, 2)) *
		Factor3;

	//Print Statements
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Radius/Apothem of figure with area given: %.1lf\n", RadiusCalc);
	printf("Area of inscribed figure [%c] : %.1lf\n", getOption(option), AreaCalc);

	return 0;
}

int main()
{
	printf("Max Int - %d\n", _CRT_INT_MAX);
	Exam1();
	//testGetOption();

	return(0);
}

