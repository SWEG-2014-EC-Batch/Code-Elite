#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    double exam1;
    double exam2;
    double homework;
    double finalExam;
    double finalGrade;
    char letterGrade;
};

void calculateFinalGrade(Student& student) {
    student.finalGrade = 0.20 * student.exam1 + 0.20 * student.exam2 + 0.35 * student.homework + 0.25 * student.finalExam;
}

void assignLetterGrade(Student& student) {
    if (student.finalGrade >= 90) {
        student.letterGrade = 'A';
    } else if (student.finalGrade >= 80) {
        student.letterGrade = 'B';
    } else if (student.finalGrade >= 70) {
        student.letterGrade = 'C';
    } else if (student.finalGrade >= 60) {
        student.letterGrade = 'D';
    } else {
        student.letterGrade = 'F';
    }
}

int main() {
    const int MAX_STUDENTS = 20;
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    while (numStudents < MAX_STUDENTS) {
        cout << "Enter information for student " << numStudents + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[numStudents].name;
        cout << "Exam 1: ";
        cin >> students[numStudents].exam1;
        cout << "Exam 2: ";
        cin >> students[numStudents].exam2;
        cout << "Homework: ";
        cin >> students[numStudents].homework;
        cout << "Final Exam: ";
        cin >> students[numStudents].finalExam;

        calculateFinalGrade(students[numStudents]);
        assignLetterGrade(students[numStudents]);

        numStudents++;

        char choice;
        cout << "Do you want to enter information for another student? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    ofstream outFile("grades.txt");
    outFile << left << setw(20) << "Name" << setw(10) << "Exam 1" << setw(10) << "Exam 2" << setw(10) << "Homework" << setw(12) << "Final Exam" << setw(15) << "Final Grade" << setw(12) << "Letter Grade" << endl;

    for (int i = 0; i < numStudents; i++) {
        outFile << left << setw(20) << students[i].name
                << setw(10) << students[i].exam1
                << setw(10) << students[i].exam2
                << setw(10) << students[i].homework
                << setw(12) << students[i].finalExam
                << setw(15) << fixed << setprecision(2) << students[i].finalGrade
                << setw(12) << students[i].letterGrade
                << endl;

        cout << left << setw(20) << students[i].name
             << setw(10) << students[i].exam1
             << setw(10) << students[i].exam2
             << setw(10) << students[i].homework
             << setw(12) << students[i].finalExam
             << setw(15) << fixed<< setprecision(2)<<students[i].finalGrade
             <<" "<<students[i].letterGrade<<endl;
    }

    outFile.close();

    return 0;
}
