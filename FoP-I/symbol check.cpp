#include<iostream>
using namespace std;

int main()
{ /* a program that input a character and 
    tells the user whether the input character
    is a digit, uppercase, lowercase or special character*/
    
   char symbol;
    cout<<"enter any symbol:\n";
    cin>>symbol;
    if (symbol>='A' && symbol<='Z'){
    cout<<"the symbol "<<symbol<<" is a capital letter(uppercase)";
    }
     else if (symbol>='a' && symbol<='z'){
    cout<<"the symbol "<<symbol<<" is a small letter(lowercase)";}
     else if(symbol>='0'&& symbol<='9'){
    cout<<"the symbol "<<symbol<<" is a digit";}
    else {
    cout<<"the symbol "<<symbol<< " is a special character";
    }
    return 0;
}