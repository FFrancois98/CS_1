#include <iomanip>
#include <iostream>
using namespace std;
float get_user_input(); 
float convert_weight(float);
const float conversion_factor  = 2.2;
int main()
{
	float lb_weight;
	float kg_weight;
	lb_weight = get_user_input(); // Get user input of weight
	kg_weight = convert_weight(lb_weight); // Convert weight to kilogram
	cout << fixed << showpoint << "Pounds: " << setprecision(2) << lb_weight // Display the weight
		<< " Kilograms: " << kg_weight << endl;
}
float get_user_input()
{
	float user_in;
	cout << "Enter your weight in pounds: " << endl;
	cin >> user_in;
	return user_in;
}
float convert_weight(float lb_weigh)
{
	return (float)lb_weigh / conversion_factor;
}
/*
Enter your weight in pounds:
250
Pounds: 250.00 Kilograms: 113.64
Press any key to continue . . .
*/