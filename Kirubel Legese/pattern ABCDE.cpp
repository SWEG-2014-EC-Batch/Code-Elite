#include<iostream>
using namespace std;
int main()
{
    int i,j,k=5;
    char ch='A';
    for(i=1; i<=k; i++)
    {
        for(j=1; j<=i; j++)
            cout<<ch<<" ";
            ch++;
        cout<<endl;
    }
    return 0;
}