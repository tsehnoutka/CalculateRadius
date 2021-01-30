// CalculateRadius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
/******************************************************************************

							  Online C++ Debugger.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include "stdio.h"
#include "math.h"


int main(void) {
	//Initialization of variables
	float fMassPlane = 0; //Mass of the plane
	float fMassGlider = 0; //Mass of the glider
	float fForce = 0; //Force from the propellers
	float fTension = 0; //Tension of the rope holding the glider to the plane
	float fGliderAcc = 0; //Acceleration of the glider
	float fPlaneAcc = 0;

	//Collection of variable values
	printf("Please enter the mass of the airplane (kg) -> ");
	scanf_s("%f", &fMassPlane);
	printf("Please enter the mass of the glider (kg) -> ");
	scanf_s("%f", &fMassGlider);
	printf("Please enter force produced by engines (N) -> ");
	scanf_s("%f", &fForce);

	//Math Calculations
	fTension = (float)(fForce / (fMassGlider + fMassPlane)) * (fMassGlider); //Calculate the tension
	fGliderAcc = (float)(fTension / fMassGlider); //Calculate the glider's acceleration
										   
	//Print Results
	printf("Resulting Tension = %.2f\n", fTension); //prints tension
	printf("Acceleration of the Glider = %.2f\n", fGliderAcc); //prints acceleration

	return(0);
}

/*
#define PI 3.1416

float CacluateRadius(float r) {
	return 2.0 * r * PI;
}

int main(void) {
	// your code goes here
	//const float PI = 3.1416;  //  Or you can use #define like above
	float fRadius = 0.0;

	printf("Please enter your radius: ");
	scanf_s("%f", &fRadius);

	printf("\nthe circumfrence is: %f \n",  2.0 * fRadius * PI);
	// printf("\nthe circumfrence is: %f \n",  CacluateRadius(fRadius));
	return 0;
}

/*
void fooValue(int i) {
	i = i + 1;
}
void fooReference(int *i) {
	*i = *i + 2;   
}

int main(void) {
	// your code goes here
	int iValue = 0;

	printf("iValue before value: %d\n", iValue);
	fooValue(iValue);
	printf("iValue after value: %d\n", iValue);

	printf("iValue before reference: %d\n", iValue);
	fooReference(&iValue);  
	printf("iValue after reference: %d\n", iValue);
	
return 0;
}
*/