#include <iostream>
using namespace std;
int main(){
    for(int i=0;i<6;++i){
        for(int j=0;j<=i;++j){
            if(i==5 || j==0 || j==i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl<<endl;
    }
    return 0;
}