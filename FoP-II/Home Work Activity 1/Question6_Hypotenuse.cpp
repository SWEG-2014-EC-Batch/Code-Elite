#include <iostream>
#include <math.h>
using namespace std;
double hypotenuseCalculator(double side1 , double side2);

int main(){
    cout<<"\nThe hypotenuse of the right angle triangle with side lengths 3 and 4 is "<<hypotenuseCalculator(3 , 4);
    cout<<"\nThe hypotenuse of the right angle triangle with side lengths 5 and 12 is "<<hypotenuseCalculator(5 , 12);
    cout<<"\nThe hypotenuse of the right angle triangle with side lengths 8 and 15 is "<<hypotenuseCalculator(8 , 15);
    return 0;
}

double hypotenuseCalculator(double side1 , double side2){
    double hypotenuse;
    hypotenuse = sqrt((pow(side1 , 2) + pow(side2 , 2)));
    return hypotenuse;
}