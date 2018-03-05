#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void evaluate_cholesterol(int, int, string&, string&); // declare prototypes
void evaluate_blood_pressure(int, int, string&, string&);
float compute_ratio(int, int);

int main()
{
	int HDL_R, LDL_R, SYS_R, DIA_R, num_pat, readings; // delcare variables
	float ratio;
	string HDL_E, LDL_E, SYS_E, DIA_E, name;
	char patient_type;
	ifstream myfile; 
	myfile.open("infile.txt"); // open file for streaming
	cout << "Enter the number of the patient records: "; // prompt user of number of patients
	cin >> num_pat; // read in number of patients
	for (int i = 0; i < num_pat; i++)
	{
		myfile >> name >> patient_type >> readings; // read in patient info
		cout << endl << endl << "Current Patient's Name - " << name << endl << endl; //display patient name
		for (int j = 0; j < readings; j++)
		{
			myfile >> HDL_R >> LDL_R >> SYS_R >> DIA_R; // read in patient health numbers
			evaluate_cholesterol(HDL_R, LDL_R, HDL_E, LDL_E); // get cholesterol evaluation
			evaluate_blood_pressure(SYS_R, DIA_R, SYS_E, DIA_E); // get blood pressure evaluation
			ratio = compute_ratio(HDL_R, LDL_R); // calculate ratio of HDL to LDL
			cout << "DATA SET " << j + 1 << endl; // display patient health numbers info
			cout << "Cholesterol Profile" << endl;
			cout << " HDL: " << HDL_R << " LDL: " << LDL_R << endl;
			cout << fixed << showpoint << setprecision(4) << " Ratio: " << ratio << endl;
			cout << " HDL is " << HDL_E << endl;
			cout << " LDL is " << LDL_E << endl;
			if (ratio > 0.3)
				cout << " Ratio of HDL to LDL is good" << endl;
			else
				cout << " Ratio of HDL to LDL is not good" << endl;
			cout << "Blood Pressure Profile" << endl;
			cout << " Systolic: " << SYS_R << " Diastolic: " << DIA_R << endl;
			cout << " Systolic reading is " << SYS_E << endl;
			cout << " Diastolic reading is " << DIA_E << endl << endl;
		}
	}

}
void evaluate_cholesterol(int HDL_R, int LDL_R, string& HDL_E, string& LDL_E)
{
	if (HDL_R < 40)
		HDL_E = "Too low";
	else if (HDL_R >= 40 && HDL_R < 60)
		HDL_E = "Is okay";	
	else
		HDL_E = "Excellent";
	
	if (LDL_R < 100)
		LDL_E = "Optimal";
	else if (LDL_R >= 100 && LDL_R < 130)
		LDL_E = "Near Optimal";
	else if (LDL_R >= 130 && LDL_R < 160)
		LDL_E = "Borderline high";
	else if (LDL_R >= 160 && LDL_R < 190)
		LDL_E = "High";
	else
		LDL_E = "Very high";
}
void evaluate_blood_pressure(int SYS_R, int DIA_R, string& SYS_E, string& DIA_E)
{
	if (SYS_R < 120)
		SYS_E = "Optimal";
	else if (SYS_R < 130)
		SYS_E = "Normal";
	else if (SYS_R < 140)
		SYS_E = "Normal high";
	else if (SYS_R < 160)
		SYS_E = "Stage 1 hypertension";
	else if (SYS_R < 180)
		SYS_E = "Stage 2 hypertension";
	else
		SYS_E = "Stage 3 hypertension";

	if (DIA_R < 80)
		DIA_E = "Optimal";
	else if (DIA_R < 85)
		DIA_E = "Normal";
	else if (DIA_R < 90)
		DIA_E = "High normal";
	else if (DIA_R < 100)
		DIA_E = "Stage 1 hypertension";
	else if (DIA_R < 110)
		DIA_E = "Stage 2 hypertension";
	else
		DIA_E = "Stage 3 hypertension";
}
float compute_ratio(int HDL_R, int LDL_R)
{
	return (float)HDL_R / LDL_R;
}
/*
Enter the number of the patient records: 3


Current Patient's Name - Jones

DATA SET 1
Cholesterol Profile
HDL: 60 LDL: 124
Ratio: 0.4839
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 130 Diastolic: 84
Systolic reading is Normal high
Diastolic reading is Normal

DATA SET 2
Cholesterol Profile
HDL: 65 LDL: 121
Ratio: 0.5372
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 133 Diastolic: 80
Systolic reading is Normal high
Diastolic reading is Normal

DATA SET 3
Cholesterol Profile
HDL: 70 LDL: 120
Ratio: 0.5833
HDL is Excellent
LDL is Near Optimal
Ratio of HDL to LDL is good
Blood Pressure Profile
Systolic: 130 Diastolic: 81
Systolic reading is Normal high
Diastolic reading is Normal



Current Patient's Name - Smith

DATA SET 1
Cholesterol Profile
HDL: 30 LDL: 195
Ratio: 0.1538
HDL is Too low
LDL is Very high
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 120 Diastolic: 85
Systolic reading is Normal
Diastolic reading is High normal



Current Patient's Name - Williams

DATA SET 1
Cholesterol Profile
HDL: 45 LDL: 185
Ratio: 0.2432
HDL is Is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 190 Diastolic: 112
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension

DATA SET 2
Cholesterol Profile
HDL: 50 LDL: 181
Ratio: 0.2762
HDL is Is okay
LDL is High
Ratio of HDL to LDL is not good
Blood Pressure Profile
Systolic: 193 Diastolic: 115
Systolic reading is Stage 3 hypertension
Diastolic reading is Stage 3 hypertension

Press any key to continue . . .
*/