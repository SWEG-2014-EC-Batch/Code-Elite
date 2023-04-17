#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    char ans[11] , testAns[11] = {"BCDCBADBCD"};
    int result=0;
    for(int i=0; i<10; ++i){
        cout<<"Enter the answer for question "<<i+1<<": ";
        cin>>ans[i];
        ans[i] =(char)toupper(ans[i]);
        if(ans[i]==testAns[i]){
            result++;
        }
    }
    cout<<"You got "<<result<<" out of 10";
    return 0;
}