#include <iostream>
using namespace std;
void welcome_msg();
int main(){
    welcome_msg();
    return 0;
}
void welcome_msg(){
    string name;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"\nHello, "<<name<<"!\nWelcome to M.P";
}
