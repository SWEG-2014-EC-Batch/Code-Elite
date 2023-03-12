#include <iostream>
using namespace std;
int main(){
   /* this program calculates grade after asking
    quiz,test, assignment, project and final result*/
    float mark, quiz, test, finalExam, assignment, project;
    cout<<"Enter your Quiz Mark from 5%: ";
    do{
        cin>>quiz;
        if(quiz<0 || quiz>5){
            cout<<"You entered an invalid input. Please enter your quiz mark again: ";
        }
    }while(quiz<0 || quiz>5);
    cout<<"Enter your Test Mark form 15%: ";
    do{
        cin>>test;
        if(test<0 || test>15){
            cout<<"You entered an invalid input. Please enter your test mark again: ";
        }
    }while(test<0 || test>15);
    cout<<"Enter your Project mark from 20%: ";
    do{
        cin>>project;
        if(project<0 || project>20){
            cout<<"You entered an invalid input. Please enter your project mark again: ";
        }
    }while(project<0 || project>20);
    cout<<"Enter your assignment mark form 10%: ";
    do{
        cin>>assignment;
        if(assignment<0 || assignment>10){
            cout<<"You entered an invalid input. Please enter your assignment mark again: ";
        }
    }while(assignment<0 || assignment>10);
    cout<<"Enter your Final exam mark from 50%: ";
    do{
        cin>>finalExam;
        if(finalExam<0 || finalExam>50){
            cout<<"You entered an invalid input. Please enter your Final exam mark again: ";
        }
    }while(finalExam<0 || finalExam>50);
    mark = quiz + test + project + assignment + finalExam;
    cout<<"Your total mark from (100%) is: "<<mark<<endl;

    if(mark>=90){
        cout<<"Your grade is A+";
    }
    else if(mark>=80){
        cout<<"Your grade is A";
    }
    else if(mark>=75){
        cout<<"Your grade is B+";
    }
    else if(mark>=60){
        cout<<"Your grade is B";
    }
    else if(mark>=55){
        cout<<"Your grade is C+";
    }
    else if(mark>=45){
        cout<<"Your grade is C";
    }
    else if(mark>=30){
        cout<<"Your grade is D";
    }
    else{
        cout<<"Your grade is F";
    }
    return 0;
}