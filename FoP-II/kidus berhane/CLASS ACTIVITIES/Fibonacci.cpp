#include <iostream>
using namespace std;
int fibonacci(int n);

int main(){
    int num = 4;
    cout<<"Fibonacci number "<<num<<" is: "<<fibonacci(num);
    return 0;
}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
