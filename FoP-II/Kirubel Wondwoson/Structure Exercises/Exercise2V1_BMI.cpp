#include <iostream>
#include <ctype.h>
#include <math.h>
using namespace std;
struct person
{
    string name;
    char gender;
    int age;
    float weight, height;
} people[100];
int main()
{
    float BMI;
    int max;
    cout << "Enter number of persons : ";
    cin >> max;
    for (int i = 0; i < max; i++)
    {
        cout << endl;
        cout << "Enter your name(use 4 character): ";
        cin >> people[i].name;
        cout << "Enter your gender(M for male F for female) : ";
        cin >> people[i].gender;
        cout << "Enter your age : ";
        cin >> people[i].age;
        cout << "Enter your weight : ";
        cin >> people[i].weight;
        cout << "Enter your height : ";
        cin >> people[i].height;
        people[i].gender = toupper(people[i].gender);
    }
    cout << "Name        Age      Gender      BMI          Status" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << people[i].name << "        " << people[i].age << "       " << people[i].gender << "          " << BMI;
        people[i].gender = toupper(people[i].gender);
        BMI = people[i].weight / pow(people[i].height, 2);
        if (people[i].gender == 'M')
        {
            if (BMI < 20)
            {
                cout << "       under weight";
            }
            else if (BMI > 25)
            {
                cout << "       over weight";
            }
            else
            {
                cout << "       Normal weight";
            }
        }
        else if (people[i].gender == 'F')
        {
            if (BMI < 18)
            {
                cout << "       under weight";
            }
            else if (BMI > 23)
            {
                cout << "       over weight";
            }
            else
            {
                cout << "       Normal weight";
            }
        }
        cout << endl;
    }
    return 0;
}