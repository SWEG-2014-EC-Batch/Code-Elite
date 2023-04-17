#include <iostream>
using namespace std;
int main(){
    string inputId , id[5] = {"ETS0924/14" , "ETS1015/14" , "ETS1074/14" ,  "ETS0833/14" , "ETS1101/14"} , name[5] = {"Hawoltu" , "Mastewal" , "Meheret" , "Izzat" , "Milkias"};
    cout<<"Enter your ID (like ETS0000/10): ";
    cin>>inputId;
    for(int i=0; i<5; ++i){
        if(inputId == id[i]){
            cout<<name[i];
            break;
        }
        else if(i==4){
            cout<<"Error";
        }
    }
    return 0;
}