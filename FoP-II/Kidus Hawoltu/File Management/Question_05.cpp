#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream readFile("Question_05.txt");
    assert(readFile.is_open());

    int n;
    float num, sum;
    for(; !readFile.eof();){
        sum = 0;
        readFile>>n;
        for(int i=0; i<n; ++i){
            readFile>>num;
            sum += num;
        }
        cout<<"The average is "<<float(sum/n)<<endl;
    }
    return 0;
}