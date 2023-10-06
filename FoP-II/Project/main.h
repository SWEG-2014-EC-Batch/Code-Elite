#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <fstream>
#include <ctype.h>

#include <vector>
#include <map>
#include <iterator>

#include "StringManipulation.h"

using namespace std;

struct Course {
    string name;
    string code;
    int crHr;
    int year;
    int semester;
    string department;
    int currentTeacher;
    vector<string> prerequisites;
    vector<string> teachers;
};

struct StudCourse{
    string name;
    string code;
    int crHr;
    float grade;
    int year;
    int semester;
    char status;
    string teacher;
};

struct Student{
    string name[3];
    string id;
    int semester;
    char status;
    float cgpa;
    int rank;
    int semesterLoad;
    string department;
    string password;
    vector<StudCourse> myCourse;
};

vector<Student> students;  // student vector
vector<Course> courses;  // course vector

// Sign in functions
int student();  // Student
void teacher();  // Teacher
void staff();  // Staff(Manager)

// Student functions
void display_courses_info(Student stud);  // displays courses that the student is currently registered to

// Teacher functions
int signInToCourse(string, string);  // signs in a teacher to a course he/she is teaching to
int updateStudentCourseGrade(string, string, Course);  // changes grade of a students course

// Calculating functions
int semesterLoad(Student stud);  // calculates semester load of a student from credit hours of currently registered courses
float toPoint(float grade);  // calculates the point mark of a given mark grade
string toLetter(float grade);  // calculates the letter grade of a given mark grade
float semesterGPA(Student stud, int semester);  // calculates a student's gpa in a given semester
float calculateCgpa(Student);  // calculates cgpa of a given student

// display functions
void display_students(int*, int);  // displays selected students in ordered manner



