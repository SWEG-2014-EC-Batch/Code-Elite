#include<iostream>
using namespace std;
float mult(float num1 , float num2)
{
    float product = num1 * num2;
    cout<<product;
    return 0;
}
int main()
{
    float num1 , num2;
    cin>>num1>>num2;
    mult(num1 , num2);
    return 0;
}