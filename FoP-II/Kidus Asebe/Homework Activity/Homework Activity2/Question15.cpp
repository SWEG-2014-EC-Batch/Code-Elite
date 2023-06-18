#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;
void scale(double scaleFactor, double &num1, double &num2);
void output(double scaleFactor, double num1, double num2);

int main(){
    output(0.012, 23.6776, 18.8327);
    output(1, 65.2, 14.78);
    return 0;
}

void scale(double scaleFactor, double &num1, double &num2){
    assert(scaleFactor!=0);
    int scalePower;
    for(int i=0; ; ++i){
        if(pow(10, i)*scaleFactor == int(pow(10, i)*scaleFactor)){
            scalePower = i;
            break;
        }
    }
    num1 = (round(pow(10, scalePower)*num1))/pow(10, scalePower);   
    num2 = (round(pow(10, scalePower)*num2))/pow(10, scalePower);
}

void output(double scaleFactor, double num1, double num2){
    cout<<"\nThe numbers before scaling: "<<num1<<" and "<<num2;
    scale(scaleFactor, num1, num2);
    cout<<"\nThe numbers after scaling by "<<scaleFactor<<": "<<num1<<" and "<<num2<<'\n';
}
