#include <iostream>

using namespace std;

int main(){
    for(int i = 0; i<6; ++i){
        for(int j = 5; j>=i; --j){
            if(j==5 || j==i || i==0){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}