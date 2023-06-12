#include<iostream>
using namespace std;
int main()
{
    char message[]={"Vacation is near."},*ptr=message;
    for( ; *ptr!='\0';ptr++)
    {
        cout<<*ptr;
    }
}