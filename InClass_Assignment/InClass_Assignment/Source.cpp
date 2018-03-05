#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void drawBox(char, int, int);
int main()
{
	int row, col; // delcare the variable
	char aster = '*';
	ifstream myfile;
	myfile.open("infile.txt"); // open the file for streaming
	myfile >> row >> col; // the priming read
	while (myfile)
	{
		drawBox(aster, row, col); // displays the box
		myfile >> row >> col;
	}
	myfile.close(); // closes the streaming file
	return 0;
}
void drawBox(char aster, int row, int col)
{
	int RW, CL;
	RW = 0;
	CL = 0;
	while (RW < row)
	{
		while (CL < col)
		{
			cout << aster << ' ';
			CL++;
		}
		CL = 0;
		RW++;
		cout << endl;
	}
}
/*
* * * *
* * * *
* * * *
* * * *
* * * * *
* * * * *
* * * * *
* * * *
* * * *
* * * *
* * * *
* * * *
* * * *
* * * *
Press any key to continue . . .
*/