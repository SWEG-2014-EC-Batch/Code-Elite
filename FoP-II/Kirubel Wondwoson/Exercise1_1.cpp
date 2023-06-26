#include<iostream>
using namespace std;
void fun(float arr[] , int size);
int main()
{
    float arr[] = {10 , 20 , 30 , 40 , 50};
    fun(arr , 5);
    return 0;
}
void fun(float arr[] , int size)
{
    float temp1 , temp2;
    for(int i = 0 ; i < size ; i++){
        temp1 = arr[0];
        temp2 = arr[size - 1];
    }
    cout<<temp1<<endl;
    cout<<temp2<<endl;
    cout<<temp1 + temp2<<endl;
}