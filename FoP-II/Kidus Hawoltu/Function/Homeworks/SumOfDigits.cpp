#include <iostream>
using namespace std;
int sumOfDigits(int n);

int main(){
    int num = 127324938;
    cout<<"The sum of digits of "<<num<<" is "<<sumOfDigits(num);
    return 0;
}

int sumOfDigits(int n){
    if(n<10){
        return n;
    }
    else{
        return n%10 + sumOfDigits(n/10);
    }
}
