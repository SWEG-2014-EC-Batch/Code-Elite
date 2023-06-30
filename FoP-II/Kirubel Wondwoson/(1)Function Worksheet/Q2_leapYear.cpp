#include<iostream>
using namespace std;
int isLeapYear();
int main()
{
    isLeapYear();
    return 0;
}
int isLeapYear()
{
    int year;
    cout<<"Enter a year (like 2023) : ";
    cin>>year;                                    
    if(year % 4 != 0){                      // or the condition can be restrictesd as 
        cout<<"0";                           // if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
    }                                  
    else{
        if(year % 100 == 0 && year %400 != 0){
            cout<<"0";
        }
        else{
            cout<<"1";
        }
    }
    return 0;
}