#include <iostream>
#include <math.h>
using namespace std;
void currentReader(double cur[], int size);
void calculatePower(double res[], double cur[], double pwr[], int);
void display(double*, double*, double*, int);
double calcTotal
int main(){
    double resistance[] = {16, 27, 39, 56, 81}, current[5], power[5];
    int num = 5;
    currentReader(current, num);
    calculatePower(resistance, current, power, num);
    display(resistance, current, power, num);
    return 0;
}

void currentReader(double cur[], int size){
    for(int i = 0; i < size; ++i){
        cout<<"Enter current "<<i+1<<": ";
        cin>>cur[i];
    }
}
void calculatePower(double res[], double cur[], double pwr[], int size){
    for(int i = 0; i < size; ++i){
        pwr[i] = res[i] * pow(cur[i], 2);
    }
}
void display(double res[], double cur[], double pwr[], int size){
    cout<<"\n_________________________________________________";
    cout<<"\n Resistance\t|\tCurrent\t|\tPower";
    cout<<"\n_________________________________________________";
    for(int i = 0 ; i < size ; i++){
        cout<<"\n|\t"<<res[i]<<"\t|\t"<<cur[i]<<"\t|\t"<<pwr[i]<<"\t|";
    }
}




