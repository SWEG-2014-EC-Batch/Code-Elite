#include <iostream> 
#include <fstream>  
using namespace std;

struct client{
    int accNumber;
    char firstName[10];
    char lastName[15];
    double balance ;
  } person;

void putData()
{
  cout<<"\n\t"<<person.accNumber;
  cout<<"\t"<<person.firstName;
  cout<<"\t\t"<<person.lastName;
  cout<<"\t\t'"<<person.balance;
}

void readData(int accountNum)
{
  fstream infl;
  infl.open("client.dat", ios::in|ios::binary); 

  cout<<"\nAccount Number\tFirst Name\tLast Name\tAccount balance\n";

  infl.read( (char *) &person, sizeof(person) ); 

  while(infl.eof() == false){
    if(accountNum == person.accNumber){
        putData();
        break;
    }
    infl.read( (char *) &person, sizeof(person) ); 
  }
  infl.close();
}

int main() {
    int account_num;
    cout<<"Enter account number: ";
    cin>>account_num;
   readData (account_num);
}
