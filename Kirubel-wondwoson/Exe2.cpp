#include <iostream>
#include<ctype.h>
using namespace std;
int main()
{
  char L;

  cout<<"Enter the Letter: ";
  cin>>L;
  (L>='a'&& L<='z')?cout<<(char)toupper(L):cout<<(char)tolower(L);
  return 0;

}
 