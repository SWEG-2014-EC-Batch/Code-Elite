#include<iostream>
using namespace std;
int main()
{  
int row, column;
cout<<" enter number of row ";
cin>>row;
cout<<" enter number of column ";
cin>>column;
for(int k=1;k<=row;k+=1)
{
 for(int i=1;i<=column;i+=1)
  {
   cout<<"* ";
  }
   cout<<endl;
}return 0;
}