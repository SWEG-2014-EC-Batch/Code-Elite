#include <iostream>
using namespace std;
void input(double& lengthfeet, double& lengthinch, double& lengthmeter, double& lengthcenti);
void conversion(double lengthfeet, double lengthinch, double lengthmeter, double lengthcenti, int& choice2);
void output(int choice2, double nlengthfeet, double nlengthinch, double nlengthmeter, double nlengthcenti);
int choice2;
double nlengthfeet, nlengthinch, nlengthmeter, nlengthcenti;
double lengthfeet, lengthinch, lengthmeter, lengthcenti;
int main()
{
	int choice;
	do
	{
		input(lengthfeet, lengthinch, lengthmeter, lengthcenti);
		conversion(lengthfeet, lengthinch, lengthmeter, lengthcenti, choice2);
		output(choice2, nlengthfeet, nlengthinch, nlengthmeter, nlengthcenti);
		cout << "enter 1 to repeat the program or enter 0 to end the program: ";
		cin >> choice;
	} while (choice != 0);
	return 0;
}
void input(double& lengthfeet, double& lengthinch, double& lengthmeter, double& lengthcenti)
{
	cout << "enter your length in feets: ";
	cin >> lengthfeet;
	cout << "enter your length in inches: ";
	cin >> lengthinch;
	cout << "enter your length in meters: ";
	cin >> lengthmeter;
	cout << "enter your length in centimeter: ";
	cin >> lengthcenti;
}
void conversion(double lengthfeet, double lengthinch, double lengthmeter, double lengthcenti, int& choice2)
{
retry:
	cout << "enter 2 for convertion of feets to meters and inches to centimeters or enter 3 for convertion of meters to feets and centimeters to inches: ";
	cin >> choice2;
	switch (choice2) {
	case 2:
		nlengthmeter = lengthfeet * 0.305;
		nlengthcenti = lengthinch * 2.54;
		break;
	case 3:
		nlengthfeet = lengthmeter * 3.28;
		nlengthinch = lengthcenti * 0.393;
		break;
	default:
		cout << "wrong input!!!!";
		goto retry;
	}
}
void output(int choice2, double nlengthfeet, double nlengthinch, double nlengthmeter, double nlengthcenti)
{
	if (choice2 == 2)
	{
		cout << "The convesion to meter is: " << nlengthmeter << endl;
		cout << "The conversion to centimeter is: " << nlengthcenti << endl;
	}
	else if (choice2 == 3)
	{
		cout << "The conversion to feet is: " << nlengthfeet << endl;
		cout << "The conversion to inch is: " << nlengthinch << endl;
	}
	else
	{
		cout << "errrror!!!!";
	}
}