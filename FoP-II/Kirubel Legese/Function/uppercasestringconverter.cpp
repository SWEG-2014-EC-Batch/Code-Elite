#include <iostream>
using namespace std;
int main()
{
	char word[100], word1[100];
	int length = 0, i = 0;
	cout << "enter a word: ";
	cin.getline(word, 100);
	while (word[i])
	{
		length++;
		i++;
	}
	for (int i = 0;i < length;i++)
	{
		if (word[i] >= 65 && word[i] <= 90)
		{
			cout << word[i];
		}
		else
		{
			word[i] = word[i] - 32;
			cout << word[i];
		}

	}

	return 0;
}


