// CalculateRadius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/******************************************************************************

							  Online C++ Debugger.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <string.h>

bool nearlyEqual(double a, double b, double epsilon) {
	//printf("\nThe difference is - %f\n", fabs(a - b));
	if (fabs(a - b) < epsilon)
		return true;
	else
		return false;
}

bool testOutPutStrings(int strNum, const char* createdString) {
	const char outputStrings[10][200] = {
		{"Resulting tension on cable #1:   29081.63 Newtons"},
		{"Resulting tension on cable #2:   13775.51 Newtons"},
		{"Resulting tension on cable #1:   29081.63 Newtons"},
		{"Resulting tension on cable #2:   15306.12 Newtons"},
		{"Resulting tension on cable #1:    9578.79 Newtons"},
		{"Resulting tension on cable #2:    4732.31 Newtons"},
		{"Resulting tension on cable #1:    9290.37 Newtons"},
		{"Resulting tension on cable #2:    4551.15 Newtons"},
		{"Resulting tension on cable #1:    994.97 Newtons"},
		{"Resulting tension on cable #2:    452.26 Newtons"}
	};  //  end of Output Strings

	int iResult = strcmp(outputStrings[strNum], createdString);
	if (0 != iResult) {
		printf("\nThe two strings were NOT equal !!!\n%s SHOULD BE:\n%s\n\n", createdString, outputStrings[strNum]);
		return false;
	}
	return true;
}  //  end of test Output Strings


void testNumOfDigits() {
	double aPropForce[] = { 75000,38657,4500,10,100,1000 };
	short aNumOfDigits[] = { 5,5,4,2,3,4 };
	const int NUM_OF_TEST = sizeof(aPropForce) / sizeof(double);
	int count = 0;

	for (int i = 0; i < NUM_OF_TEST; i++) {
		int iNumOfDigits = (int)(ceil((int)log10(aPropForce[i])) + 1);  //  log10 and ceil return double ( need to explicitley cast them to int to avoid warnings)
		if (iNumOfDigits == aNumOfDigits[i]){
			//printf("%.2f Digits is correct at %d\n", aPropForce[i], iNumOfDigits);
		}
		else {
			printf("%.2f Digits is wrong at %d, should have been %d\n", aPropForce[i], iNumOfDigits, aNumOfDigits[i]);
			count++;
		}
	} //  end of for
	if (0 == count)
		printf("\nAll number of Digits  tests ran SUCCESFULLY!!!!!\n\n");
}  //  end of test Number of Digits


void testCalculations() {
	double aAirplane[]  = { 15000,15000,12750.9,7500,775 };
	double aGlider1[]   = { 5000,4500,2125.2,1260,120 };
	double aGlider2[]   = { 4500,5000,2075.136,1210,100 };
	double aPropForce[] = { 75000,75000,38657,37500,4500 };
	double aTension1[] = { 29081.63,29081.63,9578.79,9290.37,994.97 };
	double aTension2[]  = { 13775.51,15306.12,4732.31,4551.15,452.26 };
	const int NUM_OF_TEST = sizeof(aAirplane)/sizeof(double);
	int iErrCount = 0;
	const double EPSILON = .01;  //  the tolerence for double comparision
	int iStringNumber = 0;
	const int NUM_OF_SPACES = 6;


	printf("\n\n");
	for (int i = 0; i < NUM_OF_TEST; i++) {
		double Acc = aPropForce[i] / (aAirplane[i] + aGlider1[i] + aGlider2[i]); //Calculation for the acceleration
		double Tension1 = Acc * (aGlider1[i] + aGlider2[i]); //Calculation for the first tension
		double Tension2 = Acc * (aGlider2[i]); //Calculation for the second tension
		char tension1Output[200] = {};
		char tension2Output[200] = {};

		//**************************************************
		//		Test output strings
		//**************************************************
		int iNumOfDigits = (int)(ceil((int)log10(aPropForce[i])) + 1);
		sprintf_s(tension1Output, "Resulting tension on cable #1:%*.2f Newtons", iNumOfDigits + NUM_OF_SPACES, Tension1);
		if (!testOutPutStrings(iStringNumber, tension1Output)) {
			++iErrCount;
		}
		iStringNumber++;
		sprintf_s(tension2Output, "Resulting tension on cable #2:%*.2f Newtons", iNumOfDigits + NUM_OF_SPACES, Tension2);
		if (!testOutPutStrings(iStringNumber, tension2Output)) {
			++iErrCount;
		}
		iStringNumber++;

		//**************************************************
		//		Test calculations
		//**************************************************
		//  Tension 1
		if (!nearlyEqual(Tension1, aTension1[i], EPSILON)) {
			printf("Tension 1 is wrong.  Should be - %f\t was %f\n", aTension1[i], Tension1);
			iErrCount++;
		}
		else
		{
			//printf("Tension 1 is Correct.  we expected - %f, it was %f\n", aTension1[i], Tension1);
		}
		//  Tension 2
		if (!nearlyEqual(Tension2, aTension2[i], EPSILON)) {
			printf("Tension 2 is wrong.  Should be - %f\t was %f\n", aTension2[i], Tension2);
			iErrCount++;
		}
		else {
			//printf("Tension 2 is Correct.  we expected - %f, it was %f\n", aTension2[i], Tension2);
		}
	}  //  end of for loop
	if (0 == iErrCount)
		printf("\nAll Calculation / String  tests ran SUCCESFULLY!!!!!\n\n");
} //  end of test Calculations


