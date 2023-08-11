#include<iostream>
using namespace std;
int sum(int num1)
{
	if (num1<10)
	{
		return num1;
	}
	else
	{
		return (num1%10+sum(num1/10));
	}
}
int main()
{
	int num;
	cout << "enter a certain number: ";
	cin >> num;
	cout << sum(num);
	return 0;
}