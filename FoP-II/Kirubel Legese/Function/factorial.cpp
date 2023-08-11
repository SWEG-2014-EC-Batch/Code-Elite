#include <iostream>
using namespace std;
int fibonnaci(int n)
{
    if (n==0)
    {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }

    else
    {
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }
}

int main()
{
    int n;
    cout << "enter the nth term of fibonnaci you want: ";
    cin >> n;
    cout<<fibonnaci(n);
    return 0;
}

