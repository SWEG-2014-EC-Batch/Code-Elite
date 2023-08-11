#include<iostream>
#include<string.h>
#include<cmath>
#include<cstdlib>
using namespace std;
struct person
{
	string name;
	char gender;
	double height, weight;
};
int main()
{
	person personal, personal1[100];
	double bmi;
	int choice;
	cout << "for how many people do you want to calculate, enter 1 for a single person of enter any number you like for number of people you like: ";
	cin >> choice;
	if (choice == 1)
	{
		cout << "enter the name of the person: ";
		cin >> personal.name;
	start:
		cout << "enter the gender of the person: ";
		cin >> personal.gender;
		personal.gender = tolower(personal.gender);
		if (personal.gender != 'm' && personal.gender != 'f')
		{
			cout << "error, wrong gender" << endl;
			goto start;
		}
		cout << "enter the height of the person: ";
		cin >> personal.height;
		cout << "enter the weight of the person: ";
		cin >> personal.weight;
		bmi = personal.weight / pow(personal.height, 2);
		cout << "the bmi of the person is: " << bmi;
		if (personal.gender == 'm')
		{
			if (bmi <= 19)
			{
				cout << "the person is underweight";
			}
			else if (bmi > 19 && bmi <= 24)
			{
				cout << "you are in good shape";
			}
			else
			{
				cout << "you are overweight";
			}
		}
		else if (personal.gender == 'f')
		{
			if (bmi <= 17)
			{
				cout << "the person is underweight";
			}
			else if (bmi > 17 && bmi <= 21)
			{
				cout << "you are in good shape";
			}
			else
			{
				cout << "you are overweight";
			}
		}
		else
		{
			cout << "error, wrong gender";
		}
	}
	else 
	{
		for (int i = 0;i < choice&& i<100;i++)
		{
			double bmi[100];
			cout << "enter the name of the person: ";
			cin >> personal1[i].name;
			cout << "enter the gender of the person: ";
			cin >> personal1[i].gender;
			personal1[i].gender = tolower(personal1[i].gender);
			if (personal1[i].gender != 'm' && personal1[i].gender != 'f')
			{
				cout << "error, wrong gender" << endl;
				exit(-1);
			}
			cout << "enter the height of the person: ";
			cin >> personal1[i].height;
			cout << "enter the weight of the person: ";
			cin >> personal1[i].weight;
			bmi[i] = personal1[i].weight / pow(personal1[i].height, 2);
		}
		for (int i = 0;i < choice && i < 100;i++)
		{
			double bmi[100];
			if (personal1[i].gender == 'm')
			{
				if (bmi[i] <= 19)
				{
					cout << "the person is underweight" << endl;
				}
				else if (bmi[i] > 19 && bmi[i] <= 24)
				{
					cout << "you are in good shape" << endl;
				}
				else
				{
					cout << "you are overweight" << endl;
				}
			}
			else if (personal1[i].gender == 'f')
			{
				if (bmi[i] <= 17)
				{
					cout << "the person is underweight";
				}
				else if (bmi[i] > 17 && bmi[i] <= 21)
				{
					cout << "you are in good shape";
				}
				else
				{
					cout << "you are overweight";
				}
			}
			else
			{
				cout << "error, wrong gender";
			}
		}
	}
}