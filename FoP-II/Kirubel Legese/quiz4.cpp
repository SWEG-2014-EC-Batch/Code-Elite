#include<iostream>
#include<cmath>
using namespace std;
bool prime(int num1);
void message(int num1);
int main()
{
	int x;
	cout << "enter a certain number: ";
	cin >> x;
	cout << prime(x) << endl;
	message(x);
	return 0;
}
bool prime(int num1)
{
	if (num1 > 1 && num1 < 1000)
	{
		int root;
		root = (int)sqrt(num1);
		for (int i = 2; i <= root; i++)
		{
			if (num1 / i == 0)
			{
				return false;
				break;
			}
			else
			{
				return true;
			}
		}
	}
}void message(int num1)
{
	if (prime(num1))
	{
		cout << num1 << " is not a prime number";
	}
	else
	{
		cout << num1 << " is a prime number";
	}
}
