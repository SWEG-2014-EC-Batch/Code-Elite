#include <iostream>
#include <ctype.h>
using namespace std;

void readTime(int&, int&);
void convert(int&, char&);
void display(int, int, char);

int main(){
    char repeat;
    do{
        int hours, minutes;
        char meridian = 'A';
        readTime(hours, minutes);
        if(hours < 0 || hours > 23 || minutes < 0 || minutes > 59){
            cout<<"Wrong input";
            return 0;
        }
        convert(hours, meridian);
        display(hours, minutes, meridian);

        cout<<"Do you want the program to repeat? reply 'Y' for yes and 'N' for no: ";
        cin>>repeat;
        repeat = toupper(repeat);
    }while(repeat == 'Y');
    
}
void readTime(int &hr, int &min){
    cout<<"Enter the time in 24 - hour notaion \nHours: ";
    cin>>hr;
    cout<<"Minutes: ";
    cin>>min;
}
void convert(int &hr, char &mer){
    if(hr >= 13){
        hr -= 12;
        mer = 'P';
    }
}
void display(int hr, int min, char mer){
    cout<<"The time in 12 - hour notation: "<<hr<<":"<<min<<" "<<mer<<"M"<<endl;
}
