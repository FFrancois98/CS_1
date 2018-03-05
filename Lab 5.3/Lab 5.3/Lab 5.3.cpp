#include <iostream> 
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
void heading();
float find_mean(int, int, int, int);
float stand_deviation(int, int, int, int, float);

int main()
{
	int num1;
	int num2;
	int num3;
	int num4;
	float mean;
	float std_devi;
	heading();
	cout << endl << "Enter 1st integer: ";
	cin >> num1;
	cout << endl << "Enter 2nd integer: ";
	cin >> num2;
	cout << endl << "Enter 3rd integer: ";
	cin >> num3;
	cout << endl << "Enter 4th integer: ";
	cin >> num4;
	mean = find_mean(num1, num2, num3, num4);
	std_devi = stand_deviation(num1, num2, num3, num4, mean);
	cout << endl << "Mean: " << mean << endl << "Standard Deviation: " << std_devi << endl;
}
float find_mean(int num1, int num2, int num3, int num4)
{
	float mean = (float)(num1 + num2 + num3 + num4) / 4;
	return mean;
}
float stand_deviation(int num1, int num2, int num3, int num4, float mean)
{
	float std_de;
	std_de = (float)sqrt((pow((num1 - mean), 2) + pow((num2 - mean), 2) + pow((num3 - mean), 2) + pow((num4 - mean), 2)) / (4 - 1));
	return std_de;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 9, 2017" << endl;
	cout << "Lab 5, Problem 3" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}
/*
******************************************************************
Fleurevca Francois
@02818122
February 9, 2017
Lab 5, Problem 3
SYCS-135 Computer Science 1
******************************************************************

Enter 1st integer: 3

Enter 2nd integer: 6

Enter 3rd integer: 7

Enter 4th integer: 10

Mean: 6.5
Standard Deviation: 2.88675
Press any key to continue . . .
*/