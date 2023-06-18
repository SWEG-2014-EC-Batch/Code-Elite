#include <iostream>
using namespace std;

void calcQuotient(double n1, double n2, double &answer);

int main(){
    double num1 = 12, num2 = 3, quotient = 6;

    calcQuotient(num1, num2, quotient);
    cout<<"The quotient is: "<<quotient;
    return 0;
}

void calcQuotient(double n1, double n2, double &answer){
    answer = n1/n2;
    
}