#include<iostream>
#include<math.h>
#include<ctype.h>
using namespace std;
int main(){
    int weight,height,menu,no_of_person,n;
    float BMI;
    char gender;
    string X;
    cout<<"Enter 1 if you want the BMI calculator for a single person.\nEnter 2 if you want the BMI calculator for a limited person.\nEnter 3 if you want the BMI calculator for unlimmited number of Person until you want to stop.";
    cin>>menu;
switch (menu)
{
case 1:cout<<"Enter your gender? M for male and F for female: ";
       cin>>gender;
       gender=toupper(gender);
     if(gender=='M'){
             cout<<"\nEnter your weight in kg: ";
             cin>>weight;
             cout<<"\nEnter your height in meter: ";
             cin>>height;
            BMI=weight/pow(height,2);
          if(BMI<20){
             cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
          }  
          else if(BMI>25){
             cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
          } 
          else{
            cout<<"Your BMI is "<<BMI<<"\nYou are Normal.";} 
    }
    else if(gender=='F'){
             cout<<"\nEnter your weight in kg: ";
             cin>>weight;
             cout<<"\nEnter your height in meter: ";
             cin>>height; 
           BMI=weight/pow(height,2);
        if(BMI<18){
           cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
        }
        else if(BMI>23){
            cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
        }
        else{cout<<"Your BMI is "<<BMI<<"\nYou are Normal.";}  
    }
    else{cout<<"Invalid input";}
break;
case 2: cout<<"For how many person do you want this BMI Calculater: ";
        cin>>no_of_person;
         n=1;
         while(n<=no_of_person){
            cout<<"\nEnter your gender? M for male and F for female: ";
            cin>>gender;
             gender=toupper(gender); 
            if(gender=='M'){
                cout<<"\nEnter Your weight in kg: ";
                cin>>weight;
                cout<<"\nEnter Your height in meter: ";
                cin>>height;
                  BMI=weight/pow(height,2);
                if(BMI<20){
                    cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
                }
                else if(BMI>25){
                    cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
                   }
                else{cout<<"Your BMI is "<<BMI<<"\nYou are Normal.keep it up!";}
           }
           else if(gender=='F'){
                cout<<"\nEnter your weight in kg: ";
                cin>>weight;
                cout<<"\nEnter your height in meter: ";
                cin>>height; 
                  BMI=weight/pow(height,2);
                if(BMI<18){
                   cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
                }   
                else if(BMI>23){
                   cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
                }        
                else{cout<<"Your BMI is "<<BMI<<"\nYou are Normal.";}
           }
           else{cout<<"Invalid input";}
           n++; 
        } 
        break; 
case 3: while(X!="STOP"){
            cout<<"\nTo continue press any key or To stop enter STOP: ";
            cin>>X; 
            if(X=="STOP"){
            break;}
            cout<<"\nEnter your gender? M for male and F for female: ";
            cin>>gender;
             gender=toupper(gender);
            if(gender=='M'){
                cout<<"Enter Your weight in kg: ";
                cin>>weight;
                cout<<"Enter Your height in meter: ";
                cin>>height;
                  BMI=weight/pow(height,2);
                if(BMI<20){
                    cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
                }
                else if(BMI>25){
                    cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
                   }
                else{cout<<"Your BMI is "<<BMI<<"\nYou are Normal.keep it up!";}
           }
           else if(gender=='F'){
                cout<<"\nEnter your weight in kg: ";
                cin>>weight;
                cout<<"\nEnter your height in meter: ";
                cin>>height; 
                  BMI=weight/pow(height,2);
                if(BMI<18){
                   cout<<"Your BMI is "<<BMI<<"\nYour are under weight,so you need some kind of treatment.";
                }   
                else if(BMI>23){
                   cout<<"Your BMI is "<<BMI<<"\nYou are over weight,so you need exercise.";
                }        
                else{cout<<"Your BMI is "<<BMI<<"\nYou are Normal.";}
           }
           else{cout<<"Invalid input";}
         }   
         break;    
 default:
        {cout<<"Invalid input";}
        break;
      }
}







