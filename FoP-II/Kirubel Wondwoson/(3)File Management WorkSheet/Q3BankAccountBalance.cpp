#include<iostream>
#include<fstream>
#include<ctype.h>
using namespace std;
struct Account{
    long long int accNum;
    string fname, lname;
    double balance;
};
Account accounts[5], account;
void readAndDisplay(Account);
int main()
{
    cout<<"What is your Account number? \n CBE account number : ";
    cin>>account.accNum;
    readAndDisplay(account);
    return 0;
}
void readAndDisplay(Account account){
    ifstream inputrecords("Q3BankRecord.doc", ios::in);
    if(!inputrecords.is_open()){
        cout<<"Unable to open.";
    }
    int i = 0;
    do{
        inputrecords>>accounts[i].accNum>>accounts[i].fname>>accounts[i].lname>>accounts[i].balance;
        if(account.accNum == accounts[i].accNum){
            cout<<"______________________________________________________"<<endl;
            cout<<"Account Number  First name   Last name       Balance"<<endl;
            cout<<"______________________________________________________"<<endl;
            cout<<accounts[i].accNum<<"  "<<accounts[i].fname<<"      "<<accounts[i].lname<<"        "<<accounts[i].balance;
            break;
        }
        i++;
    }while(i<5); 
    if(account.accNum != accounts[i].accNum){
            cout<<"Sorry, your account number doesn't not exist in our database";
    }
}