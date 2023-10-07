#include <iostream>
#include <vector>
#include "main.h"
using namespace std;

int main() {

    readFromFile();

    char signIn;

    do{
        cout<<"\nSign in as\nA: Student\nB: Teacher\nC: Staff\n\nEnter E to exit the program\nYour choice: ";
        cin>> signIn;
        signIn = toupper(signIn);
        
        switch (signIn){
            case 'A':
                student();
                break;

            case 'B':
                teacher();
                break;
                
            case 'C':
                staff();
                break;
        }
    }while(signIn == 'A' || signIn == 'B' || signIn == 'C');
    
    if(change) save();

    return 0;
}
