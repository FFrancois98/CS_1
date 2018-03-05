#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int get_year();
int get_starting_day();
void print_heading(int);
string read_month_name();
int read_num_days();
int print_month(int, int, string);

ifstream myfile;
int main()
{
	int year, start_date, no_of_days;
	string month;
	myfile.open("infile.txt");
	year = get_year();
	start_date = get_starting_day();
	month = read_month_name();
	while (myfile)
	{
		no_of_days = read_num_days();
		start_date = print_month(start_date, no_of_days, month);
		cout << endl << endl;
		month = read_month_name();
	}
}
int get_year()
{
	int year;
	cout << "Enter the year: " << endl;
	cin >> year;
	return year;
}
int get_starting_day()
{
	int start_date;
	cout << "Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat):"
		<< endl;
	cin >> start_date;
	return start_date;
}
void print_heading(int year)
{
	cout << '\t' << '\t' << "YEAR -- " << year << endl << endl;
}
string read_month_name()
{
	string month;
	myfile >> month;
	return month;
}
int read_num_days()
{
	int num_days;
	myfile >> num_days;
	return num_days;
}
int print_month(int first_day, int no_of_days, string month)
{
	int last_date = first_day;
	cout << '\t' << '\t' << '\t' << month << endl;
	cout << '\t' << "Sun: \tMon: \tTue: \tWed: \tThu: \tFri: \tSat:" << endl;

	for (int i = 1; i <= first_day; i++)
	{
		cout << '\t';
	}
	
	for (int count = 1; count <= no_of_days; count++)
	{
		cout << left << '\t' << count;
		last_date++;
		if ((last_date % 7) == 0)
		{
			cout << endl;
		}
	}
	return last_date % 7;
}

/*
Enter the year:
2010
Enter the start date (0 = Sun, 1 = Mon, 2 = Tues, 3 = Wed, 4 = Thurs, 5 = Fri, 6 = Sat):
3
January
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4
5       6       7       8       9       10      11
12      13      14      15      16      17      18
19      20      21      22      23      24      25
26      27      28      29      30      31

February
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1
2       3       4       5       6       7       8
9       10      11      12      13      14      15
16      17      18      19      20      21      22
23      24      25      26      27      28

March
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1
2       3       4       5       6       7       8
9       10      11      12      13      14      15
16      17      18      19      20      21      22
23      24      25      26      27      28      29
30      31

April
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4       5
6       7       8       9       10      11      12
13      14      15      16      17      18      19
20      21      22      23      24      25      26
27      28      29      30

May
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3
4       5       6       7       8       9       10
11      12      13      14      15      16      17
18      19      20      21      22      23      24
25      26      27      28      29      30      31


June
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4       5       6       7
8       9       10      11      12      13      14
15      16      17      18      19      20      21
22      23      24      25      26      27      28
29      30

July
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4       5
6       7       8       9       10      11      12
13      14      15      16      17      18      19
20      21      22      23      24      25      26
27      28      29      30      31

August
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2
3       4       5       6       7       8       9
10      11      12      13      14      15      16
17      18      19      20      21      22      23
24      25      26      27      28      29      30
31

September
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4       5       6
7       8       9       10      11      12      13
14      15      16      17      18      19      20
21      22      23      24      25      26      27
28      29      30

October
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4
5       6       7       8       9       10      11
12      13      14      15      16      17      18
19      20      21      22      23      24      25
26      27      28      29      30      31

November
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1
2       3       4       5       6       7       8
9       10      11      12      13      14      15
16      17      18      19      20      21      22
23      24      25      26      27      28      29
30

December
Sun:    Mon:    Tue:    Wed:    Thu:    Fri:    Sat:
1       2       3       4       5       6
7       8       9       10      11      12      13
14      15      16      17      18      19      20
21      22      23      24      25      26      27
28      29      30      31

Press any key to continue . . .
*/