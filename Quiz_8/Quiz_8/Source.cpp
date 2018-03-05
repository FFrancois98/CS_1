#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void look_up(ifstream&, string&, string&);
int main()
{
	string phone_num, full_name; // used to store last name and phone number
	char answer;
	ifstream myfile;
	do
	{
		look_up(myfile, phone_num, full_name);
		cout << "This is " << full_name << "\'s phone number: " << phone_num << endl;
		cout << "Would you like to search another name? (Y/N)  ";
		cin >> answer;
	} while (answer != 'N');
}
void look_up(ifstream& myfile, string& phone_num, string& full_name) 
{
	string first, last, fname, lname;
	myfile.open("infile.txt");
	cout << "Enter last name: " << endl;
	cin >> lname;
	cout << "Enter first name: " << endl;
	cin >> fname;
	for (int i = 0; i < 14; i++)
	{
		myfile >> first >> last >> phone_num;
		full_name = first + ' ' + last;
		if (lname == last && fname == first)
		{
			break;
		}
	}
	myfile.close();
}
/*
Enter last name:
Keeling
Enter first name:
Harry
This is Harry Keeling's phone number: (202)806-4830
Would you like to search another name? (Y/N)  Y
Enter last name:
Shurn
Enter first name:
Todd
This is Todd Shurn's phone number: (410)560-8909
Would you like to search another name? (Y/N)  Y
Enter last name:
Paul
Enter first name:
Arthur
This is Arthur Paul's phone number: (202)865-9090
Would you like to search another name? (Y/N)  N
Press any key to continue . . .
*/