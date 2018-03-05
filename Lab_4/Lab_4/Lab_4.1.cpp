#include <iostream>                        // include input/output library code
#include <string>                          // include string manipulate library code
using namespace std;                       // allows all of the names in a namespace 
										   // to be accessed without the namespace 
										   // identifier as a qualifier

int main()
{
	string myname;                     // 1.  declare variable to store my name 
	cout << "Enter your name ";        // 2.  prompt the user for their name
	cin >> myname;                     // 3.  get name from user
	cout << "Hello " + myname << endl; // 4.  output message
	return 0;                          // return program completed OK to
									   // the operating system
}

/*

Enter your name Francois
Hello Francois
Press any key to continue . . .

*/