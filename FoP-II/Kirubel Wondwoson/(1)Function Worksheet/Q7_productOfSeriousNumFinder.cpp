#include <iostream>
#include <cstdarg>
using namespace std;
int product(int count, ...); // Variable-Length argument list is a function that can accept-
                             // varying number of Arguments at run time
int main()
{
    cout << product(2 , 1) << endl;
    cout << product( 4 , 3 , 2 ) << endl;
    cout << product( 5 , 4 , 3 ,2 ) << endl;
    cout << product( 2 , 3 , 4 , 5 , 6) << endl;
    return 0;
}
int product(int count, ...)
{
    int result = 1;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        int num = va_arg(args, int );
        result *= num;
    }
    va_end(args);
    return result;
}
