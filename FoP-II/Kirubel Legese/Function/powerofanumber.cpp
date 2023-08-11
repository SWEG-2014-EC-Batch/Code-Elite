#include<iostream>
using namespace std;
double exponential(int num1, int power1)
{
	if (power1 == 0)
	{
		return 1;
	}
	else if (power1 == 1)
	{
		return num1;
	}
	else
	{
		return (num1 * exponential(num1, power1 - 1));
	}

}
int main()
{
	int power, num;
	cout << "enter the number to be calculated: ";
	cin >> num;
	cout << "enter the power that the number is raised for: ";
	cin >> power;
	cout << exponential(num, power);
	return 0;
}