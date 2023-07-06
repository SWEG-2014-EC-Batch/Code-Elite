#include <iostream>
#include <ctype.h>
using namespace std;

struct Person{
    bool error;
    string name;
    char gender;
    int age;
    float weight, height, bmi;
};

void input(Person* a, int n);
void display(Person* a, int n);

int main(){
    int n;
    cout<<"Enter the number of people(max 100): ";
    cin>>n;
    Person *person = new Person[n];
    input(person, n);
    display(person, n);
    return 0;
}

void input(Person* a, int n){
    for(int i=0; i<n; ++i){
        cout<<"\nEnter person "<<i+1<<"\'s name: ";
        cin>>a[i].name;
        cout<<"Enter person "<<i+1<<"\'s gender. F for female and M for male: ";
        cin>>a[i].gender;
        a[i].gender = toupper(a[i].gender);
        cout<<"Enter person "<<i+1<<"\'s age: ";
        cin>>a[i].age;
        cout<<"Enter person "<<i+1<<"\'s weight: ";
        cin>>a[i].weight;
        cout<<"Enter person "<<i+1<<"\'s height: ";
        cin>>a[i].height;
        if((a[i].gender != 'M' && a[i].gender != 'F') || a[i].weight<=0 || a[i].height<=0 || a[i].age<=0){
            cout<<"Wrong input for person "<<i+1<<endl;
            a[i].error = true;
            continue;
        }
        a[i].bmi = a[i].weight / (a[i].height * a[i].height);
    }
}

void display(Person* a, int n){
    cout<<"\n_______________________________________________________________________________________________________________";
    cout<<"\n|No     |Name\t|   Gender      |      Age      |   Weight      |     Height    |       BMI     |  Remark";
    cout<<"\n---------------------------------------------------------------------------------------------------------------";
    for(int i=0; i<n; ++i){
        if(a[i].error){
            continue;
        }
        cout<<"\n|"<<i+1<<"\t|"<<a[i].name<<"\t|\t"<<a[i].gender<<"\t|\t"<<a[i].age<<"\t|\t"<<a[i].weight<<"\t|\t"<<a[i].height<<"\t|\t"<<a[i].bmi<<"\t|  ";
        if(a[i].gender == 'F'){
            if(a[i].bmi < 18){
                cout<<"Underweight";
            }
            else if(a[i].bmi <= 23){
                cout<<"Normal";
            }
            else{
                cout<<"Overweight";
            }
        }
        else if(a[i].gender == 'M'){
            if(a[i].bmi < 20){
                cout<<"Underweight";
            }
            else if(a[i].bmi <= 25){
                cout<<"Normal";
            }
            else{
                cout<<"Overweight";
            }
        }
    }
    cout<<"\n---------------------------------------------------------------------------------------------------------------";
}
