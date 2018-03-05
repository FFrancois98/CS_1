#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void getData(int&, int&);
void printData(int, int);

int main()
{
	int hours, miles;
	getData(hours, miles);
	printData(hours, miles);
	return 0;
}
void getData(int& hours, int& miles)
{
	cout << "Enter the total miles: "; //prompt user for data
	cin >> miles; // get data
	cout << "Enter the total hours: ";
	cin >> hours;
}
void printData(int hours, int miles)
{
	float mph = (float)miles / hours;  // calculate miles per hour
	cout << "The number of miles is " << miles << endl; // display data
	cout << "The number of hours is " << hours << endl;
	cout << fixed << showpoint << "The number of miles per hour is " << setprecision(2) << mph << endl;
}
/*
Enter the total miles: 12340
Enter the total hours: 460
The number of miles is 12340
The number of hours is 460
The number of miles per hour is 26.83
Press any key to continue . . .
*/