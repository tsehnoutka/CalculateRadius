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
const double M_PI = 3.1426;

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
		//int iNumOfDigits = log10(aPropForce[i]);
		if (iNumOfDigits == aNumOfDigits[i]){
			printf("%.2F Digits is correct at %d\n", aPropForce[i], iNumOfDigits);
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

void Lab210215() {
	//Initialization
	double option = 0.00; //initialize option user has to make between (1) polygon inside of a circle and (2) circle inside of polygon
	double Num_Sides = 0.00; //initialize number of polygon sides
	double Apothem = 0.00; //initialize length of polygon apothem 
	double CircleR = 0.00; //initialize radius of the resulting circle
	double CircleA = 0.00; //initialize area of the resulting circle
	double PolyS = 0.00; //initialize side length of the resulting polygon
	double PolyA = 0.00; //initialize area of the resulting polygon

	//User Input
	printf("1. Polygon inside of circle\n"); //display option 1
	printf("2. Circle inside of polygon\n"); //display option 2
	printf("Select your option -> "); //displays prompt for option selection
	scanf_s("%lf", &option); //input user option choice
	printf("Enter number of polygon sides -> "); //displays prompt for polygon side number
	scanf_s("%lf", &Num_Sides); //input number of polygon sides
	printf("Enter length of polygon apothem -> "); //displays prompt for polygon apothem
	scanf_s("%lf", &Apothem); //input length of polygon apothem

	//Calculation
	PolyS = 2 * tan((M_PI / Num_Sides)) * Apothem; //calculates polygon side length
	PolyA = (PolyS * Apothem * Num_Sides) / 2; //calculates polygon area
	CircleR = (Apothem / (cos(M_PI / Num_Sides))) * fmod(option, 2) + Apothem * fmod((option + 1), 2); //calculates circle radius, and depending on the option chosen a different radius will be outputted 
	CircleA = M_PI * pow(CircleR, 2); // calculates circle area

	//Output
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); //prints answer box top border
	printf("Circle Radius: %16.2f\n", CircleR); //prints radius of the circle
	printf("Circle Area: %18.2f\n", CircleA); //prints area of the circle
	printf("Polygon Side Length: %10.2f\n", PolyS); //prints side length of the polygon
	printf("Polygon Area: %17.2f\n", PolyA); //prints area of the polygon
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"); //prints answer box bottom border

	return;
}
void TestOptionChoice() {
	int option[] = {1,2,3,4,5,6,15,10,30, 200,_CRT_INT_MAX};
	char result[] = { 'T', 'S', 'C', 'C','C', 'C', 'C', 'C', 'C', 'C', 'C' };
	short errorCount = 0;
	//printf("CRT INT MAX = %d\n", _CRT_INT_MAX);

	for (int i = 0; i < sizeof(option) / sizeof(int); i++) {
		printf("*********************     i = %d     ********************* \n", option[i]);
		char OptionChoice = '0';

		switch (option[i]) {
			case 1:
				OptionChoice = 'T';
				break;
			case 2:
				OptionChoice = 'S';
				break;
			default:
				OptionChoice = 'C';
		}

		/*
		int Factor1 = (1 / option[i]);  //  equals 1 when option = 1, else zero
		//int Factor2 = (-1) * ((2 / option[i]) * ((1 / option[i]) - 1));  //  equals 1 when option = 2, else zero
		//int Factor3 = (int)( (double)(option[i] / 3) * (double)(5.0 / option[i])   );

		int Factor2A = 2 / option[i];  
		int Factor2B = 1 / option[i];  
		int Factor2C = Factor2B - 1;
		int Factor2 = (-1) * (Factor2A * Factor2C);
		printf("Factor2A - %d\tFactor2b - %d\tFactor2C - %d\tFactor2 - %d\n", Factor2A, Factor2B, Factor2C, Factor2);


		int Factor3A = option[i] / 3;  // zero when option is less than 3, 1 or greater  when 3 or greater 
		double Factor3B = 5.0 / option[i];  //  greater than 1 when option is <5 , 1 when 5, < 1 when greater than 5
		int Factor3 = (int)(Factor3A * Factor3B); //  equals 1 when option[i] >= 3, else zero
		//printf("Factor3A - %d\tFactor3B - %lf\tFactor3 - %d\n", Factor3A, Factor3B, Factor3);
		
		//printf("Factor1 - %d\tFactor2 - %d\tFactor3 - %d\t\n", Factor1, Factor2, Factor3);

		char OptionChoice = 'T' * Factor1 + 'S' * Factor2 + 'C' * Factor3;
		*/
		if (OptionChoice != result[i]) {
			printf("****  ERROR  ***** Got - %c(%d)\t Expected - %c\n", OptionChoice, OptionChoice, result[i]);
			++errorCount;
		} //  end if
		else
			printf("Option- %d produced %c\n", option[i], OptionChoice);
			
		printf("\n");
	}  //  end for
	if (!errorCount) {
		printf("\n\n******************************************\n");
		printf("          All test ran SUCCESSFULLY\n");
		printf(    "******************************************\n\n");
	}
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
	char OptionChoice; //Initializes the option choice for the print statement


	//Input Statements
	printf("Enter desired option -> ");
	scanf_s("%d", &option);
	printf("Enter area of figure -> ");
	scanf_s("%lf", &AreaGiven);

	//Calculations
	Factor1 = (1 / option);
	Factor2 = (-1) * ((2 / option) * ((1 / option) - 1));
	Factor3 = (int)(((double)(option / 3) * (double)(5.0 / option)));
	RadiusCalc = sqrt(AreaGiven / M_PI) * Factor1 + sqrt(AreaGiven / M_PI) * Factor2 + sqrt((AreaGiven / option / tan(M_PI / (option + Factor1)))) * Factor3;
	AreaCalc = (RadiusCalc * cos(M_PI / 6)) * (RadiusCalc + RadiusCalc * sin(M_PI / 6)) * Factor1 + (2 * pow(RadiusCalc, 2)) * Factor2 + (M_PI * pow(RadiusCalc, 2)) * Factor3;
	OptionChoice = 'T' * Factor1 + 'S' * Factor2 + 'C' * Factor3;

	//Print Statements
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Radius/Apothem of figure with area given: %.1lf\n", RadiusCalc);
	printf("Area of inscribed figure [%c] : %.1lf\n", OptionChoice, AreaCalc);

	return 0;

	}

