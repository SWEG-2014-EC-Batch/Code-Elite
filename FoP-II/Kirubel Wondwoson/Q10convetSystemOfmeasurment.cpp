#include<iostream>
#include<math.h>
using namespace std;
void accept(double &feet , double &inch , double &meter , double &centimeter , int menu);
//or
// void acceptImperial(double &feet , double &inch);
// void acceptMetric(double &meter , double &centimeter);
void convert(double *feet , double *inch , double *meter , double *centimeter , int menu);
//or
// void convertToMetric(double feet , double inch , double *meter , double *centimeter);
// void convertToImperial(double meter , double centimeter , double *feet , double *inch );
void display(double meter , double centimeter , double feet , double inch , int menu);
int main()
{
    int menu , check;
    double  i , f , m , cm;
    do{
        cout<<"\nEnter 1 For Feet And Inch To Meter And Centimeter Converstion And 2 For The Reverse : ";
        cin>>menu;
        switch(menu){
            case 1:
            accept( f ,  i ,  m , cm  ,  menu);
            //or
            //acceptImperial(i , f);
            // convertToMetric(i , f , &m ,&cm);
            convert(&i , &f , &m ,&cm ,menu );
            display(i , f , m ,  cm , menu);
            break;
            case 2:
            accept( f ,  i ,  m , cm  ,  menu);
            //or
            //acceptMetric(i , f );
            // convertToImperial(i , f , &m , &cm);
            convert(&i , &f , &m ,&cm ,menu );
            display(i ,f , m , cm , menu);
            break;
            default:
            cout<<"You enterd invalid number."<<endl;
            break;
        }
        cout<<"Do you want the program to continue?Enter '1' to continue '0' to quit : ";
        cin>>check;
    }while(check == 1);
    return 0;
}
void accept(double &feet , double &inch , double &meter , double &centimeter , int menu)
{
     if(menu == 1){
        cout<<"Enter a length in feet : ";
        cin>>feet;
        cout<<"Enter a length in inch : ";
        cin>>inch;
     }
     if(menu == 2){
        cout<<"Enter a length in meter : ";
        cin>>meter;
        cout<<"Enter a length in centimeter : ";
        cin>>centimeter;
     }
}
//or
// void acceptImperial(double &feet , double &inch){
//         cout<<"Enter a length in feet : ";
//         cin>>feet;
//         cout<<"Enter a length in inch : ";
//         cin>>inch;
// }
// void acceptMetric(double &meter , double &centimeter){
//         cout<<"Enter a length in meter : ";
//         cin>>meter;
//         cout<<"Enter a length in centimeter : ";
//         cin>>centimeter;
//}
void convert(double *feet , double *inch , double *meter , double *centimeter , int menu){
    if(menu == 1){
        *meter = (((*feet * 12) + *inch)*2.54/100);
        *centimeter = fmod((((*feet * 12) + *inch)*2.54) , 100);
    }
    if(menu == 2){
        *feet = ((*meter / 0.3048) + *centimeter/100/0.3048); 
        *inch = fmod(((*meter * 100) + *centimeter)/2.54 , 12);  
    }
}
//or
// void convertToMetric(double feet , double inch , double *meter , double *centimeter){
//     *meter = (((feet * 12) + inch)*2.54/100);
//     *centimeter = fmod((((feet * 12) + inch)*2.54) , 100);
// }
// void convertToImperial(double meter , double centimeter , double *feet , double *inch){
//    *feet = ((*meter / 0.3048) + *centimeter/100/0.3048); 
//    *inch = fmod(((*meter * 100) + *centimeter)/2.54 , 12);
// }
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
