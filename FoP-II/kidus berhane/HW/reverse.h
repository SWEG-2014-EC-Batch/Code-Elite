#include<iostream>
#include<cstring>
using namespace std;
void reverse(char word1[100])
{
    int length;
    char word2[100];
    length=strlen(word1);
    for(int i=0;i<length;i++)
    {
        word2[i]=word1[length-i-1];
        cout<<word2[i];
    }
}