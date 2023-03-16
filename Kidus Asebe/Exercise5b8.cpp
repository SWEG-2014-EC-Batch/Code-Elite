#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<6;++i){
        for(int j=0;j<11;++j){
            if(i+j==10 || i==j || (i==0 && j%2==0)){
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