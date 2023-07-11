#include <iostream>
#include <fstream>
using namespace std;

int main(){
    struct student{
        string name;
        float exam1;
        float exam2;
        float homework;
        float finalExam;
        float grade;
        char gradeLetter;
    }stud[20];

    int num;
    cout<<"For how many students do you want to enter data(maximum 20): ";
    cin>>num;
    if(num>20){
        num = 20;
    }
    for(int i = 0; i < num; i++){
        cout<<"\nEnter name of student "<<i+1<<": ";
        cin>>stud[i].name;
        cout<<"Enter exam 1 result(out of 100): ";
        cin>>stud[i].exam1;
        cout<<"Enter exam 2 result(out of 100): ";
        cin>>stud[i].exam2;
        cout<<"Enter homework result(out of 100): ";
        cin>>stud[i].homework;
        cout<<"Enter final exam result(out of 100): ";
        cin>>stud[i].finalExam;
        stud[i].grade = 0.2 * stud[i].exam1 + 0.2 * stud[i].exam2 + 0.35 * stud[i].homework + 0.25 * stud[i].finalExam;
        if(stud[i].grade >= 90){
            stud[i].gradeLetter = 'A';
        }
        else if(stud[i].grade >= 80){
            stud[i].gradeLetter = 'B';
        }
        else if(stud[i].grade >= 70){
            stud[i].gradeLetter = 'C';
        }
        else if(stud[i].grade >= 60){
            stud[i].gradeLetter = 'D';
        }
        else if(stud[i].grade < 60){
            stud[i].gradeLetter = 'F';
        }
    }    
    cout<<"\t\t Grade report\n";
    cout<<"_____________________________________________________________________________________________________"<<endl;
    cout<<"\tName\t\tExam 1\t\tExam 2\t  Homework\t  Final Exam\t  Grade\t\t Grade Letter"<<endl;
    cout<<"_____________________________________________________________________________________________________"<<endl;
    for(int i = 0; i < num; i++){
        cout<<"\t"<<stud[i].name<<"\t|\t" << stud[i].exam1<<"\t|\t" << stud[i].exam2<<"\t|\t"<<stud[i].homework<<"\t|\t"<<stud[i].finalExam<<"\t|\t"<<stud[i].grade<<"\t|\t"<<stud[i].gradeLetter<<endl;
    }
    cout<<"_____________________________________________________________________________________________________"<<endl;
    ofstream outfl("Question_06.txt", ios::out);
    assert(outfl.is_open());
    for(int i = 0; i < num ; i++){
        outfl<<stud[i].name<<" " << stud[i].exam1<<" " << stud[i].exam2<<" "<<stud[i].homework<<" "<<stud[i].finalExam<<" "<<stud[i].grade<<" "<<stud[i].gradeLetter<<endl;
    }
    outfl.close();
    return 0;
}
