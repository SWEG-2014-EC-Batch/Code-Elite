#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int num[18];
    int sum, avg1, avg2, avg3;
    ifstream irecords("Q5.txt",ios::in);
    for(int i = 0 ; i < 18 ; i++){
        sum = 0;
        if(num[i] == 5){
            for(int j = 0 ; j < 5 ; j++){
                sum += num[j];
            }
            avg1 = sum/5;
        }
        irecords.seekg(6,ios::beg);
        sum = 0;
        if(num[i] == 6){
            for(int j = i ; j < i+6 ; j++){
                sum += num[j];
            }
            avg2 = sum/6;
        }
        irecords.seekg(5,ios::cur);
        sum = 0;
        if(num[i] == 4){
            for(int j = i ; j < i+4 ; j++){
                sum += num[j];
            }
            avg3 = sum/4;
        }
    }
    cout<<avg1<<endl;
    cout<<avg2<<endl;
    cout<<avg3<<endl;
    return 0;
}