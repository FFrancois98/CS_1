#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int dollars(int);
int cents(int);

int main()
{
	int pennies, dollar, cent;
	cout << "Enter the number of pennies that you have? "; //Prompt the user to enter a number of cents. 
	cin >> pennies; //Get the number of cents from the user. 
	dollar = dollars(pennies); //Convert the number of cents into dollars and cents.
	cent = cents(pennies);
	cout << endl << "You have this much money: $" << dollar << "." << cent << endl; //Output the conversion to the user in the currency format

}
int dollars(int pennies)
{
	return  pennies / 100;
}
int cents(int pennies)
{
	return pennies % 100;
}
/*
Enter the number of pennies that you have? 789

You have this much money: $7.89
Press any key to continue . . .
Enter the number of pennies that you have? 99

You have this much money: $0.99
Press any key to continue . . .
*/