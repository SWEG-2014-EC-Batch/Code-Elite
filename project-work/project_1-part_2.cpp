#include <iostream>
using namespace std;
int main(){
    int n;
    char letter;
    // prompt user to input a capital letter
    cout<<"Enter a capital letter (A-Z): ";
    cin>>letter;                                        // Read users input

    if(letter<'A'){
        cout<<"You entered invalid letter.";            // if input is wrong print error message and end the program
        return 0;
    }
    
    n = int(letter) - 64;
    
    for(int i=0; i<(2*n + 1); ++i){                     // total number of rows
        if(i<n){                                        // upper half of the pattern
            for(int j=0; j<=i; ++j){                    // left side of the upper half
                cout<<char(65+j)<<' ';
            }
            for(int j=i+1; j<(2*n - i); ++j){           // empty space at the middle
                cout<<"  ";
            }
            for(int j=(2*n - i); j<(2*n + 1); ++j){     // right side of the upper half
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        else if(i==n){                                  // middle row of the pattern
            for(int j=0; j<i; ++j){                     // left side of the middle row
                cout<<char(65+j)<<' ';
            }
            cout<<"J ";                                 // middle column of the middle row
            for(int j=i+1; j<(2*n + 1); ++j){           // right side of the middle row
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        else{                                           // lower half of the pattern
            for(int j=0; j<(2*n + 1 - i); ++j){         // left side of the lower half
                cout<<char(65+j)<<' ';
            }
            for(int j=(2*n + 1 - i); j<i; ++j){         // empty space at the middle
                cout<<"  ";
            }
            for(int j=i; j<(2*n + 1); ++j){             // right side of the lower half
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        cout<<endl;                                     // new line for each row
    }   
    return 0;
}
