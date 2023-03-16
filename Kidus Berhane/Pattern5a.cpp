#include <iostream>

using namespace std;

int main(){
    for(int i = 10; i<=49; ++i){
        cout<<i<<" ";
        if((i+1) % 10 == 0) {
            cout<<endl;
        }
    }
}