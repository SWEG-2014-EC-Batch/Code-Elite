#include <iostream>
#include <fstream>
using namespace std;

int main(){
    struct emp{
        string name;
        float rate;
        int hours;
        float regurlar;
        float overtime;
        float gross;
    };
    emp employees[4];
    ifstream infl("data.txt");
    int i = 0;
    while(infl.eof() == false){
        infl >> employees[i].name >> employees[i].rate >> employees[i].hours;
        i++;
    }
    for(int i = 0; i < 4; i++){
        if(employees[i].hours <= 40){
            employees[i].regurlar = employees[i].rate * employees[i].hours;
            employees[i].overtime = 0;
        }
        else{
            employees[i].regurlar = employees[i].rate * 40;
            employees[i].overtime = (employees[i].rate*1.5) * (employees[i].hours - 40);
        }
        employees[i].gross = employees[i].regurlar + employees[i].overtime;
    }
    cout<<"\t\t Pay report\n";
    cout<<"_____________________________________________________________________________________________________"<<endl;
    cout<<"\tName\t\t\tpay rate\thours\t  Regular pay\t  Overtime pay\t  Gross Pay"<<endl;
    cout<<"_____________________________________________________________________________________________________"<<endl;
    for(int i = 0; i < 4; i++){
        cout<<"\t"<<employees[i].name<<"\t|\t" << employees[i].rate<<"\t|\t" << employees[i].hours<<"\t|\t"<<employees[i].regurlar<<"\t|\t"<<employees[i].overtime<<"\t|\t"<<employees[i].gross<<endl;
    }
    cout<<"_____________________________________________________________________________________________________"<<endl;
}