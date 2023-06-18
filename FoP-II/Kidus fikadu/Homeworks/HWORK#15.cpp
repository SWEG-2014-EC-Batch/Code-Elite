
#include <iostream>

using namespace std;

void scale(double rate, double& num1, double& num2) {
	double num1b, num2b;
	num1b = num1;
	num2b = num2;
	num1 = num1 * rate;
	num2 = num2 * rate;
	cout << "before : (" << num1b << " - " << num2b << ")" << endl;
	cout << "after : (" << num1 << " - " << num2 << ")" << endl;
}
int main() {
	double rate;
	int k = 0;
	char menu;
	double first, second;
	do {
		cout << "enter the rate of scaling other than zero\n";
		cin >> rate;
		if (rate == 0) {
			do {

				cout << "enter an other number other than zero\n";
				cin >> rate;
				k++;

			} while (k < 3 && rate==0);
			if (k == 3) {
				return 0;
			}
		}

		cout << "enter the first number\n";
		cin >> first;
		cout << "enter the second number\n";
		cin >> second;
		scale(rate, first, second);
		cout << "if you want to repeat press 'y': ";
		cin >> menu;
		menu = toupper(menu);
	} while (menu == 'Y');
	return 0;
}
