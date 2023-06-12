#include<iostream>
using namespace std;
int main()
{
    int arr1[2][3]={45,67,75,64,83,59};
    int *ptr1;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            *ptr1++;
            cout<<ptr1<<" ";
        }
        cout<<endl;
    }
    
   int arr[2][3],*ptr=&arr[0][0];
   *(ptr)=45;
   *(ptr+1)=67;
   *(ptr+2)=75;
   *(ptr+3)=64;
   *(ptr+4)=83;
   *(ptr+5)=59;
   for(int i=0;i<2;i++)
   {
    for(int j=0;j<3;j++)
    {  
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }
  
 

    return 0;
}