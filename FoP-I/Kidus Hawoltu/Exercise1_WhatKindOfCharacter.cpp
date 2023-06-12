#include <iostream>
using namespace std;
int main()
{
    char character;
    cout<<"Enter a character: ";
    cin>>character;
    if(character>='A' && character<='Z'){
        if(character=='A' || character == 'E' || character == 'I' || character == 'O' || character == 'U'){
            cout<<"The character '"<<character<<"' is a vowel upper case letter.";
        }
        else{
            cout<<"The character '"<<character<<"' is a consonant upper case letter.";
        }
    }
    else if(character>='a' && character<='z'){
        if(character=='a' || character == 'e' || character == 'i' || character == 'o' || character == 'u'){
            cout<<"The character '"<<character<<"' is a vowel lower case letter.";
        }
        else{
            cout<<"The character '"<<character<<"' is a consonant lower case letter.";
        }
    }
    else if(character>='0' && character<='9' && int(character)%2 == 0){
        cout<<"The character '"<<character<<"' is an even number";
    }
    else if(character>='0' && character<='9' && int(character)%2 == 1){
        cout<<"The character '"<<character<<"' is an odd number";
    }   
    else{
        cout<<"The character '"<<character<<"' is a special character.";
    }
    return 0;
}