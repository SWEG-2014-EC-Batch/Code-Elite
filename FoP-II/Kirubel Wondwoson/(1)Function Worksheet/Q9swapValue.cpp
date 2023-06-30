#include<iostream>
#include<algorithm>
using namespace std;
void swapValue(int &a , int &b , int &c);
int main(){
    int x , y , z;
    cin>>x>>y>>z;
    swapValue(x  , y  , z );
    cout<<x<<" "<<y<<" "<<z<<endl; 
}
void swapValue(int &a , int &b , int &c){
    if(a > b){
        if(a > c && c > b){   // a > c > b
            swap(b , c);
        }
    }
    if(b > a){
        if(b > c && a > c){   //b > a > c
            swap(a , b);
        }
        if(b > c && c > a){   //b > c > a
            swap(a , c);
            swap(b , c);
        }
    }
    if(c > a ){
        if(c > b && a > b){   //c > a > b
            swap(b , c);
            swap(a , b);
        }
        if(c > b && b > a){   //c > b > a
            swap(a , c);
        }
    }
}