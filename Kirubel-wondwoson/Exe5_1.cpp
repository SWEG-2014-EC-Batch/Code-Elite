#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    do{
        cout<<num<<endl;
        num+=2;      
    } while(num>=0 && num<=100);
}

