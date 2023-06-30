#include <iostream>
using namespace std;
int fibonacci(int n = 10)
{
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    int sum = arr[0] + arr[1];
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int num, choice;
    cout << "Enter 1 to specify the digit you want 0 for default : ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter a number : ";
        cin >> num;
        cout << "The fiboncci series up to " << num << "'s number is : " << fibonacci(num);
    }
    else if (choice == 0)
    {
        cout << "The fiboncci series up to " << num << "'s number is : " << fibonacci();
    }
    else{
        cout<<"Error";
        return 0;
    }
    return 0;
}