#include <iostream>
using namespace std;
void decendingOrder(int &n1, int &n2, int &n3);
void output(int n1, int n2, int n3);

int main(){
    output(-23, 15, 190);
    output(0, 18, 2);
    output(133, 100, 154);
    output(12, 67, 30);
    output(90, 0, 23);
    output(77, 52, 11);
    output(12, 12, 23);
    output(77, 10, 10);
    output(15, 90, 15);
    output(10, 10, 10);
    return 0;
}

void decendingOrder(int &n1, int &n2, int &n3){
    if(n1<n2){
        swap(n1, n2);
    }
    if(n2<n3){
        swap(n2, n3);
    }
    if(n1<n2){
        swap(n1, n2);
    }
}

void output(int n1, int n2, int n3){
    cout<<"\nBefore swapping: "<<n1<<", "<<n2<<" ,"<<n3;
    decendingOrder(n1, n2, n3);
    cout<<"\nAfter swapping: "<<n1<<", "<<n2<<" ,"<<n3<<'\n';
}
