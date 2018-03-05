#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
void gpa_report(string, string, string, int, int, float);

int main() 
{
	string first_name; //Declare variables
	string last_name;
	string classification;
	int quality_points;
	int credits;
	float gpa;
	heading();
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file
	cout << endl << "                  GPA REPORT" << endl;
	cout << endl << "   Name			Class   QP   Credits    GPA" << endl;
	myfile >> first_name >> last_name >> classification
		>> quality_points >> credits; // Read the data for first student from the file.
	gpa = (float)quality_points / credits; //compute GPA
	gpa_report(first_name, last_name, classification, quality_points, credits, gpa); // Display first student data
	myfile >> first_name >> last_name >> classification
		>> quality_points >> credits; // Read the data for second student from the file.
	gpa = (float)quality_points / credits; //compute GPA
	gpa_report(first_name, last_name, classification, quality_points, credits, gpa); // Display second student data
	myfile >> first_name >> last_name >> classification
		>> quality_points >> credits; // Read the data for second student from the file.
	gpa = (float)quality_points / credits; // compute GPA
	gpa_report(first_name, last_name, classification, quality_points, credits, gpa); // Display third student data
	cout << "******************************************************************" << endl;
	return 0;
}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "September 13, 2010" << endl;
	cout << "Lab 4, Problem 4" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}
void gpa_report(string first_name, string last_name, string classification, int quality_points, int credits, float gpa)
{
	cout << endl << first_name << setw(10) << last_name << setw(4) << '\t' <<
		classification << setw(9) << quality_points << setw(8) << credits
		<< setw(10) << setprecision(2) << fixed << gpa << endl;
}
/*
******************************************************************
Fleurevca Francois
@02818122
September 13, 2010
Lab 4, Problem 4
SYCS-135 Computer Science 1
******************************************************************

GPA REPORT

Name                 Class   QP   Credits    GPA

Joe     Smith           S       40      12      3.33

Fred     Davis          F       35      14      2.50

June   Freeman          J       40      10      4.00
******************************************************************
Press any key to continue . . .
*/