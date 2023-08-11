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
void givedata()
{
	cout << "\n" << num.accountnumber;
	cout << "\n" << num.firstname;
	cout << "\n" << num.lastname;
	cout << "\n" << num.accountbalance;
}
void readata(int accountnumber)
{
	fstream filecustomer;
	filecustomer.open("file of customer.dat", ios::in | ios::out | ios::trunc | ios::app | ios::binary);
	if (!filecustomer.is_open())
	{
		cout << "error,unable to open file" << endl;
	}
	while (!filecustomer.eof())
	{
		if(accountnumber==num.accountnumber)
		{
		givedata();
		break;
		}
		filecustomer.read((char*)&num, sizeof(num));
    }
	filecustomer.close();
}
int main()
{
	int accountnum1;
	cout << "enter your account number: ";
	cin >> accountnum1;
	readata(accountnum1);
	return 0;
}