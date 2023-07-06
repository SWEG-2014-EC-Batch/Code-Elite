#include <iostream>
#include <ctype.h>
using namespace std;
void printVowel(string word);

int main(){
    string word;
    cout<<"Enter the word: ";
    cin>>word;
    printVowel(word);
    return 0;
}

void printVowel(string word){
    int wordSize = word.length();
    for(int i=0; i<wordSize; ++i){
        if((toupper(word[i])=='A' || toupper(word[i])=='E' || toupper(word[i])=='I' || toupper(word[i])=='O' || toupper(word[i])=='U')){
            cout<<word[i]<<endl;
        }
    }
}
