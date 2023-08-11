#include<iostream>
using namespace std;
int main()
{
	char word[100], word1[100];
	int length=0, length1=0, unfalse = 0, untrue = 0, i = 0, j = 0;
	cout << "enter the first word: ";
	cin.getline(word, 100);
	cout << "enter the second word: ";
	cin.getline(word1, 100);
	while (word[i])
	{
		length++;
		i++;
	}
	while (word1[j])
	{
		length1++;
		j++;
	}
	if (length > length1)
	{
		for (int i = 0;i < length;i++)
		{
			if (word[i] != word1[i])
			{
				unfalse++;
			}
			else
			{
				untrue++;
			}
		}
		if (unfalse != 0)
		{
			cout << true;
		}
		else if (untrue == length && untrue == length1)
		{
			cout << false;
		}
	}
	else
	{
		for (int i = 0;i < length;i++)
		{
			if (word[i] != word1[i])
			{
				unfalse++;
			}
			else
			{
				untrue++;
			}
		}
		if (unfalse != 0)
		{
			cout << true;
		}
		else if (untrue == length && untrue == length1)
		{
			cout << false;
		}
	}
	return 0;
}
	