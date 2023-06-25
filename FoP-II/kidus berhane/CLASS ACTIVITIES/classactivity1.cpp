#include<iostream>
using namespace std;

void printSum(float num1, float num2);

int main()
{
    float array[5];
    float sum;

    for ( int i = 0; i < 5; i++)
    {
        cout<<"enter a number";
        cin >> array[i];
    }

    sum =array[0]+array[4];
    cout<<array[0]<<endl<<array[4]<<endl<< "Their sum is:"<<sum;

   
     return 0;
}
 void printSum(float num1, float num2)
    {
    cout<<num1<<endl<<num2;
    }