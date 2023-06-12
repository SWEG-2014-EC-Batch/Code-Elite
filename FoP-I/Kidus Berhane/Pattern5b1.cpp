#include <iostream>

using namespace std;

int main(){
    for(int i = 0; i<28; ++i){
        cout<<"* ";
        if((i+1)%7==0){
            cout<<endl;
        }
    }
}