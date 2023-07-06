#include <iostream>
using namespace std;

struct phone{
    int areaCode;
    int exchange;
    int number;
};
struct Person{
    string name;
    phone phoneNumber;
};

void input(Person*, int);
void print(Person*, int);

int main(){
    int n = 2;
    // cout<<"How many people are there? ";
    // cin>>n;
    Person *person = new Person[n];
    input(person, n);
    print(person, n);
    return 0;
}

void input(Person *person, int n){
    for(int i=0; i<n; ++i){
        cout<<"\nEnter person "<<i+1<<"\'s name: ";
        cin>>person[i].name;
        cout<<"Enter the area code of person "<<i+1<<": ";
        cin>>person[i].phoneNumber.areaCode;
        cout<<"Enter the exchange of person "<<i+1<<": ";
        cin>>person[i].phoneNumber.exchange;
        cout<<"Enter the rest of person "<<i+1<<"\'s phone number: ";
        cin>>person[i].phoneNumber.number;
    }
}

void print(Person *person, int n){
    cout<<"\nName\t  Phone Number";
    for(int i=0; i<n; ++i){
        cout<<endl<<person[i].name<<"\t("<<person[i].phoneNumber.areaCode<<") "<<person[i].phoneNumber.exchange<<'-'<<person[i].phoneNumber.number;
    }
}