#include <iostream>
using namespace std;

void sortDescending(int&, int&, int&);

int main(){
    int num1, num2, num3;
    cout<<"Enter three numbers: ";
    cin>>num1>>num2>>num3;
    cout<<"Before swapping: "<<num1<<" "<<num2<<" "<<num3;
    sortDescending(num1, num2, num3);
    cout<<"After swapping (from largest to smallest): "<<num1<<" "<<num2<<" "<<num3;
}

void sortDescending(int& n1, int& n2, int& n3){
    if(n1>n2){
        if(n3>n1){
            int temp = n1;
            n1 = n3;
            n3 = n2;
            n2 = temp;            
        }
        else if(n3>n2){
            int temp = n2;
            n2 = n3;
            n3 = temp;
        }
    }
    else{
        if(n3>n2){
            int temp = n1;
            n1 = n3;
            n3 = temp;
        }
        else if(n3>n1){
            int temp = n1;
            n1 = n2;
            n2 = n3;
            n3 = temp;
        }
        else{
            int temp = n1;
            n1 = n2;
            n2 = temp;
        }
    }
}