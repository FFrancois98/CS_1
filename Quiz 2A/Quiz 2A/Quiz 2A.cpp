#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

float get_vehicle_price(string);
float calculate_other_costs(float);
float calculate_sales_tax(float);
float calculate_registration_fee(float);
void display_total_car_cost(string, float, float);
void heading();


int main()
{
	string make_model1;
	string make_model2;
	string make_model3;
	string make_model4;
	float price1;
	float price2;
	float price3;
	float price4;
	long double other_costs;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt");//Open file
	getline(myfile, make_model1); //1. Get vehicle make and model
	price1 = get_vehicle_price(make_model1); // 2. Get current price of vehicle.
	getline(myfile, make_model2); //1. Get vehicle make and model
	price2 = get_vehicle_price(make_model2); // 2. Get current price of vehicle.
	getline(myfile, make_model3); // 1. Get vehicle make and model
	price3 = get_vehicle_price(make_model3); // 2. Get current price of vehicle.
	getline(myfile, make_model4); // 1. Get vehicle make and model
	price4 = get_vehicle_price(make_model4); // 2. Get current price of vehicle.
	heading();
	cout << endl << "                  Howard University Used Car Company" << endl;
	cout << endl <<"          make_model      Price     Other Costs   Total Cost" << endl << endl;

	other_costs = calculate_other_costs(price1); // 3. Calculate other costs of the vehicle.
	display_total_car_cost(make_model1, price1, other_costs); // 4. Display total car cost

	other_costs = calculate_other_costs(price2); // 3. Calculate other costs of the vehicle.
	display_total_car_cost(make_model2, price2, other_costs); // 4. Display total car cost

	other_costs = calculate_other_costs(price3); // 3. Calculate other costs of the vehicle.
	display_total_car_cost(make_model3, price3, other_costs); // 4. Display total car cost

	other_costs = calculate_other_costs(price4); // 3. Calculate other costs of the vehicle.
	display_total_car_cost(make_model4, price4, other_costs); // 4. Display total car cost
}

float get_vehicle_price(string make_model)
{
	float price;
	cout << "Enter the price of the " << make_model << ": ";
	cin >> price;
	return price;
}
float calculate_other_costs(float price)
{
	float other_costs;
	float sales_tax = calculate_sales_tax(price);
	float registration_fee = calculate_registration_fee(price);
	other_costs = sales_tax + registration_fee;
	return other_costs;

}
float calculate_sales_tax(float price)
{
	float sales_tax;
	sales_tax = price * 0.06;
	return sales_tax;
}
float calculate_registration_fee(float price)
{
	float registration_fee;
	float administrative_fee = 240.0;
	float cost_of_tags = 120.0;
	registration_fee = (price * 0.10) + administrative_fee + cost_of_tags;
	return registration_fee;
}
void display_total_car_cost(string make_model, float price, float other_costs)
{
	float total_cost;
	total_cost = price + other_costs;
	cout << fixed << showpoint << setw(16) << make_model << '\t' 
		<< setprecision(2) << price << setprecision(2) << setw(12) <<
		other_costs << setprecision(2) << setw(16) << total_cost << setprecision(2) << endl;


}
void heading()
{
	cout << "******************************************************************" << endl;
	cout << "Fleurevca Francois" << endl;
	cout << "@02818122" << endl;
	cout << "February 8, 2017" << endl;
	cout << "Quiz 2A" << endl;
	cout << "SYCS-135 Computer Science 1" << endl;
	cout << "******************************************************************" << endl;
}

/*

Enter the price of the Ford Mustang: 45679.00
Enter the price of the Mercedes S550: 95793.00
Enter the price of the Lexus RL: 76521.00
Enter the price of the Audi Q7: 59459.00
******************************************************************
Fleurevca Francois
@02818122
February 8, 2017
Quiz 2A
SYCS-135 Computer Science 1
******************************************************************

Howard University Used Car Company

make_model      Price     Other Costs   Total Cost

Ford Mustang        45679.00     7668.64        53347.64
Mercedes S550        95793.00    15686.88       111479.88
Lexus RL        76521.00    12603.36        89124.36
Audi Q7        59459.00     9873.44        69332.44
Press any key to continue . . .

*/