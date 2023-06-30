#include <iostream>
#include <ctype.h>
#include <math.h>
using namespace std;
// structure declaration
struct person
{
    string name;
    char gender;
    int age;
    float weight, height;
};
// structure definition
person people1[100];
// function prototype with structure parameter
void getData(person[] , int);
void display(person[] , int);
int main()
{
    int numperson;
    cout<<"Enter the number of students : ";
    cin>>numperson;
    getData(people1 , numperson);
    display(people1 , numperson);
    return 0;
}
void getData(person people2[] , int numperson)
{ 
    for (int i = 0; i < numperson; i++)
    {
        cout << endl;
        cout << "Enter your name(use 4 character): ";
        cin >> people2[i].name;
        cout << "Enter your gender(M for male F for female) : ";
        cin >> people2[i].gender;
        cout << "Enter your age : ";
        cin >> people2[i].age;
        cout << "Enter your weight : ";
        cin >> people2[i].weight;
        cout << "Enter your height : ";
        cin >> people2[i].height;
    }
}
void display(person people2[] , int numperson)
{
    float BMI;
    cout << "Name        Age      Gender      BMI              Status" << endl;
    for (int i = 0; i < numperson; i++)
    {
        people2[i].gender = toupper(people2[i].gender);
        BMI = people2[i].weight / pow(people2[i].height, 2);
        cout << people2[i].name << "        " << people2[i].age << "       " << people2[i].gender << "           "<<BMI<<"          ";
        if (people2[i].gender == 'M')
        {
            if(BMI < 20){
                cout<<"under weight";
            }
            else if (BMI > 25){
                cout<<"Over weight";
            }
            else {
                cout<<"Normal wight";
            }
        }
        else if(people2[i].gender == 'F')
        {
            if(BMI < 18){
                cout<<"under weight";
            }
            else if (BMI > 23){
                cout<<"Over weight";
            }
            else {
                cout<<"Normal wight";
            }
        }
        cout<<endl;
    }
}