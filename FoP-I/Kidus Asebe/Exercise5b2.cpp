#include <iostream>
using namespace std;
int main(){
    for(int i = 0; i<8; ++i){
        cout<<"* ";        
    }
    cout<<endl;
    for(int i=0; i<40; ++i){
        if(i%8==0 || (i+1)%8==0){
            cout<<"* ";
        }
        else{
            cout<<"  ";
        }
        if((i+1)%8==0){
            cout<<endl;
        }
    }
    for(int i=0; i<8; ++i){
        cout<<"* ";
    }
    return 0;
}