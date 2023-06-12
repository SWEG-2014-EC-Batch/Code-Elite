#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            cout<<char(97+j)<<"  ";
        }
        cout<<endl;
    }
    return 0;
}