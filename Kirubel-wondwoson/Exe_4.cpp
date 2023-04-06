#include<iostream>
using namespace std;
int main()
{
    int choise;
    cout<<"Enter your choise:";
    cin>>choise;
    switch (choise)
    {
    case 1:
    cout<<"coffee";
        break;
    case 2:
    cout<<"Tea";
        break;
    case 3:
    cout<<"water";
        break;
    default:
    cout<<"Invalied input";
        break;
    }


}