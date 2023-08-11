#include<iostream>
using namespace std;
struct info
{
	struct phone
	{
		int areacode;
		int exchange;
		int number;
	}p1;
	struct name
	{
		string name1;
	}n1;
};
int main()
{
	info n[10];
	for (int i = 0;i < 2;i++)
	{
		cout << "enter the name of the person: ";
		cin >> n[i].n1.name1;
		cout << "enter the area code number of the phone number: ";
		cin >> n[i].p1.areacode;
		cout << "enter the exchange number of the phone number: ";
		cin >> n[i].p1.exchange;
		cout << "enter the code number of the phone number: ";
		cin >> n[i].p1.number;
	}
	for (int i = 0;i < 2;i++)
	{
		cout << n[i].n1.name1 << endl;
		cout << "(" << n[i].p1.areacode << ")" << n[i].p1.exchange << "-" << n[i].p1.number << endl;
	}
	return 0;
}