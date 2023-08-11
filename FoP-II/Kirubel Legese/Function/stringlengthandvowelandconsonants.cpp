#include <iostream>
using namespace std;
int main()
{
    char word[100];
    int length = 0, i = 0, vowel = 0, consonant = 0;
    cout << "enter any word: ";
    cin.getline(word, 200);
    while (word[i])
    {
        length++;
        i++;
    }
    cout << "the length of the string is: " << length << endl;
    for (int i = 0;i < length;i++)
    {
        if (word[i] == 'a', word[i] == 'e', word[i] == 'i', word[i] == 'o', word[i] == 'u')
        {
            vowel++;
        }
        else
        {
            consonant++;
        }
    }
    cout << "the number of vowels is: " << vowel << endl;
    cout << "the number of consonants is: " << consonant << endl;
    return 0;
}

