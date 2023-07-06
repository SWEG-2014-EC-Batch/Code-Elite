#include <iostream>
#include <math.h>
using namespace std;

double windchillFactor(double temperature, double windSpeed);
void output(double temperature, double windSpeed);

int main(){
    output(5, 50);
    output(0, 30);
    output(-5, 20);
    output(10, 0);
    // output(11, 20);  //temperature is greater than 10
    // output(5, -50);  //wind speed is negative
    return 0;
}

double windchillFactor(double temperature, double windSpeed){
    assert(windSpeed>=0 && temperature<=10);
    double windchillIndex;
    if(temperature<=10){
        windchillIndex = 13.12 + pow(0.6215, temperature) + 11.37*pow(windSpeed, 0.16) + 0.3965*temperature*pow(windSpeed, 0.016);
    }
    return windchillIndex;
}

void output(double temperature, double windSpeed){
    cout<<"\nThe windchill factor at "<<temperature<<" degree celcius and wind speed of "<<windSpeed<<"m/s is "<<windchillFactor(temperature, windSpeed);
}
