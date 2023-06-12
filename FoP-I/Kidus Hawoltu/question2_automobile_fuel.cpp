/*Question 2
Write a program that prompts the capacity in gallons of an automobile fuel tank and the miles per gallons the 
automobiles can be driven. The program outputs the number miles the automobile cam be driven without refueling.
*/
#include <iostream>
using namespace std;
int main()
{
    float capacity,miles_per_gallon,number_of_miles;
    cout<<"What is the capacity in gallons of the automobile fuel tank (in gallons)? ";
    cin>>capacity;
    cout<<"What is the number of miles per gallon the automobile can be driven? ";
    cin>>miles_per_gallon;
    number_of_miles = capacity * miles_per_gallon;
    cout<<"The number of miles the automobile can be driven without refueling is "<<number_of_miles<<"miles";
    return 0;
}