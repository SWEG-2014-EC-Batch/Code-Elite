#include <iostream>
using namespace std;
int main(){
    int n;
    char letter;

    cout<<"Enter a capital letter (A-Z): ";
    cin>>letter;

    if(letter<'A'){
        cout<<"You entered invalid letter.";
        return 0;
    }
    
    n = int(letter) - 64;
    return 0;
}
