#include <iostream>
using namespace std;
double getProduct(int num1 , double num2);

int main(){
    int firstNum;
    double secondNum;
    cout<<"Enter the first number(only integer): ";
    cin>>firstNum;
    cout<<"Enter the second number: ";
    cin>>secondNum;
    cout<<"\nThe product of "<<firstNum<<" and "<<secondNum<<" is "<<getProduct(firstNum , secondNum);
    return 0;
}

double getProduct(int num1 , double num2){
    double product;
    product = double(num1) * num2;
    return product;
}