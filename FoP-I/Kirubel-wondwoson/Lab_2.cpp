#include<iostream>
using namespace std;
int main()
#define PI 3.141159
{
    double r;
    double area;
    
    cout<<"Enter the radius of a circle:";
    cin>>r;

    area=PI*r*r;
    cout<< "The area of the circle is "<<area;
   
    return 0;
}