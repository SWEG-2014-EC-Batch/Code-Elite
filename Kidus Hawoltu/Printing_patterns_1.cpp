#include <iostream>
using namespace std;
int main(){
    int row, col, num;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    cout<<"Enter the starting number: ";
    cin>>num;
    for(int i=0;i<row*col;++i){
        cout<<num+i<<' ';
        if((i+1)%col == 0){
            cout<<endl;
        }
    }
    return 0;
}