#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<4-i;++j){
            cout<<"   ";
        }
    for(int j=4-i;j<5;++j){
        cout<<5-j<<"  ";
    }
        cout<<endl;
    }
    return 0;
}