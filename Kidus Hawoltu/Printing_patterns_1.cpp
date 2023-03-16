#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<40;++i){
        cout<<10+i<<' ';
        if((i+1)%10 == 0){
            cout<<endl;
        }
    }
    return 0;
}