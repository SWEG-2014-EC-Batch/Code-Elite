#include <iostream>
#include <ctype.h>
#include <string.h>
#include "Group_project_2_version2.h"
using namespace std;

int main(){
    int numStud , numCourse;

    input(numStud, numCourse);

    int subIndex , n , percent , realStud = numStud;
    unsigned int *crHr = new unsigned int[numCourse];
    char menu , menu2;
    bool *error = new bool[numStud];
    string *subjectName = new string[numCourse] , *studId = new string[numStud] , **gradeMark = new string*[numStud] , searchId , searchSub;
    float *totalCrHr = new float[numStud] , **point = new float*[numStud] , *cgpa = new float[numStud] , *totalMark = new float[numStud], *avg = new float[numStud];
    float **subjectMark = new float*[numStud] , *totalPoint = new float[numStud] , *chosenSubjectMark = new float[numStud] , *subjectCounted = new float[numStud];

    for(int i=0; i<numStud; ++i){
        error[i] = false;
        totalCrHr[i] = 0;
        totalPoint[i] = 0;
        totalMark[i] = 0;
        subjectCounted[i] = 0;

        //declaring dynamic 2D arrays
        subjectMark[i] = new float[numCourse];
        point[i] = new float[numCourse];
        gradeMark[i] = new string[numCourse];
    }

    input(subjectName, crHr, numCourse);
    input(studId, error, numStud);

    for(int i=0; i<numStud; ++i){
        if(error[i]){
            realStud--;
        }
    }

    input(subjectName, studId, subjectMark, error, numStud, numCourse);
    markToGrade(subjectMark, point, gradeMark, error, numStud, numCourse);
    calculate(gradeMark, subjectMark, subjectCounted, totalMark, avg, error, numStud, numCourse);
    calculate(gradeMark, point, crHr, totalPoint, totalCrHr, cgpa, error, numStud, numCourse);

    int *orders = new int[realStud];

    //ordering student Ids alphabetically (in ascending order)
    order(studId, realStud, numStud, orders, error);

    //displaying the titles of the table
    cout<<endl<<"    ";
    for(int i=0; i<numCourse; ++i){
        cout<<"        ";
    }
    cout<<"STUDENT'S MArk SHEET"<<endl;

    //displaying the table
    display(subjectName, studId, gradeMark, subjectMark, subjectCounted, avg, cgpa, orders, numStud, numCourse, realStud);

    int count = 0;
    do{
        cout<<"Menu\nEnter 'A' to search for the result of a specific student\nEnter 'B' to get the Top n results based on CGPA\nEnter 'C' to get the Top n results based on Average\nEnter 'D' to get the Top n results based on a specific subject\nEnter 'E' to End the program\nYour choice: ";
        cin>>menu;
        menu = toupper(menu);

        int count2 = 0;
        switch(menu){
            case 'A':
                cout<<"Enter the Id number: ";
                cin>>searchId;
                for(int i=0; i<numStud; ++i){
                    if(error[i]){
                        continue;
                    }
                    if(studId[i] == searchId){
                        orders[0] = i;
                        cout<<endl<<"        ";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"        ";
                        }
                        cout<<"Results of "<<searchId<<endl;
                        display(subjectName, studId, gradeMark, subjectMark, subjectCounted, avg, cgpa, orders, numStud, numCourse);
                        break;
                    }
                    else if(i == numStud - 1){
                        cout<<"\n<<The ID could not be found.>>\n"<<endl;
                    }
                }
                break;

            case 'B':
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\n<<The percentage is out of range>>\n"<<endl;
                        break;
                    }
                    n=percent*(realStud)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>realStud){
                        cout<<"\n<<n is out of range (0-"<<realStud<<")>>\n"<<endl;
                        break;
                    }
                }
                
                //finding top n students in descending order of CGPA
                order(cgpa, n, numStud, orders, error);

                //displaying the titles of the table
                cout<<" ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on CGPA result"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on CGPA result"<<endl;
                }

                //displaying the table
                display(subjectName, studId, gradeMark, subjectMark, subjectCounted, avg, cgpa, orders, numStud, numCourse, n);
                break;

            case 'C':
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\n<<The percentage is out of range>>\n"<<endl;
                        break;
                    }
                    n=percent*(realStud)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>realStud){
                        cout<<"\n<<n is out of range (0-"<<realStud<<")>>\n"<<endl;
                        break;
                    }
                }

                //finding top n students in descending order of Average
                order(avg, n, numStud, orders, error);

                //displaying the titles of the table
                cout<<"   ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on Average"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on Average"<<endl;
                }

                //displaying the table
                display(subjectName, studId, gradeMark, subjectMark, subjectCounted, avg, cgpa, orders, numStud, numCourse, n);
                break;

            case 'D':
                cout<<"Enter the Subject name: ";
                cin>>searchSub;
                //storing the index of the course chosen
                for(int i=0; i<numCourse; ++i){
                    if(subjectName[i] == searchSub){
                        subIndex = i;
                        break;
                    }
                    else if(i==numCourse-1){
                        count2 += 1;
                    }
                }
                if(count2!=0){
                    cout<<"\n<<Invalid course name.>>\n"<<endl;
                    break;
                }
                for(int i=0; i<numStud; ++i){
                    chosenSubjectMark[i] = subjectMark[i][subIndex];
                }
                cout<<endl<<"Do you want the top n students or the top m\% students\nEnter '%' to get top students by percent and any other character for top n students: ";
                cin>>menu2;
                if(menu2=='%'){
                    cout<<"Enter the percentage(0-100): ";
                    cin>>percent;
                    if(percent<0 || percent>100){
                        cout<<"\n<<The percentage is out of range>>\n"<<endl;
                        break;
                    }
                    n=percent*(realStud)/100;  //changing percent to n
                }
                else{
                    cout<<"Enter the value of n: ";
                    cin>>n;
                    if(n<0 || n>realStud){
                        cout<<"\n<<n is out of range (0-"<<realStud<<")>>\n"<<endl;
                        break;
                    }
                }

                //finding top n students in descending order of the chosen course
                order(chosenSubjectMark, n, numStud, orders, error);

                //displaying the titles of the table
                cout<<endl<<" ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on "<<subjectName[subIndex]<<" result"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on "<<subjectName[subIndex]<<" result"<<endl;
                }

                //displaying the table
                display(subjectName, studId, gradeMark, subjectMark, subjectCounted, avg, cgpa, orders, numStud, numCourse, n);
                break;

            case 'E':
            cout<<"\n<<Thank you for using this program!!>>\n"<<endl;
                count = 3;
                break;

            default:
                cout<<"\n<<You entered wrong input.>>\n"<<endl;
                count += 1;
                break;
        }
    }while(count<3);

    delete []orders;
    return 0;
}
