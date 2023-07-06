#include <iostream>
#include <ctype.h>
using namespace std;

void input(double &a, double &b, int c);  //accepts feet and inch or meter and centimeter based on value of c

double ft_to_m(double ft, double in);  //changes the feet and inch to meter
double m_to_ft(double m, double cm);  //changes the meter and centimeter to feet

void m_cm(double &m, double &cm);  //makes sure that meter is an integer and centimeter is not greater than 100
void ft_in(double &ft, double &in);  //makes sute that feet is an integer and inch is not greater than 12

void output(double a, double b, int c);  //displays the results based on the inputs

int main(){
    double num1=0, num2=0;
    int menu;
    char menu2='Y';
    while(menu2=='Y'){
        cout<<"\nEnter 1 to convert length in feet and inches to meter and centimeter\nEnter 2 to convert length in meter and centimeter to feet and inches\nYour choice: ";
        cin>>menu;
        input(num1, num2, menu);
        output(num1, num2, menu);
        cout<<"\nEnter Y to repeat and any other character to end the program: ";
        cin>>menu2;
        menu2 = toupper(menu2);
    }
    return 0;
}

void input(double &a, double &b, int c){
    if(c==1){
        cout<<"\nEnter the feet: ";
        cin>>a;
        cout<<"Enter the inch: ";
        cin>>b;
    }
    else if(c==2){
        cout<<"\nEnter the meter: ";
        cin>>a;
        cout<<"Enter the centimeter: ";
        cin>>b;
    }
}

double ft_to_m(double ft, double in){
    return (ft+(in/12))*0.3048; 
}

void m_cm(double &m, double &cm){
    cm += 100*(m - int(m));
    m = int(m);
    m += int(cm/100);
    cm = 100*((cm/100) - int(cm/100));
    
}

double m_to_ft(double m, double cm){
    return (m+(cm/100))/0.3048;
}

void ft_in(double &ft, double &in){
    in += 12*(ft - int(ft));
    ft = int(ft);
    ft += int(in/12);
    in = 12*(in/12 - int(in/12));
}

void output(double a, double b, int c){
    double new_a, new_b;
    
    if(c==1){
        ft_in(a, b);
        new_a = ft_to_m(a, b);
        new_b = 0;
        m_cm(new_a, new_b);
        cout<<'\n'<<a<<"ft and "<<b<<" inches is the same as "<<new_a<<"m and "<<new_b<<"cm.\n";
    }
    else if(c==2){
        m_cm(a, b);
        new_a = m_to_ft(a, b);
        new_b = 0;
        ft_in(new_a, new_b);
        cout<<'\n'<<a<<"m and "<<b<<"cm is the same as "<<new_a<<"ft and "<<new_b<<" inches.\n";
    }
    else{
        cout<<" Wrong choice!!!\n";
    }
}
