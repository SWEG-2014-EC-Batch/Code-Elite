#include<iostream>
using namespace std;
int fibonacci(int);
int main()
{
    int n;
    cout<<"Enter the nth digit : ";
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}
int fibonacci(int n)
{
    if(n == 0){
        return 0;
    }
    else if (n == 1 || n == 2){
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}