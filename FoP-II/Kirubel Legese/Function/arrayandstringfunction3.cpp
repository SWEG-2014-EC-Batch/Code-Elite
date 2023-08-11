#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void currentarray(double current[5]);
void powercalculation(double current[5], double resistance[5], double power[5]);
void display(double current[5], double power[5], double resistance[5]);
int main()
{
    double resistance[5];
    double current[5];
    double power[5];
    for (int i = 0;i < 5;i++)
    {
        cout << "enter resistance: ";
        cin >> resistance[i];
    }
    currentarray(current);
    powercalculation(current, resistance, power);
    display(current, power, resistance);
    return 0;
}
void currentarray(double current[5])
{
       
        for (int i = 0;i < 5;i++)
        {
            cout << "enter the current: ";
            cin >> current[i];
        }
 }
void powercalculation(double current[5],double resistance [5], double power[5])
{
    
    for (int i = 0;i < 5;i++)
    {
        power[i] = resistance[i] * pow(current[i], 2);
    }
}
void display(double current[5],double power[5],double resistance[5])
{
    cout << "resistance " << setw(7) << "current " << setw(7) << "power " << endl;
    for (int i = 0;i < 5;i++)
    {
        cout << resistance[i] << setw(7) << current[i] << setw(7) << power[i] << endl;
    }

}

