#include<iostream>
#include<fstream>
using namespace std;
struct Employee{
    int id, workYr;
    char gender;
    float hourlyWage;
};
Employee employee[5];
void read();
void update();
int main(){
    read();
    update();
    return 0;
}
void read(){
    ifstream irecords("Q4.docx", ios::in);
    if(!irecords.is_open()){
        cout<<"Un able to open.";
        exit(1);
    }
    int i = 0;
    do{
        irecords>>employee[i].id      
               >>employee[i].gender
               >>employee[i].hourlyWage   
               >>employee[i].workYr;
               //update working year by 5 year
               employee[i].workYr += 5;
        i++;
    }while(i<5);
    irecords.clear();
}
void update(){
    ofstream orecords("Q4.docx", ios::out);
    if(!orecords.is_open()){
        cout<<"Un able to open.";
        exit(1);
    }
    int i=0;
    orecords<<"_________"<<endl
           <<" Updated "<<endl
           <<"_________"<<endl;
    do{
        orecords<<employee[i].id<<"  "
               <<employee[i].gender<<"  "
               <<employee[i].hourlyWage<<"  "
               <<employee[i].workYr
               <<endl;
               i++;
    }while(i<5);
}
