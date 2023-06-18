#include <iostream>
using namespace std;
void biggestnum(int num1, int num2, int num3);
int main()
{
	int x, y, z;
	cout << "enter the first number: ";
	cin>> x;
	cout << "enter the second number: ";
	cin>> y;
	cout << "enter the third number: ";
	cin >> z;
	biggestnum(x, y, z);
	return 0;
}
void biggestnum(int num1, int num2, int num3)
{
	int biggest, bigger;
	biggest = num1;
	if (biggest < num2)
	{
		biggest = num2;
		if (biggest < num3)
		{
			biggest = num3;
			cout << biggest << num2 << num1;
		}
		else
		{
			if (num1 > num3)
			{
				cout << biggest << num1 << num3;
			}
			else
			{
				cout << biggest << num3 << num1;
			}
		}
	}
	else if(biggest<num3)
	{
		biggest = num3;
		if (num1 > num2)
		{
			cout << biggest << num1 << num2;
		}
		else
		{
			cout << biggest << num2 << num1;
		}
		
	}
	else
	{
		if (num2 > num3)
			cout << biggest << num2 << num3;
		else
		{
			cout << biggest << num3 << num2;
		}
	}
}