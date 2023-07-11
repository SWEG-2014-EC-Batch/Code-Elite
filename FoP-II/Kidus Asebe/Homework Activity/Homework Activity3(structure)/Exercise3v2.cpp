#include <iostream>
using namespace std;

int main(){
    struct person {
        string name;
    };
    struct phone {
        int areaCode;
        int exchange;
        int number;
        person owner;
    };
    phone phoneNo[10];

    for(int i = 0; i < 10; ++i){
        int phoneNumber;
        cout<<"Enter phone number(10 digits): ";
        cin>>phoneNumber;
        cout<<"Enter phone number owner's name: ";
        cin>>phoneNo[i].owner.name;

        phoneNo[i].number = phoneNumber % 10000;
        phoneNumber /= 10000;
        phoneNo[i].exchange = phoneNumber % 1000;
        phoneNumber /= 1000;
        phoneNo[i].areaCode = phoneNumber;

    }
    cout<<"________________________________________"<<endl;
    cout<<"|\tPhone book\t\t|\n";
    cout<<"________________________________________"<<endl;
    cout<<"|\tName\t|\tPhone numbers\t|\n";
    cout<<"________________________________________"<<endl;
    for(int i = 0; i < 10; ++i){
        cout<<"|\t"<<phoneNo[i].owner.name<<"\t|\t"<<"("<<phoneNo[i].areaCode<<") "<<phoneNo[i].exchange<<"-"<<phoneNo[i].number<<"\t|"<<endl;
    }
    cout<<"----------------------------------------"<<endl;
}