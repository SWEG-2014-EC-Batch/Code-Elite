// structdef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;


int main() {
	int size;
	cout << "enter size\n";
	cin >> size;
	
	struct p {
		int age;
		string name;
		char g;
		float w, h, bmi;

	}*st= new p[size];


//start:
	string name;
	for (int i = 0; i < size; ++i) {
		cout << "enter your name \n";
		cin >> st[i].name;
		cout << "enter your age " << st[i].name << endl;
		cin >> st[i].age;
		cout << "enter your gender " << st[i].name << endl;;
		cin >> st[i].g;
		st[i].g = tolower(st[i].g);
		cout << "enter your weight " << st[i].name << endl;;
		cin >> st[i].w;
		cout << "enter your height " << st[i].name << endl;;
		cin >> st[i].h;
		cout << endl;
	}
		for (int i = 0; i < size; ++i) {

			if (st[i].g == 'f') {
				st[i].bmi = st[i].w / pow(st[i].h, 2);
				cout << " mrs " << st[i].name << " your bmi is : " << st[i].bmi << endl;
				if (st[i].bmi < 18) {
					cout << " ms " << st[i].name << " you are underweight\n";
				}
				else if (st[i].bmi >= 18 && st[i].bmi <= 23) {
					cout << " mrs " << st[i].name << " you are normalweight\n";

				}
				else {
					cout << " mrs " << st[i].name << " you are overweight\n";
				}
			}
			if (st[i].g == 'm') {
				st[i].bmi = st[i].w / pow(st[i].h, 2);
				cout << " mr " << st[i].name << " your bmi is : " << st[i].bmi<<endl;
				if (st[i].bmi < 20) {
					cout << " mr " << st[i].name << " you are underweight\n";
				}
				else if (st[i].bmi >= 20 && st[i].bmi <= 25) {
					cout << " mr " << st[i].name << " you are normalweight\n";

				}
				else {
					cout << " mr " << st[i].name << " you are overweight\n";
				}
				
			}
			cout << endl;

		}
		//goto start;
	}

