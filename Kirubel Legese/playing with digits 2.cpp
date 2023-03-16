#include<iostream>
using namespace std;
int main()
{  
 int number, revenumber=0, remainder;
cout<<"enter an integer ";
cin>>number;
while(number>0)
{
remainder=number%10;
number=number/10;
revenumber=(revenumber*10)+remainder;
}
cout<<"reverse number is "<<revenumber<<endl;
return 0;
}