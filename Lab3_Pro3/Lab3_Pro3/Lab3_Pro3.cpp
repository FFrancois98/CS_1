#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	int num_1;
	int num_2;
	int num_3;
	int num_4;
	int num_5;

	float first_answer;

	cout << fixed << showpoint;
	cout << "Enter the 1st number: ";
	cin >> num_1;
	cout << "Enter the 2nd number: ";
	cin >> num_2;
	cout << "Enter the 3rd number: ";
	cin >> num_3;
	cout << "Enter the 4th number: ";
	cin >> num_4;
	cout << "Enter the 5th number: ";
	cin >> num_5;
	first_answer = (float)(num_1 + num_2) / (num_3 + num_4 + num_5);
	cout << setprecision(4) << fixed << first_answer << endl;

	return 0;
}

/*
Enter the 1st number: 1293
Enter the 2nd number: 2321
Enter the 3rd number: 12312432
Enter the 4th number: 12421
Enter the 5th number: 12321
0.0003
Press any key to continue . . .
*/