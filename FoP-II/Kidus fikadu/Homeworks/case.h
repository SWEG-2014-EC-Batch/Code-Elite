#include <iostream>


using namespace std;
string toup(string a) {
	int l = slen(a);
	
	for (int i = 0; i < l; ++i) {
		if (a[i] >= 97 && a[i] <= 122) {
			a[i] = ((int)a[i]) - 32;
			a[i] = (char)a[i];
		}
	}
	return a;
 }
string tolow(string a) {
	int l = slen(a);

	for (int i = 0; i < l; ++i) {
		if (a[i] >= 65 && a[i] <= 90) {
			a[i] = ((int)a[i]) + 32;
			a[i] = (char)a[i];
		}
	}
	return a;
}
