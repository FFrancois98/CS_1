#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct examType
{
	string semester_name;
	int semester_year;
	int no_of_grades;
	float average_grade;
	int no_of_grades_above_average;
	int no_of_grades_below_average;
	int grades_array[35];
};
void calculate_statistics(examType[]);
void input_data(examType[], ifstream&);
void print_results(examType[]);
void calculate_average(examType[], int);
void calculate_above_average(examType[], int);
void calculate_below_average(examType[], int);

int main()
{
	examType statistics_array[5];
	ifstream myfile;
	myfile.open("infile.txt");
	input_data(statistics_array, myfile);
	calculate_statistics(statistics_array);
	print_results(statistics_array);
}
void input_data(examType statistics_array[], ifstream& myfile)
{
	for (int i = 0; i < 5; i++)
	{
		myfile >> statistics_array[i].semester_name >> statistics_array[i].semester_year >> statistics_array[i].no_of_grades;
		for (int j = 0; j < statistics_array[i].no_of_grades; j++)
		{
			myfile >> statistics_array[i].grades_array[j];
		}
	}
}
void calculate_statistics(examType statistics_array[])
{
	for (int i = 0; i < 5; i++)
	{
		calculate_average(statistics_array, i);
		calculate_above_average(statistics_array, i);
		calculate_below_average(statistics_array, i);
	}
}
void calculate_average(examType statistics_array[], int semester_index)
{
	int sum_grades = 0;
	for (int i = 0; i < statistics_array[semester_index].no_of_grades; i++)
	{
		sum_grades += statistics_array[semester_index].grades_array[i];
	}
	statistics_array[semester_index].average_grade = (float)sum_grades / statistics_array[semester_index].no_of_grades;
}
void calculate_above_average(examType statistics_array[], int semester_index)
{
	statistics_array[semester_index].no_of_grades_above_average = 0;
	for (int i = 0; i < statistics_array[semester_index].no_of_grades; i++)
	{
		if (statistics_array[semester_index].grades_array[i] > statistics_array[semester_index].average_grade)
		{
			statistics_array[semester_index].no_of_grades_above_average++;
		}
	}
}
void calculate_below_average(examType statistics_array[], int semester_index)
{
	statistics_array[semester_index].no_of_grades_below_average = 0;
	for (int i = 0; i < statistics_array[semester_index].no_of_grades; i++)
	{
		if (statistics_array[semester_index].grades_array[i] < statistics_array[semester_index].average_grade)
		{
			statistics_array[semester_index].no_of_grades_below_average++;
		}
	}
}
void print_results(examType statistics_array[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Analysis of exams in " << statistics_array[i].semester_name << " "
			<< statistics_array[i].semester_year << endl << endl;
		cout << "The number of grades is " << statistics_array[i].no_of_grades << endl;
		cout << "The average grade is " << fixed << showpoint << setprecision(2)
			<< statistics_array[i].average_grade << endl;
		cout << "The number of grades above the average is " << statistics_array[i].no_of_grades_above_average << endl;
		cout << "The number of grades below the average is " << statistics_array[i].no_of_grades_below_average << endl << endl;
	}
}
/*
Analysis of exams in Fall 2013

The number of grades is 17
The average grade is 66.06
The number of grades above the average is 9
The number of grades below the average is 8

Analysis of exams in Spring 2014

The number of grades is 10
The average grade is 67.70
The number of grades above the average is 5
The number of grades below the average is 5

Analysis of exams in Fall 2014

The number of grades is 12
The average grade is 57.33
The number of grades above the average is 6
The number of grades below the average is 6

Analysis of exams in Spring 2015

The number of grades is 20
The average grade is 70.00
The number of grades above the average is 11
The number of grades below the average is 9

Analysis of exams in Fall 2015

The number of grades is 15
The average grade is 60.13
The number of grades above the average is 8
The number of grades below the average is 7

Press any key to continue . . .
*/