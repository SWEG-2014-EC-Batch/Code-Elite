#include <iostream>
using namespace std;
int main(){
    float netSalary, grossSalary, taxRate, bonusRate, workedHours, bonusPayment, pension;
    int num;
    cout<<"Enter the number of Employees you want to calculate the net salary for: ";
    cin>>num;
    for(int i = 1;i<=num;i++){
        cout<<"Enter the gross salary of employee number "<<i<<": ";
        cin>>grossSalary;
        cout<<"Enter the worked hours of employee number "<<i<<": ";
        cin>>workedHours;
        
        if(workedHours>40){
            cout<<"Enter the employee's Bonus payment rate per hour(in %): ";
            cin>>bonusRate;
            bonusPayment = bonusRate * (workedHours - 40);
        }
        else{
            bonusPayment = 0;
        }
        if(grossSalary<200 && grossSalary>=0){
            taxRate = 0;
        }
        else if(grossSalary<600){
            taxRate = 10;
        }
        else if(grossSalary<1200){
            taxRate = 15;
        }
        else if(grossSalary<2000){
            taxRate = 20;
        }
        else if(grossSalary<3500){
            taxRate = 25;
        }
        else if(grossSalary>3500){
            taxRate = 30;
        }
        pension = grossSalary * 0.07;
        netSalary = (grossSalary - pension + bonusPayment)*(1 - taxRate/100);
        cout<<"The Net Salary of employee number "<<i<<" is "<<netSalary<<endl;
    }
}