#include<iostream>
#include<fstream>
using namespace std;
struct customer
{
	int accountnumber;
	char firstname[10];
	char lastname[15];
	double accountbalance;
}num;
void getdata()
{
	for (int i = 0;i < 5;i++)
	{
		cout << "enter the account number of " << i + 1 << " customer: ";
		cin >> num.accountnumber;
		cout << "enter the first name of " << i + 1 << " customer: ";
		cin >> num.firstname;
		cout << "enter the last name of " << i + 1 << " customer: ";
		cin >> num.lastname;
		cout << "enter the account balance of " << i + 1 << " customer: ";
		cin >> num.accountbalance;
	}
}
void writedata()
{
	fstream filecustomer;
	filecustomer.open("file of customer.dat", ios::in | ios::out | ios::trunc | ios::app | ios::binary);
	if (!filecustomer.is_open())
	{
		cout << "error,unable to open file" << endl;
	}
	getdata;
	filecustomer.write((char*)&num, sizeof(num));
	filecustomer.close();
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		writedata();
	}
	return 0;
}