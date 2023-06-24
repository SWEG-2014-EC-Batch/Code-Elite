#include <iostream>
using namespace std;
double power(double n, int exp);

int main(){
    int num = 10, exp = 2;
    cout<<power(num, exp)<<endl;
    cout<<power(10, -2)<<endl;
    return 0;
}

double power(double n, int exp){
    if(n==0){
        return 0;
    }
    else if(exp==0){
        return 1;
    }
    else if(exp<0){
        return 1/power(n, -1*exp);
    }
    else{
        return n*power(n, exp-1);
    }
}
