#include <iostream>
#include <math.h>
using namespace std;
bool primeChecker(int num);
void display(int num);

int main(){
    display(37);
    display(1003);
    display(57);
    display(2);
    display(9);
    display(1);
    display(11);
    return 0;
}

bool primeChecker(int num){
    if(num>1 && num<1000){
        int sqrtnum = sqrt(num);
        for(int i=1; i<=sqrtnum; ++i){
            if(i!=1 && num%i == 0){
                return false;
            }
            else if(i == sqrtnum){
                return true;
            }
        }
    }
    else{
        return false;
    }
}

void display(int num){
    if(primeChecker(num)){
        cout<<num<<" is a prime number between 1 and 1000.\n";
    }
    else{
        cout<<num<<" is NOT a prime number between 1 and 1000.\n";
    }
}