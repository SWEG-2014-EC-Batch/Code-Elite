#include<iostream>
#include<cmath>
using namespace std;
double windchill(double windspeed, int temp);
int main()
{
    double windspeed1;
    int temp1;
    cout << "enter the recorded windspeed: ";
    cin >> windspeed1;
    cout << "enter the recorded temprature: ";
    cin >> temp1;
    cout << "The windchill index is: "<<windchill(windspeed1, temp1);
    return 0;
}
double windchill(double windspeed, int temp)
{
    double windchillindex1, windspeed2, temp2, windspeed3;
    if (temp < 10)
    {
        temp2 = 0.6215 * temp;
        windspeed2 = 11.37 * pow(windspeed, 0.16);
        windspeed3 = 0.3965 * temp * pow(windspeed, 0.16);
        windchillindex1 = 13.12 + temp2 - windspeed2 + windspeed3;
        return  windchillindex1;
    }
    else
    {
        cout << " errror, the temprature must be less than 10" << endl;
    }
}

