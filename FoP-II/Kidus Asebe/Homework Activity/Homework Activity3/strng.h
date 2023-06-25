#ifndef STRNG_H
#define STRNG_H
#include <iostream>
using namespace std;
int length(char str[]){
    int len = 0;
    for(int i = 0; str[i] != '\0'; ++i){
        len++;
    }
    return len;
}
int numberOfVow(char str[]){
    int num = 0;
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U'){
            num++;
        }
    }
    return num;
}
int numberOfCons(char str[]){
    int num;
    num = length(str) - numberOfVow(str);
    return num;
}
string rev(char str[]){
    char reversed[50];
    int leng;
    leng = length(str);
    for(int i = 0; str[i] != '\0'; ++i){
        reversed[i] = str[leng - i - 1];
    }
    reversed[leng] = '\0';
    return reversed;
}
int compare(char str1[], char str2[]){
    int comp = 0;
    for(int i = 0; str1[i] != '\0' && str2[i] != '\0' && comp == 0; ++i){
        if(str1[i] > str2[i]){
            comp = 1;
        }
        else if(str1[i] < str2[i]){
            comp = -1;
        }
        else if(str1[i + 1] == '\0' && str2[i + 1] != '\0'){
            comp = -1;
        }
        else if(str1[i + 1] != '\0' && str2[i + 1] == '\0'){
            comp = 1;
        }
    }
    return comp;
}
string toUpper(char str[]){
    char upper[50];
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            upper[i] = str[i] - 32;
        }
        else{
            upper[i] = str[i];
        }
    }
    return upper;
}
string toLower(char str[]){
    char lower[50];
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            lower[i] = str[i] + 32;
        }
        else{
            lower[i] = str[i];
        }
    }
    return lower;
}
#endif