
#include <iostream>
#include <iostream>
using namespace std;

int fibo(int num);

int main()
{ 
	start:
	int n;
	cout << "\nenter the length\n";
	cin >> n;
	cout<<fibo(n);
	goto start;
}
int fibo(int num) {
	int sum;
	if (num == 0 || num == 1) {
		return num;
	}
	else {
		sum = fibo(num - 1) + fibo(num - 2);
		return sum;
	}
	//if (num == 0);
	//return 
}