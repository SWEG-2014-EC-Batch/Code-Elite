#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g;
    a=2;
    b=4;
    c=6;
    c=a++ +(++b);
    d=--c;
    e=c--;
    g=c;
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<g;
    return 0;
}