#include<iostream>
#include"length.h"
using namespace std;
int main()
{
    char word1[100];
    cout<<"enter a word: ";
    cin.getline(word1,100);
    length(word1);
    return 0;
}

