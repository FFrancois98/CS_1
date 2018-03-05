#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
float compute_service_charge(char, float, float);
float compute_interest(char, float, float);
void print_report(int, char, float);
int main()
{
	int acc_no;
	char acc_type;
	float min_bal, curr_bal;
	float serv_charge;
	float interest;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt"); //Open file
	heading(); // Print Heading
	while (myfile.good()) // repeats the following steps while the stream is good
	{
		myfile >> acc_no >> acc_type >> min_bal >> curr_bal; // Read the account number, account type, minimum balance, current balance
		if (curr_bal < min_bal)
		{
			serv_charge = compute_service_charge(acc_type, min_bal, curr_bal); // Computes service charge
			curr_bal -= serv_charge; // Update the account balance
		}
		else
		{
			interest = compute_interest(acc_type, min_bal, curr_bal); // computes the interest
			curr_bal += (curr_bal * interest); // Update the account balance
		}
		print_report(acc_no, acc_type, curr_bal); // Display the account infomation
	}
	myfile.close(); //Close file
	return 0;
}
float compute_service_charge(char acc_t, float min, float curr)
{
	float serv;
	if (curr < min)
	{
		if (acc_t == 'S')
		{
			serv = 10.0;
		}
		else if (acc_t == 'C')
		{
			serv = 25.0;
		}		
	}
	return serv;
}
float compute_interest(char acc_t, float min, float curr)
{
	float inter;
	float diff;
	if (acc_t == 'S')
	{
		inter = 0.04;
	}
	else if (acc_t == 'C')
	{
		diff = curr - min;
		if (diff <= 5000)
		{
			inter = 0.03;
		}
		else
		{
			inter = 0.05;
		}
	}
	return inter;
}
void print_report(int acc_no, char acc_t, float curr)
{
	cout << "******************************************************************************" << endl;
	cout << "Account Number: " << acc_no << endl;
	if (acc_t == 'S')
	{
		cout << "Account Type: Savings " << endl;
	}
	else
	{
		cout << "Account Type: Checking" << endl;
	}
	cout << fixed << showpoint << setprecision(2) << "Account Balance: $" << curr << endl;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 16, 2017" << endl;
	cout << "Lab 6, Problem 2" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "Program to update bank balance" << endl;
	cout << "******************************************************************" << endl;
}
/*
******************************************************************
Fleurevca Francois
@02818122
February 16, 2017
Lab 6, Problem 2
SYCS-135 Computer Science 1
Program to update bank balance
******************************************************************
******************************************************************************
Account Number: 46728
Account Type: Savings
Account Balance: $2808.00
******************************************************************************
Account Number: 87324
Account Type: Checking
Account Balance: $8073.45
******************************************************************************
Account Number: 79873
Account Type: Savings
Account Balance: $790.00
******************************************************************************
Account Number: 89832
Account Type: Checking
Account Balance: $3090.00
******************************************************************************
Account Number: 98322
Account Type: Checking
Account Balance: $725.00
Press any key to continue . . .
*/