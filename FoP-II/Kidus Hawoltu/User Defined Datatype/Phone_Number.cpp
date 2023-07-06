#include <iostream>
using namespace std;
int main(){
    struct phone{
        int areaCode;
        int exchange;
        int number;
    };
    phone phone1 = {212, 767, 8900}, phone2;
    cout<<"Enter the area code: ";
    cin>>phone2.areaCode;
    cout<<"Enter the exchange: ";
    cin>>phone2.exchange;
    cout<<"Enter the number: ";
    cin>>phone2.number;
    cout<<'('<<phone1.areaCode<<") "<<phone1.exchange<<'-'<<phone1.number<<endl;
    cout<<'('<<phone2.areaCode<<") "<<phone2.exchange<<'-'<<phone2.number<<endl;
    return 0;
}
