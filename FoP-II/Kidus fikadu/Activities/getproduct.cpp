#include<iostream>
using namespace std;

int SumOfArray (int arr [], int n)
{
    if (n == 0)
        return 0;
    else
        return arr [n-1] + SumOfArray (arr, n-1);
}

int main ()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr [n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr [i];
    cout << "The sum of all elements in the array is: " << SumOfArray (arr, n) << endl;
    return 0;
}
