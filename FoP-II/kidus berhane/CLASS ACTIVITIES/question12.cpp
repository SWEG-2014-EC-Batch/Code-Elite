#include<iostream>
using namespace std;
void calcQuotient (double n1,double n2,double &answer);
int main()
{
   double num1,num2, quotient;
   cout<<"enter the first number: ";
   cin>>num1;
   cout<<"enter the second number: ";
   cin>>num2;
   calcQuotient(num1,num2, quotient);
    return 0;
}
void calcQuotient (double n1,double n2,double &answer)
{
    answer = n1/n2;
    cout<<answer;
}
