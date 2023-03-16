#include<iostream>
using namespace std;
int main()
{int k,l;
cout<<"Enter a number of row: ";
cin>>l;
cout<<"Enter a number of columun: ";
cin>>k;

  for(int c=1;c<=k;c++){
     for(int r=1;r<=l;r++){
        cout<<"* ";
     }
     cout<<endl;
  }
}