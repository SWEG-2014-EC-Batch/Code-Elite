#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<7;++i){
        for(int j=0;j<8;++j){
            if(i==0 || i == 6 || j == 0 || j == 7){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}