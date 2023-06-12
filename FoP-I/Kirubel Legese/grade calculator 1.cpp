#include<iostream>
using namespace std;
int main()
{
float Totalmark, quiz, assignment, projectmark, test, finaltest;
    cout<<"enter quiz mark out of 5% ";
    do{
        cin>>quiz;
        if(quiz<0 || quiz>5){
        cout<<"Re enter your quiz mark out of 5% ";
        }
    }while(quiz<0  || quiz>5);
    cout<<"enter assignment mark out of 10% ";
    do{  
          cin>>assignment;
        if(assignment<0 || assignment >10){
        cout<<"Re enter your assignment mark out of 10% ";
        }
    }while(assignment<0 || assignment >10);
    cout<<"enter project mark out of 20% ";
    do{
        cin>>projectmark;
        if(projectmark<0 || projectmark>20){
   cout<<"Re enter your projectmark out of 20% ";
        }
    }while(projectmark<0 || projectmark>20);       
    cout<<"enter test mark out of 15% ";
    do{
        cin>>test;
        if(test<0 || test>15){
        cout<<"Re enter your testmark out of 15% ";
        }
    }while(test<0 || test>15);
    cout<<"enter final test mark out of 50% ";
    do{
        cin>>finaltest;
        if(finaltest<0 || finaltest>50){
        cout<<"Re enter your final test mark out of 50% ";
        }
    }while(finaltest<0 || finaltest>50);
    Totalmark=quiz+assignment+projectmark+test+finaltest;
    cout<<"your Total mark is "<<Totalmark<<endl;
    if(Totalmark>=90){
    cout<<"your grade is A+";
    }
    else if(Totalmark>=80){
    cout<<"your grade is A";
    }
    else if(Totalmark>=75){
    cout<<"your grade is B+";
    }
    else if(Totalmark>=60){
    cout<<"your grade is B";
    }
    else if(Totalmark>=55){
    cout<<"your grade is B-";
    }
    else if(Totalmark>=45){
    cout<<"your grade is C";
    }
    else if(Totalmark>=30){
    cout<<"your grade is D";
    }
    else{
    cout<<"your grade is F";
    }
    return 0;
}