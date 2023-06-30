#include<iostream>
using namespace std;
float findMax(float myList[] , unsigned  size);
float findMin(float myList[] , unsigned  size);
float findRange(float myList[] , unsigned  size);
float findSum(float myList[] , unsigned  size);
float findMean(float myList[] , unsigned  size);
float findMedian(float myList[] , unsigned  size);
            /*If you use void instead of float as the return type for the findRange() and findMean() functions, 
            it means that these functions do not return any value. However, in your main() function, you are trying
            to assign the results of these functions to the range and mean variables, respectively.

            When you attempt to assign the result of a void function to a variable, it results in a compilation 
            myListor because void functions do not have a return value that can be assigned to variables*/
int main()
{
    int numMarks;
    float range , mean , median;
    cout<<"Enter the number of marks : ";
    cin>>numMarks;
    float marks[numMarks];
    for(int i=0;i<numMarks;i++){
        cout<<"Mark "<<i+1<<" : ";
        cin>>marks[i];
    }
    range = findRange(marks , numMarks);
    mean = findMean(marks  , numMarks);
    median = findMedian(marks, numMarks);
    cout<<"The range is : "<<range<<endl;
    cout<<"The mean is : "<<mean<<endl;
    cout<<"The median is : "<<median<<endl;
}
float findMax(float myList[] , unsigned  size)
{
    float max = myList[0];
    for(int i=1 ; i< size ; i++){
        if(myList[i] > max){
            max = myList[i];
        }
    }
    return max;
}
float findMin(float myList[] , unsigned  size)
{
    float min = myList[0];
    for(int i = 1 ; i<size ; i++){
        if(myList[i] < min){
            min = myList[i];
        }
    }
    return min;
}
float findRange(float myList[] , unsigned  size)
{
    float maxValue , minValue , range;
    maxValue = findMax(myList , size);
    minValue = findMin(myList , size);
    range = maxValue - minValue;
    return range;
}
float findSum(float myList[] , unsigned  size)
{
    float sum = 0;
    for(int i=0;i<size ;i++){
        sum += myList[i];
    }
    return sum;
}
float findMean(float myList[] , unsigned  size)
{
    float mean;
    mean = findSum(myList , size)/size;
    return mean;
}
float findMedian(float myList[] , unsigned size)
{
    float median;
    if(size % 2 != 0){
        median = myList[int(size/2)];
    }
    else{
        median = (myList[int(size/2 - 1)] + myList[size/2])/2;
    }
    return median;
}
