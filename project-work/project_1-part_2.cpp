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
    
    for(int i=0; i<(2*n + 1); ++i){ 
        if(i<n){ 
            for(int j=0; j<=i; ++j){ 
                cout<<char(65+j)<<' ';
            }
            for(int j=i+1; j<(2*n - i); ++j){ 
                cout<<"  ";
            }
            for(int j=(2*n - i); j<(2*n + 1); ++j){
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        else if(i==n){
            for(int j=0; j<i; ++j){ 
                cout<<char(65+j)<<' ';
            }
            cout<<"J ";
            for(int j=i+1; j<(2*n + 1); ++j){
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        else{
            for(int j=0; j<(2*n + 1 - i); ++j){ 
                cout<<char(65+j)<<' ';
            }
            for(int j=(2*n + 1 - i); j<i; ++j){ 
                cout<<"  ";
            }
            for(int j=i; j<(2*n + 1); ++j){
                cout<<char(65 + 2*n - j)<<' ';
            }
        }
        
        cout<<endl;
    }   
    return 0;
}
