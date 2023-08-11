#include<iostream>
using namespace std;
struct coordinate
{
	double xint;
	double yint;
}c1;
coordinate read1()
{
	cout << "enter the x-coordinate of the point: ";
	cin >> c1.xint;
	cout << "enter the y-coordinate of the point: ";
	cin >> c1.yint;
	return c1;
}
void display(coordinate c1)
{
	cout << "The x-coordinate of the point is: " << c1.xint;
	cout << "The y-coodinate of the point is: " << c1.yint;
}

int main()
{
	read1();
	display(c1);
	return 0;
}