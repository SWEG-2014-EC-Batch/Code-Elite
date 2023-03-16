#include<iostream>
using namespace std;
int main(){
    char k;
    cout<<"Enter the value: ";
      cin>>k;
    if(k>='A'&& k<='Z'){
        
       cout<<"upper case";
    }
    else if(k>='a'&& k<='z'){
        cout<<"Lower case";
    }
    else if(k>='0' && k<='9'&& k%2==0){
         cout<<"Even number";
    }
    else if(k>='0' && k<='9'&& k%2==1 ) 
    {cout<<"Odd number";}
    else {
        cout<<"a special character";}
}