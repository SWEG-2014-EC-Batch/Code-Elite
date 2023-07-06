#include <iostream>
#include "getProduct.h"
#include "welcomeMsg.h"
using namespace std;

int main(){
    int firstNum;
    double secondNum;
    cout<<"Enter the first number(only integer): ";
    cin>>firstNum;
    cout<<"Enter the second number: ";
    cin>>secondNum;
    cout<<getProduct(firstNum , secondNum);
    return 0;
}
