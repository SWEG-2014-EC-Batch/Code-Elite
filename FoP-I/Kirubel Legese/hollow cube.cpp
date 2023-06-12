#include<iostream>
using namespace std;
int main()
{  
for(int i=0;i<7;i++)
{
for(int k=0;k<8;k++)
{
if(i==0 || i==6 || k==0 || k==7)
{
 cout<<"* ";
}
else
{
 cout<<"  ";
}
}
cout<<endl;
}
return 0;
}