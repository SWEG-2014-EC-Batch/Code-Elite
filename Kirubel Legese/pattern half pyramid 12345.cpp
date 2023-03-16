#include<iostream>
using namespace std;
int main()
{
    int i,j,k=5;
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=i; j++)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}