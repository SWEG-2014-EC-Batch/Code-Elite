#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{   /* this program calculates bmi of a person, limited person and unlimited
     person after giving menu to the user and accepting users all information i.e.
     gender, weight and height*/
    int num_people,i,menu;
    float weight,height,BMI;
    char gender;
    cout<<"This is a BMI calculator.\nIf you want to calculate BMI for a single person Enter 1.\nIf you know for how many people you will calculate BMI Enter 2.\nIf you want the program to calculate BMI until you tell it to stop Enter 3.\nYour Input: ";
    cin>>menu;
    switch(menu){
        case 1:
            do{
                cout<<"\nYour gender? Enter F for female and M for male: ";
                cin>>gender;
                gender = toupper(gender);
                if(gender == 'M' || gender == 'F'){
                    break;
                }
                cout<<"You have entered an invalid gender."<<endl;
                }while(gender);
            cout<<"Enter weight(in Kg): ";
            cin>>weight;
            cout<<"Enter height(in meter): ";
            cin>>height;
            BMI=weight/(height*height);
            cout<<"BMI = "<<BMI<<endl;
            switch (gender){
                case 'F':
                if (BMI<18){
                    cout<<"You are Underweight.";
                }
                else if (BMI>23){
                    cout<<"You are Overweight.";}
                else{
                    cout<<"You have normal BMI.";
                }
                break;
                case 'M':
                if (BMI<20){
                    cout<<"You are Underweight.";
                }
                else if (BMI>25){
                    cout<<"You are Overweight.";}
                else{
                    cout<<"You have normal BMI.";
                }
                break;
                }
                break;
        case 2:
            cout<<"\nEnter the number of people: ";
            cin>>num_people;
            for(i=1;i<=num_people;i++){
                do{
                    cout<<"\nPerson "<<i<<"'s gender? Enter F for female and M for male: ";
                    cin>>gender;
                    gender = toupper(gender);
                    if(gender == 'M' || gender == 'F'){
                        break;
                    }
                    cout<<"You have entered an invalid gender."<<endl;
                    }while(gender);
                cout<<"Enter weight(in Kg): ";
                cin>>weight;
                cout<<"Enter height(in meter): ";
                cin>>height;
                BMI=weight/(height*height);
                cout<<"Person "<<i<<"'s BMI is: "<<BMI<<endl;
                switch (gender){
                    case 'F':
                    if (BMI<18){
                        cout<<"Person "<<i<<" is Underweight.";
                    }
                    else if (BMI>23){
                        cout<<"Person "<<i<<" is Overweight.";}
                    else{
                        cout<<"Person "<<i<<" have normal BMI.";
                    }
                    break;
                    case 'M':
                    if (BMI<20){
                        cout<<"Person "<<i<<" is Underweight.";
                    }
                    else if (BMI>25){
                        cout<<"Person "<<i<<" is Overweight.";}
                    else{
                        cout<<"Person "<<i<<" have normal BMI.";
                    }
                    break;
                    }
                }
            break;
        case 3:
            i = 1;
            while(i){
                do{
                    cout<<"\nPerson "<<i<<"'s gender? Enter F for female and M for male. Enter X to end the program: ";
                    cin>>gender;
                    gender = toupper(gender);
                    if(gender == 'M' || gender == 'F' || gender == 'X'){
                        break;
                    }
                    cout<<"You have entered an invalid gender."<<endl;
                    }while(gender);
                if(gender == 'X'){
                    break;
                }
                cout<<"Enter weight(in Kg): ";
                cin>>weight;
                cout<<"Enter height(in meter): ";
                cin>>height;
                BMI=weight/(height*height);
                cout<<"Person "<<i<<"'s BMI is: "<<BMI<<endl;
                switch (gender){
                    case 'F':
                    if (BMI<18){
                        cout<<"Person "<<i<<" is Underweight.";
                    }
                    else if (BMI>23){
                        cout<<"Person "<<i<<" is Overweight.";}
                    else{
                        cout<<"Person "<<i<<" have normal BMI.";
                    }
                    break;
                    case 'M':
                    if (BMI<20){
                        cout<<"Person "<<i<<" is Underweight.";
                    }
                    else if (BMI>25){
                        cout<<"Person "<<i<<" is Overweight.";}
                    else{
                        cout<<"Person "<<i<<" have normal BMI.";
                    }
                    break;
                    }
                i++;
            }
            break;
        default:
            cout<<"You Entered a wrong input";
    }
    cout<<"\nThank You for using this program";
    return 0;
}