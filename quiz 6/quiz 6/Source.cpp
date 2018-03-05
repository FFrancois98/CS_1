#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
ifstream myfile;
char Compute_lab_grade();
char Compute_Quiz_grade();
char Compute_test_grade();
char Compute_Assignment_grade();
int get_lab_data();
int get_quiz_data();
int get_assignment_data();
int get_test_data();
float total(char);
char final_average_score(float);
//creat get function prototype
int main() {
	int counters = 1;
	char lab;
	char assgniment_score;
	char quiz_score;
	char test_score;
	float final_total_average;
	myfile.open("infile.txt");