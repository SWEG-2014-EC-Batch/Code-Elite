#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<24;++i){
        cout<<char(65+i)<<' '; 
        if((i+1)%6==0){
            cout<<endl;
        }
    }
    return 0;
}