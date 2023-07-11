#include <iostream>
#include <math.h>
using namespace std;

int main(){
    struct person {
        string name;
        char gender;
        int age;
        float weight;
        float height;
        float BMI;
    };
    person per;
    cout<<"Enter the person's name: ";
    cin>>per.name;
    cout<<"Enter the person's gender: ";
    cin>>per.gender;
    cout<<"Enter the person's age: ";
    cin>>per.age;
    cout<<"Enter the person's weight(in Kg): ";
    cin>>per.weight;
    cout<<"Enter the person's height(in meters): ";
    cin>>per.height;
    per.BMI = per.weight/pow(per.height, 2);
    cout<<per.name<<"'s BMI is: "<<per.BMI<<endl;
    if (per.gender=='m')
    {
         if (per.BMI<20)
        {
        cout<<"you are under weight"<<endl;
        }
        else if (per.BMI>=20 && per.BMI<=25)
        {
            cout<<"you have healthy weight"<<endl;
        }
        else {
            cout<<"you are over weight, do more excercise"<<endl;
        }
    }
    else if (per.gender=='f')
    {
        if (per.BMI<18)
        {
            cout<<"you are under weight"<<endl;
        }
        else if (per.BMI>=18 && per.BMI<=22)
        {
            cout<<"you have healthy weight"<<endl;
        }
        else {
            cout<<"you are over weight, do more excercise"<<endl;
        }      
              
    }    
}