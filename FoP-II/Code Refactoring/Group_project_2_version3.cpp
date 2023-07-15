#include <iostream>
#include <ctype.h>
#include <string.h>
#include "Group_project_2_version3.h"
using namespace std;

int main(){
    int numStud , numCourse;

    input(numStud, numCourse);

    Student *student = new Student[numStud];
    Course *course = new Course[numCourse];

    for(int i=0; i<numStud; ++i){
        student[i].gradeMark = new string[numCourse];
        student[i].subjectMark = new float[numCourse];
        student[i].point = new float[numCourse];
    }

    int subIndex , n , percent , realStud = numStud;
    char menu , menu2;
    string searchId , searchSub;
    float *temp = new float[numStud];
    string *tempName = new string[numStud];

    for(int i=0; i<numStud; ++i){
        student[i].totalCrHr = 0;
        student[i].totalPoint = 0;
        student[i].totalMark = 0;
        student[i].totalCourse = 0;
    }

    input(course, numCourse);
    input(student, numStud);

    for(int i=0; i<numStud; ++i){
        if(student[i].error){
            realStud--;
        }
    }

    input(course, student, numStud, numCourse);
    markToGrade(student, numStud, numCourse);
    calculate(course, student, numStud, numCourse);

    int *orders = new int[realStud];

    for(int i=0; i<numStud; ++i){
        tempName[i] = student[i].id;
    }
    //ordering student Ids alphabetically (in ascending order)
    order(tempName, realStud, numStud, orders, &student[0].error);

    //displaying the titles of the table
    cout<<endl<<"    ";
    for(int i=0; i<numCourse; ++i){
        cout<<"        ";
    }
    cout<<"STUDENT'S MArk SHEET"<<endl;

    //displaying the table
    display(course, student, orders, numStud, numCourse, realStud);

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
                    if(student[i].error){
                        continue;
                    }
                    if(student[i].id == searchId){
                        orders[0] = i;
                        cout<<endl<<"        ";
                        for(int i=0; i<numCourse; ++i){
                            cout<<"        ";
                        }
                        cout<<"Results of "<<searchId<<endl;
                        display(course, student, orders, numStud, numCourse);
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
                
                for(int i=0; i<numStud; ++i){
                    temp[i] = student[i].cgpa;
                }
                //finding top n students in descending order of CGPA
                order(temp, n, numStud, orders, &(student[0].error));

                //displaying the titles of the table
                cout<<endl<<" ";
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
                display(course, student, orders, numStud, numCourse, n);
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

                for(int i=0; i<numStud; ++i){
                    temp[i] = student[i].average;
                }
                //finding top n students in descending order of Average
                order(temp, n, numStud, orders, &(student[0].error));

                //displaying the titles of the table
                cout<<endl<<"   ";
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
                display(course, student, orders, numStud, numCourse, n);
                break;

            case 'D':
                cout<<"Enter the Subject name: ";
                cin>>searchSub;
                //storing the index of the course chosen
                for(int i=0; i<numCourse; ++i){
                    if(course[i].name == searchSub){
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
                    temp[i] = student[i].subjectMark[subIndex];
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
                order(temp, n, numStud, orders, &(student[0].error));

                //displaying the titles of the table
                cout<<endl<<" ";
                for(int i=0; i<numCourse; ++i){
                    cout<<"        ";
                }
                if(menu2=='%'){
                    cout<<"Top "<<percent<<"\% based on "<<course[subIndex].name<<" result"<<endl;
                }
                else{
                    cout<<"Top "<<n<<" based on "<<course[subIndex].name<<" result"<<endl;
                }

                //displaying the table
                display(course, student, orders, numStud, numCourse, n);
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
