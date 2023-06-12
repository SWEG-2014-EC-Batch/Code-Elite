#include <iostream>
using namespace std;
int main(){
    float netSalary,grossSalary,taxRate,bonusRate,workedHours,bonusPayment, pension;
    int num;
    cout<<"Please enter the number of Employees you want to calculate the net salary for: ";
    cin>>num;
    for(int n = 1;n<=num;n++){
        cout<<"Please enter the gross salary of employee number "<<n<<": ";
        cin>>grossSalary;
        cout<<"Please enter the worked hours of employee number "<<n<<": ";
        cin>>workedHours;
        
        if(workedHours>40){
            cout<<"Please enter the employee's Bonus payment rate per hour(in %): ";
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
        cout<<"The Net Salary of employee number "<<n<<" is "<<netSalary<<endl;
    }
}