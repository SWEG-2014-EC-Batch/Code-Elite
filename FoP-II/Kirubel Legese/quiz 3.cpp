#include<iostream>
#include<cmath>
using namespace std;
double hypotenuse(double side1, double side2);
int main()
{
	double a, b;
	cout << "enter the length of the first side: ";
	cin >> a;
	cout << "enter the length of the second side: ";
	cin >> b;
	cout << "The length of the hypotense is: " << hypotenuse(a, b);
	return 0;
}
double hypotenuse(double side1, double side2)
{
	double hyposqr, hypo1, hypo;
	hyposqr = pow(side1, 2) + pow(side2, 2);
	hypo1 = sqrt(hyposqr);
	hypo = double(hypo1);
	return hypo;
}

