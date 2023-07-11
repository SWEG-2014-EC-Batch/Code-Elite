#include<iostream>
using namespace std;

int main()
{
    struct person
    {
        string name;
        char gender;
        int age;
        float weight,height,BMI;

    };
    
    person monster1;
    
    cout<<"enter your name: ";
    cin>>monster1.name;
    cout<<"enter your sex: ";
    cin>>monster1.gender;
    cout<<"enter your age: ";
    cin>>monster1.age;
    cout<<"enter your weight: ";
    cin>>monster1.weight;
    cout<<"enter your height: ";
    cin>>monster1.height;
    

    monster1.BMI=(monster1.weight/(monster1.height*monster1.height));
    cout<<"your BMI is: "<<monster1.BMI<<endl;
    if (monster1.gender=='m')
    {
         if (monster1.BMI<20)
        {
        cout<<"you are under weight"<<endl;
        }
        else if (monster1.BMI>=20 && monster1.BMI<=25)
        {
            cout<<"you have healthy weight"<<endl;
        }
        else {
            cout<<"you are over weight, do more excercise"<<endl;
        }
    }
    else if (monster1.gender=='f')
    {
        if (monster1.BMI<18)
        {
            cout<<"you are under weight"<<endl;
        }
        else if (monster1.BMI>=18 && monster1.BMI<=22)
        {
            cout<<"you have healthy weight"<<endl;
        }
        else {
            cout<<"you are over weight, do more excercise"<<endl;
        }      
              
    }
            
    return 0;
}