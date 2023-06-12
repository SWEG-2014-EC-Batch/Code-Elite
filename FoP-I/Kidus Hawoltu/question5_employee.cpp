/*Question 5
Design an algorithm and write aa to read an employee name weekly working hours,bonus rate per hour and base 
salary and find the employees grosss-salary,Net salary and bonus payment.(Hint:penision rate-5%,tax:15%)
*/
#include <iostream>
using namespace std;
int main()
{
    int weekly_working_hr, bonus_rate, base_salary, gross_salary, net_salary, bonus_payment;
    string employee_name;

    cout<<"Emoloyee's name ";
    cin>>employee_name;

    cout<<employee_name<<"'s Weekly working hours ";
    cin>>weekly_working_hr;

    cout<<employee_name<<"'s Bonus rate per hour ";
    cin>>bonus_rate;

    cout<<employee_name<<"'s Base Salary ";
    cin>>base_salary;

    if (weekly_working_hr>40)
        bonus_payment = bonus_rate * (weekly_working_hr - 40) * 4;
    else
        bonus_payment = 0;
    gross_salary = base_salary + bonus_payment;
    net_salary = gross_salary * 0.8;

    cout<<employee_name<<endl<<"  Gross Salary = "<<gross_salary<<endl<<"  Net Salary = "<<net_salary<<endl<<"  Bonus Payment = "<<bonus_payment;
    return 0;
}