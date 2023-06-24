#include <iostream>
using namespace std;
int fact(int n);

int main(){
    int num=5;
    cout<<"Factorial of "<<num<<" is "<<fact(num)<<endl;
}

int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return (n*fact(n-1));
    }
}
