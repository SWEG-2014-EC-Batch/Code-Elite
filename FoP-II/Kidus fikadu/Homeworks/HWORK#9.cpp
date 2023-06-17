

#include <iostream>

using namespace std;

void swap(int& x, int& y) {
	int k = 0;
	k = x;
	x = y;
	y = k;
	//cout << x << " " << y << endl;
}

void refunction(int& a, int& b, int& c) {




	if (b > a) {
		if (c > b) {
			swap(a, c);

		}
		else {
			if (c > a) {
				swap(a, c);
			}
			swap(b, a);

		}
	}
	if (a > b) {
		if (c > b) {
			if (c > a) {
				swap(a, c);
			}
			swap(b, c);

		}

	}
	cout << "After : " << a << " " << b << " " << c << endl;


}

int main()
{
    start:
    int n1, n2, n3;
    cout << "enter three numbers\n";
    cin >> n1 >> n2 >> n3;
    cout <<"Before : "<< n1 << " " << n2 << " " << n3 << endl;

    refunction(n1, n2, n3);
    goto start;
}

