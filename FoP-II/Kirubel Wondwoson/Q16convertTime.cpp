#include<iostream>
using namespace std;
void input(int &hour , int &min , char &sign , char &sign2){
    cout<<"\nEnter the time in 24 notation (use P for PM and A for AM (like 14:30 P)) : ";
    cin>>hour>>sign>>min>>sign2;
}
void convert(int &hour , int min , char sign , char&sign2){
    if(hour > 12 && hour <25){
        hour -= 12;
        if(hour > 1 && hour <6){
            sign2 = 'P';
        }
        else{
            sign2 = 'A';
        }
    }
}
void display(int &hour , int &min , char&emp , char&sign2){
    cout<<hour<<':'<<min<<sign2;
}
int main()
{
    int hour , min , check; char sign ,sign2;
    do{
        input(hour , min , sign , sign2);
        convert(hour , min , sign , sign2);
        display(hour , min , sign , sign2);
        cout<<"\nEnter 1 to continue any other number to quit : ";
        cin>>check;
    }while(check == 1);
    return 0;
}