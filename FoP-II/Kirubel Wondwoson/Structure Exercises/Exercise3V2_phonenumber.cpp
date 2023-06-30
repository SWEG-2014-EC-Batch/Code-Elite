#include <iostream>
using namespace std;
struct phone
{
    int areacode, exchange, number;
};
struct people
{
    string firstname, lastname;
    phone phoneNum;
};
int main()
{
    people person[10];
    for (int i = 0; i < 10; i++){
        cout << "First name(use 5 charater) : ";
        cin >> person[i].firstname;
        cout << "Last name(use 5 character) : ";
        cin >> person[i].lastname;
        cout << "Enter the area code of your phone number : ";
        cin >> person[i].phoneNum.areacode;
        cout << "Enter the exchange of your phone number : ";
        cin >> person[i].phoneNum.exchange;
        cout << "Enter the number of your phone number : ";
        cin >> person[i].phoneNum.number;
        cout << endl;
    }
    cout << "______________________________________________" << endl;
    cout << "First name      Last name        phone number " << endl;
    cout << "______________________________________________" << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout<<person[i].firstname<<"           "<<person[i].lastname<<"            "<<"("<<person[i].phoneNum.areacode<<") "<<person[i].phoneNum.exchange<<"-"<<person[i].phoneNum.number<<endl;
        cout << "______________________________________________" << endl;
    }
    return 0;
}