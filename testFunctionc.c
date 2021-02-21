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
		int iNumOfDigits = (int)(ceil((int)log10(aPropForce[i])) + 1);  //  log10 and ceil return double ( need to explicitly  cast them to int to avoid warnings)
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
	return (0);
}