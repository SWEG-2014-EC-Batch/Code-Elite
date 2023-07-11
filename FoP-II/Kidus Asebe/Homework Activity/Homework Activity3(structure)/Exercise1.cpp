#include <iostream>
using namespace std;

int main(){
    struct student {
        string id;
        string name;
        float testMark;
        float finalMark;
        float totalMark;
    };
    int num;
    cout<<"Enter number of students: ";
    cin>>num;
    student *stud1 = new student[num];
    for(int i = 0; i < num; ++i){
    cout<<"Enter the id of student "<<i+1<<": ";
    cin>>stud1[i].id;
    cout<<"Enter the students name: ";
    cin>>stud1[i].name;
    cout<<"Enter the students test mark: ";
    cin>>stud1[i].testMark;
    cout<<"Enter the sudents final mark: ";
    cin>>stud1[i].finalMark;

    stud1[i].totalMark = stud1[i].testMark + stud1[i].finalMark;
    }
    for(int i = 0; i < num; ++i){
        cout<<stud1[i].name<<"\'s final mark is: "<<stud1[i].totalMark<<endl;
    }


}