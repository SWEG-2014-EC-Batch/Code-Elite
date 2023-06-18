#include <iostream>
using namespace std;
int multiplier(int num1 , int num2 = 1 , int num3 = 1 , int num4 = 1 , int num5 = 1 , int num6 = 1 , int num7 = 1 , int num8 = 1 , int num9 = 1 , int num10 = 1);

int main(){
    cout<<"\n4*3 = "<<multiplier(4, 3);
    cout<<"\n4*3*2 = "<<multiplier(4, 3, 2);
    cout<<"\n4*3*2*5 = "<<multiplier(4, 3, 2, 5);
    cout<<"\n4*3*2*5*-2 = "<<multiplier(4, 3, 2, 5, -2);
    cout<<"\n4*3*2*5*-2*-3 = "<<multiplier(4, 3, 2, 5, -2, -3);
    cout<<"\n1*2*3*4*5*6*7*8*9*10 = "<<multiplier(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    return 0;
}

int multiplier(int num1, int num2, int num3, int num4, int num5, int num6, int num7, int num8, int num9, int num10){
    return num1*num2*num3*num4*num5*num6*num7*num8*num9*num10;
}
