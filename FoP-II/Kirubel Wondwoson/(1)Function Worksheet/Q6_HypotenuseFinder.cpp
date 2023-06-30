#include<iostream>
#include<cmath>
using namespace std;
double findHyp(double  , double );
int main()
{
    double Side1 = 3.0 , side2 = 4.0;
    cout<<"Triangle 1 hypothenes : "<<findHyp(Side1 , side2)<<endl;
    Side1 = 5.0 , side2 = 12.0;
    cout<<"Triangle 2 hypothenes : "<<findHyp(Side1 , side2)<<endl;
    Side1 = 8.0 , side2 = 15.0;
    cout<<"Triangle 3 hypothenes : "<<findHyp(Side1 , side2);
    return 0;
}
double findHyp(double Side1 , double side2){
    double hypothenus = hypot(Side1 , side2); // or  hypothenus = sqrt(pow(Side1 , 2) + pow(side2 , 2));
    return hypothenus;
}