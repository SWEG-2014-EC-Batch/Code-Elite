#include<iostream>
using namespace std;
void length(char word[100])
{
    int len=0,i=0;
    while(word[i])
    {
        len++;
        i++;
    }
    cout<<len;
    
}

