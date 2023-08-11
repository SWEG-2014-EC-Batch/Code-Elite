#include<iostream>
#include<math.h>
using namespace std;
struct complex
{
	double real;
	double imagine;
}c[2];
complex c1;
void add(complex c[],int size)
{
	c1.real = c[0].real + c[1].real;
	c1.imagine = c[0].imagine + c[1].imagine;
	cout << "The new complex number is: " << c1.real << "+" << c1.imagine<<"i";
}
void subtract(complex c[], int size)
{
	c1.real = c[0].real - c[1].real;
	c1.imagine = c[0].imagine - c[1].imagine;
	cout << "The new complex number is: " << c1.real << "+" << c1.imagine << "i";
}
void multiply(complex c[], int size)
{
	c1.real = (c[0].real * c[1].real) - (c[0].imagine * c[1].imagine);
	c1.imagine = (c[0].real * c[1].imagine) + (c[1].real * c[0].imagine);
	cout << "The new complex number is: " << c1.real << "+" << c1.imagine << "i";
}
void divide(complex c[], int size)
{
	double divisor,real1,imagine1;
	divisor = pow(c[1].real, 2) + pow(c[1].imagine, 2);
	real1= (c[0].real * c[1].real) + (c[0].imagine * c[1].imagine);
	imagine1 = (c[1].real * c[0].imagine) - (c[0].real * c[1].imagine);
	c1.real = real1 / divisor;
	c1.imagine = imagine1 / divisor;
	cout << "The new complex number is: " << c1.real << "+" << c1.imagine << "i";
}
int main()
{
	cout << "enter the real part of the first complex number: ";
	cin >> c[0].real;
	cout << "enter the imaginary part of the first complex number: ";
	cin >> c[0].imagine;
	cout << "enter the real part of the second complex number: ";
	cin >> c[1].real;
	cout << "enter the imaginary part of the second complex number: ";
	cin >> c[1].imagine;
	multiply(c, 2);
	return 0;
}
