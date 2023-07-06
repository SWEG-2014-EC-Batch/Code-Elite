#include <iostream>
using namespace std;
void mult(float x, float y);
int main(){
    float num1, num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    mult(num1,num2);
}
void mult(float x, float y){
    cout<<"The product of "<<x<<" and "<<y<<" is "<<x*y;
}
