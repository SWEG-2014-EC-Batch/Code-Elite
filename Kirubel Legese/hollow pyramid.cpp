#include<iostream>
using namespace std;
int main()
{
for(int i=1;i<=6;i++)
{
for(int k=i;k<6;k++)
cout<<" ";
for(int j=1;j<=(2*i-1);j++)
{
if(i==6 || j==1 || j==(2*i-1))
cout<<"*";
else 
cout<<" ";
}
cout<<"\n";
}
return 0;
}