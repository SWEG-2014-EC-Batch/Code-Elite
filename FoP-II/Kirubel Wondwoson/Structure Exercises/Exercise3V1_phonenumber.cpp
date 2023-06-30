#include <iostream>
using namespace std;
struct phone
{
    int areacode , exchange , number;   
};
phone phone1 = {212 , 767 , 8900}, phone2;
int main()
{
    cout<<"("<<phone1.areacode<<")"<<" "<<phone1.exchange<<"-"<<phone1.number<<endl;
    cout<<"Enter the area code : ";
    cin>>phone2.areacode;
    cout<<"Enter the exchange number : ";
    cin>>phone2.exchange;
    cout<<"Enter the number : ";
    cin>>phone2.number;
    
    cout<<"("<<phone2.areacode<<")"<<" "<<phone2.exchange<<"-"<<phone2.number;
    return 0;
}