int main()
{
	//testNumOfDigits();
	//Lab210215();
	//Exam1();
	TestOptionChoice();
	/*
	//Declaration of Variables
	double Mass_air = 0.00; //Establish the mass of the airplane
	double Mass_glide1 = 0.00; //Establish the mass of the first glider
	double Mass_glide2 = 0.00; //Establish the mass of the second glider
	double Force_prop = 0.00; //Establish the force of the propellor
	double Acc = 0.00; //Establish the acceleration of the system
	double Tension1 = 0.00; //Establish the tension in the first rope
	double Tension2 = 0.00; //Establish the tension in the second rope
	int WidthModifier = 0;//Establish the Width Modifier

	printf("Enter mass of airplane (kg) -> "); //Print statement asking for the airplanes mass
	scanf_s("%lf", &Mass_air); //respective scanf_s statement
	printf("Enter mass of glider #1 (kg) -> "); //Print statement asking for the first gliders mass
	scanf_s("%lf", &Mass_glide1); //respective scanf_s statement
	printf("Enter mass of glider #2 (kg) -> "); //Print statement asking for the second gliders mass
	scanf_s("%lf", &Mass_glide2); //respective scanf_s statement
	printf("Enter force produced by propellers (N) -> "); //Print statement asking for the force
	scanf_s("%lf", &Force_prop); //respective scanf_s statement

	Acc = Force_prop / (Mass_air + Mass_glide1 + Mass_glide2); //Calculation for the acceleration
	Tension1 = Acc * (Mass_glide1 + Mass_glide2); //Calculation for the first tension
	Tension2 = Acc * (Mass_glide2); //Calculation for the second tension
	WidthModifier = log10(Force_prop) + 6;

	printf("\nAcceleration: %.2lf m/s^2\n", Acc); //Output Print statements
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Resulting tension on cable #1: %*.2lf Newtons\n", WidthModifier, Tension1);
	printf("Resulting tension on cable #2: %*.2lf Newtons\n", WidthModifier, Tension2);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	*/
	return(0);
	
}



/*
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
	scanf_s_s("%lf", &Mass_air); //respective scanf_s statement
	printf("Enter mass of glider #1 (kg) -> "); //Print statement asking for the first gliders mass
	scanf_s_s("%lf", &Mass_glide1); //respective scanf_s statement
	printf("Enter mass of glider #2 (kg) -> "); //Print statement asking for the second gliders mass
	scanf_s_s("%lf", &Mass_glide2); //respective scanf_s statement
	printf("Enter force produced by propellers (N) -> "); //Print statement asking for the force
	scanf_s_s("%lf", &Force_prop); //respective scanf_s statement

	Acc = Force_prop / (Mass_air + Mass_glide1 + Mass_glide2); //Calculation for the acceleration
	Tension1 = Acc * (Mass_glide1 + Mass_glide2); //Calculation for the first tension
	Tension2 = Acc * (Mass_glide2); //Calculation for the second tension

	printf("\nAcceleration: %.2lf m/s^2\n", Acc); //Output Print statements
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("Resulting tension on cable #1: %10.2lf Newtons\n", Tension1);
	printf("Resulting tension on cable #2: %10.2lf Newtons\n", Tension2);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	
	return(0);

} //  end of main
*/


	/*
	//Collection of variable values
	printf("Please enter the mass of the airplane (kg) -> ");
	scanf_s_s("%f", &fMassPlane);
	printf("Please enter the mass of the glider (kg) -> ");
	scanf_s_s("%f", &fMassGlider);
	printf("Please enter force produced by engines (N) -> ");
	scanf_s_s("%f", &fForce);
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
	scanf_s_s("%f", &fRadius);

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