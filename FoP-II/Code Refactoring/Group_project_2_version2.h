#ifndef GROUP_PROJECT_2_VERSION2_H
#define GROUP_PROJECT_2_VERSION2_H

#include <iostream>
#include <ctype.h>
#include <string.h>
#include <assert.h>
using namespace std;

void input(int&, int&);  //inputs number of students and number of courses(subjects)
void input(string*, unsigned int*, int);  //inputs name and credit hour of each course
void input(string*, bool*, int);  //inputs Id of each student
void input(string*, string*, float**, bool*, int, int);  //inputs the mark of every subject for each student
void markToGrade(float**, float**, string**, bool*, int, int);  //converts the marks to grades and points
void calculate(string**, float**, float*, float*, float*, bool*, int, int);  //calculates average for each student
void calculate(string**, float**, unsigned int*, float*, float*, float*, bool*, int, int);  //calculates cgpa for each student
void order(string*, int, int, int*, bool*, bool = true);  //determines the order of students based on their ids (primarily in ascending order)
void order(float*, int, int, int*, bool*, bool = false);  //determines the order of students based on their results (primarily in descending order)
void display(string*, string*, string**, float**, float*, float*, float*, int*, int, int, int = 1);  //displays the table

void input(int &studNum, int &courseNum){
    cout<<"Enter the number of students: ";
    cin>>studNum;
    cout<<"Enter the number of courses: ";
    cin>>courseNum;
    assert(studNum >= 0 && courseNum >=0);
}

void input(string *name, unsigned int *creditHr, int courseNum){
    for(int i=0; i<courseNum; ++i){
        cout<<endl<<"Enter the name of course "<<i+1<<" (use 4 characters): ";
        cin>>name[i];
        if((name[i]).length() != 4){
            cout<<"Please use 4 characters: ";
            cin>>name[i];
        }
        assert(name[i].length() == 4);

        cout<<"Enter the credit hour of "<<name[i]<<" : ";
        cin>>creditHr[i];
    }
}

void input(string *id, bool *error, int studNum){
    for(int i=0; i<studNum; ++i){
        int count=0;
        do{
            error[i] = false;
            cout<<endl<<"Enter the ID of student "<<i+1<<" (like ETS0000/10): ";
            cin>>id[i];
            if(id[i].length() != 10){
                cout<<"Please use 10 characters (like ETS0000/10): ";
                cin>>id[i];
            }
            if(id[i].length() != 10){
                count += 1;
                error[i] = true;
            }
            else{
                for(int j=0; j<i; ++j){
                    if(id[i] == id[j]){
                        cout<<"<<The student is already in database.>>"<<endl;
                        count = 3;
                        error[i] = true;
                        break;
                    }
                }
            }
            
        }while(error[i] && count<3);
    }
}

void input(string *courseName, string *id, float **mark, bool *error, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        cout<<endl;
        if(!error[i]){
            for(int j=0; j<courseNum; ++j){
                int count = 0;
                do{
                    cout<<"Enter the mark of "<<courseName[j]<<" for "<<id[i]<<" (enter '101' for NG): ";
                    cin>>mark[i][j];
                    if((mark[i][j] >= 0 && mark[i][j] <= 100) || mark[i][j] == 101){
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

void markToGrade(float **mark, float **point, string **grade, bool *error, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        if(!error[i]){
            for(int j=0; j<courseNum; ++j){
                if(mark[i][j] < 0 || mark[i][j] > 100){
                    grade[i][j] = "NG";
                    point[i][j] = 0;
                    mark[i][j] = 0;
                }
                else if(mark[i][j] >= 85){
                    point[i][j] = 4.0;
                    grade[i][j] = "A ";
                }
                else if(mark[i][j] >= 75){
                    point[i][j] = 3.5;
                    grade[i][j] = "B+";
                }
                else if(mark[i][j] >= 70){
                    point[i][j] = 3.0;
                    grade[i][j] = "B ";
                }
                else if(mark[i][j] >= 60){
                    point[i][j] = 2.5;
                    grade[i][j] = "C+";
                }
                else if(mark[i][j] >= 50){
                    point[i][j] = 2.0;
                    grade[i][j] = "C ";
                }
                else if(mark[i][j] >= 40){
                    point[i][j] = 1.5;
                    grade[i][j] = "D ";
                }
                else{
                    point[i][j] = 0.0;
                    grade[i][j] = "F ";
                }                
            }
        }
    }
}

void calculate(string **grade, float **mark, float *subjectCounted, float *totalMark, float *average, bool *error, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        if(!error[i]){
            for(int j=0; j<courseNum; ++j){
                if(grade[i][j] != "NG"){
                    subjectCounted[i]++;
                    totalMark[i] += mark[i][j];
                }
            }
            if(subjectCounted[i] != 0){
                average[i] = totalMark[i] / subjectCounted[i];
            }
        }
    }
}

void calculate(string **grade, float **point, unsigned int *creditHour, float *totalPoint, float *totalCreditHour, float *cgpa, bool *error, int studNum, int courseNum){
    for(int i=0; i<studNum; ++i){
        if(!error[i]){
            for(int j=0; j<courseNum; ++j){
                if(grade[i][j] != "NG"){
                    totalCreditHour[i] += creditHour[j];
                    totalPoint[i] += (creditHour[j] * point[i][j]);
                }
            }
            if(totalCreditHour[i] != 0){
                cgpa[i] = totalPoint[i] / totalCreditHour[i];
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

void display(string *courseName, string *id, string **grade, float **mark, float* subjectCounted, float *average, float *cgpa, int *orders, int studNum, int courseNum, int n){
    
    //displaying the upper borders of the table
    cout<<"______________";
    for(int i=0; i<courseNum; ++i){
        cout<<"________________";
    }
    cout<<"______________________"<<endl;

    cout<<" Stud. ID       ";
    for(int i=0; i<courseNum; ++i){
        cout<<"    "<<courseName[i]<<"        ";
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
        cout<<' '<<id[orders[i]]<<"   ";
        for(int j=0; j<courseNum; ++j){
            if(grade[orders[i]][j] == "NG"){
                cout<<"    "<<grade[orders[i]][j]<<" : "<<grade[orders[i]][j]<<"     ";
                continue;
            }
            cout<<"    "<<mark[orders[i]][j]<<" : "<<grade[orders[i]][j]<<"     ";
        }
        if(subjectCounted[orders[i]] == 0){
            cout<<"    --        --"<<endl<<endl;
            continue;
        }
        cout<<"    "<<average[orders[i]]<<"        "<<cgpa[orders[i]]<<endl;
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
