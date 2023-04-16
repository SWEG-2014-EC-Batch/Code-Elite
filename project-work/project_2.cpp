#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
int main(){
    int numStud , numCourse;
    cout<<"Enter the number of students: ";
    cin>>numStud;
    cout<<"Enter the number of courses: ";
    cin>>numCourse;
    if(numStud<0 || numCourse<0){
        return 0;
    }
    int subIndex , n , percent , *count2 = new int[numStud] , *orders;
    unsigned int *crHr = new unsigned int[numCourse];
    char menu , menu2;
    string *subjectName = new string[numCourse] , *studId = new string[numStud] , **gradeMark = new string*[numStud] , searchId , searchSub , lastId , orderId;
    float *totalCrHr = new float[numStud] , *totalPoint = new float[numStud] , *cgpa = new float[numStud] , *totalMark = new float[numStud];
    float **subjectMark = new float*[numStud] , **point = new float*[numStud] , *avg = new float[numStud] , *temp = new float[numStud] , order , minValue;

    for(int i=0; i<numStud; ++i){
        totalCrHr[i] = 0;
        totalPoint[i] = 0;
        totalMark[i] = 0;
        temp[i] = 0;

        subjectMark[i] = new float[numCourse];
        point[i] = new float[numCourse];
        gradeMark[i] = new string[numCourse];
    }
    for(int i=0; i<numCourse; ++i){
        cout<<endl<<"Enter the name of course "<<i+1<<" (use 4 characters): ";
        cin>>subjectName[i];
        if((subjectName[i]).length() != 4){
            cout<<"Please use 4 characters: ";
            cin>>subjectName[i];
        }
        if(subjectName[i].length() != 4){
            return 0;
        }

        cout<<"Enter the credit hour of "<<subjectName[i]<<" : ";
        cin>>crHr[i];
    }

    for(int i=0; i<numStud; ++i){
        count2[i]=0;
        int error;
        do{
            error=0;
            cout<<endl<<"Enter the ID of student "<<i+1<<" (like ETS0000/10): ";
            cin>>studId[i];
            if(studId[i].length() != 10){
                cout<<"Please use 10 characters (like ETS0000/10): ";
                cin>>studId[i];
            }
            if(studId[i].size() != 10){
                count2[i] = 2;
            }
            for(int j=0; j<i; ++j){
                if(studId[i] == studId[j]){
                    cout<<"The student is already in database."<<endl;
                    error+=1;
                    break;
                }
            }
            count2[i]+=1;
        }while(error!=0 && count2[i]<3);

        if(count2[i] == 3){
            continue;
        }
        for(int j=0; j<numCourse; ++j){

            int k=0;
            do{
                cout<<"Enter the mark of "<<subjectName[j]<<" for "<<studId[i]<<" (enter '101' for NG): ";
                cin>>subjectMark[i][j];
                if(subjectMark[i][j] == 101){
                    k = 2;
                }
                else if((subjectMark[i][j] < 0 || subjectMark[i][j] > 100) && k<3){
                    cout<<"You entered wrong input!! ";
                    if(k<2){
                        cout<<"Try again!";
                    }
                    cout<<endl;
                }
                ++k;
            }while((subjectMark[i][j] < 0 || subjectMark[i][j] > 100) && k<3);

            if(subjectMark[i][j] < 0 || subjectMark[i][j] > 100){
                gradeMark[i][j] = "NG";
                point[i][j] = 0;
                subjectMark[i][j] = 0;
            }
            else if(subjectMark[i][j] >= 85){
                point[i][j] = 4.0;
                gradeMark[i][j] = "A ";
            }
            else if(subjectMark[i][j] >= 75){
                point[i][j] = 3.5;
                gradeMark[i][j] = "B+";
            }
            else if(subjectMark[i][j] >= 70){
                point[i][j] = 3.0;
                gradeMark[i][j] = "B ";
            }
            else if(subjectMark[i][j] >= 60){
                point[i][j] = 2.5;
                gradeMark[i][j] = "C+";
            }
            else if(subjectMark[i][j] >= 50){
                point[i][j] = 2.0;
                gradeMark[i][j] = "C ";
            }
            else if(subjectMark[i][j] >= 40){
                point[i][j] = 1.5;
                gradeMark[i][j] = "D ";
            }
            else{
                point[i][j] = 0.0;
                gradeMark[i][j] = "F ";
            }

            if(gradeMark[i][j] == "NG"){
                continue;
            }

            temp[i] += 1;
            totalMark[i] += subjectMark[i][j];

            totalPoint[i] += (crHr[j] * point[i][j]);
            totalCrHr[i] += crHr[j];
        }

        if(temp[i] == 0){
            continue;
        }

        avg[i] = totalMark[i] / temp[i];
        cgpa[i] = totalPoint[i] / totalCrHr[i];
    }
    
    return 0;
}
