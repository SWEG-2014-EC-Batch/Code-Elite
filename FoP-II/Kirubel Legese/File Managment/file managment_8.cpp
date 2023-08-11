#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream read1;
	read1.open("file_8.txt", ios::trunc);
	if (!read1.is_open())
	{
		cout << "error,unable to open file" << endl;
	}
	int count;
	char character;
	for (int i = 0;i < 26;i++)
	{
		count = 0;
		read1.seekg(0, ios::beg);
		for (;!read1.eof();)
		{
			read1.get(character);
			if (character == 'a' + i)
			{
				count++;
			}
		}
		if (count != 0)
		{
			cout << char('a' + i) << count << endl;
		}
	}
	read1.close();
	return 0;
}