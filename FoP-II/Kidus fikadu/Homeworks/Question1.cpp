#include <iostream>
#include <fstream>
using namespace std;

void myFunc(char[], int[], int&);

int main(){
    int myarray[50], count = 0;
    char fileName[] = "try.txt";
    myFunc(fileName, myarray, count);
    for(int i = 0; i < count; i++){
        cout<<myarray[i]<<" ";
    }
    cout<<"\ncount = "<<count;
      
}
void myFunc(char file[], int arr[], int& count){
    ifstream infl(file);
    if ( !infl.is_open() ) {	
    cout << "File could not be opened" << endl;  
    exit( 1 );
    }
    do{
        infl >> arr[count];
        count++;
    }while(infl.eof() == false);
    infl.close();
}