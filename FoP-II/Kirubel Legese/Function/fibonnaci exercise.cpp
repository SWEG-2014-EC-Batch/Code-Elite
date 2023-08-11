#include<iostream>
using namespace std;
int fibonacci(int n1)
{
	if (n1 == 0 || n1 == 1)
	{
		return n1;
	}
	else
	{
		return(fibonacci(n1-1) + fibonacci(n1 - 2));
	}
}
int main()
{
	int n;
	cout << "enter n,that get nth fibonacci number: ";
	cin >> n;
	cout << fibonacci(n);
	return 0;
}