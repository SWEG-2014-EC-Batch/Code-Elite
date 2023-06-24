#include <iostream>
#include "slength.h"
using namespace std;

string rev(string a) {
	char b;
	 int p=0,l = slen(a);
	
	
		 for (int i = 0; i < l; ++i) {
			 if (p < l / 2) {
				 b = a[l - 1 - i];
				 a[l - 1 - i] = a[i];
				 a[i] = b;
				 p++;
			 }

		 }
		 for (int i = 0; i < l; ++i) {
			 //cout << a[i];


		 }
	return a;
}