int student(){
    string studId;
    cout<<endl<<"Enter your Id: ";
    cin>>studId;

    int index;
    for(int i = 0; i < students.size(); ++i){
        if(studId == students[i].id){
            index = i;
            break;
        }
        else if(i == students.size() - 1){
            cout<<endl<<"There is no student with id "<<studId<<"in the database!";
            return 0;
        }
    }

    string password;
    cout<<endl<<"For first time sign in your password is the first 5 letters of your grandparent's name in capital followed by the first 5 letters of your Id in small letters";
    cout<<"\nEnter your password: ";
    cin>>password;
    if(password != students[index].password){
        cout<<endl<<"Incorrect Password!";
        return 0;
    }

    if(students[index].status == 'G' && students[index].semester == 1000){
        int year;
        do{
            cout<<endl<<"Enter your graduation year: ";
            cin>>year;
            if(year < 2000 || year > 2500) year = -1;
        }while(year == -1);
        students[index].semester = year;
        refresh(students[index]);
    }

    char menu;
    string courseCode;
    do{
        cout<<endl<<"Enter 'A' to display student information";
        cout<<endl<<"Enter 'B' to register to a course";
        cout<<endl<<"Enter 'C' to drop a course";
        cout<<endl<<"Enter 'D' to display course information";
        cout<<endl<<"Enter 'E' to change your password";
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your choice: ";
        cin>>menu;
        menu = toupper(menu);
        switch (menu){
            case 'A':
                display_student_info(students[index]);
                break;

            case 'B':
                if(students[index].status == 'G'){
                    cout<<endl<<"You can\'t register to any course because you have graduated!!";
                    break;
                }
                courseRegister(students[index].id);
                break;

            case 'C':
                if(students[index].status == 'G'){
                    cout<<endl<<"You can\'t drop any courses because you have graduated!!";
                    break;
                }
                cout<<endl<<"Enter the code of the course you want to drop (Enter 'X' to go back): ";
                cin>>courseCode;
                if(courseCode != "x" && courseCode != "X") dropCourse(courseCode, students[index]);
                break;

            case 'D':
                display_courses_info(students[index]);
                break;

            case 'E':
                changePassword(students[index].password);
                break;
        }
    }while(menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D' || menu == 'E');

    return 0;
}

void teacher(){
    string tchId;
    string courseCode;
    cout<<endl<<"Please enter teacher Id: ";
    cin>>tchId;

    do{
        cout<<endl<<"Please enter course Code (Enter 'X' to go back): ";
        cin>>courseCode;
        if(courseCode != "x" && courseCode != "X") signInToCourse(tchId, courseCode);
    }while(courseCode != "x" && courseCode != "X");
}

void staff(){
    char menu;
    do{
        cout<<endl<<"Enter 'A' to Display student information";
        cout<<endl<<"Enter 'B' to Display course information";
        cout<<endl<<"Enter 'C' to Search student";
        cout<<endl<<"Enter 'D' to Search Course";
        cout<<endl<<"Enter 'E' to Manipulate student record";
        cout<<endl<<"Enter 'F' to Manipulate course record";
        cout<<endl<<"Enter 'G' for Statistical reports";
        cout<<endl<<"Enter 'H' to Sort Students";
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your choice: ";
        cin>>menu;
        menu = toupper(menu);
        switch (menu)
        {
        case 'A':
            display_students_forstaff();
            break;

        case 'B':
            display_courses_forstaff();
            break;

        case 'C':
            search_stud();
            break;

        case 'D':
            search_course();
            break;
            
        case 'E':
            manipulateStudentRecord();
            break;

        case 'F':
            manipulateCourseRecord();
            break;

        case 'G':
            statistical_report();
            break;

        case 'H':
            sort_students();
            break;
        }
    }while(menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D' || menu == 'E' || menu == 'F' || menu == 'G' || menu == 'H');
}

int signInToCourse(string tchId, string courseCode){
    int index;
    for(int i = 0; i < courses.size(); ++i){
        if(courses[i].code == courseCode){
            index = i;
            break;
        }
        else if(i == courses.size() - 1){
            cout<<endl<<"There is no course with course code "<<courseCode<<endl;
            return 0;
        }
    }

    if(teacher_teaches_course(tchId, courses[index])){
        char menu;
        do{
            cout<<endl<<"Enter 'A' to display your students";
            cout<<endl<<"Enter 'B' to insert grades to students";
            cout<<endl<<"Enter any other character to go back";
            cout<<endl<<"Your choice: ";
            cin>>menu;
            menu = toupper(menu);
            switch (menu)
            {
            case 'A':
                for(int i = 0; i < students.size(); ++i){
                    for(int j = 0; j < students[i].myCourse.size(); ++j){
                        if((courses[index].code == students[i].myCourse[j].code) && (tchId == students[i].myCourse[j].teacher) && students[i].status != 'P'){
                            cout<<endl<<students[i].id<<'\t'<<students[i].name;
                            break;
                        }
                    }
                }
                break;
            
            case 'B':
                string studId;
                do{
                    cout<<endl<<"Enter the id of the student (Enter 'X' to go back): ";
                    cin>>studId;
                    
                    if(studId != "x" && studId != "X"){
                        updateStudentCourseGrade(tchId, studId, courses[index]);
                    }
                }while(studId != "x" && studId != "X");
                break;
            }
        }while(menu == 'A' || menu == 'B');
    }
    else{
        cout<<endl<<"The teacher with Id "<<tchId<<" does not teach course "<<courseCode<<endl;
    }

    return 0;
}

int updateStudentCourseGrade(string tchId, string studId, Course course){
    int index, index2;
    for(int i = 0; i < students.size(); ++i){
        if(students[i].id == studId){
            index = i;
            break;
        }
        else if(i == students.size() - 1){
            cout<<endl<<"There is no student with id "<<studId<<endl;
            return 0;
        }
    }

    for(int i = 0; i < students[index].myCourse.size(); ++i){
        if((course.code == students[index].myCourse[i].code) && (tchId == students[index].myCourse[i].teacher) && students[index].status == 'R'){
            index2 = i;
            break;
        }
        else if(i == students[index].myCourse.size() - 1){
            cout<<endl<<"The teacher with Id "<<tchId<<" does not teach student "<<studId<<" this semester!"<<endl;
            return 0;
        }
    } 

    float grade;
    do{
        cout<<endl<<"Enter the grade of "<<studId<<" (Enter 101 for NG): ";
        cin>>grade;

        if((grade >= 0 && grade <= 100) || grade == 101){
            students[index].myCourse[index2].grade = grade;
            refresh(students[index]);
        }
        else{
            cout<<endl<<"Invalid Grade!";
        }
    }while((grade < 0 || grade > 100) && grade != 101);

    return 0;
}

int semesterLoad(Student stud){
    int load = 0;

    for(int i = 0; i < stud.myCourse.size(); i++){

        if(stud.myCourse[i].grade == -1){
            load += stud.myCourse[i].crHr;
        }
    }
    return load;
}

float toPoint(float grade){
    if( grade > 100) return 0;
    else if(grade >= 85) return 4.0;
    else if(grade >= 80) return 3.75;
    else if(grade >= 75) return 3.5;
    else if(grade >= 70) return 3.0;
    else if(grade >= 65) return 2.75;
    else if(grade >= 60) return 2.5;
    else if(grade >= 50) return 2.0;
    else if(grade >= 45) return 1.5;
    else if(grade >= 40) return 1;

    return 0.0;
}

string toLetter(float grade){ 
    if( grade > 100) return "NG";
    else if(grade >= 90) return "A+";
    else if(grade >= 85) return "A ";
    else if(grade >= 80) return "A-";
    else if(grade >= 75) return "B+";
    else if(grade >= 70) return "B ";
    else if(grade >= 65) return "B-";
    else if(grade >= 60) return "C+";
    else if(grade >= 50) return "C ";
    else if(grade >= 45) return "C-";
    else if(grade >= 40) return "D ";
    else if(grade >= 0) return "F ";

    return "- ";
}

float semesterGPA(Student stud, int semester){
    int totalCrHr = 0;
    float totalPoint = 0;

    for(int i = 0; i < stud.myCourse.size(); i++){
        if(stud.myCourse[i].year == ((semester + 1) / 2) && stud.myCourse[i].semester == (((semester + 1) % 2) + 1) && (stud.myCourse[i].status == 'P' || stud.myCourse[i].status == 'F')){
            totalPoint += (stud.myCourse[i].crHr * toPoint(stud.myCourse[i].grade));
            totalCrHr += stud.myCourse[i].crHr;
        }
    }

    if(totalCrHr == 0) return 0;
    return (totalPoint/totalCrHr);
}

float calculateCgpa(Student stud){
    int totalCrHr = 0;
    float totalPoint = 0;

    for(int i = 0; i < stud.myCourse.size(); ++i){
        if(stud.myCourse[i].status == 'P' || stud.myCourse[i].status == 'F'){
            totalPoint += (stud.myCourse[i].crHr * toPoint(stud.myCourse[i].grade));
            totalCrHr += stud.myCourse[i].crHr;
        }
    }

    if(totalCrHr == 0) return 0;
    return (totalPoint / totalCrHr);
}

void display_courses_info(Student stud){
    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;

    for(int i = 1; i <= stud.semester && i <= 10; ++i){
        cout<<"\t\tYear "<<(i + 1) / 2<<", Semester "<<((i+1) % 2) + 1<<" Course information\n";
        cout<<"____________________________________________________________________________________________________________________________________\n";
        cout<<"|\tCourse name\t|\tCourse code\t|\tGrade\t|\tGrade mark\t|\tStatus\t|\n";

        for(int j = 0; j < stud.myCourse.size(); j++){
            if((stud.myCourse[j].year == (i + 1) / 2) && (( stud.myCourse[j].semester = (((i+1) % 2) + 1)))){
                cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";
                cout<<"|\t"<<stud.myCourse[j].name<<"\t|\t"<<stud.myCourse[j].code<<"\t|\t";
                stud.myCourse[j].grade == -1 ? cout<<"- " : cout<<stud.myCourse[j].grade;
                cout<<"\t|\t"<<toLetter(stud.myCourse[j].grade)<<"\t|\t"<<statusToWords(stud.myCourse[j].status)<<"\t|\n";
            }
        }
        
        cout<<"____________________________________________________________________________________________________________________________________\n";
        cout<<"\n|Year "<<(i + 1) / 2<<", Semester "<<((i+1) % 2) + 1<<" GPA: "<<semesterGPA(stud, i)<<'\n';
        cout<<"____________________________________________________________________________________________________________________________________\n";

    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_students(int *orders, int n){
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;

    if(n == 0) cout<<endl<<"There are no students that fit the criteria!!"<<endl;
    else{
        cout<<"\t\tStudent Information\n";
        cout<<"____________________________________________________________________________________________________________________________________\n";
        cout<<"|\tFirst Name\t|\tLast Name\t|\tId\t|Department\t|\t";
        if(students[orders[0]].status == 'G') cout<<"Graduation ";
        cout<<"Year\t|\tCGPA\t|Status\t|\n";
        for(int i = 0; i < n; ++i){
            cout<<"|\t"<<students[orders[i]].name[0]<<"\t|\t"<<students[orders[i]].name[1]<<"\t|\t"<<students[orders[i]].id<<"\t|\t"<<students[orders[i]].department<<"\t|\t";
            students[orders[i]].status == 'G' ? cout<<students[orders[i]].semester : cout<<(students[orders[i]].semester + 1)/ 2;
            cout<<"\t|\t"<<students[orders[i]].cgpa<<"\t|\t"<<statusToWords(students[orders[i]].status)<<"\t|"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------------------------------\n"; 
        }   
    }
    
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

#endif
