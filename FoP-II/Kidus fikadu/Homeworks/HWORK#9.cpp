

#include <iostream>
#include "swaper.h"

using namespace std;

int main()
{
    start:
    int n1, n2, n3;
    cout << "enter three numbers\n";
    cin >> n1 >> n2 >> n3;
    cout <<"Before : "<< n1 << " " << n2 << " " << n3 << endl;

    refunction(n1, n2, n3);
    goto start;
}

