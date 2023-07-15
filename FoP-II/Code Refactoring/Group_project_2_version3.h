#ifndef GROUP_PROJECT_2_VERSION3_H
#define GROUP_PROJECT_2_VERSION3_H

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <assert.h>
using namespace std;

struct Student{
    string id, *gradeMark;
    bool error;
    float *subjectMark, *point, totalMark, totalPoint, totalCourse, average, cgpa, totalCrHr;
};

struct Course{
    string name;
    unsigned int crHr;
};

void input(int&, int&);  //inputs number of students and number of courses(subjects)
void input(Course*, int);  //inputs name and credit hour of each course
void input(Student*, int);  //inputs Id of each student
void input(Course*, Student*, int, int);  //inputs the mark of every subject for each student
void markToGrade(Student*, int, int);  //converts the marks to grades and points
void calculate(Course*, Student*, int, int);  //calculates average and cgpa for each student
void order(string*, int, int, int*, bool*, bool = true);  //determines the order of students based on their ids (primarily in ascending order)
void order(float*, int, int, int*, bool*, bool = false);  //determines the order of students based on their results (primarily in descending order)
void display(Course*, Student*, int*, int, int, int = 1);  //displays the table

void input(int &studNum, int &courseNum){
    cout<<"Enter the number of students: ";
    cin>>studNum;
    cout<<"Enter the number of courses: ";
    cin>>courseNum;
    assert(studNum >= 0 && courseNum >=0);
}

void input(Course *course, int courseNum){
    for(int i=0; i<courseNum; ++i){
        cout<<endl<<"Enter the name of course "<<i+1<<" (use 4 characters): ";
        cin>>course[i].name;
        if((course[i].name).length() != 4){
            cout<<"Please use 4 characters: ";
            cin>>course[i].name;
        }
        assert(course[i].name.length() == 4);

        cout<<"Enter the credit hour of "<<course[i].name<<" : ";
        cin>>course[i].crHr;
    }
}

void input(Student *student, int studNum){
    for(int i=0; i<studNum; ++i){
        int count=0;
        do{
            student[i].error = false;
            cout<<endl<<"Enter the ID of student "<<i+1<<" (like ETS0000/10): ";
            cin>>student[i].id;
            if(student[i].id.length() != 10){
                cout<<"Please use 10 characters (like ETS0000/10): ";
                cin>>student[i].id;
            }
            if(student[i].id.length() != 10){
                count = 3;
                student[i].error = true;
            }
            else{
                for(int j=0; j<i; ++j){
                    if(student[i].id == student[j].id){
                        cout<<"<<The student is already in database.>>"<<endl;
                        count++;
                        student[i].error = true;
                        break;
                    }
                }
            }
            
        }while(student[i].error && count<3);
    }
}

void input(Course *course, Student *student, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        cout<<endl;
        if(!student[i].error){
            for(int j=0; j<courseNum; ++j){
                int count = 0;
                do{
                    cout<<"Enter the mark of "<<course[j].name<<" for "<<student[i].id<<" (enter '101' for NG): ";
                    cin>>student[i].subjectMark[j];
                    if((student[i].subjectMark[j] >= 0 && student[i].subjectMark[j] <= 100) || student[i].subjectMark[j] == 101){
                        break;
                    }
                    else{
                        cout<<"<<You entered wrong input!! ";
                        if(count<2){
                            cout<<"Try again!>>";
                        }
                        cout<<endl;
                    }
                    count++;
                }while(count<3);
            }
        }
    }
}

void markToGrade(Student *student, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        if(!student[i].error){
            for(int j=0; j<courseNum; ++j){
                if(student[i].subjectMark[j] < 0 || student[i].subjectMark[j] > 100){
                    student[i].gradeMark[j] = "NG";
                    student[i].point[j] = 0;
                    student[i].subjectMark[j] = 0;
                }
                else if(student[i].subjectMark[j] >= 85){
                    student[i].point[j] = 4.0;
                    student[i].gradeMark[j] = "A ";
                }
                else if(student[i].subjectMark[j] >= 75){
                    student[i].point[j] = 3.5;
                    student[i].gradeMark[j] = "B+";
                }
                else if(student[i].subjectMark[j] >= 70){
                    student[i].point[j] = 3.0;
                    student[i].gradeMark[j] = "B ";
                }
                else if(student[i].subjectMark[j] >= 60){
                    student[i].point[j] = 2.5;
                    student[i].gradeMark[j] = "C+";
                }
                else if(student[i].subjectMark[j] >= 50){
                    student[i].point[j] = 2.0;
                    student[i].gradeMark[j] = "C ";
                }
                else if(student[i].subjectMark[j] >= 40){
                    student[i].point[j] = 1.5;
                    student[i].gradeMark[j] = "D ";
                }
                else{
                    student[i].point[j] = 0.0;
                    student[i].gradeMark[j] = "F ";
                }                
            }
        }
    }
}

