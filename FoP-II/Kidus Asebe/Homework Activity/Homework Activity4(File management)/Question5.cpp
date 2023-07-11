#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream infl("numbers.txt");
    int i = 1;
    while(infl.eof() == false){
        int count, sum = 0, num;
        float avg;
        infl >> count;
        for(int i = 0; i<count; i++){
            infl >> num;
            sum += num;
        }
        avg = sum/count;
        cout<<"the average of group "<<i<<"  is: "<<avg<<endl;
        i++;
    }
}