int main()
{
	testNumOfDigits();
	testCalculations();
	/*
	//Declaration of Variables
	double Mass_air = 0.00; //Establish the mass of the airplane
	double Mass_glide1 = 0.00; //Establish the mass of the first glider
	double Mass_glide2 = 0.00; //Establish the mass of the second glider
	double Force_prop = 0.00; //Establish the force of the propellor
	double Acc = 0.00; //Establish the acceleration of the system
	double Tension1 = 0.00; //Establish the tension in the first rope
	double Tension2 = 0.00; //Establish the tension in the second rope

	printf("Enter mass of airplane (kg) -> "); //Print statement asking for the airplanes mass
	scanf_s("%lf", &Mass_air); //respective scanf statement
	printf("Enter mass of glider #1 (kg) -> "); //Print statement asking for the first gliders mass
	scanf_s("%lf", &Mass_glide1); //respective scanf statement
	printf("Enter mass of glider #2 (kg) -> "); //Print statement asking for the second gliders mass
	scanf_s("%lf", &Mass_glide2); //respective scanf statement
	printf("Enter force produced by propellers (N) -> "); //Print statement asking for the force
	scanf_s("%lf", &Force_prop); //respective scanf statement

	Acc = Force_prop / (Mass_air + Mass_glide1 + Mass_glide2); //Calculation for the acceleration
	Tension1 = Acc * (Mass_glide1 + Mass_glide2); //Calculation for the first tension
	Tension2 = Acc * (Mass_glide2); //Calculation for the second tension

	printf("\nAcceleration: %.2lf m/s^2\n", Acc); //Output Print statements
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Resulting tension on cable #1: %10.2lf Newtons\n", Tension1);
	printf("Resulting tension on cable #2: %10.2lf Newtons\n", Tension2);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	*/
	return(0);

} //  end of main


	/*
	//Collection of variable values
	printf("Please enter the mass of the airplane (kg) -> ");
	scanf_s("%f", &fMassPlane);
	printf("Please enter the mass of the glider (kg) -> ");
	scanf_s("%f", &fMassGlider);
	printf("Please enter force produced by engines (N) -> ");
	scanf_s("%f", &fForce);
	int iNumOfDigits = (int)((ceil(log10(fForce))+1)*sizeof(char));  // (int)((ceil(log10(num))+1)*sizeof(char))

	//Math Calculations
	fTension = (double)(fForce / (fMassGlider + fMassPlane)) * (fMassGlider); //Calculate the tension
	fGliderAcc = (double)(fTension / fMassGlider); //Calculate the glider's acceleration

	//Print Results
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Resulting Tension          =%*.2f Newtons\n", NUM_OF_SPACES + iNumOfDigits, fTension); //prints tension
	printf("Acceleration of the Glider =%*.2f m/sec\n", NUM_OF_SPACES + iNumOfDigits, fGliderAcc); //prints acceleration
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
	*/


/*
#define PI 3.1416

double CacluateRadius(double r) {
	return 2.0 * r * PI;
}

int main(void) {
	// your code goes here
	//const double PI = 3.1416;  //  Or you can use #define like above
	double fRadius = 0.0;

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