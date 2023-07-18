#include<iostream>
#include<fstream>
using namespace std;
struct Employee{
    int id , hours,workYr;
    char gender;
    float hourlyWage , totalPay;
};
Employee employee[5];
int main(){
    double totalPay = 0;
    ifstream inputRecords("Q4.docx" , ios::in);
    int i = 0;
    do{
        inputRecords>>employee[i].id;
        inputRecords>>employee[i].gender;
        inputRecords>>employee[i].hourlyWage;
        inputRecords>>employee[i].workYr;
        cout<<"Enter hours "<<employee[i].id<<" worked in a month : "; 
        cin>>employee[i].hours;
        employee[i].totalPay= employee[i].hours*employee[i].hourlyWage;
        i++;
    }while(i<5);
    cout<<endl;  
    cout<<"_____________________________________"<<endl;
    cout<<" Monthly payement of each employee"<<endl;
    cout<<"______________________________________"<<endl;
    i=0;
    do{
        cout<<employee[i].id<<"'s monthly payement : "<<employee[i].totalPay;
        cout<<endl;
        i++;
    }while(i<5);
}