#include <iostream> 
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
float compute_gross_pay(float, float, char);
float compute_taxes(float);
float compute_fed_tax(float);
float compute_state_tax(float);
float compute_city_tax(float);
float compute_net_pay(float, float);
void print_pay_check(string, string, string, string, string, string, string, string, float, float, float);

int main()
{
	float pay_rate, gross_pay, total_tax, net_pay;
	int deductions, id_num, counter;
	char part_fulltime;
	string first_name, last_name, house_num, street_name, street_type;
	string city, state, zip;
	ifstream myfile; //Declare file input object 
	myfile.open("infile.txt"); //Open file
	counter = 0;
	while (myfile)
	{
		myfile >> last_name >> first_name >> deductions >> id_num >> house_num >> street_name >> street_type >> city >> state
			>> zip >> pay_rate >> part_fulltime;
		gross_pay = compute_gross_pay(pay_rate, deductions, part_fulltime);
		total_tax = compute_taxes(gross_pay);
		net_pay = compute_net_pay(gross_pay, total_tax);
		print_pay_check(house_num, street_name, street_type, city, state, zip, first_name, last_name, gross_pay, net_pay, total_tax);
		counter += 1;
	}
	
}
void print_pay_check(string h_num, string s_name, string s_type, string city, string state, string zip, string f_name, string l_name, float g_p, float n_pay, float t_tax)
{
	cout << "******************************************************************************" << endl;
	cout << fixed << showpoint << setprecision(2) << "ABC Flower" << '\t' << '\t' << "2/23/2017" << endl << "123 Georgia Ave" << endl
		<< "Washington, DC 20059" << endl <<
		"Payable to: " << l_name << " " << f_name << '\t' << "Pay this amount: $" <<
		n_pay << endl;
	cout << '\t' << h_num << " " << s_name << " " << s_type <<
		endl << '\t' << city << " " << state << " " << zip << endl;
	cout << fixed << showpoint << setprecision(2) << endl << "Gross Pay  $" << g_p << endl << "Total Taxes  $" << t_tax << endl;
}
float compute_gross_pay(float rate, float deduct, char p_f)
{
	float g_p = rate * 40;
	if (p_f == 'P')
	{
		g_p += (float)deduct * 10.50;
	}
	return g_p;
}
float compute_taxes(float g_p)
{
	float t_tax;
	float f_tax = compute_fed_tax(g_p);
	float s_tax = compute_state_tax(f_tax);
	float c_tax = compute_city_tax(s_tax);
	t_tax = f_tax + c_tax + s_tax;
	return t_tax;
}
float compute_fed_tax(float g_p)
{
	float f_tax;
	if (g_p <= 200)
	{
		f_tax = g_p * 0.10;
	}
	else if (g_p <= 500)
	{
		f_tax = (200 * 0.10) + ((g_p - 200) * 0.20);
	}
	else 
	{
		f_tax = ((200 * 0.10) + (300 * 0.20) + ((g_p - 500) * 0.30));
	}
	return f_tax;
}
float compute_state_tax(float f_tax)
{
	float s_tax;
	if (f_tax < 80)
	{
		s_tax = 0;
	}
	else
	{
		s_tax = f_tax * 0.10;
	}
	return s_tax;
}
float compute_city_tax(float s_tax)
{
	float c_tax;
	if (s_tax <= 50)
	{
		c_tax = 0;
	}
	else
	{
		c_tax = s_tax * 0.08;
	}
	return c_tax;
}
float compute_net_pay(float g_p, float t_tax)
{
	float n_pay = g_p - t_tax;
	return n_pay;
}
/*
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: Herold, Will        Pay this amount: $201.44
123 Main St.
Washington, DC 20019

Gross Pay  $226.80
Total Taxes  $25.36
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: Jackson, Stan       Pay this amount: $373.60
12 Douglas Ave.
Baltimore, MD 30220

Gross Pay  $442.00
Total Taxes  $68.40
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: Jerry, Francis      Pay this amount: $727.91
2345 6th Street
Woodbridge, VA 44040

Gross Pay  $971.50
Total Taxes  $243.60
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: John, Wilson        Pay this amount: $352.80
12 Georgia Ave.
Washington, DC 20019

Gross Pay  $416.00
Total Taxes  $63.20
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: Smith, Stanley      Pay this amount: $446.17
56 D Street
Baltimore, MD 30229

Gross Pay  $551.00
Total Taxes  $104.83
******************************************************************************
ABC Flower              2/23/2017
123 Georgia Ave
Washington, DC 20059
Payable to: Jeffers, Claude     Pay this amount: $1203.40
66 32nd Street
Woodbridge, VA 44049

Gross Pay  $1681.20
Total Taxes  $477.80
Press any key to continue . . .
*/