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

bool change;
vector<Student> students;  // student vector
vector<Course> courses;  // course vector

// File related Functions
int readFromFile();  //Read from file and write to variables (vectors)
int save();  //Save changes by writing variables (vectors) to file

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
string statusToWords(char status);  // converts the character status to word status
int howMany(int year, string department, char status = '\0');  // calculates the number of students with a particular status in a given year and department
void refresh(StudCourse&);  // calculates the derived members of the structure from the main members
void refresh(Student&, bool = false);  // calculates the derived members of the structure from the main members and calculates rank if the boolean is true

// Order function template
template <typename T>
void order(int*, int, map<int, T>, bool = true);  // orders the map in ascending or descending orders based on the map's values

//Staff functions
void search_stud();  // searches for students
void search_by_course();  // searches for students who are registered to a given course
void search_by_id();  // searches for a specific student using the student's id

void search_course();  // searches for courses
void search_by_course_code();  // searches for a specific course using the course code
int search_by_student();  // searches for courses that a given student is currently registered to
void search_by_teacher();  // searches for courses that a given teacher currently teaches
void search_by_prerequisite();  // searches for courses that have the given course code as a prerequisite

int manipulateStudentRecord();  // enables user to manipulate student record
int updateExistingStudent();  // identifies which student record will be manipulated
int updateStudent(Student&);  // modifies a given student record
int recordNewStudent();  // adds a new student to student record

int manipulateCourseRecord();  // enables user to manipulate course record
int updateExistingCourse();  // identifies which course record will be manipulated
int updateCourse(Course&);  // modifies a given course record
int deleteCourse(int);  // deletes a given course from course record
int insertNewCourse();  // inserts a new course to course record

