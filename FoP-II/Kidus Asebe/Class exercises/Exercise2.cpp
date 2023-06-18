#include<iostream>199
using namespace std;
int leap (int year1);
int main()
{
    int year;
    cout<<"enter the year: ";
    cin>>year;
    cout<<leap(year);
    return 0;
}
int leap ( int year1){
    if(year1%4==0)
    {
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}

