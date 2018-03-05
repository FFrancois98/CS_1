#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
char compute_lab_grade();
char compute_quiz_grade();
char compute_test_grade();
char compute_assignment_grade();
int get_lab_data();
int get_quiz_data();
int get_test_data();
int get_assignment_data();
float letter_to_gpa(char);

ifstream myfile; //Declare file input object 

int main()
{
	float lab_gpa, q_gpa, t_gpa, ass_gpa, final_gpa; //Declares variables
	myfile.open("infile.txt"); //Open file
	char lab_grade, quiz_grade, test_grade, assignment_grade, final_letter; //Declares variables
	lab_grade = compute_lab_grade(); // retrevies data and computes letter grade
	int i = 1;
	while (myfile)
	{
		assignment_grade = compute_assignment_grade(); // retrevies data and computes letter grade
		quiz_grade = compute_quiz_grade(); // retrevies data and computes letter grade
		test_grade = compute_test_grade(); // retrevies data and computes letter grade 
		lab_gpa = letter_to_gpa(lab_grade); // computes numerical gpa based off letter grade
		q_gpa = letter_to_gpa(quiz_grade);
		t_gpa = letter_to_gpa(test_grade);
		ass_gpa = letter_to_gpa(assignment_grade);

		final_gpa = (((10 * q_gpa) + (25 * ass_gpa) + (30 * lab_gpa) + (35 * t_gpa)) / 100); // computes final grade

		if (final_gpa < 0.7)
		{
			final_letter = 'F';
		}
		else if (0.7 <= final_gpa && final_gpa < 1.7)
		{
			final_letter = 'D';
		}
		else if (1.7 <= final_gpa && final_gpa < 2.7)
		{
			final_letter = 'C';
		}
		else if (2.7 <= final_gpa && final_gpa < 3.49)
		{
			final_letter = 'B';
		}
		else if (final_gpa >= 3.49)
		{
			final_letter = 'A';
		}
		cout << "Student " << i << endl; // displays result of computations
		cout << "Students Lab Grade is: " << lab_grade  << endl;
		cout << "Students Assignment Grade is: " << assignment_grade << endl;
		cout << "Students Quiz Grade is: " << quiz_grade << endl;
		cout << "Students Exam Grade is: " << test_grade << endl;
		cout << "Students Final Grade is a " << final_letter << endl << endl;
		lab_grade = compute_lab_grade(); // retrevies data and computes letter grade
		i = i + 1;
	}
	
}
char compute_lab_grade()
{
	int ls = get_lab_data();
	char lab_grade;
	if (ls < 30)
	{
		lab_grade = 'F';
	}
	else if (30 <= ls && ls < 40)
	{
		lab_grade = 'D';
	}
	else if (40 <= ls && ls < 50)
	{
		lab_grade = 'C';
	}
	else if (50 <= ls && ls < 60)
	{
		lab_grade = 'B';
	}
	else
	{
		lab_grade = 'A';
	}
	return lab_grade;
}
char compute_quiz_grade()
{
	int qs = get_quiz_data();
	char q_grade;
	if (qs < 60)
	{
		q_grade = 'F';
	}
	else if (60 <= qs && qs < 70)
	{
		q_grade = 'D';
	}
	else if (70 <= qs && qs < 85)
	{
		q_grade = 'C';
	}
	else if (85 <= qs && qs < 100)
	{
		q_grade = 'B';
	}
	else
	{
		q_grade = 'A';
	}
	return q_grade;
}
char compute_test_grade()
{
	int ts = get_test_data();
	char tes_score;
	if (ts < 150)
	{
		tes_score = 'F';
	}
	else if (150 <= ts && ts < 180)
	{
		tes_score = 'D';
	}
	else if (180 <= ts && ts < 210)
	{
		tes_score = 'C';
	}
	else if (210 <= ts && ts < 360)
	{
		tes_score = 'B';
	}
	else 
	{
		tes_score = 'A';
	}
	return tes_score;
}
char compute_assignment_grade()
{
	int as = get_assignment_data();
	char ass_score;
	if (as < 80)
	{
		ass_score = 'F';
	}
	else if (80 <= as && as < 100)
	{
		ass_score = 'D';
	}
	else if (100 <= as && as < 112)
	{
		ass_score = 'C';
	}
	else if (112 <= as && as < 130)
	{
		ass_score = 'B';
	}
	else
	{
		ass_score = 'A';
	}
	return ass_score;
}
int get_lab_data()
{
	int LAB1, LAB2, LAB3, LAB4, LAB5, lab_score;
	myfile >> LAB1 >> LAB2 >> LAB3 >> LAB4 >> LAB5;
	lab_score = LAB1 + LAB2 + LAB3 + LAB4 + LAB5;
	return lab_score;
}
int get_quiz_data()
{
	int QZ1, QZ2, QZ3, QZ4, QZ5, QZ6, QZ7, QZ8, QZ9, QZ10, QZ11, QZ12, quiz_score;
	myfile >> QZ1 >> QZ2 >> QZ3 >> QZ4 >> QZ5 >> QZ6 >> QZ7 >> QZ8 >> QZ9 >> QZ10 >> QZ11 >> QZ12;
	quiz_score = QZ1 + QZ2 + QZ3 + QZ4 + QZ5 + QZ6 + QZ7 + QZ8 + QZ9 + QZ10 + QZ11 + QZ12;
	return quiz_score;
}
int get_test_data()
{
	int TST1, TST2, Final, test_score;
	myfile >> TST1 >> TST2 >> Final;
	test_score = TST1 + TST2 + Final;
	return test_score;
}
int get_assignment_data()
{
	int ASGN1, ASGN2, ASGN3, ASGN4, ASGN5, ASGN6, ASGN7, assign_score;
	myfile >> ASGN1 >> ASGN2 >> ASGN3 >> ASGN4 >> ASGN5 >> ASGN6 >> ASGN7;
	assign_score = ASGN1 + ASGN2 + ASGN3 + ASGN4 + ASGN5 + ASGN6 + ASGN7;
	return assign_score;
}
float letter_to_gpa(char letter)
{
	float gpa;
	if (letter == 'A')
	{
		gpa = 4.0;
	}
	else if (letter == 'B')
	{
		gpa = 3.0;
	}
	else if (letter == 'C')
	{
		gpa = 2.0;
	}
	else if (letter == 'D')
	{
		gpa = 1.0;
	}
	else if (letter == 'F')
	{
		gpa = 0.0;
	}
	return gpa;
}
/*
Student 1
Students Lab Grade is: F
Students Assignment Grade is: D
Students Quiz Grade is: F
Students Exam Grade is: B
Students Final Grade is a D

Student 2
Students Lab Grade is: B
Students Assignment Grade is: C
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a B

Student 3
Students Lab Grade is: C
Students Assignment Grade is: B
Students Quiz Grade is: F
Students Exam Grade is: B
Students Final Grade is a C

Student 4
Students Lab Grade is: C
Students Assignment Grade is: D
Students Quiz Grade is: F
Students Exam Grade is: B
Students Final Grade is a C

Student 5
Students Lab Grade is: C
Students Assignment Grade is: F
Students Quiz Grade is: D
Students Exam Grade is: B
Students Final Grade is a C

Student 6
Students Lab Grade is: B
Students Assignment Grade is: A
Students Quiz Grade is: C
Students Exam Grade is: B
Students Final Grade is a B

Student 7
Students Lab Grade is: C
Students Assignment Grade is: F
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a C

Student 8
Students Lab Grade is: A
Students Assignment Grade is: B
Students Quiz Grade is: C
Students Exam Grade is: B
Students Final Grade is a B

Student 9
Students Lab Grade is: B
Students Assignment Grade is: D
Students Quiz Grade is: B
Students Exam Grade is: C
Students Final Grade is a C

Student 10
Students Lab Grade is: F
Students Assignment Grade is: C
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a C

Student 11
Students Lab Grade is: F
Students Assignment Grade is: F
Students Quiz Grade is: F
Students Exam Grade is: D
Students Final Grade is a F

Student 12
Students Lab Grade is: B
Students Assignment Grade is: B
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a B

Student 13
Students Lab Grade is: A
Students Assignment Grade is: D
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a B

Student 14
Students Lab Grade is: B
Students Assignment Grade is: B
Students Quiz Grade is: C
Students Exam Grade is: B
Students Final Grade is a B

Student 15
Students Lab Grade is: B
Students Assignment Grade is: B
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a B

Student 16
Students Lab Grade is: F
Students Assignment Grade is: F
Students Quiz Grade is: F
Students Exam Grade is: B
Students Final Grade is a D

Student 17
Students Lab Grade is: A
Students Assignment Grade is: F
Students Quiz Grade is: F
Students Exam Grade is: B
Students Final Grade is a C

Student 18
Students Lab Grade is: F
Students Assignment Grade is: B
Students Quiz Grade is: B
Students Exam Grade is: C
Students Final Grade is a C

Student 19
Students Lab Grade is: A
Students Assignment Grade is: C
Students Quiz Grade is: C
Students Exam Grade is: B
Students Final Grade is a B

Student 20
Students Lab Grade is: A
Students Assignment Grade is: D
Students Quiz Grade is: B
Students Exam Grade is: B
Students Final Grade is a B

Press any key to continue . . .
*/