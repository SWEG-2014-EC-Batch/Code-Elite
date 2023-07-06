#include <iostream>
using namespace std;
bool isLeapYear(int x);
int main(){
    int year;
    cout<<"Enter the year: ";
    cin>>year;
    if(isLeapYear(year)){
        cout<<"The year "<<year<<" is a leap year.";
    }
    else{
        cout<<"The year "<<year<<" is not a leap year.";
    }
}
bool isLeapYear(int x){
    if(x%4 == 0){
        if(x%100 == 0){
            if(x%400 == 0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}
