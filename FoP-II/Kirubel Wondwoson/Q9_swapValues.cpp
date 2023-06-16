#include<iostream>
#include<algorithm>
using namespace std;
void swapValues(int& , int& , int&);
int main()
{
    int n1 , n2 , n3 ;
    cout<<"Enter three numbers : ";
    cin>>n1>>n2>>n3;
    cout<<"BEFORE SWAPING : "<<n1<<' '<<n2<<' '<<n3<<endl;
    cout<<"AFTER SWAPING : ";
    swapValues(n1 , n2 , n3);
    return 0;
}
void swapValues(int &a , int &b , int &c)
{
    if(a > b){
        if(a > c && c > b){
            swap(b , c);
        }
    }
    if(b > a){
        if(b > c && a > c){
            swap(a , b);
        }
        if(b > c && c > a){
            swap(a , b);
            swap(b , c);
        }
    }
    if(c > a){
        if(c > b && a > b){
            swap(a , c);
            swap(b , c);
        }            
        if(c > b && b > a){
            swap(a , c);
        }
        
    }
    cout<<a<<' '<<b<<' '<<c<<endl;
}