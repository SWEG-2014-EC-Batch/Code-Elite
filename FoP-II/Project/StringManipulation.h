#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H

#include <iostream>
using namespace std;
int stringlength(string str);  // returns the length of a string
string strToLower(string str);  // returns the lower case version of a string
string strToUpper(string str);  // returns the upper case version of a string
string strConcat(string str1, string str2, int length1 = -1, int length2 = -1);  // concatenates the two strings and returns the resulting string
template <typename T>
T highest(T n, T m);  // returns the larger value of the two parameters
template <typename T>
void prints(T value, int n = 1);  // prints the first parameter n times on terminal

int stringlength(string str){
    int length = 0;
    for(int i=0; str[i] != '\0'; ++i) length++;
        
    return length;
}

string strToLower(string str){
    int length = stringlength(str);
    char *lower = new char[length + 1];

    for(int i=0; i<length; ++i){
        if(str[i]>='A' && str[i]<='Z') lower[i] = str[i] + 32;
        else lower[i] = str[i];
    }
    lower[length] = '\0';

    return lower;
}

string strToUpper(string str){
    int length = stringlength(str);
    char *upper = new char[length + 1];

    for(int i=0; i<length; ++i){
        if(str[i]>='a' && str[i]<='z') upper[i] = str[i] - 32;
        else upper[i] = str[i];
    }
    upper[length] = '\0';


    return upper;
}

string strConcat(string str1, string str2, int length1, int length2){
    if(length1 == -1 || length1 > stringlength(str1)) length1 = stringlength(str1);
    if(length2 == -1 || length2 > stringlength(str2)) length2 = stringlength(str2);
    
    char *result = new char[length1 + length2 + 1];

    for(int i = 0; i < length1; ++i) result[i] = str1[i];
    for(int i = 0; i < length2; ++i) result[length1 + i] = str2[i];

    result[length1 + length2] = '\0';

    return result;
}

template <typename T>
T highest(T n, T m){
    if(n > m) return n;
    return m;
}

template <typename T>
void prints(T value, int n){
    for(int i = 0; i < n; ++i) cout<<value;
}

#endif
