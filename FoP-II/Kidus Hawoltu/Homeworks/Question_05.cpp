#include <iostream>
#include <math.h>
using namespace std;
double cubeAndSqrt(double num1 , double num2);

int main(){
    double num1 , num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number(only positive number): ";
    cin>>num2;
    cout<<"\n("<<num1<<")^3 + ("<<num2<<")^0.5 = "<<cubeAndSqrt(num1 , num2);
    return 0;
}

double cubeAndSqrt(double num1 , double num2){
    double answer;
    answer = pow(num1 , 3) + sqrt(num2);
    return answer;
}
