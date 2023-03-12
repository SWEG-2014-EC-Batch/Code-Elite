#include<iostream>
using namespace std;

int main(){
    /* this program reverses the number the 
    user inputs*/
    int num,r, rev=0;
    cout<<"enter a number to be reversed\n";
    cin>>num;
    
     while (num){
    r=num%10;
     rev=(rev*10)+r;
     num=num/10;
    }
        cout<<"the reverse is "<<rev;
    
    return 0;
}