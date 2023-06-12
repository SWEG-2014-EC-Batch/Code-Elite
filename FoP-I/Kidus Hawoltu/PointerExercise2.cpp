#include <iostream>
using namespace std;
int main(){
    int array[2][3] , *ptr=&array[0][0];
    *ptr = 45;
    *(ptr+1) = 67;
    *(ptr+2) = 75;
    *(ptr+3) = 64;
    *(ptr+4) = 83;
    *(ptr+5) = 59;
    for(int i=0; i<2; ++i){
        for(int j=0; j<3; ++j){
            cout<<array[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}