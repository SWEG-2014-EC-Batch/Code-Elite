#include <iostream>
#include <math.h>
using namespace std;

double windchill(double, double);

int main(){
    double windSpeed, temperature;
    cout<<"Enter wind speed (in m/sec): ";
    cin>>windSpeed;
    int count = 0;
    do{
        cout<<"Enter temperature (in degree celcius). temperature must be less than 10: ";
        cin>>temperature;
        if(temperature > 10){
            count++;
        }   
        if(count == 3){
            return 0;
        }  
            
    }while(temperature > 10);

    cout<<"The windchill index is: "<<windchill(windSpeed, temperature);
}

double windchill(double v, double t){
    double windchillIndex;
    windchillIndex = 13.12 + 0.6215*t - 11.37*pow(v, 0.16) + 0.3965*t*pow(v, 0.016);
    return windchillIndex;
}