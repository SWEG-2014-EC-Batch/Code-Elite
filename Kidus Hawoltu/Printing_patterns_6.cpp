#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<6;++i){
        for(int j=0;j<5-i;++j){
            cout<<"  ";
        }
        for(int j=0;j<i+1;++j){
            cout<<"*   ";
        }
        cout<<endl<<endl;
    }
    return 0;
}