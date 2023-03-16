#include<iostream>
using namespace std;
int main()
{  
for(int i=0;i<6;i++)
{
for(int k=0;k<=5-i;k++)
{
if(i==0 || k==0 || k==5-i ) 
{
cout<<"* ";
}
else{
cout<<"  ";}
}
cout<<endl;
}
return 0;
}