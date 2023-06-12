#include <iostream>
using namespace std;
int main(){
    int letter[2][26];
    for(int i=0;i<26;++i){
        letter[0][i] = 65 + i;
        letter[1][i] = 97 + i;
    }
    for(int i=0;i<26;++i){
        cout<<(char)letter[0][i]<<(char)letter[1][i]<<' ';
        if((i+1)%5  == 0){
           cout<<endl;
        }
    }
    return 0;
}