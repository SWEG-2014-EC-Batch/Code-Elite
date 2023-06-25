#include<iostream>
using namespace std;

int main()
{
    int resistance[5];
    double power[5];
    double current[5];
    
    for (int i = 0; i < 5; i++)
    {
       cout<<"enter a resistance ";
       cin>> resistance;
    }
    currentcal(current);
    powercal(current,power ,resistance);
    

    return 0;
}

void currentcal(double num1, double num2, double num3, double num4, double num5)
{
   
    for (int i = 0; i < 5; i++)
    {
        cout<<"enter a current";
        cin>> current;
    }
void powercal(double current[5],int resistance[5])
{
    
    for (int i = 0; i < 5; i++)
    {
        power[i]=resistance[i]* pow(current[i],2);
    }
void display(double current[5],double power[5],int resistance[5]);
    





}
    
    




}