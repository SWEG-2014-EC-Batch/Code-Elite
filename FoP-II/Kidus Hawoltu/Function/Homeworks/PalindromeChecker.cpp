#include <iostream>
using namespace std;
bool isPalindrome(string word, int size, int index=0);

int main(){
    string word = "zasdggfdsa";
    int wordLength = word.length();
    if(isPalindrome(word, wordLength)){
        cout<<"It is a palindrome.";
    }
    else{
        cout<<"It is not a palindrome.";
    }
    return 0;
}

bool isPalindrome(string word, int size, int index){
    if(index == (size-1)/2){
        if(word[index] == word[size/2]){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(word[index] == word[size-index-1]){
            return true && isPalindrome(word, size, index+1);
        }
        else{
            return false;
        }
    }
}
