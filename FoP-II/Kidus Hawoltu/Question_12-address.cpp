#include <iostream>
using namespace std;
void calcQuotient(double n1, double n2, double& answer);

int main(){
    double num1 = 12, num2 = 3, quotient;
    calcQuotient(num1, num2, quotient);
    if(num2 == 0){
        cout<<"Can\'t divide by 0!";
    }
    else{
        cout<<num1<<"/"<<num2<<" = "<<quotient;
    }
    return 0;
}

void calcQuotient(double n1, double n2, double& answer){
    answer = n1/n2;
}
