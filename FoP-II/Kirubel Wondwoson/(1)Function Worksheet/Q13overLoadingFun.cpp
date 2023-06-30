#include <iostream>
using namespace std;
double findMax(double n1, double n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}
double findMax(double n1, double n2, double n3)
{
    if (n1 > n2 && n1 > n3)
    {
        return n1;
    }
    else if (n2 > n1 && n2 > n3)
    {
        return n2;
    }
    else
    {
        return n3;
    }
}
int main()
{
    double num1, num2, num3;
    cout << "Enter 2 numbers : ";
    cin >> num1 >> num2;
    cout << "The maximum is : " << findMax(num1, num2) << endl;
    cout << "Enter 3 numbers : ";
    cin >> num1 >> num2 >> num3;
    cout << "The maximum is : " << findMax(num1, num2, num3) << endl;
}