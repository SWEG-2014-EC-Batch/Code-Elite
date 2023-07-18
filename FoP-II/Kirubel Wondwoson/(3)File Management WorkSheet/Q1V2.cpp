#include<iostream>
#include<fstream>
using namespace std;
void readfile(int , int& , int[]);
int main()
{
    int records, count, arr[10];
    readfile(records, count, arr);
    return 0;
}
void readfile(int records, int &count, int arr[10]){
    count = 0;
    ifstream inputtxt("Q1.txt" , ios::in);
    inputtxt.read((char*)&arr , 10);
    if(!inputtxt.is_open()){
        cout<<"unable to open.";
    }
    else{
        while(count < 10){
            inputtxt.read((char*)&arr, 10);
            count++;
        }
        cout<<endl;
        cout<<count;
    }
}