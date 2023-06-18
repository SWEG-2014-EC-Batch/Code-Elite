#include <iostream>
#include <ctype.h>
using namespace std;

void readLength(float&, float&, int);
void convert(float&, float&, float&, float&, int);
void display(float, float, int);

int main(){
    char repeat;
    do{
        float feet, inches, meters, centimeters;
        int choice;
        cout<<"Enter 1 to convert length from (feet and inches) to (meters and centimeters) \n or 2 to convert from (meters and centimeters) to (feet and inches): ";
        cin>>choice;
        switch(choice){
            case 1:
                readLength(feet, inches, choice);
                convert(feet, inches, meters, centimeters, choice);
                display(meters, centimeters, choice);
                break;
            case 2:
                readLength(meters, centimeters, choice);
                convert(feet, inches, meters, centimeters, choice);
                display(feet, inches, choice);
                break;
            default:
                break;        
        }
        
        cout<<"Do you want the program to repeat? reply 'Y' for yes and 'N' for no: ";
        cin>>repeat;
        repeat = toupper(repeat);
    }while(repeat == 'Y');
}
void readLength(float& length, float& subLength, int num){
    if(num == 1){
        cout<<"Enter length"<<endl<<"Feet: ";
        cin>>length;
        cout<<"Inches: ";
        cin>>subLength;
    }
    else{
        cout<<"Enter length"<<endl<<"Meters: ";
        cin>>length;
        cout<<"Centimeters: ";
        cin>>subLength;
    }   
}
void convert(float& ft, float& inc, float& met, float& cent, int num){
    if(num == 1){
        int temp;
        met =  ft*0.3048 + inc*0.3048/12;
        temp = met;
        cent = (met - temp)*100;
        met = temp;
    }
    else{
        int temp;
        ft = met/0.3048 + cent/100/0.3048;
        temp = ft;
        inc = (ft - temp)*12;
        ft = temp;
    }
}
void display(float length, float subLength, int num){
    if(num == 1) cout<<"Converted value"<<endl<<"Meters: "<<length<<endl<<"Centimeters: "<<subLength<<endl;
    else cout<<"Converted value"<<endl<<"Feet: "<<length<<endl<<"Inches: "<<subLength<<endl;
}
