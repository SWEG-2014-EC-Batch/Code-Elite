#include <iostream>
#include <math.h>
using namespace std;

void input(int &n);
void printRow(int row, int n);

int main(){
    int n;
    input(n);
    for(int i=0; i<=2*n + 1; ++i){   
        printRow(i, n);
    }
    return 0;
}

void input(int &n){
    char letter;
    cout<<"Enter a capital letter (A-Z): ";     // prompt user to input a capital letter
    cin>>letter;                                // Read users input

    if(letter<'A' || letter>'Z'){
        cout<<"You entered invalid letter.";    // if input is wrong print error message and end the program
        assert(false);
    }
    n = int(letter) - 64;
}

void printRow(int row, int n){
    int num = abs(n-row);
    for(int i=0; i<=n-num && i!=n; ++i){
        cout<<char(65+i)<<' ';
    }
    for(int i=n-num+1; i<n+num; ++i){
        cout<<"  ";
    }
    for(int i=n+num; i<=2*n; ++i){
        if(i==n){
            cout<<"J ";
        }
        else{
            cout<<char(65+2*n-i)<<' ';
        }
    }
    cout<<endl;                    // new line for each row
}
