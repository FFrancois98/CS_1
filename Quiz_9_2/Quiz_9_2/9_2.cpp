#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void drawTri(char, int);
int main()
{
	int row, col; // declare variables
	char aster = '*';
	ifstream myfile;
	myfile.open("infile.txt"); // open file for streaming
	myfile >> row; // priming read
	while (myfile)
	{
		drawTri(aster, row); // displays the triangle
		myfile >> row;
	}
	myfile.close(); // closes the file
	return 0;
}

void drawTri(char aster, int row)
{
	int RW, CL;
	RW = 1;
	CL = 0;
	while (RW <= row)
	{
		while (CL < RW)
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
*
* *
* * *
* * * *
*
* *
* * *
*
* *
* * *
* * * *
* * * * *
* * * * * *
* * * * * * *
Press any key to continue . . .
*/