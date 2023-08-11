#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream readfile;
	readfile.open("file_5.txt", ios::trunc);
	if (!readfile.is_open())
	{
		cout << "error,unable to open file" << endl;
	}
	int num;
	double num1; 
	for (;!readfile.eof();)
	{
		double sum = 0;
		readfile >> num;
		for (int i = 0;i < num;i++)
		{
			readfile >> num1;
			sum += num1;
		}
		cout << "The average is " << double(sum / num) << endl;
	}
	return 0;
}