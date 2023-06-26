#include<iostream>
using namespace std;
double findSum(double[] , int);
int main()
{
    double arr[5] = {1,2,3,4,5};
    cout<<findSum(arr , 5);
    return 0;
}
double findSum(double arr[] , int size)
{
    if(size < 0){
        return 0;
    }
    return arr[size] + findSum(arr , size - 1);
}