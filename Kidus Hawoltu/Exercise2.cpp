#include <iostream>
using namespace std;
int array1[4]={9,8,7,6};
int main(){
    int array2[4]={1,2,3,4};
    cout<<"____________________"<<endl;
    cout<<"|No| Array1 | Array2|"<<endl;
    cout<<"--------------------"<<endl;
    for(int i=0;i<4;++i){
        cout<<'|'<<i<<"|   "<<array1[i]<<"    |    "<<array2[i]<<"   |"<<endl;
    }
    cout<<"--------------------"<<endl;
    return 0;
}