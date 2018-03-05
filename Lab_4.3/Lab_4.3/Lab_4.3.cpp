#include <iostream> 
#include <iomanip>
using namespace std;
void heading();
float const imburse_rate = 0.35;
int main()
{
	float begin_reading;
	float end_reading;
	float imburse_amount;
	float miles_travel;
	heading();
	cout << fixed << showpoint;
	cout << endl << "Enter beginning odometer reading=> ";		// 1. prompt user input of beginning reading
	cin >> begin_reading;										// 2. get user input
	cout << endl << "Enter ending odometer reading=> ";			// 3. prompt user input of end reading
	cin >> end_reading;											// 4. get user input
	miles_travel = end_reading - begin_reading;					// 5. subtract end input frombrginning input
	imburse_amount = miles_travel * imburse_rate;				// 6. multiply difference by .35
	cout << endl << "You traveled " << setprecision(2) << miles_travel  // 7. output data
		<< " miles. At $.35 per mile, your reimbursement is "
		<< setprecision(2) << imburse_amount << "." << endl;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "September 13, 2010" << endl;
	cout << "Lab 4, Problem 3" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}

/*

******************************************************************
Fleurevca Francois
@02818122
September 13, 2010
Lab 4, Problem 3
SYCS-135 Computer Science 1
******************************************************************

Enter beginning odometer reading=> 55044

Enter ending odometer reading=> 55178

You traveled 134.00 miles. At $.35 per mile, your reimbursement is 46.90.
Press any key to continue . . .

*/