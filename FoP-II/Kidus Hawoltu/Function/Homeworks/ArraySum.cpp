#include <iostream>
using namespace std;
double arraySum(double array[], int size);

int main(){
    double array[] = {12, 23, 13, 87};
    cout<<arraySum(array, 4);
    return 0;
}

double arraySum(double array[], int size){
    if(size == 1){
        return array[0];
    }
    else{
        return array[size-1] + arraySum(array, size-1);
    }
}
