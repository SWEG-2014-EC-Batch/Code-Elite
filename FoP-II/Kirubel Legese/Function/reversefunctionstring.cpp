#include <iostream>
using namespace std;
int main()
{
    char word[100];
    int length = 0, i = 0;
    cout << "enter a word: ";
    cin.getline(word, 100);
	while (word[i])
	{
		length++;
		i++;
	}
    for(int i = 0;i < length;i++)
    {
        word[i] = word[length - i-1];
        cout << word[i];
    }
    return 0;
}

