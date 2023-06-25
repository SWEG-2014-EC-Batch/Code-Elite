#include <iostream>
using namespace std;

int sum(int);

int main(){
    int num = 1234;
    cout<<"The sum of the digits is: "<<sum(num);
}
int sum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return (n % 10) + sum(n/10);
    }
}