/* Question 3
Write a program that converts a letter entered from the keyboard to its uppercase or 
lowercase equivalent (Hint :- use the function defined in ctype.h library header file).
*/
#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    char letter;
    cout<<"Enter a small or capital letter ";
    cin>>letter;
    (letter>='a' && letter<='z') ? cout<<toupper(letter) : cout<<tolower(letter);
    return 0;
}