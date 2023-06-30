#include<iostream>
using namespace std;
bool isPrime(int num);
int main(){
    cout<<"1 implies prime , 0 implies not prime"<<endl;
    cout<<isPrime(17)<<endl;
    cout<<isPrime(10)<<endl;
    cout<<isPrime(13);
    return 0;
}
bool isPrime(int num){
    if(num < 2 || num > 1000){
        return false;
    }
    for(int i=2;i<num/2;i++){
        if(num % i == 0 ){
            return false;
        }
    }
    return true;
}