#include <iostream>
using namespace std;

int pow(int, int);

int main(){
    cout<<pow(5, 3);
}

int pow(int num, int p){
    if(p==0){
        return 1;
    }
    else if(p==1){
        return num;
    }
    else{
        return num * pow(num, p-1);
    }
}