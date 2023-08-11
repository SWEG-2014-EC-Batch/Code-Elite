#include<iostream>
using namespace std;
struct phone
{
	int areacode, exchange, number;
};
int main()
{
	phone area = { 213,767,8900 }, code;
	cout << "enter the area code for a phone number: ";
	cin >> code.areacode;
	cout << "enter the exchange for a phone number: ";
	cin >> code.exchange;
	cout << "enter the number for a phone number: ";
	cin >> code.number;
	cout << "The new phone number is: " << code.areacode << "-" << code.exchange << "-" << code.number;
	return 0;
}