#include <iostream>
using namespace std;
int main(){
   /* int capitalLetter[26], smallLetter[26];
    for(int i=0;i<26;++i){
        capitalLetter[i] = 65 + i;
        smallLetter[i] = 97 + i;
    }
    for(int i=0;i<26;++i){
        cout<<(char)capitalLetter[i]<<(char)smallLetter[i]<<' '; 
        if((i+1)%5 == 0){
            cout<<endl;
        }
        cout<<endl;
    }
    */
   int letter[52];
   for(int i=0;i<26;++i){
        letter[i] = 65 + i;
        letter[26+i] = 97 + i;
    }
    for(int i=0;i<26;++i){
        cout<<(char)letter[i]<<(char)letter[26+i]<<' ';
        if((i+1)%5 == 0){
            cout<<endl;
        }
    }
    return 0;
}