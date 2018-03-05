#include <iostream>                        // include input/output library code
#include <string>                          // include string manipulate library code
using namespace std;                       // allows all of the names in a namespace 
void heading();							   // to be accessed without the namespace 
										   // identifier as a qualifier

int main()
{

	int side_inch;							// declares varaible for length of side
	int area;								// declares area variable
	heading();								// calls heading

	cout << "AREA CALCULATOR" << endl;      // prompt area calculator
	cout << endl << "Enter the number of inches of a side=> "; // 1. prompt user input 
	cin >> side_inch;						// 2. get user input
	area = side_inch * side_inch;			// 3. multiply input by itself
	cout << endl << "The area is " << area << endl; // 4. output data
}

void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "September 13, 2010" << endl;
	cout << "Lab 4, Problem 2" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;

}

/*

******************************************************************
Fleurevca Francois
@02818122
September 13, 2010
Lab 4, Problem 2
SYCS-135 Computer Science 1
******************************************************************
AREA CALCULATOR

Enter the number of inches of a side=> 12

The area is 144
Press any key to continue . . .

*/