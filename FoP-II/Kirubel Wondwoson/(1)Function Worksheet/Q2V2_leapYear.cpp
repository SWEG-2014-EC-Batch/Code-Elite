#include <iostream>
using namespace std;
bool isLeapYear(int year);
int main()
{
    int yr;
    cout<<"Enter the year(like 2023): ";
    cin>>yr;
    if(isLeapYear(yr))
    {
        cout<<yr<<" is a leap year";
    }
    else{
        cout<<yr<<" is not a leap year";
    }
}
bool isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}