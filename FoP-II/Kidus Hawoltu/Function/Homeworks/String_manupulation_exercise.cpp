#include <iostream>
#include "StringManipulation.h"
using namespace std;

int main(){
    string string1 = "Kidus Hawoltu" , string2 = "Addis Ababa Science and Technology University";
    cout<<'\n'<<stringlength(string1)<<"\t||\t"<<stringlength(string2);
    cout<<'\n'<<vowelNum(string1)<<"\t||\t"<<vowelNum(string2);
    cout<<'\n'<<consonantNum(string1)<<"\t||\t"<<consonantNum(string2)<<endl;

    cout<<'\n'<<reverseString(string1)<<"\t||\t"<<reverseString(string2);
    cout<<'\n'<<strToLower(string1)<<"\t||\t"<<strToLower(string2);
    cout<<'\n'<<strToUpper(string1)<<"\t||\t"<<strToUpper(string2)<<endl;

    cout<<"\nA "<<compareString(string1, string2);
    cout<<"\nB "<<compareString(string2, string1);
    cout<<"\nC "<<compareString("Asdf", "Asdf")<<endl;
    return 0;
}
