#include <iostream>
#include <fstream>
using namespace std;

struct Employee{
    char name[20];
    float rate, regularPay, overtimePay, grossPay;
    int hours;
};

ifstream employeeData;

void getData(string, Employee*, int&);
void display(Employee*, int);

int main(){
    Employee employee[10];
    int count;
    getData("Question_02.txt", employee, count);
    display(employee, count);
    return 0;
}

void getData(string fileName, Employee *employee, int &count){
    employeeData.open(fileName, ios::beg | ios::in);
    assert(employeeData.is_open());
    for(int i=0; !employeeData.eof(); ++i){
        employeeData.getline(employee[i].name, 20, '.');
        employeeData>>employee[i].rate;
        employeeData>>employee[i].hours;

        if(employee[i].hours > 40){
            employee[i].regularPay = employee[i].rate * 40;
            employee[i].overtimePay = 1.5 * employee[i].rate * (employee[i].hours - 40);
        }
        else{
            employee[i].regularPay = employee[i].rate * employee[i].hours;
            employee[i].overtimePay = 0;
        }
        employee[i].grossPay = employee[i].regularPay + employee[i].overtimePay;

        count++;
    }

    employeeData.close();
}

void display(Employee *employee, int count){
    cout<<"     Name\tRate\tHours\tRegular\tOvertime  Gross"<<endl;
    for(int i=0; i<count; ++i){
        cout<<employee[i].name<<'\t'<<employee[i].rate<<'\t'<<employee[i].hours<<'\t'<<employee[i].regularPay<<'\t'<<employee[i].overtimePay<<"\t   "<<employee[i].grossPay<<endl;
    }
}
