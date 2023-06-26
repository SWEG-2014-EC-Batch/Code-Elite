#include<iostream>
#include<math.h>
using namespace std;
void acceptCurrent(double current[] , int size);
void calPower(double resistance[] , double current[] , double power[] , int size);
void displayPower(double resistance[] , double current[] , double power[] , int size);
int main()
{
    double resistance[] = {16 , 27 ,39 , 56 ,81};
    double current[5] , power[5];
    acceptCurrent(current , 5);
    calPower(resistance , current , power , 5);
    displayPower(resistance , current , power , 5);
}
void acceptCurrent(double current[] , int size)
{
    for(int i = 0 ; i < size ; i++){
        cout<<"Current "<<i+1<<" : ";
        cin>>current[i];
    }
}
void calPower(double resistance[] , double current[] , double power[] , int size)
{
    for(int i = 0 ; i< size ;i++){
        power[i] = resistance[i] * pow(current[i] , 2);
    }
}
void displayPower(double resistance[] , double current[] , double power[] , int size)
{
    double total1 = 0 , total2 = 0 , total3 = 0;
    cout<<"\nResistance       Current          Power  "<<endl;
    for(int i=0;i<5;++i){
      cout<<resistance[i]<<"               "<<current[i]<<"                "<<power[i];
      total1 +=resistance[i];
      total2 += current[i];
      total3 += power[i];
      cout<<endl;
    }
     cout<<"Total: "<<total1<<"       "<<total2<<"               "<<total3<<endl;
}

