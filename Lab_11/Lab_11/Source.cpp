#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

enum CarMakeType { Audi, Chrysler, Ford, Nissan, Mercedes, Honda, Volvo, Porsche, Lexus }; //Make enumerated list of cars that company sells.

struct DateType {               //Make a date struct that contains information about day, month, and year.
	int day;                   //Declare struct variables (ALL INT).
	int month;
	int year;
};
struct CarType {               //Make struct that contains information about the customer, delivery date of the car, cost, and car model.
	string fname;             //Declare struct variables.
	string lname;
	float cost;
	DateType date_delivery;
	CarMakeType car_make;
};

CarType Get_Car_data(ifstream&);              //Function Prototypes
void Lookup_Car_data(char, CarType[]);
void Modify_Car_data(float, int, CarType[]);
void Output_car_data(CarType[], ofstream&);
void Print_Car_report(CarType[]);
void Write_Car_Output(CarType[], ofstream&);

int main()
{
	CarType cars[10];
	char car_brand, answer;
	ifstream myfile;
	myfile.open("infile.txt");
	ofstream myfile2;
	myfile2.open("outfile.txt");
	for (int i = 0; i < 10; i++)
	{
		cars[i] = Get_Car_data(myfile);
	}
	do 
	{
		cout << "Choose from the list of car manufacturers below." << endl
			<< "(F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda, " << endl
			<< "A - Audi, C - Chrysler, V - Volvo, P - Porsche)" << endl;
		cout << "Enter the make of the car you wish to discount: ";
		cin >> car_brand;
		Lookup_Car_data(car_brand, cars);
		cout << endl << "Do you want to discount any more cars? (Y/N) ";
		cin >> answer;
		cout << endl;
	} while (answer != 'N');
	Output_car_data(cars, myfile2);
	myfile.close();
	myfile2.close();
	return 0;
}
// Get_Car_data function reads one set of car data from the input file, stores the data in a local CarType struct and returns this struct to main.
CarType Get_Car_data(ifstream& myfile)
{
	CarType car;
	char make_model;
	myfile >> car.fname >> car.lname >> car.cost >> car.date_delivery.day
		>> car.date_delivery.month >> car.date_delivery.year >> make_model;
	switch (make_model)
	{
	case 'A': car.car_make = Audi;
		break;
	case 'F': car.car_make = Ford;
		break;
	case 'L': car.car_make = Lexus;
		break;
	case 'N': car.car_make = Nissan;
		break;
	case 'M': car.car_make = Mercedes;
		break;
	case 'H': car.car_make = Honda;
		break;
	case 'C': car.car_make = Chrysler;
		break;
	case 'V': car.car_make = Volvo;
		break;
	case 'P': car.car_make = Porsche;
		break;
	default:
		break;
	}
	return car;
}
//Lookup_Car_data function should find the first car of this make in the Car array and display the car data to the user and prompt the user for the desired discount.
void Lookup_Car_data(char make_model, CarType cars[])
{	
	float discount_per;
	CarMakeType make;
	string model;
	switch (make_model)
	{
	case 'F': make = Ford;
		break;
	case 'L': make = Lexus;
		break;
	case 'N': make = Nissan;
		break;
	case 'M': make = Mercedes;
		break;
	case 'H': make = Honda;
		break;
	case 'A': make = Audi;
		break;
	case 'C': make = Chrysler;
		break;
	case 'V': make = Volvo;
		break;
	case 'P': make = Porsche;
		break;
	default:
		break;
	}
	for (int i = 0; i < 10; i++)
	{
		if (make == cars[i].car_make)
		{
			cout << "You are modifying: " << endl;
			cout << '\t' << "Customer Name: " << cars[i].fname << " " << cars[i].lname << endl;
			cout << '\t' << "Car Price:      $" << fixed << showpoint << setprecision(2) << cars[i].cost << endl;
			cout << '\t' << "Purchase Date: " << cars[i].date_delivery.day << "/" << cars[i].date_delivery.month << "/" << cars[i].date_delivery.year << endl;
			switch (cars[i].car_make)
			{
			case Audi: model = "Audi";
				break;
			case Ford: model = "Ford";
				break;
			case Lexus: model = "Lexus";
				break;
			case Nissan: model = "Nissan";
				break;
			case Mercedes: model = "Mercedes";
				break;
			case Honda: model = "Honda";
				break;
			case Chrysler: model = "Chrysler";
				break;
			case Volvo: model = "Volvo";
				break;
			case Porsche: model = "Porsche";
				break;
			default:
				break;
			}
			cout << '\t' << "Car Model:     " << model << endl;
			cout << "Enter the discount (e.g. 0.10 = 10%): ";
			cin >> discount_per;
			Modify_Car_data(discount_per, i, cars);
			break;
		}

	}

	
}
//Modify_Car_data function should apply the discount to the price data member of the Car struct in the Car array for the selected car as indicated by the Car index parameter
void Modify_Car_data(float discount, int car_index, CarType car[])
{
	cout << endl;
	cout << "Old Price: $" << car[car_index].cost << endl;
	cout << "New Price: $" << (car[car_index].cost - (car[car_index].cost * discount)) << endl;
	cout << (discount * 100) << "% Discount has been applied" << endl;
	cout << endl;
	car[car_index].cost = (car[car_index].cost - (car[car_index].cost * discount));
}
//Output_car_data function should call the Print_Car_Report function with the Car array
void Output_car_data(CarType car[], ofstream& myfile2)
{
	Print_Car_report(car);
	Write_Car_Output(car, myfile2);
}
//Write_Car_output function loops through the data in the Car array and outputs the car data to lines of the output file.
void Write_Car_Output(CarType cars[], ofstream& myfile2)
{
	for (int i = 0; i < 10; i++)
	{
		string model;
		switch (cars[i].car_make)
		{
		case Audi: model = "Audi";
			break;
		case Ford: model = "Ford";
			break;
		case Lexus: model = "Lexus";
			break;
		case Nissan: model = "Nissan";
			break;
		case Mercedes: model = "Mercedes";
			break;
		case Honda: model = "Honda";
			break;
		case Chrysler: model = "Chrysler";
			break;
		case Volvo: model = "Volvo";
			break;
		case Porsche: model = "Porsche";
			break;
		default:
			break;
		}
		myfile2 << cars[i].fname << " " << cars[i].lname << '\t' << fixed << showpoint << setprecision(2) << cars[i].cost
			<< '\t' << cars[i].date_delivery.day << "/" << cars[i].date_delivery.month << "/" << cars[i].date_delivery.year
			<< '\t' << model << endl;
	}
}
//Print_Car_Report function prints a heading and then loops through the data in the Car array and displays the car data to lines of the console window.
void Print_Car_report(CarType cars[])
{
	cout << "Customer Name" << '\t' << "Price" << '\t' << '\t' << "Purchase Date" << '\t' << "Model" << endl;
	for (int i = 0; i < 10; i++)
	{
		string model;
		switch (cars[i].car_make)
		{
		case Audi: model = "Audi";
			break;
		case Ford: model = "Ford";
			break;
		case Lexus: model = "Lexus";
			break;
		case Nissan: model = "Nissan";
			break;
		case Mercedes: model = "Mercedes";
			break;
		case Honda: model = "Honda";
			break;
		case Chrysler: model = "Chrysler";
			break;
		case Volvo: model = "Volvo";
			break;
		case Porsche: model = "Porsche";
			break;
		default:
			break;
		}
		cout << cars[i].fname << " " << cars[i].lname << '\t' << fixed << showpoint << setprecision(2) << cars[i].cost
			<< '\t' << cars[i].date_delivery.day << "/" << cars[i].date_delivery.month << "/" << cars[i].date_delivery.year
			<< '\t' << model << endl;
	}
}
 /*
 Choose from the list of car manufacturers below.
 (F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda,
 A - Audi, C - Chrysler, V - Volvo, P - Porsche)
 Enter the make of the car you wish to discount: F
 You are modifying:
 Customer Name: Tiny Tim
 Car Price:      $55000.00
 Purchase Date: 1/1/1985
 Car Model:     Ford
 Enter the discount (e.g. 0.10 = 10%): .10

 Old Price: $55000.00
 New Price: $49500.00
 10.00% Discount has been applied


 Do you want to discount any more cars? (Y/N) Y

 Choose from the list of car manufacturers below.
 (F - Ford, L - Lexus, N - Nissan, M - Mercedes, H - Honda,
 A - Audi, C - Chrysler, V - Volvo, P - Porsche)
 Enter the make of the car you wish to discount: L
 You are modifying:
 Customer Name: Bear Bare
 Car Price:      $44444.00
 Purchase Date: 9/6/1990
 Car Model:     Lexus
 Enter the discount (e.g. 0.10 = 10%): .20

 Old Price: $44444.00
 New Price: $35555.20
 20.00% Discount has been applied


 Do you want to discount any more cars? (Y/N) N

 Customer Name   Price           Purchase Date   Model
 Tiny Tim        49500.00        1/1/1985        Ford
 Mary Murphy     12500.00        2/7/1995        Nissan
 Bear Bare       35555.20        9/6/1990        Lexus
 Sally Sale      7500.00 6/3/1970        Mercedes
 Betty Bye       18888.00        4/8/1988        Chrysler
 Alice Alas      23005.00        6/6/1992        Ford
 Randy Law       12098.00        1/4/2009        Audi
 Carl Lane       45000.00        12/3/2003       Porsche
 Janis Smith     23450.00        7/11/2001       Volvo
 George Lee      14560.00        4/4/1999        Honda
 Press any key to continue . . .
 */