#include <iostream>
#include "lengthVwlCons.h"
using namespace std;

int main(){
    char word[50];
    cout<<"Enter a word: ";
    cin>>word;
    cout<<"The length of the word is: "<<length(word)<<endl;
    cout<<"The number of vowels in the word is: "<<numberOfVow(word)<<endl;
    cout<<"The number of consonants in the word is: "<<numberOfCons(word);
}