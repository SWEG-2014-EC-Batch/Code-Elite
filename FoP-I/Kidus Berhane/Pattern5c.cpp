#include <iostream>
using namespace std;
int main(){
    int row, col, num, interval;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<"Enter the number of columns: ";
    cin>>col;
    cout<<"Enter the starting number: ";
    cin>>num;
    cout<<"Enter the interval between consecutive numbers: ";
    cin>>interval;
    for(int i=0;i<row*col;++i){
        cout<<num+(interval*i)<<' ';
        if((i+1)%col == 0){
            cout<<endl;
        }
    }
    return 0;
}