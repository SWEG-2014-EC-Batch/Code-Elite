#include <iostream>
#include "strng.h"
using namespace std;

int main(){
    char word[50];
    cout<<"Enter a word: ";
    cin>>word;
    cout<<"The word in capiatal letters: "<<toUpper(word);
}