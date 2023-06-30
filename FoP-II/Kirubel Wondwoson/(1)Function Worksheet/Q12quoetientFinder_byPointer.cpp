#include <iostream>
using namespace std;
void calcQuotient(double n1, double n2, double *answer);
int main()
{
    double num1 = 10, num2 = 2, quotient;
    calcQuotient(num1, num2, &quotient);
    cout << "The quotient is : " << quotient;
}
void calcQuotient(double n1, double n2, double *answer)
{
    *answer = n1 / n2;
}