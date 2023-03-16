#include<iostream>
using namespace std;
int main()
{  
 for(int i=65;i<89;i++)
 {
    cout<<char(i)<<' ';
  if((i+2)%6==0)
  cout<<endl;
 }

return 0;
}