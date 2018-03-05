#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
float compute_area(float, float);
float compute_price(float);
float average(float, int);
void print_report(string, float, float, float, float);
const float charge_sqft = 0.05;
int main()
{
	string address; // declare variables
	int counter = 0;
	float lawn_wid, lawn_len, area_lawn, price;
	float tot_price = 0;
	float tot_len = 0;
	float tot_wid = 0;
	float tot_area = 0;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file
	heading();
	cout << "********************Daily Lawn Cutting Report****************" << endl; // Display Heading
	cout << "Address    " << '\t' << '\t' << "Width" << '\t' << "Length" << '\t' << "Area" << '\t' << '\t' << "Cost" << endl << endl;
	while (myfile.good()) // Repeat while stream is good
	{
		getline(myfile, address); // read address, lawn width and lawn length from the file
		myfile >> lawn_wid >> lawn_len;
		area_lawn = compute_area(lawn_len, lawn_wid); // compute the area of the lawn
		price = compute_price(area_lawn); //  compute the amount to charge the client
		tot_price += price; // add charge to daily total
		tot_area += area_lawn; // add area to total area
		tot_len += lawn_len; // add length to total length
		tot_wid += lawn_wid; // add width to total width
		print_report(address, area_lawn, lawn_wid, lawn_len, price); //  display the client address, the lawn dimensions, the lawn area and the amount to charge
		counter += 1;
		myfile.ignore(10, '\n');
	}
	myfile.close();
	cout << endl << "Daily Total -- $" << fixed << showpoint << setprecision(2) << tot_price << endl; // display the total amount of money they have earned for the day
	cout << fixed << showpoint << setprecision(2) << "Average Length -- " << average(tot_len, counter) << endl; // compute and display to average width
	cout << fixed << showpoint << setprecision(2) << "Average Width -- " << average(tot_wid, counter) << endl; // compute and display the average length
	cout << fixed << showpoint << setprecision(2) << "Average Area -- " << average(tot_area, counter) << endl; // compute and display the average area
}
float compute_area(float len, float wid)
{
	return len * wid;
}
float compute_price(float area)
{
	return area * charge_sqft;
}
float average(float total, int count)
{
	return (float)total / count;
}
void print_report(string addy, float area, float wid, float len, float cost)
{
	cout << fixed << showpoint << setprecision(2) << addy << '\t' << '\t' << wid << '\t' << len << '\t' << area << '\t' << '\t' << "$" << cost << endl;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 16, 2017" << endl;
	cout << "Lab 6, Problem 1" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "Program to print lawn cutting results." << endl;
	cout << "******************************************************************" << endl;
}
/*
******************************************************************
Fleurevca Francois
@02818122
February 16, 2017
Lab 6, Problem 1
SYCS-135 Computer Science 1
Program to print lawn cutting results.
******************************************************************
********************Daily Lawn Cutting Report****************
Address                 Width   Length  Area            Cost

123 Main St             55.60   67.00   3725.20         $186.26
67 Georgia Ave          30.00   40.00   1200.00         $60.00
1234 14th St            79.20   24.50   1940.40         $97.02

Daily Total -- $343.28
Average Length -- 43.83
Average Width -- 54.93
Average Area -- 2288.53
Press any key to continue . . .
*/