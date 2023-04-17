#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace std;
int main(){
    char username[11] , password[16] , passwords[][16] = {"1234567890" , "1234aa" , "1234bb" , "1234cc" , "1234dd"} , usernames[][11]={"ABCDEFGHIJ" , "AAAA" , "BBB" , "CCC" , "DDD"};
    cout<<"Enter your username(atmost 10 characters): ";
    cin>>username;
    for(int i=0; username[i]!='\0'; ++i){
        username[i]=toupper(username[i]);
    }
    cout<<"Enter your password(6-15 characters): ";
    cin>>password;
    if(strlen(username)>10 || strlen(password)<6 || strlen(password)>15){
        cout<<"Incorrect password size.";
    }
    else{
        for(int i=0; i<5; ++i){
            if((strcmp(username, usernames[i]))==0 && (strcmp(password, passwords[i]))==0){
                cout<<"You are logged in";
                break;
            }
            else if(i==4){
                cout<<"Invalid username or password.";
            }
        }
    }
    return 0;
}