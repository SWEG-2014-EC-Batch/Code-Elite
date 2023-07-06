#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H
using namespace std;
int stringlength(string str);  //returns the length of a string
bool isVowel(char a);  //checks whether a character is vowel letter or not
bool isConsonant(char a);  //checks whether a character is consonant letter or not
int vowelNum(string str);  //returns the number of vowels in a string
int consonantNum(string str);  //returns the number of consonants in a string
string reverseString(string str);  //returns the reverse of a string
int compareString(string str1, string str2);  //compares two strings and returns 0 if they are equal, 1 if the first string is greater and -1 if the second string is greater
string strToLower(string str);  //returns the lower case version of a string
string strToUpper(string str);  //returns the upper case version of a string

int stringlength(string str){
    int length = 0;
    for(int i=0; str[i] != '\0'; ++i){
        length++;
    }
    return length;
}

bool isVowel(char a){
    if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U'){
        return true;
    }
    else{
        return false;
    }
}

bool isConsonant(char a){
    if(((a>='a' && a<='z') || (a>='A' && a<='Z')) && !isVowel(a)){
        return true;
    }
    else{
        return false;
    }
}

int vowelNum(string str){
    int vowels = 0;
    for(int i=0; str[i] != '\0'; ++i){
        if(isVowel(str[i])){
            vowels++;
        }
    }
    return vowels;
}

int consonantNum(string str){
    int consonants = 0;
    for(int i=0; str[i] != '\0'; ++i){
        if(isConsonant(str[i])){
            consonants++;
        }
    }
    return consonants;
}

string reverseString(string str){
    int length = stringlength(str);
    char *revStr = new char[length];
    for(int i=0; i<length; ++i){
        revStr[i] = str[length - i - 1];
    }
    return revStr;
}

int compareString(string str1, string str2){
    int count = 0;
    for(int i=0; str1[i] != 0 && str2[i] != 0; ++i){
        if(str1[i] > str2[i]){
            count++;
        }
        else if(str1[i] < str2[i]){
            count--;
        }

        if(count != 0){
            return count;
        }
    }

    if(stringlength(str1) > stringlength(str2)){
        count++;
    }
    else if(stringlength(str1) < stringlength(str2)){
        count--;
    }
    return count;
}

string strToLower(string str){
    int length = stringlength(str);
    char *lower = new char[length];
    for(int i=0; i<length; ++i){
        if(str[i]>='A' && str[i]<='Z'){
            lower[i] = str[i] + 32;
        }
        else{
            lower[i] = str[i];
        }
    }
    return lower;
}

string strToUpper(string str){
    int length = stringlength(str);
    char *upper = new char[length];
    for(int i=0; i<length; ++i){
        if(str[i]>='a' && str[i]<='z'){
            upper[i] = str[i] - 32;
        }
        else{
            upper[i] = str[i];
        }
    }
    return upper;
}
#endif
