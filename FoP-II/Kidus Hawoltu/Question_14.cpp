#include <iostream>
using namespace std;
int fibonacci(int n1 = 1);

int main(){
    cout<<fibonacci()<<endl<<fibonacci(100);
    return 0;
}

int fibonacci(int n1){
    int nthFibonacci = 1, temp = 0 , temp2;
    for(int i=0; i<n1; ++i){
        temp2 = nthFibonacci;
        nthFibonacci += temp;
        temp = temp2;
    }
    return nthFibonacci;
}