#include <iostream>
using namespace std;

int main(){
    struct phone {
        int areaCode;
        int exchange;
        int number;
    };
    phone phone1, phone2 = {212, 767, 8900};
    cout<<"Enter an area code(three numbers): ";
    cin>>phone1.areaCode;
    cout<<"Enter an exchange(three numbers): ";
    cin>>phone1.exchange;
    cout<<"Enter a number(four numbers): ";
    cin>>phone1.number;

    cout<<"The phone numbers are:\n";
    cout<<"("<<phone1.areaCode<<") "<<phone1.exchange<<"-"<<phone1.number<<endl;
    cout<<"("<<phone2.areaCode<<") "<<phone2.exchange<<"-"<<phone2.number<<endl;
}