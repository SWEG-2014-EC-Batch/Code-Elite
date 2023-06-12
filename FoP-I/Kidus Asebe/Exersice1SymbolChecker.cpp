#include <iostream>

using namespace std;

int main(){
    char character;

    cout<<"Enter a character: ";
    cin>>character;
    if(character>='A' && character<='Z'){
        switch(character){
            case 'A':
               
            case 'E':
                
            case 'I':
                
            case 'O':
                
            case 'U':
                cout<<"You entered a vowel Capital letter: "<<character;
                break;
            default:
                cout<<"You entered a consonant Capital letter: "<<character;                   

        }
    }
    else if(character>='a' && character<='z'){
        switch(character){
            case 'a':
                
            case 'e':
               
            case 'i':
                
            case 'o':
                
            case 'u':
                cout<<"You entered a vowel Small letter: "<<character;
                break;
            default:
                cout<<"You entered a consonant Small letter: "<<character;                   

        }
    }
    else if(character>='0' && character<='9'){
        
        switch(int(character)%2){
         case 0:
            cout<<"You enterd an even digit: "<<character;
            break;
         default:
            cout<<"You enterd an odd digit: "<<character;
            break;                     
        } 
    }
    else{
        cout<<"You entered a special character: "<<character;
    }
    return 0;
}