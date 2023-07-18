#include <iostream>
#include <fstream>
#include <ctype.h>
#include<algorithm>
using namespace std;
struct Employee
{
    int id, workYr;
    char gender;
    float hourlyWage;
};
Employee employee[5];
void accept();
void sortInFile();
int main()
{
    sortInFile();
    return 0;
}
void sortInFile(){
    int i = 0;
    ofstream orecords("Q4.docx", ios::out);
    if(!orecords.is_open()){
        cout<<"Un able to open.";
        exit(1);
    }
    //accept from the user
    do{
        cout << "Id : ";
        cin >> employee[i].id;
        reenter:
        cout << "Gender('M'/'F') : ";
        employee[i].gender = toupper(employee[i].gender);
        cin >> employee[i].gender;
        // if(employee[i].gender != 'M' || employee[i].gender != 'F'){
        //     cout<<"Invalid."<<endl;;
        //     goto reenter;
        // }
        cout << "Hourly wage : ";
        cin >> employee[i].hourlyWage;
        cout << "Working year in a company : ";
        cin >> employee[i].workYr;
        i++;
    } while (i < 5);
    //sort in Accending order
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 1 ; j < 5 - i ; j++){
            if(employee[j-1].id > employee[j].id){
                swap(employee[j-1].id , employee[j].id);
            }
        }
    }
    //write in a file
    for(int i = 0 ; i < 5 ; i++){
        orecords << employee[i].id << "  "
                 << employee[i].gender << "  "
                 << employee[i].hourlyWage << "  "
                 << employee[i].workYr;
        orecords << endl;
    }
}