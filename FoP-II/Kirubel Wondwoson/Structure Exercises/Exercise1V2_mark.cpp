#include <iostream>
using namespace std;
struct student
{
    string id, name;
    float testMark;
    float finalMark;
} students[100];
int main()
{
    int max;
    cout << "Enter the maximum number of students : ";
    cin >> max;
    for (int i = 0; i < max; i++)
    {
        cout<<endl;
        cout << "Enter your name : ";
        cin >> students[i].name;
        cout << "Enter your id : ";
        cin >> students[i].id;
        cout << "Enter your test result : ";
        cin >> students[i].testMark;
        cout << "Enter your final result : ";
        cin >> students[i].finalMark;
        cout << "Total Mark : " << students[i].testMark + students[i].finalMark;
    }

    return 0;
}