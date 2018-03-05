#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void GetStoreData(string[], float[][5], ifstream&);
float ComputeSalesTotal(int, float[][5]);
void DisplayStoreData(string[], float[][5], float[]);

const int MAX_ROWS = 7;
const int MAX_COLUMNS = 5;

int main()
{
	string store_names[7];
	float sales[7][5], store_totals[7];
	ifstream myfile;
	myfile.open("infile.txt");
	GetStoreData(store_names, sales, myfile);
	for (int i = 0; i < 7; i++)
	{
		store_totals[i] = ComputeSalesTotal(i, sales);
	}
	DisplayStoreData(store_names, sales, store_totals);
}
//In the Get_store_data function, you must use a nested loop to read and store the data into the array of store names and into the two-dimensional store sales array.
void GetStoreData(string store_names[], float sales[][5], ifstream& myfile)
{
	for (int i = 0; i < 7; i++)
	{
		myfile >> store_names[i];
		for (int j = 0; j < 5; j++)
		{
			myfile >> sales[i][j];
		}
	}
}
//In the Compute_sales_total function, the store index is used to read the sales figures in the indicated row of the sales array. Using a for statement, this function should total the sales amounts and return this total to main.
float ComputeSalesTotal(int store_index, float sales[][5])
{
	float total = 0;
	for (int i = 0; i < 5; i++)
	{
		total += sales[store_index][i];
	}
	return total;
}
//Display_Store_Data function send it the store sales array, the store names array, and the store totals array. This function simply prints a heading and then, using a counter-controlled loop, print the corresponding data from each array 
void DisplayStoreData(string store_names[], float sales[][5], float store_totals[])
{
	cout << "   Store Name" << '\t' << "Jan" << '\t' << "Feb" << '\t' << "Mar"
		<< '\t' << "Apr" << '\t' << "May" << '\t' << "TOTAL" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << store_names[i] << left << '\t';
		for (int j = 0; j < 5; j++)
		{
			cout << fixed << showpoint << setprecision (2) << left << sales[i][j] << '\t';
		}
		cout << fixed << showpoint << setprecision(2) << left << store_totals[i] << endl;
	}
}
/*
Store Name   Jan     Feb     Mar     Apr     May     TOTAL
Takoma_store    2.70    71.30   14.70   23.90   51.20   163.80
Bethesda_store  12.70   8.90    17.80   7.90    18.30   65.60
Triangle_store  2.40    73.00   14.90   23.10   51.40   164.80
Calmday_store   12.70   8.10    19.80   27.90   8.30    76.80
Vincent_store   6.70    74.30   19.70   21.90   50.20   172.80
Ivy_store       1.70    3.00    67.80   97.90   38.30   208.70
Pierre_store    45.70   31.30   84.70   49.90   73.20   284.80
Press any key to continue . . .
*/
