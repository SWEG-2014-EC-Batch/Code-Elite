#include<iostream>
using namespace std;
struct stock
{
	string name;
	double estiearn;
	double estipriratio;
}s[5];
double stockprice(double earn1,double ratio1)
{
	return earn1 * ratio1;
}
int main()
{
	for (int i = 0;i < 5;i++)
	{
		cout << "enter the stock name: " << endl;
		cin >> s[i].name;
		cout << "enter the estimated earning of the stock: ";
		cin >> s[i].estiearn;
		cout << "enter the estimated price to earning ratio: ";
		cin >> s[i].estipriratio;
		cout <<"The stock price of the stock "<<s[i].name<<" is: " << stockprice(s[i].estiearn, s[i].estipriratio);
	}
	return 0;
}
	