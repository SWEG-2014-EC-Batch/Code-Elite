#include <iostream>

using namespace std;

int main(){
    char charac;

    cout<<"Enter a character: ";
    cin>>charac;
    if(charac>='A' && charac<='Z'){
        switch(charac){
            case 'A':
               
            case 'E':
                
            case 'I':
                
            case 'O':
                
            case 'U':
                cout<<"You entered a vowel Capital letter: "<<charac;
                break;
            default:
                cout<<"You entered a consonant Capital letter: "<<charac;                   

        }
    }
    else if(charac>='a' && charac<='z'){
        switch(charac){
            case 'a':
                
            case 'e':
               
            case 'i':
                
            case 'o':
                
            case 'u':
                cout<<"You entered a vowel Small letter: "<<charac;
                break;
            default:
                cout<<"You entered a consonant Small letter: "<<charac;                   

        }
    }
    else if(charac>='0' && charac<='9'){
        
        switch(int(charac)%2){
         case 0:
            cout<<"You enterd an even digit: "<<charac;
            break;
         default:
            cout<<"You enterd an odd digit: "<<charac;
            break;                     
        } 
    }
    else{
        cout<<"You entered a special character: "<<charac;
    }
    return 0;
}