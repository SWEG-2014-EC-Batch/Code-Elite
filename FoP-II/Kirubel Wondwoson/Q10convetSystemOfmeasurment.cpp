#include<iostream>
#include<math.h>
using namespace std;
void acceptImperial(double &feet , double &inch);
void acceptMetric(double &meter , double &centimeter);
void convertToMetric(double feet , double inch , double *meter , double *centimeter);
void convertToImperial(double meter , double centimeter , double *feet , double *inch );
void display(double meter , double centimeter , double feet , double inch , int menu);
int main()
{
    int menu , check;
    double  i , f , m , cm;
    do{
        cout<<"\nENTER 1 FOR FEET AND INCH TO MERER AND CENTIMETER CONVERTION AND 2 FOR THR REVERSE : ";
        cin>>menu;
        switch(menu){
            case 1:
            acceptImperial(i , f);
            convertToMetric(i , f , &m ,&cm);
            display(i , f , m ,  cm , menu);
            break;
            case 2:
            acceptMetric(i , f );
            convertToImperial(i , f , &m , &cm);
            display(i ,f , m , cm , menu);
            break;
            default:
            cout<<"You enterd invalid number."<<endl;
            break;
        }
        cout<<"Enter 1 to continue any other number to stop : ";
        cin>>check;
    }while(check == 1);
    return 0;
}
void acceptImperial(double &feet , double &inch){
        cout<<"Enter a length in feet : ";
        cin>>feet;
        cout<<"Enter a length in inch : ";
        cin>>inch;
}
void acceptMetric(double &meter , double &centimeter){
        cout<<"Enter a length in meter : ";
        cin>>meter;
        cout<<"Enter a length in centimeter : ";
        cin>>centimeter;
}

void convertToMetric(double feet , double inch , double *meter , double *centimeter){
    *meter = (((feet * 12) + inch)*2.54/100);
    *centimeter = fmod((((feet * 12) + inch)*2.54) , 100);
}
void convertToImperial(double meter , double centimeter , double *feet , double *inch){
    *feet = ((meter * 100) + centimeter)/2.54*12;
    *inch = fmod(((meter * 100) + centimeter)/2.54 , 12);
}
void display(double feet , double inch , double meter , double centimetrer , int menu){
    if(menu == 1){
        cout<<"The Length in meter is : "<<meter<<" m"<<endl;
        cout<<"The Length in centimeter is : "<<centimetrer<<" cm"<<endl;
    }
    if(menu == 2){
        cout<<"The Length in feet is : "<<feet<<" feet"<<endl;
        cout<<"The Length in inch is : "<<inch<<" inch"<<endl;
    }
}
