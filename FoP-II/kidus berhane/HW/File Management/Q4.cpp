#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
using namespace std;

struct Employee{
    char id[20], sex;
    float hourlyWage;
    int years;
};

struct Employee2{
    char id[10], sex;
    float hourlyWage, totalPay;
    int years, hours;
};

ofstream writeOnFile;
ifstream readFile;
fstream updateFile;

void getData(Employee*, int);
void order(Employee*, int);
void swap(Employee&, Employee&);
void writeToFile(char*, Employee*, int);

void readingFile(char*, Employee2*, int);
void display(Employee2*, int);

void modifyFile(char*, Employee*, int);

int main(){
    int n;
    Employee employee[10], updatedEmployee[10];
    Employee2 employee2[2];
    //n=10

    //Question 1
    cout<<"Enter the number of Employees(max 10): ";
    cin>>n;
    if(n>10){
        n=10;
    }
    getData(employee, n);
    writeToFile("Question_04.txt", employee, n);

    //Question 2
    readingFile("Question_04.txt", employee2, 3);
    display(employee2, 3);

    //Question 3
    modifyFile("Question_04.txt", updatedEmployee, n);
    return 0;
}

void getData(Employee *employee, int n){
    for(int i=0; i<n; ++i){
        cout<<"\nEnter the ID of Employee "<<i+1<<": ";
        cin>>employee[i].id;
        cout<<"Enter the sex(M/F) of Employee "<<i+1<<": ";
        cin>>employee[i].sex;
        employee[i].sex = toupper(employee[i].sex);
        cout<<"Enter the hourly wage of Employee "<<i+1<<": ";
        cin>>employee[i].hourlyWage;
        cout<<"Enter the number of years Employee "<<i+1<<" has worked: ";
        cin>>employee[i].years;
    }
    order(employee, n);
}

void order(Employee *employee, int n){
    for(int i=0; i<n-1; ++i){
        for(int j=i+1; j<n; ++j){
            if(strcmp(employee[i].id, employee[j].id) > 0){
                swap(employee[i], employee[j]);
            }
        }
    }
}

void swap(Employee &employee1, Employee &employee2){
    Employee temp = employee1;
    employee1 = employee2;
    employee2 = temp;
}

void writeToFile(char* fileName, Employee *employee, int n){
    writeOnFile.open(fileName, ios::beg | ios::out);
    assert(writeOnFile.is_open());

    for(int i=0; i<n; ++i){
        writeOnFile.seekp(0, ios::end);
        writeOnFile<<employee[i].id<<". "<<employee[i].sex<<' '<<employee[i].hourlyWage<<' '<<employee[i].years<<' ';
    }

    writeOnFile.close();
}

void readingFile(char* fileName, Employee2 *employee, int n){
    readFile.open(fileName, ios::beg | ios::in);
    assert(readFile.is_open());

    for(int i=0; i<n; ++i){
        readFile.getline(employee[i].id, 10, '.');
        readFile.seekg(1, ios::cur);
        readFile.get(employee[i].sex);
        readFile>>employee[i].hourlyWage>>employee[i].years;
        readFile.seekg(1, ios::cur);

        cout<<"\nEnter the number of hours "<<employee[i].id<<" worked this month: ";
        cin>>employee[i].hours;
        employee[i].totalPay = employee[i].hourlyWage * employee[i].hours;
    }

    readFile.close();
}

void display(Employee2 *employee, int n){
    cout<<" ID\t\tSex\tTotal Pay"<<endl;
    for(int i=0; i<n; ++i){
        cout<<employee[i].id<<'\t'<<employee[i].sex<<'\t'<<employee[i].totalPay<<endl;
    }
}

void modifyFile(char* fileName, Employee *employee, int n){
    char searchID[10], newID[10], newSex, a;
    int index = -1, newYear;
    float newHourlyWage;

    readFile.open(fileName, ios::beg | ios::in);
    assert(readFile.is_open());

    cout<<"\nEnter the Id of the employee you want to change: ";
    cin>>searchID;
    for(int i=0; i<n; ++i){
        readFile.getline(employee[i].id, 10, '.');
        readFile.seekg(1, ios::cur);
        readFile.get(employee[i].sex);
        readFile>>employee[i].hourlyWage>>employee[i].years;
        if(strcmp(searchID, employee[i].id) == 0){
            index = i;
        }
        readFile.seekg(1, ios::cur);
    }
    readFile.close();

    if(index != -1){
        cout<<"\nEnter the new Id(Enter . to keep the old one): ";
        cin>>newID;
        cout<<"Enter sex(Enter x to keep the old one): ";
        cin>>newSex;
        newSex = toupper(newSex);
        cout<<"Enter the new hourly wage(Enter -1 to keep the old one): ";
        cin>>newHourlyWage;
        cout<<"Enter the new number of years(Enter -1 to keep the old one): ";
        cin>>newYear;

        if(strcmp(newID, ".") != 0){
            strcpy(employee[index].id, newID);
        }
        if(newSex != 'X'){
            employee[index].sex = newSex;
        }
        if(newHourlyWage != -1){
            employee[index].hourlyWage = newHourlyWage;
        }
        if(newYear != -1){
            employee[index].years = newYear;
        }

        order(employee, n);
        writeToFile(fileName, employee, n);
    }
    else{
        cout<<"The Id couldn't be found!!"<<endl;
    }
}
