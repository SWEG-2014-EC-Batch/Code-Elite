#include<iostream>
using namespace std;

struct Complex
{
    float real;
    float imag;
};

Complex add(Complex n1, Complex n2)
{
    Complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}

Complex subtract(Complex n1, Complex n2)
{
    Complex temp;
    temp.real = n1.real - n2.real;
    temp.imag = n1.imag - n2.imag;
    return temp;
}

Complex multiply(Complex n1, Complex n2)
{
    Complex temp;
    temp.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    temp.imag = (n1.real * n2.imag) + (n1.imag * n2.real);
    return temp;
}

Complex divide(Complex n1, Complex n2)
{
    Complex temp;
    float denominator = (n2.real * n2.real) + (n2.imag * n2.imag);
    temp.real = ((n1.real * n2.real) + (n1.imag * n2.imag)) / denominator;
    temp.imag = ((n1.imag * n2.real) - (n1.real * n2.imag)) / denominator;
    return temp;
}

int main()
{
    Complex num1, num2, result;

    cout << "Enter first complex number:\n";
    cout << "Real part: ";
    cin >> num1.real;
    cout << "Imaginary part: ";
    cin >> num1.imag;

    cout << "\nEnter second complex number:\n";
    cout << "Real part: ";
    cin >> num2.real;
    cout << "Imaginary part: ";
    cin >> num2.imag;

    result = add(num1, num2);
    cout << "\nSum of two complex numbers is: " << result.real << " + " << result.imag << "i";

    result = subtract(num1, num2);
    cout << "\nDifference of two complex numbers is: " << result.real << " + " << result.imag << "i";

    result = multiply(num1, num2);
    cout << "\nProduct of two complex numbers is: " << result.real << " + " << result.imag << "i";

    result = divide(num1, num2);
    cout << "\nDivision of two complex numbers is: " << result.real << " + " << result.imag << "i\n";

   return 0;
}
