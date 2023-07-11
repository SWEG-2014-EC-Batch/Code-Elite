#include<iostream>
using namespace std;

int main()
{
    struct stud_data
    {
      char id[20];
      string name;
      float testMark;
      float finalMark,totalMark;
    };

    stud_data stud1;
    cout<<"enter your name: ";
    cin>>stud1.name;
    cout<<"enter your id: ";
    cin>>stud1.id;
    cout<<"enter your test mark out of 50: ";
    cin>>stud1.testMark;
    
    cout<<"enter your final mark out of 50: " ;
    cin>>stud1.finalMark;

    stud1.totalMark=stud1.testMark+stud1.finalMark;
    cout<<"Name: "<<stud1.name<<endl;
    cout<<"ID: "<<stud1.id<<endl;
    cout<<"Total mark out of 100: "<<stud1.totalMark<<endl;


    return 0;
    
}