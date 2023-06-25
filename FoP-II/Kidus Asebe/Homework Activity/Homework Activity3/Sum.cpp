#include <iostream>
using namespace std;

int sumCalculator(int [], int size);

int main(){
    int myArray[] = {1, 2, 4, 6, 4};
    cout<<"The sum is: "<<sumCalculator(myArray, 5);
}
int sumCalculator(int arr[], int size){
    if(size == 0){
        return arr[0];
    }
    else{
        return arr[size] + sumCalculator(arr, size - 1);
    }
    
}