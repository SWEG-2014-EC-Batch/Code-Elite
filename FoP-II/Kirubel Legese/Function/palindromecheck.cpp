#include<iostream>
#include<cstring>
using namespace std;
bool palindrome(char word1[],int intial,int len1)
{
	if(len1==0||len1==1)
	{
		return true;
	}
	else if (intial == len1)
	{
		return true;
	}
	else if(word1[intial]==word1[len1-1])
	{
		return palindrome(word1, intial+1,len1 - 1);
	}
	else
	{
		return false;
	}
}
int main()
{
	char word[100];
	int length;
	bool result;
	cout << "enter the number that you want to be check palindrome or not: ";
	cin.getline(word,100);
	length = strlen(word);
	result = palindrome(word, 0, length);
	if (result)
	{
		cout << "The word is palindrome";
	}
	else
	{
		cout << "The word is not palindrome";
	}
	return 0;
}