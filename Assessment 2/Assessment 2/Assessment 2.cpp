#include <iostream> 
#include <iomanip>
#include <math.h>
using namespace std;
float calculate_monthly_payment(int, float, int);


int main()
{
	int principal;
	float first_interest;
	float interest;
	int num_years;
	int num_months;

	float payment_amount;

	cout << fixed << showpoint;
	cout << "Enter the mortgage principal: ";
	cin >> principal;
	cout << "Enter the annual interest rate: ";
	cin >> first_interest;
	cout << "Enter the number of years of the loan:  ";
	cin >> num_years;

	num_months = num_years * 12;
	interest = first_interest / 12;

	payment_amount = calculate_monthly_payment(principal, interest, num_months);

	cout << "For a loan amount of " << principal << " with an interest rate of "
		<< setprecision(2) << fixed << first_interest << " and a " << num_years 
		<< " year mortgage, your monthly payments are $";
	cout << setprecision(2) << fixed << payment_amount << endl;

	return 0;
}

float calculate_monthly_payment(int principal, float interest, int num_months)
{
	float payment_amount = (float)principal * ((interest * (pow((1 + interest),
		num_months))) / (pow((1 + interest), num_months) - 1));
	return payment_amount;
}


/*

Enter the mortgage principal: 50000
Enter the annual interest rate: 0.07
Enter the number of years of the loan:  7
 For a loan amount of 50000 with an interest rate of 0.07 and a 7 year mortgage, your monthly payments are $754.63
Press any key to continue . . .

*/