#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
float difference_of(float, float);
float average(float, float);

int main()
{
	float total_temp;
	float avg_temp;
	float current_temp;
	float previous_temp;
	float diff_of_temp;
	float num_of_temps;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file

	heading();
	cout << "TEMP" << '\t' << "DIFF" << endl;

	myfile >> current_temp;
	num_of_temps = 1;
	total_temp = current_temp;
	cout << endl << current_temp << endl;
	
	while (myfile.good())
	{
		previous_temp = current_temp;
		myfile >> current_temp;
		num_of_temps += 1;
		total_temp += current_temp;
		diff_of_temp = difference_of(previous_temp, current_temp);
		cout << current_temp << '\t' << diff_of_temp << endl;
	}
	avg_temp = average(total_temp, num_of_temps);
	cout << endl << "Average Temperature: " << fixed << setprecision(2) << avg_temp << endl;
}
float difference_of(float pre, float curr)
{
	float diff = curr - pre;
	return diff;
}
float average(float total, float num_temps)
{
	float avg = total / num_temps;
	return avg;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 9, 2017" << endl;
	cout << "Lab 5, Problem 2" << endl;
	cout << "Compute the difference between temperatures and the average temp " << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}
/*
******************************************************************
Fleurevca Francois
@02818122
February 9, 2017
Lab 5, Problem 2
Compute the difference between temperatures and the average temp
SYCS-135 Computer Science 1
******************************************************************
TEMP    DIFF

34.5
38.6    4.1
42.4    3.8
46.8    4.4
51.3    4.5
63.1    11.8
60.2    -2.9
55.9    -4.3
60.3    4.4
56.7    -3.6
50.3    -6.4
42.2    -8.1

Average Temperature: 50.19
Press any key to continue . . .
*/