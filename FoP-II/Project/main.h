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
void display_student_info(Student stud);  // displays information about the student that signed in
void display_courses_info(Student stud);  // displays courses that the student is currently registered to
int courseRegister(string);  // displays courses that the student can register to
bool canRegister(Course, Student, bool = false);  // checks whether or not a student can register to a course
int registration(string, Student&);  // registers a course to a student
int dropCourse(string, Student&);  // drops a course that a student was registered to
int changePassword(string&);  // changes the password
bool isNewStudent(Student);  // return true if the student is new (doesn't have any completed courses) and returns false oterwise

// Teacher functions
bool teacher_teaches_course(string teacher, Course crs);  // checks if the teacher teaches the course
int signInToCourse(string, string);  // signs in a teacher to a course he/she is teaching to
int updateStudentCourseGrade(string, string, Course);  // changes grade of a students course

// Calculating functions
int semesterLoad(Student stud);  // calculates semester load of a student from credit hours of currently registered courses
float toPoint(float grade);  // calculates the point mark of a given mark grade
string toLetter(float grade);  // calculates the letter grade of a given mark grade
float semesterGPA(Student stud, int semester);  // calculates a student's gpa in a given semester
float calculateCgpa(Student);  // calculates cgpa of a given student
void calculateRank(int, string);  // calculates the rank of a student in his/her year and department
void refresh(StudCourse&);  // calculates the derived members of the structure from the main menbers
void refresh(Student&, bool = false);  // calculates the derived members of the structure from the main menbers and calculates rank if the boolean is true

// Order function template
template <typename T>
void order(int*, int, map<int, T>, bool = true);  // orders the map in ascending or descending orders based on the map's values

//Staff functions
int manipulateStudentRecord();  // enables user to manipulate student record
int updateExistingStudent();  // identifies which student record will be manipulated
int updateStudent(Student&);  // modifies a given student record
int recordNewStudent();  // adds a new student to student record

int manipulateCourseRecord();  // enables user to manipulate course record

// display functions
void display_students_forstaff();  // displays students in a given year and department
void display_courses_forstaff();  // displays courses in a given department
void display_students(int*, int);  // displays selected students in ordered manner
void display_courses(int*, int);  // displays selected students in ordered manner
void display_course_info(Course course);  // displays information about the given course
int sort_students();  // sorts students by cgpa or specific course grade and displays the result
int promote(Student&);  // promotes the student to the next semester if they are eligible



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

