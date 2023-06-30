#include <iostream>
using namespace std;
struct student
{
    string id , name;
    float testMark;
    float finalMark;
}student1;
int main()
{
    cout<<"Enter your name : ";
    cin>>student1.name;
    cout<<"Enter your id : ";
    cin>>student1.id;
    cout<<"Enter your test result : ";
    cin>>student1.testMark;
    cout<<"Enter your final result : ";
    cin>>student1.finalMark;
    cout<<"Total Mark : "<<student1.testMark + student1.finalMark;
    return 0;
}