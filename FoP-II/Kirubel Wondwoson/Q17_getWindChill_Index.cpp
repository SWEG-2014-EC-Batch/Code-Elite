#include <iostream>
#include <math.h>
using namespace std;
double getWindChillIndex(double v, double t, double &w);
int main()
{
    int count = 0;
    double windSpeed, temp, w;
    cout << "Enter the wind speed in (m/s) : ";
    cin >> windSpeed;

    do
    {
        cout << "Enter the temperature in degree Celsius (temp < 10): ";
        cin >> temp;
        if (temp > 10)
        {
            cout << "You enterd above threshold ( 10 degree celsius)";
        }
        count++;
    } while (temp > 10 && count < 3);
    if(count == 3){
        return 0;
    }
    cout << "The windchill index is : " << getWindChillIndex(windSpeed, temp, w) << " degree celsius";
    return 0;
}
double getWindChillIndex(double v, double t, double &w)
{
    w = 13.12 + 0.6215 * t - 11.37 * pow(v, 0.16) + 0.3965 * t * pow(v, 0.016);
    return w;
}