#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
void heading();
float calculate_avg(float);
 
int main()
{
	float angela;
	float langston;
	float maya;
	float malcolm;
	float class_avg;
	float std_avg;
	float cls_total;
	float a_total = 0;
	float l_total = 0;
	float may_total = 0;
	float mal_total = 0;

	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file

	heading();
	cout << endl << setw(15) << '\t' << "Angela" << setw(10) << "Langston"
		<< setw(7) << "Maya" << setw(13) << "Malcolm" << setw(14)
		<< "Class Total" << setw(17) << "Class Average" << endl;

	myfile >> angela >> langston >> maya >> malcolm;
	a_total += angela;
	l_total += langston;
	may_total += maya;
	mal_total += malcolm;
	cls_total = angela + langston + maya + malcolm;
	class_avg = calculate_avg(cls_total);
	cout << endl << fixed << showpoint << setprecision(1)
		<<	"Algebra" << '\t' << setw(12) << angela << '\t' << setw(5) << langston
		<< '\t' << setw(7) << maya << '\t' << setw(10) << malcolm << '\t' << setw(8) << cls_total
		<< '\t' << setw(8) << class_avg << endl;

	myfile >> angela >> langston >> maya >> malcolm;
	a_total += angela;
	l_total += langston;
	may_total += maya;
	mal_total += malcolm;
	cls_total = angela + langston + maya + malcolm;
	class_avg = calculate_avg(cls_total);
	cout << endl << fixed << showpoint << setprecision(1)
		<< "CS1" << '\t' << setw(12) << angela << '\t' << setw(5) << langston
		<< '\t' << setw(7) << maya << '\t' << setw(10) << malcolm << '\t' << setw(8) << cls_total
		<< '\t' << setw(8) << class_avg << endl;

	myfile >> angela >> langston >> maya >> malcolm;
	a_total += angela;
	l_total += langston;
	may_total += maya;
	mal_total += malcolm;
	cls_total = angela + langston + maya + malcolm;
	class_avg = calculate_avg(cls_total);
	cout << endl << fixed << showpoint << setprecision(1)
		<< "English" << '\t' << setw(12) << angela << '\t' << setw(5) << langston
		<< '\t' << setw(7) << maya << '\t' << setw(10) << malcolm << '\t' << setw(8) << cls_total
		<< '\t' << setw(8) << class_avg << endl;

	myfile >> angela >> langston >> maya >> malcolm;
	a_total += angela;
	l_total += langston;
	may_total += maya;
	mal_total += malcolm;
	cls_total = angela + langston + maya + malcolm;
	class_avg = calculate_avg(cls_total);
	cout << endl << fixed << showpoint << setprecision(1)
		<< "Science" << '\t' << setw(12) << angela << '\t' << setw(5) << langston
		<< '\t' << setw(7) << maya << '\t' << setw(10) << malcolm << '\t' << setw(8) << cls_total
		<< '\t' << setw(8) << class_avg << endl;

	cout << endl << endl << fixed << showpoint << setprecision(1)
		<< "Average" << '\t' << setw(12);
	std_avg = calculate_avg(a_total);
	cout << std_avg << '\t' << setw(5);
	std_avg = calculate_avg(l_total);
	cout << std_avg << '\t' << setw(7);
	std_avg = calculate_avg(may_total);
	cout << std_avg << '\t' << setw(10);
	std_avg = calculate_avg(mal_total);
	cout << malcolm << '\t' << setw(8) << endl;

}
float calculate_avg(float total)
{
	float average;
	average = total / 4;
	return average;
}
void heading()
{
	string date;
	cout << "What is today's date? (ex: May 1, 2010 = 5/1/10): ";
	cin >> date;
	cout << endl << "DATE " << date << "********************************************************************* Page 1";
	cout << endl << "***********************************SMALL COLLEGE GRADE REPORT**************************";
}
/*
What is today's date? (ex: May 1, 2010 = 5/1/10): 2/9/17

DATE 2/9/17********************************************************************* Page 1
***********************************SMALL COLLEGE GRADE REPORT**************************
Angela  Langston   Maya      Malcolm   Class Total    Class Average

Algebra         64.5     56.7      67.4       90.0         278.6            69.7

CS1             88.6     77.0      55.3       89.4         310.3            77.6

English         91.3     67.4      89.0      100.0         347.7            86.9

Science        100.0     89.4      80.2       91.4         361.0            90.2


Average         86.1     72.6      73.0       91.4
Press any key to continue . . .
*/