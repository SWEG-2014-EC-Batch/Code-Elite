

#include <iostream>
#include <string.h>

using namespace std;


void vow(string a);

int main()
{
    string letter;
    cout << "enter the string \n";
    cin >> letter;
    vow(letter);
}

void vow(string a) {

    int l = a.length();
    for (int i = 0; i < l; i++) {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
            cout << a[i]<<" ";
        }

    }


}


