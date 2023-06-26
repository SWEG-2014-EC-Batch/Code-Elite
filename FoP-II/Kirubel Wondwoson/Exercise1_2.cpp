#include<iostream>
#include<ctype.h>
using namespace std;
void printVowel(string str);
int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    printVowel(str);
    return 0;
}
void printVowel(string str)
{
    for(int i = 0 ; str[i] != '\0' ; i++){
        str[i] = tolower(str[i]);
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            cout<<str[i];
        }
    }
}