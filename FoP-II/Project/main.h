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

#endif