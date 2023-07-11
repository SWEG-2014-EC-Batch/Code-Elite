#include <iostream>
#include <fstream>
using namespace std;

struct client{
    int accNumber;
    char firstName[10];
    char lastName[15];
    double balance ;
  } person;

void getdata(){
  cout<<"Enter account number : ";
  cin>>person.accNumber;
  cout<<"\nEnter first name : ";
  cin>>person.firstName;
  cout<<"\nEnter last name: ";
  cin>>person.lastName;
  cout<<"\nEnter account balance : ";
  cin>>person.balance;
}

void AddRecord(){
  ofstream outfl;
  outfl.open("client.dat",ios::app|ios::binary);

  getdata();
  outfl.write( (char *) &person, sizeof(person) );
  outfl.close();
}

int main()
{	
    for(int i = 0; i<5; i++){
        AddRecord();
    }
    return 0;
}

