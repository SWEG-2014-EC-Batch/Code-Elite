#include<iostream>
using namespace std;
int main()
{
    int arr[2][3]={45,67,75,64,83,59};
    int* ptr;
    ptr=&arr;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}