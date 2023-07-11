#include <iostream>
#include <math.h>
using namespace std;

struct complex {
        double real;
        double imaginary;
    };

complex add(complex, complex);
complex subt(complex, complex);
complex mult(complex, complex);
complex div(complex, complex);

int main(){
    complex num1, num2, result;
    char oprtr;
    cout<<"Enter a complex number\nReal: ";
    cin>>num1.real;
    cout<<"Imaginary: ";
    cin>>num1.imaginary;
    cout<<"Enter operator (+, -, *, /): ";
    cin>>oprtr;
    cout<<"Enter another complex number\nReal: ";
    cin>>num2.real;
    cout<<"Imaginary: ";
    cin>>num2.imaginary;

    switch (oprtr){
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subt(num1, num2);
            break;
        case '*':
            result = mult(num1, num2);
            break;
        case '/':
            result = div(num1, num2);
            break;
    }
    cout<<"Result: "<<result.real<<" + "<<result.imaginary<<"i";
}

complex add(complex n1, complex n2){
    n1.real += n2.real;
    n1.imaginary += n2.imaginary;
    return n1;
}
complex subt(complex n1, complex n2){
    n1.real -= n2.real;
    n1.imaginary -= n2.imaginary;
    return n1;
}
complex mult(complex n1, complex n2){
    double temp = n1.real;
    n1.real = (n1.real * n2.real) - (n1.imaginary * n2.imaginary);
    n1.imaginary = (temp * n2.imaginary) + (n1.imaginary * n2.real);
    return n1;
}
complex div(complex n1, complex n2){
    double temp = n1.real;
    n1.real = ((n1.real * n2.real) + (n1.imaginary * n2.imaginary))/(pow(n2.real, 2) - pow(n2.imaginary, 2));
    n1.imaginary = ((temp * n2.imaginary) - (n1.imaginary * n2.real))/(pow(n2.real, 2) - pow(n2.imaginary, 2));
    return n1;
}