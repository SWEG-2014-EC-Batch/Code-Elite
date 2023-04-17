#include <iostream>
using namespace std;
int main(){
    int array[5][6] = {{1,2},{1,2,3},{},{0,0,0,0,1,2},{0,1,2,3,4}};
    for(int i=0;i<5;++i){
        for(int j=0;j<6;++j){
            cout<<array[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}