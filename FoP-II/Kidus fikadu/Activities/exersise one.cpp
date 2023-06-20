

#include <iostream>
using namespace std;

void arr(int a[5]);

int main()
{
    int a[5];
    arr(a);
}
void arr(int a[5]){
    for (int i = 0; i < 5; i++) {
        cout << "enter " << i << "th array element\n";
        cin >> a[i];
    }

    cout << a[0] << " " << a[4]<<endl;
    cout << a[0] + a[4];
}