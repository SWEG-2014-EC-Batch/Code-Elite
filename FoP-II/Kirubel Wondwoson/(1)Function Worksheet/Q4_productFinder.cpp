#include<iostream>
#include"Q4headerFile1.h"
#include"Q4headerFile2.h"
using namespace std;
int main()
{
    int firstNum = 10;
    double product , secondNum = 20.4;
    double result;
    product = getProduct(firstNum , secondNum);
    result = addNum(firstNum , secondNum);
    cout<<product<<endl;
    cout<<result<<endl;
}
