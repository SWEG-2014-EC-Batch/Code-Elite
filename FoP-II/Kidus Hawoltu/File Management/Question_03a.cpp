#include <iostream>
#include <fstream>
using namespace std;

struct client{
    int accNumber;
    char firstName[10], lastName[15];
    double balance ;
} person;

void getdata();
void AddRecord();

int main(){	
    for(int i = 0; i<5; i++){
        AddRecord();
    }
    return 0;
}

void getdata(){
  cout<<"\nEnter account number : ";
  cin>>person.accNumber;
  cout<<"Enter first name : ";
  cin>>person.firstName;
  cout<<"Enter last name: ";
  cin>>person.lastName;
  cout<<"Enter account balance : ";
  cin>>person.balance;
}

void AddRecord(){
  ofstream outfl;
  outfl.open("Question_03.dat",ios::app|ios::binary);
  assert(outfl.is_open());

  getdata();
  outfl.write( (char *) &person, sizeof(person) );
  outfl.close();
}
