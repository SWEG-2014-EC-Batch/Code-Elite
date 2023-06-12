#include<iostream>
using namespace std;

int main()
{ 
    float C,MPG,M;
    cout<<"Enter the capcity in Gallon:";
    cin>>C;
    cout<<"Enter the Mile per Gallon:";
    cin>>MPG;
    M=C*MPG;
    cout<<"The mile that the Automobile can be driven with out refuling is:"<<M;
    return 0;
}
