#include<iostream>
using namespace std;
int main()
{
    float gross salary,worked hours,income tax rate,overtime bonus rate/hour,overtime payment,net salary;
    cout<<"Enter gross salary of employee ";
    cin>>gross salary;
    cout<<"Enter income tax rate of employee";
    cin>>income tax rate;
    cout<<"Enter worked hour";
    cin>>worked hour;
    if(worked hour>40){
    cout<<"Enter overtime bonus rate/hour";
    overtime payment=overtime bonus rate/hour*(worked hour-40);
    net salary=gross salary-0.07(gross salary)-income tax rate(gross salary)+overtime payment;
    cout<<"The employee's net salary is "<<net salary<<endl;
    }
    else if(worked hour<40){
    net salary=gross salary-0.07(gross salary)-income tax rate(gross salary);
    cout<<"The employee's net salary is "<<net salary<<endl;
    }
}
    
    
    
    
    