//Body mass index                           
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float w,h,z,BMI;
    
   cout<<"Your weight:";
      cin>>w;
   cout<<"Your height:";
      cin>>h;
   BMI=w/pow(h,2);
   cout<<"Your BMI is:"<<BMI<<endl;
   if (BMI<18)
    cout<<"you are under weight.";
   else if (BMI>24)
    cout<<"you are over weight.";
   else
    cout<<"you are Normal.";

    return 0;   
}