#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
double sum(double num1, double num2);
int main()
{
	double x, y;
	cout << "enter the first number: ";
	cin >> x;
	cout << "enter the second number: ";
	cin >> y;
	cout << "The sum of the numbers is " << sum(x, y);
	return 0;
}
double sum(double num1, double num2)
{
	double cube, square, answer;
	cube = pow(num1, 3);
	square = sqrt(num2);
	answer = cube + square;
	return answer;
}
