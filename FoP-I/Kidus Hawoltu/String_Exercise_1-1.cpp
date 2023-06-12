#include <iostream>
using namespace std;
int main(){
    char inputId[11] , id[][11] = {"ETS0924/14" , "ETS1015/14" , "ETS1074/14" ,  "ETS0833/14" , "ETS1101/14"};
    cout<<"Enter your ID (like ETS0000/10): ";
    cin>>inputId;
    for(int j=0; j<5; ++j){
        for(int i=0; i<10; ++i){
            if(inputId[i] == id[j][i]){
                if(i==9){
                   cout<<id[j];
                    j=5;
                }
            }
            else{
                if(j==4){
                    cout<<"Error";
                }
                break;
            }
        }
    }
    return 0;
}