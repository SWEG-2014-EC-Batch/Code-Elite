#include<iostream>
using namespace std;
struct info
{
	int id;
	string name;
	double mark1[5];
	struct date
	{
		int day;
		int month;
		int year;
	}stud;
};
info sm1[10];
double ave[10] = { 0 };
void input1()
{
	for (int i = 0;i < 5;i++)
	{
		cout << "enter the name of the student: ";
		cin >> sm1[i].name;
		cout << "enter the id.no of the student: ";
		cin >> sm1[i].id;
		for (int j = 0;j < 5;j++)
		{
			cout << "enter the mark of subject " << j + 1 << ": ";
			cin >> sm1[i].mark1[j];
		}
		
	}
}
void display(info sm1[],int size)
{
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			ave[i] += sm1[i].mark1[j];
		}
	}
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 1;j++)
		{
			cout << "|" << "Roll.no " << "Name " << "mark of subject " << j + 1 << "mark of subject " << j + 2 << "mark of subject " << j + 3 << "mark of subject " << j + 4 << "mark of subject " << j + 5 << "Average score " << endl;
		}
		for (int k = 0;k < 1;k++)
		{
			cout << "|" << sm1[i].id << " " << sm1[i].name << sm1[i].mark1[k] << sm1[i].mark1[k + 1] << sm1[i].mark1[k + 2] << sm1[i].mark1[k + 3] << sm1[i].mark1[k + 4] << ave[i] << endl;
		}
	}
}
int main()
{
	input1();
	display(sm1,10);
	return 0;
}