#include <iostream>
#include <math.h>
using namespace std;
struct complexNumber
{
              //(eg.) 3 + 5i
    float r;   // real part = 3
    float i1;  //imaginary part(number) = +5 
    char i2;   //imaginary part(charater) = i
} c1, c2, add, substruct, multiply, divide;
// c1 represents the first complex number 
// c2 represents the second complex number
void calComplex(complexNumber c1, complexNumber c2)
{
    // Add
    add.r = c1.r + c2.r;
    add.i1 = c1.i1 + c2.i1;
    // Subtract
    substruct.r = c1.r - c2.r;
    substruct.i1 = c1.i1 - c2.i1;
    // Multiply
    multiply.r = c1.r * c2.r - c1.i1 * c2.i1;
    multiply.i1 = c1.r * c2.i1 + c2.r * c1.i1;
    // Division
    divide.r = (c1.r * c2.r + c1.i1 * c2.i2) / (pow(c2.r, 2) - pow(c2.i1, 2)); //.....not sure
    divide.i1 = (c2.r * c1.i1 - c1.r * c2.i1) / (pow(c2.r, 2) - pow(c2.i1, 2));//.....not sure
        // DISPLAY
    if (add.i1 >= 0 || substruct.i1 >= 0 || multiply.i1 >= 0 || divide.i1 >= 0)
    {
        cout << add.r;
        if (add.i1 >= 0)
        {
            cout << " + " << add.i1 << c2.i2;
        }
        else
        {
            cout << add.i1 << c2.i2;
        }
        cout << endl;
        cout << substruct.r;
        if (substruct.i1 >= 0)
        {
            cout << " + " << substruct.i1 << c2.i2;
        }
        else
        {
            cout << substruct.i1 << c2.i2;
        }
        cout << endl;
        cout << multiply.r;
        if (multiply.i1 >= 0)
        {
            cout << " + " << multiply.i1 << c2.i2;
        }
        else
        {
            cout << multiply.i1 << c2.i2;
        }
        cout << endl;
        cout << divide.r;
        if (divide.i1 >= 0)
        {
            cout << " + " << divide.i1 << c2.i2;
        }
        else
        {
            cout << divide.i1 << c2.i2;
        }
    }
}
int main()
{
    cout << "Enter the first complex number : ";
    cin >> c1.r >> c1.i1 >> c1.i2;
    cout << "Enter the second complex number : ";
    cin >> c2.r >> c2.i1 >> c2.i2;
    calComplex(c1, c2);
    return 0;
}