void display_student_info(Student stud){
    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;

    cout<<endl<<"\tStudent Information\n";
    cout<<endl<<"Student Name: "<<stud.name[0]<<' '<<stud.name[1];
    cout<<endl<<"Student Id: "<<stud.id;
    cout<<endl<<"Department: "<<stud.department;
    cout<<endl<<"Status: "<<statusToWords(stud.status);
    if(stud.status == 'G'){
        cout<<endl<<"Graduation Year: ";
        if(stud.semester == 1000) cout<<"Not inserted yet!!";
        else cout<<stud.semester;
    }
    else{
        cout<<endl<<"Year: "<<(stud.semester + 1) / 2<<"\tSemester "<<((stud.semester + 1) % 2) + 1;
        cout<<endl<<"Semester Load: "<<stud.semesterLoad;
    }
    cout<<endl<<"Student CGPA: "<<stud.cgpa;
    cout<<endl<<"Student Rank: "<<stud.rank<<endl;

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_students_forstaff(){
    int year;
    string department;

    cout<<endl<<"Enter 100 to select all non-graduated years and enter 1000 to select all graduated years";
    cout<<endl<<"Please enter Batch Year or Graduation Year: ";
    cin>>year;

    cout<<"Please enter department (Enter 'All' to select all departments): ";
    cin.ignore();
    getline(cin, department);
    department = strToUpper(department);

    map<int, string> studentMap;

    if(year < 1000){
        for(int i = 0; i < students.size(); ++i){
            if((((year == 100) && students[i].status != 'G') || (year == (students[i].semester + 1) / 2)) && ((department == "ALL") || (department == students[i].department))){
                studentMap.insert(pair<int, string>(i, students[i].id));
            }
        }
    }
    else{
        for(int i = 0; i < students.size(); ++i){
            if((((year == 1000) && students[i].status == 'G') || (year == students[i].semester)) && ((department == "ALL") || (department == students[i].department))){
                studentMap.insert(pair<int, string>(i, students[i].id));
            }
        }
    }

    int *orders = new int[studentMap.size()];
    order(orders, studentMap.size(), studentMap);
    display_students(orders, studentMap.size());
    delete[] orders;
}

int sort_students(){
    int year;
    char menu;

    cout<<endl<<"Enter 100 to select all non-graduated years and enter 1000 to select all graduated years";
    cout<<endl<<"Please enter Batch Year or Graduation Year: ";
    cin>>year;

    cout<<endl<<"Enter 'A' to sort the students by CGPA";
    cout<<endl<<"Enter 'B' to sort the students by specific course";
    cout<<endl<<"Enter any other character to go back";
    cout<<endl<<"Your choice: ";
    cin>>menu;
    menu = toupper(menu);

    if(menu != 'A' && menu != 'B') return 0;

    map<int, float> resultMap;
    string department;
    string courseCode;

    switch(menu){
        case 'A':
            cout<<"Please enter department (Enter 'All' to select all department): ";
            cin.ignore();
            getline(cin, department);
            department = strToUpper(department);
            
            if(year < 1000){
                for(int i = 0; i < students.size(); ++i){
                    if((((year == 100) && students[i].status != 'G') || (year == (students[i].semester + 1) / 2)) && ((department == "ALL") || (department == students[i].department))){
                        resultMap.insert(pair<int, float>(i, students[i].cgpa));
                    }
                }
            }
            else{
                for(int i = 0; i < students.size(); ++i){
                    if((((year == 1000) && students[i].status == 'G') || (year == students[i].semester)) && ((department == "ALL") || (department == students[i].department))){
                        resultMap.insert(pair<int, float>(i, students[i].cgpa));
                    }
                }
            }
            break;

        case 'B':
            cout<<endl<<"Enter the course code: ";
            cin>>courseCode;

            if(year < 1000){
                for(int i = 0; i < students.size(); ++i){
                    for(int j = 0; j < students[i].myCourse.size(); ++j){
                        if((courseCode == students[i].myCourse[j].code) && (students[i].myCourse[j].grade != -1) && (((year == 100) && students[i].status != 'G') || (year == ((students[i].semester + 1) / 2)))){
                            resultMap.insert(pair<int, float>(i, students[i].myCourse[j].grade));
                        }
                    }
                }    
            }
            else{
                for(int i = 0; i < students.size(); ++i){
                    for(int j = 0; j < students[i].myCourse.size(); ++j){
                        if((courseCode == students[i].myCourse[j].code) && (students[i].myCourse[j].grade != -1) && (((year == 1000) && students[i].status == 'G') || (year == students[i].semester))){
                            resultMap.insert(pair<int, float>(i, students[i].myCourse[j].grade));
                        }
                    }
                }   
            }
            break;
    }

    int n, m;
    char menu2;

    cout<<endl<<"Enter '%' if you want top m% results";
    cout<<endl<<"Enter any other key to get top n results";
    cout<<endl<<"Your choice: ";
    cin>>menu2;

    if(menu2 == '%'){
        cout<<endl<<"Enter the value of n (1 - "<<resultMap.size()<<"): ";
        cin>>n;
        if(n < 1 || n > resultMap.size()) n = resultMap.size();
    }
    else{
        cout<<endl<<"Enter the value of m (1 - 100): ";
        cin>>m;
        if(m < 1 || m > 100) m = 100;
        n = m * resultMap.size() / 100;
    }

    int *orders = new int[n];
    order(orders, n, resultMap, false);
    display_students(orders, n);
    delete[] orders;
    
    return 0;
}

int changePassword(string &password){
    string newPassword;
    cout<<endl<<"Enter your previous password: ";
    cin>>newPassword;
    if(password != newPassword){
        cout<<endl<<"Wrong password!!"<<endl;
        return 0;
    }

    cout<<endl<<"Enter your new password(between 8 and 20 characters): ";
    cin>>newPassword;
    if(stringlength(newPassword) < 8 || stringlength(newPassword) > 20){
        cout<<endl<<"Invalid length!!"<<endl;
        return 0;
    }

    password = newPassword;
    return 0;
}

bool isNewStudent(Student stud){
    for(int i = 0; i < stud.myCourse.size(); ++i){
        if(stud.myCourse[i].grade != -1){
            return false;
        }
    }
    return true;
}

bool teacher_teaches_course(string teacher, Course crs){
    for(int i = 0; i < crs.teachers.size(); i++){
        if(teacher == crs.teachers[i]){
            return true;
        }
    }

    return false;
}

void display_courses(int *orders, int n){
    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;

    if(n == 0) cout<<endl<<"There is no course that fits the criteria!!"<<endl;
    else{
        cout<<endl<<"\t\tCourse Information\n";
        cout<<"____________________________________________________________________________________________________________________________________\n";
        cout<<"|\tCourses name\t|\tCourse code\t|\tCredit hour\t|\tDepartment\t|\tYear\t|\tSemester\t|\n";
        for(int i = 0; i < n; ++i){
            cout<<"|\t"<<courses[orders[i]].name<<"\t|\t"<<courses[orders[i]].code<<"\t|\t"<<courses[orders[i]].crHr<<"\t|\t"<<courses[orders[i]].department<<"\t|\t"<<courses[orders[i]].year<<"\t|\t"<<courses[orders[i]].semester<<"\t|\n";
            cout<<"------------------------------------------------------------------------------------------------------------------------------------\n";  
        }
    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_course_info(Course course){
    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;

    cout<<endl<<"Course name: "<<course.name<<endl;
    cout<<"Course code: "<<course.code<<endl;
    cout<<"Credit hour: "<<course.crHr<<endl;
    cout<<"Department: "<<course.department<<endl;
    cout<<"Year: "<<course.year<<"\tSemester: "<<course.semester<<endl;

    for(int j = 0; j < course.prerequisites.size(); j++){
        if(j == 0){
            cout<<"Course codes of prerequisites: ";
        }
        else{
            cout<<", ";
        }
        cout<<course.prerequisites[j];
    }

    cout<<"\nId of teachers that teach this course: ";
    for(int j = 0; j < course.teachers.size(); j++){
        cout<<course.teachers[j];
        if(j != course.teachers.size() - 1){
            cout<<", ";
        }
        else{
            cout<<endl;
        }
    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_courses_forstaff(){
    string department;

    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
    cout<<"Enter department (Enter All to select all department): ";
    cin.ignore();
    getline(cin, department);
    department = strToUpper(department);

    map<int, string> courseMap;
    for(int i = 0; i < courses.size(); ++i){
        if((department == "ALL") || (department == courses[i].department)){
            courseMap.insert(pair<int, string>(i, courses[i].code));
        }
    }

    int *orders = new int[courseMap.size()];
    order(orders, courseMap.size(), courseMap);
    display_courses(orders, courseMap.size());
    delete[] orders;
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

int courseRegister(string studId){
    int index;
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

    cout<<endl<<"Courses "<<students[index].id<<" can register to:"<<endl;
    for(int i = 0; i < courses.size(); ++i){
        if(canRegister(courses[i], students[index])){
            cout<<courses[i].code<<" ("<<courses[i].name<<')'<<endl;
        }
    }

    string courseCode;

    do{
        cout<<endl<<"Enter the course code to register to the course (Enter 'X' to go back): ";
        cin>>courseCode;
        if(courseCode != "x" && courseCode != "X"){
            registration(courseCode, students[index]);
        }
    }while(courseCode != "x" && courseCode != "X");

    return 0;
}

bool canRegister(Course course, Student stud, bool reason){
    if(course.department != "ALL" && course.department != stud.department){
        if(reason) cout<<endl<<"Department doesn\'t match!";
        return false;
    }

    if(stud.semester < (2 * (course.year - 1) + course.semester)){
        if(reason) cout<<endl<<"The student can\'t take this course before Year "<<course.year<<" semester "<<course.semester<<'!';
        return false;
    }

    if(stud.semesterLoad + course.crHr > 22){
        if(reason) cout<<endl<<"The semester load of the student becomes more than 22!";
        return false;
    }

    for(int i = 0; i < stud.myCourse.size(); ++i){
        if((course.code == stud.myCourse[i].code) && (stud.myCourse[i].status == 'P' || stud.myCourse[i].grade == -1)){
            if(reason) cout<<endl<<"Student "<<stud.id<<" has already learned (and passed) the course "<<course.code<<'!';
            return false;
        }
    }

    for(int i = 0; i < course.prerequisites.size(); ++i){
        for(int j = 0; j < stud.myCourse.size(); ++j){
            if((course.prerequisites[i] == stud.myCourse[j].code) && stud.myCourse[j].status == 'P'){
                break;
            }
            else if(j == stud.myCourse.size() - 1){
                if(reason) cout<<endl<<"The student needs to learn "<<course.prerequisites[i]<<" first!";
                return false;
            }
        }
    }

    return true;
}

int registration(string code, Student &stud){
    int index;
    for(int i = 0; i < courses.size(); ++i){
        if(courses[i].code == code){
            index = i;
            break;
        }
        else if(i == courses.size() - 1){
            cout<<endl<<"There is no course with course code "<<code<<endl;
            return 0;
        }
    }

    if(canRegister(courses[index], stud, true)){
        int index2 = -1;
        for(int i = 0; i < stud.myCourse.size(); ++i){
            if(courses[index].code == stud.myCourse[i].code){
                index2 = i;
                break;
            }
        }

        if(index2 == -1){
            StudCourse registeredCourse;
            registeredCourse.status = 'R';
            registeredCourse.code = courses[index].code;
            registeredCourse.name = courses[index].name;
            registeredCourse.crHr = courses[index].crHr;
            registeredCourse.year = courses[index].year;
            registeredCourse.semester = courses[index].semester;
            registeredCourse.grade = -1;
            registeredCourse.teacher = courses[index].teachers[(courses[index].currentTeacher % courses[index].teachers.size())];
            courses[index].currentTeacher = (courses[index].currentTeacher + 1) % courses[index].teachers.size();
            stud.myCourse.push_back(registeredCourse);
        }
        else{
            stud.myCourse[index2].grade = -1;
            stud.myCourse[index2].status = 'R';
            stud.myCourse[index2].teacher = courses[index].teachers[(courses[index].currentTeacher % courses[index].teachers.size())];
            courses[index].currentTeacher = (courses[index].currentTeacher + 1) % courses[index].teachers.size();
        }

        stud.semesterLoad += courses[index].crHr;
        cout<<endl<<"Student "<<stud.id<<" have successfully registered to course "<<courses[index].code<<endl;
    }
    else{
        cout<<endl<<"Student with id "<<stud.id<<" can NOT register to the course with code "<<code<<endl;
    }

    return 0;
}

template <typename T>
void order(int* orders, int n, map<int, T> orderMap, bool isascending){

    typename map<int, T>::iterator orderMapItr = orderMap.begin();
    T lastValue = orderMapItr->second, orderValue;

    for(orderMapItr = orderMap.begin(); orderMapItr != orderMap.end(); ++orderMapItr){
        if(isascending){
            if(lastValue <= orderMapItr->second){
                lastValue = orderMapItr->second;
                orders[n-1] = orderMapItr->first;
            }
        }
        else{
            if(lastValue >= orderMapItr->second){
                lastValue = orderMapItr->second;
                orders[n-1] = orderMapItr->first;
            }
        }
    }

    for(int i=0; i<n; ++i){
        orderValue = lastValue;
        for(orderMapItr = orderMap.begin(); orderMapItr != orderMap.end(); ++orderMapItr){
            int count=0;

            for(int k=0; k<i; ++k){
                if(orderMapItr->first == orders[k]){
                    count += 1;
                    break;
                }
            }

            if(count==1){
                continue;
            }

            if(isascending){
                if(orderValue >= orderMapItr->second){
                    orderValue = orderMapItr->second;
                    orders[i] = orderMapItr->first;
                }
            }
            else{
                if(orderValue <= orderMapItr->second){
                    orderValue = orderMapItr->second;
                    orders[i] = orderMapItr->first;
                }
            }
        }
    }
}

void refresh(StudCourse &course){
    if(course.grade == -1) course.status = 'R';
    else if(course.grade < 40) course.status = 'F';
    else if(course.grade == 101) course.status = 'U';
    else course.status = 'P';
}

void refresh(Student &stud, bool changePassword){
    if(changePassword){
        stud.password = strConcat(strToUpper(stud.name[2]), strToLower(stud.id), 5, 5);
    }

    stud.semesterLoad = 0;
    for(int i = 0; i < stud.myCourse.size(); ++i){
        refresh(stud.myCourse[i]);
        if(stud.myCourse[i].grade == -1){
            stud.semesterLoad += stud.myCourse[i].crHr;
        }
    }

    stud.cgpa = calculateCgpa(stud);

    if(isNewStudent(stud)){
        stud.status = 'N';
    }
    else if(stud.status != 'W' && stud.status != 'G'){
        if(stud.cgpa < 1.5){
            stud.status = 'D';
        }
        else if(stud.cgpa < 2){
            stud.status = '!';
        }
        else{
            stud.status = 'P';
        }
    }

    stud.department = strToUpper(stud.department);

    promote(stud);

    if(stud.semester > 10 && stud.semester < 2000) stud.rank = 0;
    else calculateRank(stud.semester, stud.department);
}

int promote(Student &stud){
    if(stud.status == 'D' && stud.status == 'W' && stud.status == 'G') return 0;

    if(stud.semester < 10){
        int year = (stud.semester + 1) / 2;
        int semester = ((stud.semester + 1) % 2) + 1;

        for(int j = 0; j < stud.myCourse.size(); ++j){
            if(stud.myCourse[j].year == year && stud.myCourse[j].semester == semester && stud.myCourse[j].grade == -1) return 0;
        }

        stud.semester++;
    }
    else {
        bool canGraduate = true;
        for(int j = 0; j < stud.myCourse.size(); ++j){
            if(stud.myCourse[j].status != 'P'){
                canGraduate = false;
                break;
            }
        }

        if(canGraduate) stud.semester = 1000;
        else stud.semester = 11;
    }

    return 0;
}

void calculateRank(int semester, string department){
    int n = 0;
    map<int, float> cgpaMap;

    if(semester >= 2000){
        for(int i = 0; i < students.size(); ++i){
            if(students[i].semester == semester && students[i].department == department){
                cgpaMap.insert(pair<int, float>(i, students[i].cgpa));
                n++;
            }
        }
    }
    else{
        int year = (semester + 1) / 2;
        for(int i = 0; i < students.size(); ++i){
            if(((students[i].semester + 1) / 2 == year) && (students[i].department == department)){
                cgpaMap.insert(pair<int, float>(i, students[i].cgpa));
                n++;
            }
        }
    }

    int *orders = new int[n];
    order(orders, n, cgpaMap);
    for(int i = 0; i < n; ++i){
        students[orders[i]].rank = i + 1;
    }
}

int manipulateStudentRecord(){
    char menu;

    do{
        cout<<endl<<"Enter 'A' to register a student";
        cout<<endl<<"Enter 'B' to update an existing student record";
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your choice: ";
        cin>>menu;
        menu = toupper(menu);

        switch(menu){
            case 'A':
                recordNewStudent();
                break;

            case 'B':
                updateExistingStudent();
                break;
        }
    }while(menu == 'A' || menu == 'B');

    return 0;
}

int recordNewStudent(){
    Student stud;
    cout<<endl<<"Enter the id of the new student: ";
    cin>>stud.id;

    for(int i = 0; i < students.size(); ++i){
        if(students[i].id == stud.id){
            cout<<endl<<"There is a student with id "<<stud.id<<" in database!";
            return 0;
        }
    }

    cout<<endl<<"Enter the first name of the new Student: ";
    cin>>stud.name[0];
    cout<<endl<<"Enter the father's name of the new Student: ";
    cin>>stud.name[1];
    cout<<endl<<"Enter the grandfather's name of the new Student: ";
    cin>>stud.name[2];
    stud.department = "Natural and Social Science";
    stud.semester = 1;
    students.push_back(stud);

    for(int i = 0; i < courses.size(); ++i){
        if(courses[i].year == 1 && courses[i].semester == 1){
            registration(courses[i].code, students[students.size() - 1]);
        }
    }

    refresh(students[students.size() - 1], true);

    return 0;
}

int updateExistingStudent(){
    string studId;

    cout<<endl<<"Enter the id of the student to update (Enter 'X' to go back): ";
    cin>>studId;

    if(studId == "x" && studId == "X") return 0;

    int index;
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

    updateStudent(students[index]);
    return 0;
}

int updateStudent(Student &stud){
    char menu;
    do{
        cout<<endl<<"Enter 'A' to change name of "<<stud.id;
        cout<<endl<<"Enter 'B' to change id of "<<stud.id;
        cout<<endl<<"Enter 'C' to change department of "<<stud.id;
        cout<<endl<<"Enter 'D' to Add course to "<<stud.id;
        cout<<endl<<"Enter 'E' to Drop course of "<<stud.id;
        cout<<endl<<"Enter 'F' to change status of "<<stud.id;
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your Choice: ";
        cin>>menu;
        menu = toupper(menu);

        string value;
        char value2;

        switch (menu){
        case 'A':
            cout<<endl<<"The student's current name is "<<stud.name[0]<<' '<<stud.name[1]<<' '<<stud.name[2]<<endl;
            cout<<endl<<"Enter the new first name (Enter '=' to keep the current name): ";
            cin>>value;
            if(value != "=") stud.name[0] = value;
            cout<<endl<<"Enter the new father's name (Enter '=' to keep the current name): ";
            cin>>value;
            if(value != "=") stud.name[1] = value;
            cout<<endl<<"Enter the new grandfather's name (Enter '=' to keep the current name): ";
            cin>>value;
            if(value != "=") stud.name[2] = value;
            break;

        case 'B':
            cout<<endl<<"The student's current id is "<<stud.id;
            cout<<endl<<"Enter the new id (Enter '=' to keep the current id): ";
            cin>>value;
            if(value != "=") stud.id = value;
            break;

        case 'C':
            cout<<endl<<"The student's current department is "<<stud.department;
            cout<<endl<<"Enter the new department (Enter '=' to keep the current department): ";
            cin.ignore();
            getline(cin, value);
            if(value != "=") stud.department = value;
            break;

        case 'D':
            cout<<endl<<"Enter the course code: ";
            cin>>value;
            registration(value, stud);
            break;

        case 'E':
            cout<<endl<<"Enter the course code: ";
            cin>>value;
            dropCourse(value, stud);
            break;
            
        case 'F':
            cout<<endl<<"The student's current status is '"<<statusToWords(stud.status)<<"' ";
            cout<<endl<<"Enter 'W' for withdrawal and 'C' be readmission: ";
            cin>>value2;
            value2 = toupper(value2);

            if(value2 == 'C' || value2 == 'W') stud.status = value2;
            else cout<<endl<<"Invalid Status value!";
            break;
        }

        refresh(stud);
    }while(menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D' || menu == 'E' || menu == 'F');

    return 0;
}

int dropCourse(string courseCode, Student &stud){
    int index;

    for(int i = 0; i < stud.myCourse.size(); ++i){
        if((courseCode == stud.myCourse[i].code) && (stud.myCourse[i].grade == -1)){
            index = i;
            break;
        }
        else if(i == stud.myCourse.size() - 1){
            cout<<endl<<"The student "<<stud.id<<" is not currently registered to a course with course code "<<courseCode<<'!';
            return 0;
        }
    }

    stud.myCourse.erase(stud.myCourse.begin() + index);

    return 0;
}

int manipulateCourseRecord(){
    char menu;

    do{
        cout<<endl<<"Enter 'A' to insert a new course";
        cout<<endl<<"Enter 'B' to update or delete an existing course record";
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your choice: ";
        cin>>menu;
        menu = toupper(menu);

        switch(menu){
            case 'A':
                insertNewCourse();
                break;

            case 'B':
                updateExistingCourse();
                break;
        }
    }while(menu == 'A' || menu == 'B');

    return 0;
}

#endif
