#include<iostream>
using namespace std;
void accept(double feet , double inch);
double convertFeet(double feet , double inch);
double convertInch(double feet , double inch);
void display( double feet , double inch , double meter , double centimeter);
int main()
{
    double f , i , m , cm;
    while(true){
        accept(f , i);
        if(f == 0 || i == 0){
            break;
        }
        else{
            m = convertFeet(f , i);
            cm = convertInch(f , i);
            display(i , f , m , cm);
        }
    }
    return 0;
}
void accept(double feet , double inch){
    cout<<"Enter a length in feet (enter 0 to quit) : ";
    cin>>feet;
    cout<<"Enter a length in inch (enter 0 to quit) : ";
    cin>>inch;
}
double convertFeet(double feet , double inch){
    double meter = feet*0.3048;
    return meter;
}
double convertInch(double feet , double inch){
    double centimeter = inch*25.4;
    return centimeter;
}
void display(double feet , double inch , double meter , double centimeter){
     meter = convertFeet(feet , inch);
     centimeter = convertInch(feet , inch);
    cout<<"The length in meter is "<<meter<<" m "<<endl;
    cout<<"The length in centimeter is "<<centimeter<<" cm "<<endl;
}