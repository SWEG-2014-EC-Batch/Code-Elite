
#include<iostream>
using namespace std;
int voltage[10];//Global array declaration
int main()
{  
    cout<<"voltages: ";
    for(int k=0;k<10;k++)
    {
    cout<<voltage[k]<<" ";
    }
    cout<<endl;
    //Local array declaration
     int power[10];
     cout<<"powers: ";
    for(int i=0;i<10;i++)
    {
        power[i];
    cout<<power<<" ";
    }
}
