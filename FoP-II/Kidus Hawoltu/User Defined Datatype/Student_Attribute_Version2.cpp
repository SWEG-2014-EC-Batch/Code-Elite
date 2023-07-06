#include <iostream>
using namespace std;
struct Student{
    char id[11];
    string name;
    float testMark, finalMark, mark;
};

void input(Student a[], int n);
void display(Student a[], int n);

int main(){
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    Student *student = new Student[n];
    input(student, n);
    display(student, n);
    return 0;
}

void input(Student a[], int n){
    for(int i=0; i<n; ++i){
        cout<<"Enter student "<<i+1<<"\'s id: ";
        cin>>a[i].id;
        cout<<"Enter student "<<i+1<<"\'s name: ";
        cin>>a[i].name;
        cout<<"Enter student "<<i+1<<"\'s test result(out of 30): ";
        cin>>a[i].testMark;
        cout<<"Enter student "<<i+1<<"\'s final result(out of 70): ";
        cin>>a[i].finalMark;
        a[i].mark = a[i].testMark + a[i].finalMark;
    }
}

void display(Student a[], int n){
    for(int i=0; i<n; ++i){
        cout<<a[i].id<<'\t'<<a[i].name<<'\t'<<a[i].mark<<endl;
    }
}
