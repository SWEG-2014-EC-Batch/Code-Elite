#include <iostream>
using namespace std;
void inputArray(double array[], int size);
void extremeElementSum(double array[], int size);

int main(){
    /* using dynamic array */
    // int arraySize;
    // cout<<"How many numbers? ";
    // cin>>arraySize;
    // double *myArray = new double[arraySize];
    // inputArray(myArray, arraySize);
    // extremeElementSum(myArray, arraySize);

    /* using normal array */
    double myArray[10];
    inputArray(myArray, 10);
    extremeElementSum(myArray, 10);

    return 0;
}

void inputArray(double array[], int size){
    for(int i=0; i<size; ++i){
        cout<<"Enter number "<<i+1<<": ";
        cin>>array[i];
    }
}

void extremeElementSum(double array[], int size){
    cout<<"\nThe first element is "<<array[0];
    cout<<"\nThe last element is "<<array[size-1];
    cout<<"\nTheir sum is "<<array[0] + array[size-1]<<endl;
}
