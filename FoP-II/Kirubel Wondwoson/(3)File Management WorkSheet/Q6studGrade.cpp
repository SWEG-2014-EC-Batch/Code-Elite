#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct Stud{
    char name[15];
    float exam1,exam2,homeWork,finalExam,finalGrade;
    char grade,letterGrade;
};
Stud stud[20];
void getdata();
void display();
int main()
{
    getdata();
    display();
    return 0;
}
void getdata(){
    int i = 0;
    do{
        cout<<"Enter your name : ";
        cin>>stud[i].name;
        cout<<"Enter exam 1 result : ";
        cin>>stud[i].exam1;
        cout<<"Enter exam 2 result : ";
        cin>>stud[i].exam2;
        cout<<"Enter homework result : ";
        cin>>stud[i].homeWork;
        cout<<"Enter final exam result : ";
        cin>>stud[i].finalExam;
        if(strlen(stud[i].name) > 15 || stud[i].exam1 < 0 || stud[i].exam2 < 0 || stud[i].homeWork < 0 || 
           stud[i].homeWork < 0 ){
           cout<<"Invalid input.";    
        }
        i++;
    }while(i<20);
}
void display(){
    ofstream writetofile("Q6.txt",ios::out);
    int i = 0;
    do{
        stud[i].finalGrade = 0.20*stud[i].exam1+0.20*stud[i].exam2+0.35*stud[i].homeWork + 0.25*stud[i].finalExam;
        if(stud[i].finalGrade < 0 || stud[i].finalGrade > 100){
            continue;
        }
        else if(stud[i].finalGrade > 90){
            stud[i].letterGrade = 'A';
        }
        else if(stud[i].finalGrade > 80 ){
            stud[i].letterGrade = 'B';
        }
        else if(stud[i].finalGrade > 70){
            stud[i].letterGrade = 'C';
        }
        else if(stud[i].finalGrade > 60){
            stud[i].letterGrade = 'D';
        }
        else{
            stud[i].letterGrade = 'F';
        }
        writetofile<<stud[i].name<<"   "<<stud[i].finalGrade<<"  "<<stud[i].letterGrade<<endl;
        i++;
    }while(i<20);
}