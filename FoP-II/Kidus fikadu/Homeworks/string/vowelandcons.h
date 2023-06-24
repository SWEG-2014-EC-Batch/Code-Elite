#include <iostream>
using namespace std;

void vclen(string a) {
	int n=0,c = 0, k = 0, l = 0, v = 0;

	do {

		
		if ((a[k] >= 65 && a[k] <= 90) || (a[k] >= 97 && a[k] <= 122)) {
			l++;
			if (a[k] == 'a' || a[k] == 'e' || a[k] == 'i' || a[k] == 'o' || a[k] == 'u') {

				v++;
			}
			else if (a[k] == 'A' || a[k] == 'E' || a[k] == 'I' || a[k] == 'O' || a[k] == 'U') {

				v++;
			}
			
			else {
				c++;
			}
			

		}
		else if (a[k] >= 48 && a[k] <= 57) {

			n++;
		}
		k++;
	} while (a[k] > 32 && a[k] < 126);
	cout << "vowel length : " << v << endl;
	cout << "consonant length : " << c << endl;
	cout << "number length : " << n<< endl;
	cout << "others length : " << k - (v + c + n) << endl;

}



