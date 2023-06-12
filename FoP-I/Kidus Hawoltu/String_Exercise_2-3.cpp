#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char string[1001] , symbol , inputStr[100];
    cout<<"Enter the main string: ";
    gets(string);
    cout<<"Enter the smaller string: ";
    gets(inputStr);
    cout<<"Enter the symbol: ";
    cin>>symbol;
    cout<<"The first left occurance of '"<<symbol<<"' is on \""<<strchr(string, symbol)<<'\"'<<endl;
    cout<<"The first right occurance of '"<<symbol<<"' is on \""<<strrchr(string, symbol)<<'\"'<<endl;
    cout<<"The first occurance of \""<<inputStr<<"\"' is on \""<<strstr(string, inputStr)<<'\"';
    return 0;
}