int statistical_report();  // displays a statistical report of a given year and department

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
                else if(students[index].status == 'W'){
                    cout<<endl<<"You can\'t register to any course because you have withdrawn!\nYou have to be readmitted to register to courses!";
                    break;
                }
                else if(students[index].status == 'D'){
                    cout<<endl<<"You can\'t register to any course because you are dismissed!\nAsk university adminstrators to register you to courses!";
                    break;
                }
                courseRegister(students[index].id);
                if(change) save();
                break;

            case 'C':
                if(students[index].status == 'G'){
                    cout<<endl<<"You can\'t drop any courses because you have graduated!!";
                    break;
                }
                cout<<endl<<"Enter the code of the course you want to drop (Enter 'X' to go back): ";
                cin>>courseCode;
                if(courseCode != "x" && courseCode != "X") dropCourse(courseCode, students[index]);
                if(change) save();
                break;

            case 'D':
                display_courses_info(students[index]);
                break;

            case 'E':
                changePassword(students[index].password);
                if(change) save();
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
        if(change) save();
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

        switch (menu){
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

            switch (menu){
            case 'A':
                for(int i = 0; i < students.size(); ++i){
                    for(int j = 0; j < students[i].myCourse.size(); ++j){
                        if((courses[index].code == students[i].myCourse[j].code) && (tchId == students[i].myCourse[j].teacher) && students[i].myCourse[j].status == 'R'){
                            cout<<endl<<students[i].id<<'\t'<<students[i].name[0]<<' '<<students[i].name[1];
                            break;
                        }
                    }
                }
                cout<<endl;
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
        if((course.code == students[index].myCourse[i].code) && (tchId == students[index].myCourse[i].teacher) && students[index].myCourse[i].status == 'R'){
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
            change = true;
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
    int year = (semester + 1) / 2;
    int sem = ((semester + 1) % 2) + 1;

    for(int i = 0; i < stud.myCourse.size(); i++){
        if(stud.myCourse[i].year == year && stud.myCourse[i].semester == sem && (stud.myCourse[i].status == 'P' || stud.myCourse[i].status == 'F')){
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
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

    for(int i = 1; i <= stud.semester && i <= 10; ++i){
        string space = "                                             ";
        int col1 = stringlength("Course Name");
        int col2 = stringlength("Course Code");
        int col3 = 5;
        int col4 = stringlength("Grade Mark");
        int col5 = stringlength("Status");

        for(int j = 0; j < stud.myCourse.size(); j++){
            if((stud.myCourse[j].year == (i + 1) / 2) && ((stud.myCourse[j].semester == (((i+1) % 2) + 1)))){
                col1 = highest(col1, stringlength(stud.myCourse[j].name));
                col2 = highest(col2, stringlength(stud.myCourse[j].code));
                col4 = highest(col4, stringlength(toLetter(stud.myCourse[j].grade)));
                col5 = highest(col5, stringlength(statusToWords(stud.myCourse[j].status)));
            }
        }

        int colNum = 16 + col1 + col2 + col3 + col4 + col5;
        
        cout<<endl<<endl;
        cout<<strConcat(space, "Year: ", (colNum - 38) / 2, 5)<<(i + 1) / 2<<" Semester: "<<((i+1) % 2) + 1<<" Course information";
        cout<<endl;
        prints('_', colNum);
        cout<<endl<<"| ";
        cout<<strConcat("Course Name", space, stringlength("Course Name"), col1 - stringlength("Course Name"))<<" | ";
        cout<<strConcat("Course Code", space, stringlength("Course Code"), col2 - stringlength("Course Code"))<<" | Grade | ";
        cout<<strConcat("Grade Mark", space, stringlength("Grade Mark"), col4 - stringlength("Grade Mark"))<<" | ";
        cout<<strConcat("Status", space, stringlength("Status"), col5 - stringlength("Status"))<<" | ";

        cout<<endl<<"|-"; 
        prints('-', col1); cout<<"-|-";
        prints('-', col2); cout<<"-|-";
        prints('-', col3); cout<<"-|-";
        prints('-', col4); cout<<"-|-";
        prints('-', col5); cout<<"-|";

        for(int j = 0; j < stud.myCourse.size(); j++){
            if((stud.myCourse[j].year == (i + 1) / 2) && ((stud.myCourse[j].semester == (((i+1) % 2) + 1)))){
                cout<<endl<<"| ";
                cout<<strConcat(stud.myCourse[j].name, space, stringlength(stud.myCourse[j].name), col1 - stringlength(stud.myCourse[j].name))<<" | ";
                cout<<strConcat(stud.myCourse[j].code, space, stringlength(stud.myCourse[j].code), col2 - stringlength(stud.myCourse[j].code))<<" | ";
                cout<<strConcat(strConcat(to_string(stud.myCourse[j].grade), "\0", 5, 0), space, stringlength(strConcat(to_string(stud.myCourse[j].grade), "\0", 5, 0)), col3 - stringlength(strConcat(to_string(stud.myCourse[j].grade), "\0", 5, 0)))<<" | ";
                cout<<strConcat(toLetter(stud.myCourse[j].grade), space, stringlength(toLetter(stud.myCourse[j].grade)), col4 - stringlength(toLetter(stud.myCourse[j].grade)))<<" | ";
                cout<<strConcat(statusToWords(stud.myCourse[j].status), space, stringlength(statusToWords(stud.myCourse[j].status)), col5 - stringlength(statusToWords(stud.myCourse[j].status)))<<" |";

                cout<<endl<<"|-"; 
                prints('-', col1); cout<<"-|-";
                prints('-', col2); cout<<"-|-";
                prints('-', col3); cout<<"-|-";
                prints('-', col4); cout<<"-|-";
                prints('-', col5); cout<<"-|";
            }
        }
        cout<<endl<<" Year "<<(i + 1) / 2<<", Semester "<<((i+1) % 2) + 1<<" GPA: "<<semesterGPA(stud, i)<<endl<<endl;
    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_students(int *orders, int n){
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

    if(n == 0) cout<<endl<<"There are no students that fit the criteria!!"<<endl;
    else{
        string space = "                                             ";
        int col1 = stringlength("First Name");
        int col2 = stringlength("Last Name");
        int col3 = stringlength("Id");
        int col4 = stringlength("Department");
        int col5, col5a;
        if(students[orders[0]].status == 'G') col5 = stringlength("Graduation Year");
        else{
            col5 = stringlength("Year");
            col5a = stringlength("Semester");
        }
        int col6 = highest(5, stringlength("CGPA"));
        int col7 = stringlength("Status");

        for(int i = 0; i < n; ++i){
            col1 = highest(col1, stringlength(students[orders[i]].name[0]));
            col2 = highest(col2, stringlength(students[orders[i]].name[1]));
            col3 = highest(col3, stringlength(students[orders[i]].id));
            col4 = highest(col4, stringlength(students[orders[i]].department));
            if(students[orders[0]].status == 'G') col5 = highest(col5, stringlength(to_string(students[orders[i]].semester)));
            else{
                col5 = highest(col5, stringlength(to_string((students[orders[i]].semester + 1) / 2)));
                col5a = highest(col5a, stringlength(to_string(((students[orders[i]].semester + 1) % 2) + 1)));
            }
            col7 = highest(col7, stringlength(statusToWords(students[orders[i]].status)));
        }
        int colNum = 22 + col1 + col2 + col3 + col4 + col5 + col6 + col7;
        if(students[orders[0]].status != 'G') colNum = colNum + col5a + 3;

        cout<<strConcat(space, "Student Information", (colNum - stringlength("Student Information")) / 2, stringlength("Student Information"));
        cout<<endl<<endl;
        prints('_', colNum);
        cout<<endl<<"| ";
        cout<<strConcat("First Name", space, stringlength("First Name"), col1 - stringlength("First Name"))<<" | ";
        cout<<strConcat("Last Name", space, stringlength("Last Name"), col2 - stringlength("Last Name"))<<" | ";
        cout<<strConcat("Id", space, stringlength("Id"), col3 - stringlength("Id"))<<" | ";
        cout<<strConcat("Department", space, stringlength("Department"), col4 - stringlength("Department"))<<" | ";
        if(students[orders[0]].status == 'G') cout<<strConcat("Graduation Year", space, stringlength("Graduation Year"), col5 - stringlength("Graduation Year"))<<" | ";
        else{
            cout<<strConcat("Year", space, stringlength("Year"), col5 - stringlength("Year"))<<" | ";
            cout<<strConcat("Semester", space, stringlength("Semester"), col5a - stringlength("Semester"))<<" | ";
        }
        cout<<strConcat("CGPA", space, stringlength("CGPA"), col6 - stringlength("CGPA"))<<" | ";
        cout<<strConcat("Status", space, stringlength("Status"), col7 - stringlength("Status"))<<" |";

        cout<<endl<<"|-"; 
        prints('-', col1); cout<<"-|-";
        prints('-', col2); cout<<"-|-";
        prints('-', col3); cout<<"-|-";
        prints('-', col4); cout<<"-|-";
        prints('-', col5); cout<<"-|-";
        if(students[orders[0]].status != 'G') {prints('-', col5a); cout<<"-|-";}
        prints('-', col6); cout<<"-|-";
        prints('-', col7); cout<<"-|";

        for(int i = 0; i < n; ++i){
            cout<<endl<<"| ";
            cout<<strConcat(students[orders[i]].name[0], space, stringlength(students[orders[i]].name[0]), col1 - stringlength(students[orders[i]].name[0]))<<" | ";
            cout<<strConcat(students[orders[i]].name[1], space, stringlength(students[orders[i]].name[1]), col2 - stringlength(students[orders[i]].name[1]))<<" | ";
            cout<<strConcat(students[orders[i]].id, space, stringlength(students[orders[i]].id), col3 - stringlength(students[orders[i]].id))<<" | ";
            cout<<strConcat(students[orders[i]].department, space, stringlength(students[orders[i]].department), col4 - stringlength(students[orders[i]].department))<<" | ";
            if(students[orders[0]].status == 'G') cout<<strConcat(to_string(students[orders[i]].semester), space, stringlength(to_string(students[orders[i]].semester)), col5 - stringlength(to_string(students[orders[i]].semester)))<<" | ";
            else{
                cout<<strConcat(to_string((students[orders[i]].semester + 1) / 2), space, stringlength(to_string((students[orders[i]].semester + 1) / 2)), col5 - stringlength(to_string((students[orders[i]].semester + 1) / 2)))<<" | ";
                cout<<strConcat(to_string(((students[orders[i]].semester + 1) % 2) + 1), space, stringlength(to_string(((students[orders[i]].semester + 1) % 2) + 1)), col5a - stringlength(to_string(((students[orders[i]].semester + 1) % 2) + 1)))<<" | ";
            }
            cout<<strConcat(strConcat(to_string(students[orders[i]].cgpa), "\0", 5, 0), space, stringlength(strConcat(to_string(students[orders[i]].cgpa), "\0", 5, 0)), col6 - stringlength(strConcat(to_string(students[orders[i]].cgpa), "\0", 5, 0)))<<" | ";
            cout<<strConcat(statusToWords(students[orders[i]].status), space, stringlength(statusToWords(students[orders[i]].status)), col7 - stringlength(statusToWords(students[orders[i]].status)))<<" |";

            cout<<endl<<"|-"; 
            prints('-', col1); cout<<"-|-";

            prints('-', col2); cout<<"-|-";
            prints('-', col3); cout<<"-|-";
            prints('-', col4); cout<<"-|-";
            prints('-', col5); cout<<"-|-";
            if(students[orders[0]].status != 'G') {prints('-', col5a); cout<<"-|-";}
            prints('-', col6); cout<<"-|-";
            prints('-', col7); cout<<"-|";
        } 
    }
    
    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_student_info(Student stud){
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

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
        cout<<endl<<"Year: "<<(stud.semester + 1) / 2<<"\tSemester: "<<((stud.semester + 1) % 2) + 1;
        cout<<endl<<"Semester Load: "<<stud.semesterLoad;
    }
    cout<<endl<<"Student CGPA: "<<stud.cgpa;
    cout<<endl<<"Student Rank: "<<stud.rank<<endl;

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
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

    cout<<endl<<"You have successfully changed your password";
    change = true;
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
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

    if(n == 0) cout<<endl<<"There is no course that fits the criteria!!"<<endl;
    else{
        string space = "                                             ";
        int col1 = stringlength("Course Name");
        int col2 = stringlength("Course Code");
        int col3 = stringlength("Credit Hour");
        int col4 = stringlength("Department");
        int col5 = stringlength("Year");
        int col6 = stringlength("Semester");

        for(int i = 0; i < n; ++i){
            col1 = highest(col1, stringlength(courses[orders[i]].name));
            col2 = highest(col2, stringlength(courses[orders[i]].code));
            col3 = highest(col3, stringlength(to_string(courses[orders[i]].crHr)));
            col4 = highest(col4, stringlength(courses[orders[i]].department));
            col5 = highest(col5, stringlength(to_string(courses[orders[i]].year)));
            col6 = highest(col6, stringlength(to_string(courses[orders[i]].semester)));
        }
        int colNum = 19 + col1 + col2 + col3 + col4 + col5 + col6;

        cout<<strConcat(space, "Course Information", colNum - stringlength("Course Information"), stringlength("Course Information"));
        cout<<endl<<endl;
        prints('_', colNum);

        cout<<endl<<"| ";
        cout<<strConcat("Course Name", space, stringlength("Course Name"), col1 - stringlength("Course Name"))<<" | ";
        cout<<strConcat("Course Code", space, stringlength("Course Code"), col2 - stringlength("Course Code"))<<" | ";
        cout<<strConcat("Credit Hour", space, stringlength("Credit Hour"), col3 - stringlength("Credit Hour"))<<" | ";
        cout<<strConcat("Department", space, stringlength("Department"), col4 - stringlength("Department"))<<" | ";
        cout<<strConcat("Year", space, stringlength("Year"), col5 - stringlength("Year"))<<" | ";
        cout<<strConcat("Semester", space, stringlength("Semester"), col6 - stringlength("Semester"))<<" |";

        cout<<endl<<"|-"; 
        prints('-', col1); cout<<"-|-";
        prints('-', col2); cout<<"-|-";
        prints('-', col3); cout<<"-|-";
        prints('-', col4); cout<<"-|-";
        prints('-', col5); cout<<"-|-";
        prints('-', col6); cout<<"-|";

        for(int i = 0; i < n; ++i){
            cout<<endl<<"| ";
            cout<<strConcat(courses[orders[i]].name, space, stringlength(courses[orders[i]].name), col1 - stringlength(courses[orders[i]].name))<<" | ";
            cout<<strConcat(courses[orders[i]].code, space, stringlength(courses[orders[i]].code), col2 - stringlength(courses[orders[i]].code))<<" | ";
            cout<<strConcat(to_string(courses[orders[i]].crHr), space, stringlength(to_string(courses[orders[i]].crHr)), col3 - stringlength(to_string(courses[orders[i]].crHr)))<<" | ";
            cout<<strConcat(courses[orders[i]].department, space, stringlength(courses[orders[i]].department), col4 - stringlength(courses[orders[i]].department))<<" | ";
            cout<<strConcat(to_string(courses[orders[i]].year), space, stringlength(to_string(courses[orders[i]].year)), col5 - stringlength(to_string(courses[orders[i]].year)))<<" | ";
            cout<<strConcat(to_string(courses[orders[i]].semester), space, stringlength(to_string(courses[orders[i]].semester)), col6 - stringlength(to_string(courses[orders[i]].semester)))<<" |";

            cout<<endl<<"|-"; 
            prints('-', col1); cout<<"-|-";
            prints('-', col2); cout<<"-|-";
            prints('-', col3); cout<<"-|-";
            prints('-', col4); cout<<"-|-";
            prints('-', col5); cout<<"-|-";
            prints('-', col6); cout<<"-|";
        }
    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_course_info(Course course){
    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

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

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
}

void display_courses_forstaff(){
    string department;

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
    if(stud.status == 'W' || stud.status == 'G') return false;
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
        change = true;
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

    if(stud.semester >= 1000) stud.status = 'G';

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
    bool canPass = false;
    int year = (stud.semester + 1) / 2;
    int semester = ((stud.semester + 1) % 2) + 1;

    for(int j = 0; j < stud.myCourse.size(); ++j){
        if(stud.myCourse[j].year == year && stud.myCourse[j].semester == semester){
            if(stud.myCourse[j].status == 'R') return 0;
            else if(stud.myCourse[j].status == 'P') canPass = true;
        }
    }

    if(stud.semester < 10){
        if(canPass){
            stud.semester++;
            change = true;
        }
    }
    else if(canPass){
        bool canGraduate = true;

        for(int i = 0; canGraduate && i < courses.size(); ++i){
            if(courses[i].department == stud.department){
                cout<<endl<<"course "<<i;
                for(int j = 0; j < stud.myCourse.size(); ++j){
                    if((courses[i].code == stud.myCourse[j].code) && stud.myCourse[j].status == 'P') break;
                    else if(j == stud.myCourse.size() - 1) canGraduate = false;
                }
            }
        }

        if(canGraduate) stud.semester = 1000;
        else stud.semester = 11;
        cout<<endl<<stud.semester;
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
                if(change) save();
                break;

            case 'B':
                updateExistingStudent();
                if(change) save();
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

    change = true;
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
            if(value != "="){
                stud.name[0] = value;
                change = true;
            }
            cout<<endl<<"Enter the new father's name (Enter '=' to keep the current name): ";
            cin>>value;
            if(value != "="){
                stud.name[1] = value;
                change = true;
            }
            cout<<endl<<"Enter the new grandfather's name (Enter '=' to keep the current name): ";
            cin>>value;
            if(value != "="){
                stud.name[2] = value;
                change = true;
            }
            break;

        case 'B':
            cout<<endl<<"The student's current id is "<<stud.id;
            cout<<endl<<"Enter the new id (Enter '=' to keep the current id): ";
            cin>>value;
            if(value != "="){
                stud.id = value;
                change = true;
            }
            break;

        case 'C':
            cout<<endl<<"The student's current department is "<<stud.department;
            cout<<endl<<"Enter the new department (Enter '=' to keep the current department): ";
            cin.ignore();
            getline(cin, value);
            if(value != "="){
                stud.department = value;
                change = true;
            }
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
            cout<<endl<<"Enter 'W' for withdrawal and 'C' for readmission: ";
            cin>>value2;
            value2 = toupper(value2);

            if(value2 == 'C' || value2 == 'W'){
                stud.status = value2;
                change = true;

                if(stud.status == 'W'){
                    for(int i = 0; i < stud.myCourse.size(); ++i){
                        if(stud.myCourse[i].status == 'R') dropCourse(stud.myCourse[i].code, stud);
                    }
                }
            }
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

    cout<<endl<<"You have successfully droped the course "<<courseCode;
    change = true;
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
                if(change) save();
                break;

            case 'B':
                updateExistingCourse();
                break;
        }
    }while(menu == 'A' || menu == 'B');

    return 0;
}

int insertNewCourse(){
    Course course;
    cout<<endl<<"Enter the id of the new course: ";
    cin>>course.code;

    for(int i = 0; i < courses.size(); ++i){
        if(course.code == courses[i].code){
            cout<<endl<<"There is a course with code "<<course.code<<" in database!";
            return 0;
        }
    }

    cout<<endl<<"Enter the name of the new course: ";
    cin.ignore();
    getline(cin, course.name);
    cout<<endl<<"Enter the credit hour of the new course: ";
    cin>>course.crHr;
    cout<<endl<<"Enter the department of the new course: ";
    cin.ignore();
    getline(cin, course.department);
    course.department = strToUpper(course.department);

    cout<<endl<<"Enter the year of the new course: ";
    cin>>course.year;
    if(course.year < 1 || course.year > 5){
        cout<<endl<<"Invalid year!";
        return 0;
    }

    cout<<endl<<"Enter the semester of the new course: ";
    cin>>course.semester;
    if(course.semester != 1 && course.semester != 2){
        cout<<endl<<"Invalid semester!";
        return 0;
    }

    string value;
    bool alreadyThere = false;

    do{
        cout<<endl<<"Enter id of teacher teaching this course (Enter 'X' if you are done): ";
        cin>>value;
        if(value != "x" && value != "X"){
            for(int i = 0; i < course.teachers.size(); ++i){
                if(course.teachers[i] == value){
                    cout<<endl<<"The teacher with id "<<value<<" is already a teacher of the course!!";
                    alreadyThere = true;
                    break;
                }
            }
            if(!alreadyThere) course.teachers.push_back(value);
        }
    }while(value != "x" && value != "X");

    do{
        cout<<endl<<"Enter code of a course that is a prerequisite to this course (Enter 'X' if you are done): ";
        cin>>value;
        if(value != "x" && value != "X"){
            for(int i = 0; i < course.prerequisites.size(); ++i){
                if(course.prerequisites[i] == value){
                    cout<<endl<<"The course with code "<<value<<" is already a prerequisite of the course!!";
                    alreadyThere = true;
                    break;
                }
            }

            if(!alreadyThere){
                for(int i = 0; i < courses.size(); ++i){
                    if(value == courses[i].code){
                        course.prerequisites.push_back(value);
                        break;
                    }
                    else if(i == courses.size() - 1){
                        cout<<endl<<"There is no course with code "<<value<<" in database so it can't be a prerequisite!";
                    }
                }
            }
        }
    }while(value != "x" && value != "X");

    course.currentTeacher = 0;
    courses.push_back(course);
    cout<<endl<<"You have successfully inserted course "<<courses[courses.size() - 1].code;
    change =  true;

    return 0;
}

int updateExistingCourse(){
    string courseCode;

    cout<<endl<<"Enter the code of the course to update (Enter 'X' to go back): ";
    cin>>courseCode;

    if(courseCode == "x" && courseCode == "X") return 0;

    int index;
    for(int i = 0; i < courses.size(); ++i){
        if(courses[i].code == courseCode){
            index = i;
            break;
        }
        else if(i == courses.size() - 1){
            cout<<endl<<"There is no course with code "<<courseCode<<endl;
            return 0;
        }
    }

    char menu;
    char menu2;

    do{
        cout<<endl<<"Enter 'A' to update the course";
        cout<<endl<<"Enter 'B' to delete the course";
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your choice: ";
        cin>>menu;
        menu = toupper(menu);
        switch(menu){
            case 'A':
                updateCourse(courses[index]);
                if(change) save();
                break;

            case 'B':
                cout<<endl<<"Are you sure you want to delete "<<courses[index].code<<" from the database?";
                cout<<endl<<"Enter 'Y' to delete it and any other character to go back: ";
                cin>>menu2;
                menu2 = toupper(menu2);
                if(menu2 != 'Y') break;
                deleteCourse(index);
                if(change) save();
                break;
        }
    }while(menu == 'A');

    return 0;
}

int updateCourse(Course &course){
    char menu;

    do{
        cout<<endl<<"Enter 'A' to change name of "<<course.code;
        cout<<endl<<"Enter 'B' to change credit hour of "<<course.code;
        cout<<endl<<"Enter 'C' to Add Prerequisite of "<<course.code;
        cout<<endl<<"Enter 'D' to Add teacher to "<<course.code;
        cout<<endl<<"Enter 'E' to Remove Prerequisite of "<<course.code;
        cout<<endl<<"Enter 'F' to Remove teacher of "<<course.code;
        cout<<endl<<"Enter any other character to go back";
        cout<<endl<<"Your Choice: ";
        cin>>menu;
        menu = toupper(menu);

        string value;
        int value2;
        int index;

        switch (menu){
            case 'A':
                cout<<endl<<"The course's current name is "<<course.name;
                cout<<endl<<"Enter the new name (Enter '=' to keep the current name): ";
                cin.ignore();
                getline(cin, value);
                if(value != "="){
                    course.name = value;
                    change = true;
                }
                break;

            case 'B':
                cout<<endl<<"The course's current credit hour is "<<course.crHr;
                cout<<endl<<"Enter the new credit hour (Enter '-1' to keep the current credit hour): ";
                cin>>value2;
                if(value2 >= 0){
                    course.crHr = value2;
                    change = true;
                }
                break;

            case 'C':
                do{
                    value2 = 0;
                    cout<<endl<<"Enter the new prerequisite (Enter '=' if you are done): ";
                    cin>>value;
                    if(value != "="){
                        for(int i = 0; i < course.prerequisites.size(); ++i){
                            if(value == course.prerequisites[i]){
                                cout<<endl<<value<<" is already a prerequisite of the course!!";
                                value2++;
                                break;
                            }
                        }
                        if(value2 == 0){
                            course.prerequisites.push_back(value);
                            change = true;
                        }
                    }
                }while(value != "=");
                break;

            case 'D':
                do{
                    value2 = 0;
                    cout<<endl<<"Enter the new teacher (Enter '=' if you are done): ";
                    cin>>value;
                    if(value != "="){
                        for(int i = 0; i < course.teachers.size(); ++i){
                            if(value == course.teachers[i]){
                                cout<<endl<<value<<" is already a teacher of the course!!";
                                value2++;
                                break;
                            }
                        }
                        if(value2 == 0){
                            course.teachers.push_back(value);
                            change = true;
                        }
                    }
                }while(value != "=");
                break;

            case 'E':
                value2 = 0;
                cout<<endl<<"Enter the code of the prerequisite you want to remove (Enter '=' to go back): ";
                cin>>value;

                if(value == "=") break;

                for(int i = 0; i < course.prerequisites.size(); ++i){
                    if(value == course.prerequisites[i]){
                        index = i;
                        break;
                    }
                    else if(i == course.prerequisites.size() - 1){
                        value2++;
                        cout<<endl<<"There is no prerequisite with code "<<value<<'!';
                    }
                }

                if(value2 != 0) break;

                course.prerequisites.erase(course.prerequisites.begin() + index);
                change = true;
                break;

            case 'F':
                value2 = 0;
                cout<<endl<<"Enter the id of the teacher you want to remove (Enter '=' to go back): ";
                cin>>value;

                if(value == "=") break;

                for(int i = 0; i < course.teachers.size(); ++i){
                    if(value == course.teachers[i]){
                        index = i;
                        break;
                    }
                    else if(i == course.teachers.size() - 1){
                        value2++;
                        cout<<endl<<"There is no teacher with id "<<value<<'!';
                    }
                }

                if(value2 != 0) break;

                course.teachers.erase(course.teachers.begin() + index);
                change = true;
                break;
        }

    }while(menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D' || menu == 'E' || menu == 'F');

    return 0;
}

int deleteCourse(int index){
    for(int i = 0; i < students.size(); ++i){
        for(int j = 0; j < students[i].myCourse.size(); ++j){
            if((courses[index].code == students[i].myCourse[j].code) && (students[i].myCourse[j].grade == -1)){
                cout<<endl<<"There are students learning this course this semester so it can't be deleted!";
                return 0;
            }
        }
    }

    string courseCode = courses[index].code;

    courses.erase(courses.begin() + index);

    for(int i = 0; i < courses.size(); ++i){
        int index2;
        for(int j = 0; j < courses[i].prerequisites.size(); ++j){
            if(courseCode == courses[i].prerequisites[j]){
                index2 = j;
                break;
            }
        }

        courses[i].prerequisites.erase(courses[i].prerequisites.begin() + index2);
    }

    cout<<endl<<"The course "<<courseCode<<" is deleted successfully!!";
    change = true;
    return 0;
}

void search_stud(){
        char menu;

        do{
            cout<<endl<<"Enter 'A' to search by id";
            cout<<endl<<"Enter 'B' to search by currently registered course";
            cout<<endl<<"Enter any other character to go back";
            cout<<endl<<"Your choice: ";
            cin>>menu;
            menu = toupper(menu);

            switch (menu){

            case 'A':
                search_by_id();
                break;

            case 'B':
                search_by_course();
                break;
            }
        }while(menu == 'A' || menu == 'B');
      

}

void search_by_id(){
    string id;

    cout<<"Enter the id of the student: ";
    cin>>id;

    for(int i = 0; i < students.size(); i++){
        if(students[i].id == id){
            display_student_info(students[i]);
            break;
        }
        else if(i == students.size() - 1){
            cout<<"\nStudent not found in the database!!\n";
        }
    }
}

void search_by_course(){
    string code;

    cout<<"Enter the course code: ";
    cin>>code;

    map<int, string> studentMap;
    for(int i = 0; i < students.size(); ++i){
        for(int j = 0; j < students[i].myCourse.size(); ++j){
            if((code == students[i].myCourse[j].code) && (students[i].myCourse[j].grade == -1)){
                studentMap.insert(pair<int, string>(i, students[i].id));
            }
        }
    }

    int *orders = new int[studentMap.size()];
    order(orders, studentMap.size(), studentMap);
    display_students(orders, studentMap.size());
    delete[] orders;
}

void search_course(){
        char menu;

        do{
            cout<<endl<<"Enter 'A' to search Course by its code";
            cout<<endl<<"Enter 'B' to search courses that a Student is currently registered to";
            cout<<endl<<"Enter 'C' to search courses that a Teacher teaches";
            cout<<endl<<"Enter 'D' to search courses that have specific prerequisites";
            cout<<endl<<"Enter any other key to go back";
            cout<<endl<<"Your choice: ";
            cin>>menu;
            menu = toupper(menu);

            switch (menu)
            {
                case 'A':
                    search_by_course_code();
                    break;

                case 'B':
                    search_by_student();
                    break;

                case 'C':
                    search_by_teacher();
                    break;

                case 'D':
                    search_by_prerequisite();
                    break;
            }
        }while(menu == 'A' || menu == 'B' || menu == 'C' || menu == 'D');
}

void search_by_course_code(){
    string code;

    cout<<"\nEnter course code: ";
    cin>>code;

    for(int i = 0; i < courses.size(); i++){
        if(courses[i].code == code){
            display_course_info(courses[i]);
            break;
        }
        else if(i == courses.size() - 1){
            cout<<"\nA course with this course code doesn't exist in the database!!\n";
        }
    }
}

int search_by_student(){
    string studId;

    cout<<"\nEnter the id of the student: ";
    cin>>studId;

    int index;
    for(int i = 0; i < students.size(); i++){
        if(studId == students[i].id){
            index = i;
            break;
        }
        else if(i == students.size() - 1){
            cout<<"\nStudent not found in the record\n";
            return 0;
        }
    }

    map<int, string> courseMap;

    for(int i = 0; i < students[index].myCourse.size(); ++i){
        if(students[index].myCourse[i].grade == -1){
            for(int j = 0; j < courses.size(); ++i){
                if((students[index].myCourse[i].code == courses[j].code)){
                    courseMap.insert(pair<int, string>(j, courses[j].code));
                }
                break;
            }
        }
    }
    
    int *orders = new int[students[index].myCourse.size()];
    order(orders, students[index].myCourse.size(), courseMap);
    display_courses(orders, students[index].myCourse.size());
    delete[] orders;

    return 0;
}

void search_by_teacher(){
    string teacherId;

    cout<<"\nEnter the id of the teacher: ";
    cin>>teacherId;

    map<int, string> courseMap;

    for(int i = 0; i < courses.size(); ++i){
        if(teacher_teaches_course(teacherId, courses[i])){
            courseMap.insert(pair<int, string>(i, courses[i].code));
        }
    }
    
    int *orders = new int[courseMap.size()];
    order(orders, courseMap.size(), courseMap);
    display_courses(orders, courseMap.size());
    delete[] orders;
}

void search_by_prerequisite(){
    string courseCode;

    cout<<"\nEnter the code of the prerequisite (Enter 'X' to find courses that have no prerequisite): ";
    cin>>courseCode;

    map<int, string> courseMap;

    if(courseCode == "x" || courseCode == "X"){
        for(int i = 0; i < courses.size(); ++i){
            if(courses[i].prerequisites.size() == 0) courseMap.insert(pair<int, string>(i, courses[i].code));
        }
    }
    else{
        for(int i = 0; i < courses.size(); ++i){
            for(int j = 0; j < courses[i].prerequisites.size(); ++i){
                if(courseCode == courses[i].prerequisites[j]){
                    courseMap.insert(pair<int, string>(i, courses[i].code));
                    break;
                }
            }
        }
    }

    int *orders = new int[courseMap.size()];
    order(orders, courseMap.size(), courseMap);
    display_courses(orders, courseMap.size());
    delete[] orders;
}

string statusToWords(char status){
    if(status == 'P') return "Passed";
    else if(status == 'F') return "Fail";
    else if(status == 'U') return "No Grade";
    else if(status == 'R') return "Registered";
    else if(status == 'D') return "Dismissed";
    else if(status == '!') return "Warned";
    else if(status == 'W') return "Withdrawal";
    else if(status == 'N') return "New Student";
    else if(status == 'G') return "Graduated";

    return "\0";
}

int statistical_report(){
    vector<int> graduationYears;
    string department;

    for(int i = 0; i < students.size(); ++i){
        if(students[i].semester > 1000){
            if(graduationYears.size() == 0) graduationYears.push_back(students[i].semester);
            for(int j = 0; j < graduationYears.size(); ++j){
                if(students[i].semester == graduationYears[j]) break;
                else if(j == graduationYears.size() - 1){
                    graduationYears.push_back(students[i].semester);
                }
            }
        }
    }
    cout<<endl<<"Please enter department (Enter 'All' to select all department): ";
    cin.ignore();
    getline(cin, department);
    department = strToUpper(department);

    cout<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl<<endl;

    cout<<endl<<"Statistical Report of "<<department<<" department"<<endl;

    cout<<endl<<"________________________________________________";
    cout<<endl<<"| Batch | Passed | Warned | Failed | Withdraws |\n";
    cout<<"|-------|--------|--------|--------|-----------|\n";
    for(int i = 1; i <= 5; ++i){
        cout<<"|   "<<i<<"   |";
        prints(' ', (8 - stringlength(to_string(howMany(i, department, 'P')))) / 2);
        cout<<howMany(i, department, 'P');
        prints(' ', (9 - stringlength(to_string(howMany(i, department, 'P')))) / 2);
        cout<<'|';
        prints(' ', (8 - stringlength(to_string(howMany(i, department, '!')))) / 2);
        cout<<howMany(i, department, '!');
        prints(' ', (9 - stringlength(to_string(howMany(i, department, '!')))) / 2);
        cout<<'|';
        prints(' ', (8 - stringlength(to_string(howMany(i, department, 'F')))) / 2);
        cout<<howMany(i, department, 'F');
        prints(' ', (9 - stringlength(to_string(howMany(i, department, 'F')))) / 2);
        cout<<'|';
        prints(' ', (11 - stringlength(to_string(howMany(i, department, 'W')))) / 2);
        cout<<howMany(i, department, 'W');
        prints(' ', (12 - stringlength(to_string(howMany(i, department, 'W')))) / 2);
        cout<<'|';
        cout<<"\n|-------|--------|--------|--------|-----------|\n";
    }

    cout<<endl<<endl<<"Number of New Students: "<<howMany(1, department, 'N');
    cout<<"\nNumber of non-graduates: "<<howMany(6, department)<<endl;

    if(graduationYears.size() == 0){
        cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
        return 0;
    }
    cout<<endl<<endl<<"________________________________________";
    cout<<endl<<"| Graduating Year | Number of Students |";
    cout<<endl<<"|-----------------|--------------------|\n";
    for(int i = 0; i < graduationYears.size(); ++i){
        cout<<'|';
        prints(' ', (17 - stringlength(to_string(graduationYears[i]))) / 2);
        cout<<graduationYears[i];
        prints(' ', (18 - stringlength(to_string(graduationYears[i]))) / 2);
        cout<<'|';
        prints(' ', (20 - stringlength(to_string(howMany(graduationYears[i], department)))) / 2);
        cout<<howMany(graduationYears[i], department);
        prints(' ', (21 - stringlength(to_string(howMany(graduationYears[i], department)))) / 2);
        cout<<'|';
        cout<<"\n|-----------------|--------------------|\n";
    }

    cout<<endl<<endl<<"----------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*--------------------*----------"<<endl;
    return 0;
}

int howMany(int year, string department, char status){
    int sum = 0;

    if(year < 6){
        for(int i = 0; i < students.size(); ++i){
            if(((students[i].semester + 1)/ 2 == year) && ((department == "ALL") || (students[i].department == department)) && (students[i].status == status)){
                sum++;
            }
        }
    }
    else if(year == 6){
        for(int i = 0; i < students.size(); ++i){
            if(students[i].semester == 11 && ((department == "ALL") || (students[i].department == department)) && (students[i].status == status)){
                sum++;
            }
        }
    }
    else{
        for(int i = 0; i < students.size(); ++i){
            if(students[i].semester == year && ((department == "ALL") || (students[i].department == department))){
                sum++;
            }
        }
    }

    return sum;
}

int save(){
    char choice;
    cout<<endl<<"Do you want to save all unsaved changes to the database?\nEnter 'Y' to save changes and any other character not to\nYour choice: ";
    cin>>choice;
    choice = toupper(choice);

    if(choice != 'Y'){
        return 0;
    }

    fstream studFile, coursesFile;
    studFile.open("Students", ios::out | ios::trunc);
    coursesFile.open("Courses", ios::out | ios::trunc);

    if(!studFile.is_open() || !coursesFile.is_open()){
        cout<<endl<<"Couldn\'t open file(s)!!";
        return 0;
    }

    studFile<<students.size();

    for(int i = 0; i < students.size(); ++i){
        studFile<<'\n'<<students[i].name[0];
        studFile<<'|'<<students[i].name[1];
        studFile<<'|'<<students[i].name[2];
        studFile<<'|'<<students[i].id;
        studFile<<'|'<<students[i].semester;
        studFile<<'|'<<students[i].department;
        studFile<<'|'<<students[i].password;
        studFile<<'\n'<<students[i].myCourse.size();

        for(int j = 0; j < students[i].myCourse.size(); ++j){
            studFile<<'\n'<<students[i].myCourse[j].name;
            studFile<<'|'<<students[i].myCourse[j].code;
            studFile<<'|'<<students[i].myCourse[j].crHr;
            studFile<<'|'<<students[i].myCourse[j].grade;
            studFile<<'|'<<students[i].myCourse[j].year;
            studFile<<'|'<<students[i].myCourse[j].semester;
            studFile<<'|'<<students[i].myCourse[j].teacher;
        }
    }

    coursesFile<<courses.size()<<'\n';

    for(int i = 0; i < courses.size(); ++i){
        coursesFile<<'\n'<<courses[i].name;
        coursesFile<<'|'<<courses[i].code;
        coursesFile<<'|'<<courses[i].crHr;
        coursesFile<<'|'<<courses[i].year;
        coursesFile<<'|'<<courses[i].semester;
        coursesFile<<'|'<<courses[i].department;
        coursesFile<<'|'<<courses[i].currentTeacher;
        coursesFile<<'\n'<<courses[i].prerequisites.size()<<'|';

        for(int j = 0; j < courses[i].prerequisites.size(); ++j){
            coursesFile<<courses[i].prerequisites[j]<<'|';
        }

        coursesFile<<'\n'<<courses[i].teachers.size()<<'|';

        for(int j = 0; j < courses[i].teachers.size(); ++j){
            coursesFile<<courses[i].teachers[j]<<'|';
        }
    }

    studFile.close();
    coursesFile.close();
    change = false;
    cout<<endl<<"File successfully saved!!"<<endl;
    return 0;
}

int readFromFile(){
    fstream studentFile, courseFile;
    courseFile.open("Courses", ios::in);
    studentFile.open("Students", ios::in);

    if(!studentFile.is_open() || !courseFile.is_open()){
        cout<<endl<<"Couldn\'t open file(s)!!";
        return 0;
    }

    int size, size1;
    Course course;
    Student stud;

    courseFile.seekg(0, ios::beg);
    courseFile>>size;
    courseFile.seekg(1, ios::cur);

    for(int i = 0; i < size; ++i){
        Course course;

        courseFile.seekg(1, ios::cur);
        getline(courseFile, course.name, '|');
        getline(courseFile, course.code, '|');
        courseFile>>course.crHr;
        courseFile.seekg(1, ios::cur);
        courseFile>>course.year;
        courseFile.seekg(1, ios::cur);
        courseFile>>course.semester;
        courseFile.seekg(1, ios::cur);
        getline(courseFile, course.department, '|');
        course.department = strToUpper(course.department);
        courseFile>>course.currentTeacher;
        courseFile.seekg(1, ios::cur);
        courseFile>>size1;
        courseFile.seekg(1, ios::cur);

        for(int j = 0; j < size1; ++j){
            string prerequisite;
            getline(courseFile, prerequisite, '|');
            course.prerequisites.push_back(prerequisite);
        }

        courseFile.seekg(1, ios::cur);
        courseFile>>size1;
        courseFile.seekg(1, ios::cur);

        for(int j = 0; j < size1; ++j){
            string teacher;
            getline(courseFile, teacher, '|');
            course.teachers.push_back(teacher);
        }

        courses.push_back(course);
    }

    studentFile.seekg(0, ios::beg);
    studentFile>>size;
    studentFile.seekg(1, ios::cur);

    for(int i = 0; i < size; ++i){
        Student stud;

        getline(studentFile, stud.name[0], '|');
        getline(studentFile, stud.name[1], '|');
        getline(studentFile, stud.name[2], '|');
        getline(studentFile, stud.id, '|');
        studentFile>>stud.semester;
        studentFile.seekg(1, ios::cur);
        getline(studentFile, stud.department, '|');
        getline(studentFile, stud.password);
        studentFile>>size1;
        studentFile.seekg(1, ios::cur);

        for(int j = 0; j < size1; ++j){
            StudCourse myCourse;

            getline(studentFile, myCourse.name, '|');
            getline(studentFile, myCourse.code, '|');
            studentFile>>myCourse.crHr;
            studentFile.seekg(1, ios::cur);
            studentFile>>myCourse.grade;
            studentFile.seekg(1, ios::cur);
            studentFile>>myCourse.year;
            studentFile.seekg(1, ios::cur);
            studentFile>>myCourse.semester;
            studentFile.seekg(1, ios::cur);
            getline(studentFile, myCourse.teacher);

            stud.myCourse.push_back(myCourse);
        }

        students.push_back(stud);
        refresh(students[i]);
    }

    courseFile.close();
    studentFile.close();
    cout<<endl<<"File successfully read!!"<<endl;
    return 0;
}

#endif
