#include <iostream>

using namespace std;

int comp(string a, string b) {
	int x, y, z;
	int  l = slen(a);
	int  lb = slen(b);
	if (l >= lb) {
		for (int i = 0; i < l; ++i) {
			if ((int)a[i] > (int)b[i]) {
				x = 1;
				return x;
				break;
			}
			else if ((int)a[i] < (int)b[i]) {
				y = -1;
				return y;
				break;
			}
			else {
				
				continue;

			}
			
			
		}
		z = 0;
		return z;
	}
	else if (lb > l) {
		for (int i = 0; i < lb; ++i) {
			if ((int)a[i] > (int)b[i]) {
				x = 1;
				return x;
				break;
			}
			else if ((int)a[i] < (int)b[i]) {
				y = -1;
				return y;
				break;
			}
			else {
				continue;

			}
			
		}
		z = 0;

		return z;
	}

}