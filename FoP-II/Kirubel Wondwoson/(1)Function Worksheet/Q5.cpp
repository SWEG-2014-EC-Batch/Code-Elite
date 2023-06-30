#include<iostream>
#include<cmath>
using namespace std;
double calc(double  , double );
int main()
{
    double num1 , num2 ;
    cout<<"Enter two numbers : ";
    cin>>num1>>num2; 
    cout<<calc(num1 , num2);
    return 0;
}
double calc(double firstNum , double secondNum){
    double answer;
    answer = pow(firstNum , 3) + sqrt(secondNum);
    return answer;
}