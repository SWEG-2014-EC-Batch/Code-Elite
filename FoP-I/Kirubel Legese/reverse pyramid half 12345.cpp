#include<iostream>
using namespace std;
int main()
{
    int i,j,k=5,m;
    for(i=1; i<=k; i++)
    {
    for(m=5-i;m>0;m--)
    cout<<"  ";
        for(j=1; j<=i; j++)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}