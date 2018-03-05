#include <iostream> 
#include <iomanip>
#include <fstream>
using namespace std;

void get_user_input(char&, int&, int&, int&, int&); // declare prototype
float compute_item_cost(char, int, int, int, int);
int main()
{
	int pieces, width, height, length; // declare variables
	float price, total;
	total = 0;
	char type;
	get_user_input(type, pieces, width, height, length); // get user data
	while (type != 'T') // repeat following steps
	{
		price = compute_item_cost(type, pieces, width, height, length); // compute price
		if (type == 'P') // display price
		{
			cout << fixed << showpoint << setprecision(2) << pieces << " " << width << "X" << height << "X" << length << " Pine, cost: $" << price << endl;
			cout << "*****************************************************************************************************************" << endl;
		}
		else if (type == 'F')
		{
			cout << fixed << showpoint << setprecision(2) << pieces << " " << width << "X" << height << "X" << length << " Fir, cost: $" << price << endl;
			cout << "*****************************************************************************************************************" << endl;
		}
		else if (type == 'C')
		{
			cout << fixed << showpoint << setprecision(2) << pieces << " " << width << "X" << height << "X" << length << " Cedar, cost: $" << price << endl;
			cout << "*****************************************************************************************************************" << endl;
		}
		else if (type == 'M')
		{
			cout << fixed << showpoint << setprecision(2) << pieces << " " << width << "X" << height << "X" << length << " Maple, cost: $" << price << endl;
			cout << "*****************************************************************************************************************" << endl;
		}
		else if (type == 'O')
		{
			cout << fixed << showpoint << setprecision(2) << pieces << " " << width << "X" << height << "X" << length << " Oak, cost: $" << price << endl;
			cout << "*****************************************************************************************************************" << endl;
		}
		total += price; // add to total
		get_user_input(type, pieces, width, height, length); // get user data
	}
	cout << "Total Cost: $" << fixed << showpoint << setprecision(2) << total << endl; // display total price
	return 0;
}
void get_user_input(char& type, int& pieces, int& width, int& height, int& length)
{
	cout << "Enter item ( Wood Type --- No of Pieces --- Width --- Height --- Length)" << endl;
	cin >> type;
	if (type != 'T')
	{
		cin >> pieces >> width >> height >> length;
	}
}
float compute_item_cost(char type, int pieces, int width, int height, int length)
{
	float board_feet = (float)(width * height * length) / 12;
	float price;
	if (type == 'P')
	{
		price = (float)pieces * board_feet * 0.89;
	}
	else if (type == 'F')
	{
		price = (float)pieces * board_feet * 1.09;
	}
	else if (type == 'C')
	{
		price = (float)pieces * board_feet * 2.26;
	}
	else if (type == 'M')
	{
		price = (float)pieces * board_feet * 4.50;
	}
	else if (type == 'O')
	{
		price = (float)pieces * board_feet * 3.10;
	}
	return price;
}
/*
Enter item ( Wood Type --- No of Pieces --- Width --- Height --- Length)
P 10 2 4 8
10 2X4X8 Pine, cost: $47.47
*****************************************************************************************************************
Enter item ( Wood Type --- No of Pieces --- Width --- Height --- Length)
M 1 1 12 8
1 1X12X8 Maple, cost: $36.00
*****************************************************************************************************************
Enter item ( Wood Type --- No of Pieces --- Width --- Height --- Length)
T
Total Cost: $83.47
Press any key to continue . . .
*/