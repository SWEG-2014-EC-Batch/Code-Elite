#include <iostream>
#include <math.h>
using namespace std;

struct ComplexNumber{
    double real;
    double imaginary;
};

void input(ComplexNumber&, ComplexNumber&);
void display(ComplexNumber);
ComplexNumber add(ComplexNumber, ComplexNumber);
ComplexNumber substruct(ComplexNumber, ComplexNumber);
ComplexNumber multiply(ComplexNumber, ComplexNumber);
ComplexNumber divide(ComplexNumber, ComplexNumber);

int main(){
    ComplexNumber num1, num2;
    input(num1, num2);
    display(num1); cout<<" + "; display(num2); cout<<" = "; display(add(num1, num2));  cout<<endl;
    display(num1); cout<<" - "; display(num2); cout<<" = "; display(substruct(num1, num2));  cout<<endl;
    display(num1); cout<<" * "; display(num2); cout<<" = "; display(multiply(num1, num2));  cout<<endl;
    display(num1); cout<<" / "; display(num2); cout<<" = "; display(divide(num1, num2));  cout<<endl;
    return 0;
}

void input(ComplexNumber &n1, ComplexNumber &n2){
    cout<<"\nEnter the real part of number 1: ";
    cin>>n1.real;
    cout<<"Enter the imaginary part of number 1: ";
    cin>>n1.imaginary;
    cout<<"\nEnter the real part of number 2: ";
    cin>>n2.real;
    cout<<"Enter the imaginary part of number 2: ";
    cin>>n2.imaginary;
}

void display(ComplexNumber n){
    if(n.real == 0){
        if(n.imaginary == 0){
            cout<<0;
        }
        else if(n.imaginary < 0){
            cout<<"("<<n.imaginary<<"i)";
        }
        else{
            cout<<n.imaginary<<'i';
        }
    }
    else{
        if(n.imaginary == 0){
            cout<<n.real;
        }
        else if(n.imaginary < 0){
            cout<<"("<<n.real<<" - "<<(-1 * n.imaginary)<<"i)";
        }
        else{
            cout<<"("<<n.real<<" + "<<n.imaginary<<"i)";
        }
    }
}

ComplexNumber add(ComplexNumber n1, ComplexNumber n2){
    ComplexNumber sum;
    sum.real = n1.real + n2.real;
    sum.imaginary = n1.imaginary + n2.imaginary;
    return sum;
}

ComplexNumber substruct(ComplexNumber n1, ComplexNumber n2){
    ComplexNumber difference;
    difference.real = n1.real - n2.real;
    difference.imaginary = n1.imaginary - n2.imaginary;
    return difference;
}

ComplexNumber multiply(ComplexNumber n1, ComplexNumber n2){
    ComplexNumber product;
    product.real = (n1.real * n2.real) - (n1.imaginary * n2.imaginary);
    product.imaginary = (n1.real * n2.imaginary) + (n1.imaginary *n2.real);
    return product;
}

ComplexNumber divide(ComplexNumber n1, ComplexNumber n2){
    ComplexNumber quotient;
    quotient.real = ((n1.real * n2.real) + (n1.imaginary * n2.imaginary)) / (pow(n2.real, 2) + pow(n2.imaginary, 2));
    quotient.imaginary = ((n2.real * n1.imaginary) - (n1.real * n2.imaginary)) / (pow(n2.real, 2) + pow(n2.imaginary, 2));
    return quotient;
}
