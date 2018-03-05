#include <iostream> 
#include <iomanip>
using namespace std;
void heading();  // function prototypes
float divide_sum(int, int, int, int, int);
void display_answer(float);


int main()
{
	int num_1;
	int num_2;
	int num_3;
	int num_4;
	int num_5;

	float first_answer;

	heading();

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
	
	first_answer = divide_sum(num_1, num_2, num_3, num_4, num_5);
	display_answer(first_answer);

	return 0;
}

void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "September 13, 2010" << endl;
	cout << "Lab 3, Problem 1" << endl;
	cout << "This program simply outputs a heading for my output" << endl;
	cout << "******************************************************************" << endl;

}

float divide_sum(int num_1, int num_2, int num_3, int num_4, int num_5) 
{
	float first_answer = (float)(num_1 + num_2) / (num_3 + num_4 + num_5);
	return first_answer;
}

void display_answer(float first_answer)
{
	cout << setprecision(4) << fixed << first_answer << endl;
}

/*

******************************************************************
Fleurevca Francois
@02818122
September 13, 2010
Lab 3, Problem 1
This program simply outputs a heading for my output
******************************************************************
Enter the 1st number: 4654
Enter the 2nd number: 45645
Enter the 3rd number: 2342
Enter the 4th number: 235435
Enter the 5th number: 34543
0.1847
Press any key to continue . . .

*/