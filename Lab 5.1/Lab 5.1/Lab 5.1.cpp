#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
float calculate_degree_f(float);

int main()
{
	float degree_c;
	float degree_f;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file

	heading();

	while (myfile.good())
	{
		myfile >> degree_c;
		degree_f = calculate_degree_f(degree_c);
		cout << setprecision(0) << degree_c << " Degrees C = " << fixed
			<< setprecision(2) << degree_f << " Degrees F" << endl;
	}
		
}

float calculate_degree_f(float c)
{
	float deg_f;
	deg_f = ((c * 9) / 5) + 32;
	return deg_f;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 9, 2017" << endl;
	cout << "Lab 5, Problem 1" << endl;
	cout << "Calculate Farenheit Temperatures" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}

/*
******************************************************************
Fleurevca Francois
@02818122
February 9, 2017
Lab 5, Problem 1
Calculate Farenheit Temperatures
SYCS-135 Computer Science 1
******************************************************************
24 Degrees C = 75.20 Degrees F
78 Degrees C = 172.40 Degrees F
34 Degrees C = 93.20 Degrees F
29 Degrees C = 84.20 Degrees F
0 Degrees C = 32.00 Degrees F
Press any key to continue . . .
*/