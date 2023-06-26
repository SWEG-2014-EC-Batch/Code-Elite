#include<iostream>
using namespace std;
double findExpo(double num , int pow);
int main()
{
    double num;
    int pow;
    cout<<"Enter a number : ";
    cin>>num;
    cout<<"Enter its power : ";
    cin>>pow;
    cout<<findExpo(num , pow);
    return 0;
}
double findExpo(double num , int pow)
{
    if(pow < 0){
        return 0;
    }
    if(pow == 0){
        return 1;
    }
    return num*findExpo(num , pow - 1);
}