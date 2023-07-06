#include <iostream>
#include <math.h>
using namespace std;
void inputCurrent(double current[], int size);
void calculatePower(double resistance[], double current[], double power[], int size);
double calculateTotal(double array[], int size);  //returns the sum of array elements
void display(double resistance[], double current[], double power[], int size);

int main(){
    double resistance[] = {16, 27, 39, 56, 81}, current[5], power[5];
    inputCurrent(current, 5);
    calculatePower(resistance, current, power, 5);
    display(resistance, current, power, 5);
    return 0;
}

void inputCurrent(double current[], int size){
    for(int i=0; i<size; ++i){
        cout<<"Enter current "<<i+1<<": ";
        cin>>current[i];
    }
}

void calculatePower(double resistance[], double current[], double power[], int size){
    for(int i=0; i<size; ++i){
        power[i] = resistance[i] * pow(current[i], 2);
    }
}

double calculateTotal(double array[], int size){
    double sum=0;
    for(int i=0; i<size; ++i){
        sum += array[i];
    }
    return sum;
}

void display(double resistance[], double current[], double power[], int size){
    cout<<"\n_________________________________________";
    cout<<"\n| No. | Resistance |  Current |  Power";
    cout<<"\n|     |   (Ohm)    | (Ampere) |  (Watt)";
    cout<<"\n|-----------------------------------------";
    for(int i=0; i<size; ++i){
        cout<<"\n|  "<<i+1<<"  |     "<<resistance[i]<<"     |\t"<<current[i]<<"\t|  "<<power[i];
    }
    cout<<"\n|Total|    "<<calculateTotal(resistance, 5)<<"     |\t"<<calculateTotal(current, 5)<<"\t|  "<<calculateTotal(power, 5);
    cout<<"\n-----------------------------------------";
}