void calculate(Course *course, Student *student, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        if(!student[i].error){
            for(int j=0; j<courseNum; ++j){
                if(student[i].gradeMark[j] != "NG"){
                    student[i].totalCourse++;
                    student[i].totalMark += student[i].subjectMark[j];
                    student[i].totalCrHr += course[j].crHr;
                    student[i].totalPoint += (course[j].crHr * student[i].point[j]);
                }
            }
            if(student[i].totalCourse != 0){
                student[i].average = student[i].totalMark / student[i].totalCourse;
            }
            if(student[i].totalCrHr != 0){
                student[i].cgpa = student[i].totalPoint / student[i].totalCrHr;
            }
        }
    }
}

void order(string *id, int n, int studNum, int *orders, bool *error, bool isascending){
    string lastId, orderId;
    lastId = id[0];
    for(int i=0; i<studNum; ++i){
        if(error[i]){
            continue;
        }
        if(isascending){
            if(lastId <= id[i]){
                lastId = id[i];
                orders[n-1] = i;
            }
        }
        else{
            if(lastId >= id[i]){
                lastId = id[i];
                orders[n-1] = i;
            }
        }
    }
    for(int i=0; i<n; ++i){
        orderId = lastId;
        for(int j=0; j<studNum; ++j){
            if(error[j]){
                continue;
            }
            int count=0;
            for(int k=0; k<i; ++k){
                if(j == orders[k]){
                    count += 1;
                    break;
                }
            }
            if(count==1){
                continue;
            }
            if(isascending){
                if(orderId >= id[j]){
                    orderId = id[j];
                    orders[i] = j;
                }
            }
            else{
                if(orderId <= id[j]){
                    orderId = id[j];
                    orders[i] = j;
                }
            }
        }
    }
}

void order(float *num, int n, int studNum, int *orders, bool *error, bool isascending){
    float lastValue, orderValue;
    lastValue = num[0];
    for(int i=0; i<studNum; ++i){
        if(error[i]){
            continue;
        }
        if(isascending){
            if(lastValue <= num[i]){
                lastValue = num[i];
                orders[n-1] = i;
            }
        }
        else{
            if(lastValue >= num[i]){
                lastValue = num[i];
                orders[n-1] = i;
            }
        }
    }
    for(int i=0; i<n; ++i){
        orderValue = lastValue;
        for(int j=0; j<studNum; ++j){
            if(error[j]){
                continue;
            }
            int count=0;
            for(int k=0; k<i; ++k){
                if(j == orders[k]){
                    count += 1;
                    break;
                }
            }
            if(count==1){
                continue;
            }
            if(isascending){
                if(orderValue >= num[j]){
                    orderValue = num[j];
                    orders[i] = j;
                }
            }
            else{
                if(orderValue <= num[j]){
                    orderValue = num[j];
                    orders[i] = j;
                }
            }
        }
    }
}

void display(Course *course, Student *student, int *orders, int studNum, int courseNum, int n){
    
    //displaying the upper borders of the table
    cout<<"______________";
    for(int i=0; i<courseNum; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl;

    cout<<" Stud. ID       ";
    for(int i=0; i<courseNum; ++i){
        cout<<"    "<<course[i].name<<"        ";
    }
    cout<<"Average    CGPA"<<endl;

    cout<<"              ";
    for(int i=0; i<courseNum; ++i){
        cout<<"________________";
    }
    cout<<endl;

    cout<<"                ";
    for(int i=0; i<courseNum; ++i){
        cout<<"Mark : Grade    ";
    }
    cout<<endl;

    cout<<"______________";
    for(int i=0; i<courseNum; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl;

    //displaying each row of the table
    for(int i=0; i<n; ++i){
        cout<<' '<<student[orders[i]].id<<"   ";
        for(int j=0; j<courseNum; ++j){
            if(student[orders[i]].gradeMark[j] == "NG"){
                cout<<"    "<<student[orders[i]].gradeMark[j]<<" : "<<student[orders[i]].gradeMark[j]<<"     ";
                continue;
            }
            cout<<"    "<<student[orders[i]].subjectMark[j]<<" : "<<student[orders[i]].gradeMark[j]<<"     ";
        }
        if(student[orders[i]].totalCourse == 0){
            cout<<"    --        --"<<endl<<endl;
            continue;
        }
        cout<<"    "<<student[orders[i]].average<<"        "<<student[orders[i]].cgpa<<endl;
        if(i<n-1){
            cout<<endl;
        }
    }

    //displaying the lower borders of the table
    cout<<"______________";
    for(int i=0; i<courseNum; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl<<endl;

    for(int i=0; i<n; ++i) orders[i] = 0;  //resetting orders
}

#endif
