#include <iostream>
#include "strng.h"
using namespace std;

int main(){
    char word1[50], word2[50];
    cout<<"Enter two words: ";
    cin>>word1>>word2;
    cout<<compare(word1, word2);
}