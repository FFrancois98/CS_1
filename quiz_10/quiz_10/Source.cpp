#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void print_students(student_type[]); // prototype

struct Address_type
{
	int street_no;
	string street_name;
	string city;
	string state;
	int zip;
};
struct student_type
{
	string lname;
	string fname;
	int ID;
	float GPA;
	char classification;
	float account_balance;
	Address_type student_address;
};

int main()
{
	ifstream myfile;
	myfile.open("infile.txt");
	student_type students[5];
	for (int i = 0; i < 5; i++)
	{
		myfile >> students[i].lname >> students[i].fname >> students[i].ID
			>> students[i].GPA >> students[i].classification >> students[i].account_balance
			>> students[i].student_address.street_no;
		getline(myfile, students[i].student_address.street_name);
		myfile >> students[i].student_address.city >> students[i].student_address.state
			>> students[i].student_address.zip;
	}

}
void print_students(student_type students[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Student Name" << "\t\t" << "Student ID" << '\t' << "Student GPA" << '\t' << "Student Class"
			<< '\t' << "Account Balance" << '\t' << "Student Address" << endl;
		cout << left << students[i].lname << ", " << students[i].fname << '\t' << students[i].ID;
		cout << left << fixed << showpoint << students[i].GPA << '\t' << students[i].classification << '\t' <<
			setprecision(2) << students[i].account_balance;
		cout << left << '\t' << students[i].student_address.street_no << " " << students[i].student_address.street_name
			<< " " << students[i].student_address.city << " " << students[i].student_address.state << " " <<
			students[i].student_address.zip;
	} 
}