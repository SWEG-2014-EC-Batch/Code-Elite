/*Question 4
Write a program that find the result of the exepression x^Y where the value of X and Y are entered by the user.
*/
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x,y;
    cout<<"Enter the value of X(base): ";
    cin>>x;
    cout<<"Enter the value of Y(exponent): ";
    cin>>y;
    cout<<"X^Y = "<<pow(x,y);
    return 0;
}