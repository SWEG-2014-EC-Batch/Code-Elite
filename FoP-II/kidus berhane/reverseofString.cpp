#include<iostream>
#include"reverse.h"
using namespace std;
int main()
{
    char word2[100];
    cout<<"enter any word: ";
    cin.getline(word2,100);
    reverse(word2);
    return 0;
}