#include <iostream>
using namespace std;
double max(double n1, double n2);
double max(double n1, double n2, double n3);

int main(){
    cout<<endl<<max(1.0,2.0)<<endl<<max(2.0,1.0)<<endl;
    cout<<endl<<max(1.0,2.0,3.0)<<endl<<max(1.0,3.0,2.0)<<endl<<max(3.0,2.0,1.0);
}

double max(double n1, double n2){
    if(n1 > n2){
        return n1;
    }
    else{
        return n2;
    }
}

double max(double n1, double n2, double n3){
    return max(max(n1, n2), n3);
}
