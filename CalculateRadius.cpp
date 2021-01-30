// CalculateRadius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>

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