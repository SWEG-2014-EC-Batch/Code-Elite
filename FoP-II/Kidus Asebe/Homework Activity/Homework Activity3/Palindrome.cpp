#include <iostream>
using namespace std;

string palindrome(char[], int);

int main(){
    char word[] = "cocacoc";
    cout<<palindrome(word, 8);
}
int len = 8;
string palindrome(char str[], int size){
    if(size == 0){
        if(str[0] == str[len-1]){
            return "Palindrome";
        }
        else{
            return "Not Palindrome";
        }
    }
    else{
        if(str[size-1] == str[len - size]){
            return palindrome(str, size -1);
        }
        else{
            return "Not Palindrome";
        }
    }
}