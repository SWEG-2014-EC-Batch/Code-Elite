#include<iostream>
using namespace std;
double multi(double num1, double num2);
int main(){
   double num3,num4;
    cout<<"enter the first number"<<endl;
    cin>>num3;
    cout<<"enter the second number"<<endl;
    cin>>num4;
    cout<<multi(num3,num4);
    return 0;
}
double multi(double num1,double num2)
{
    return num1*num2;
}