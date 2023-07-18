#include <iostream>
#include <fstream>
using namespace std;
void countLowercaseLetter(char[] , int);
int main(){
    char letters[150];
    cout << "CHARACTER        OCCURRENCES" << endl;
    //give a space in a file to hold characters up to our size and there is a distorted information
    countLowercaseLetter(letters,150);
    return 0;
}
void countLowercaseLetter(char letters[], int size){
    ifstream iletters("Q8.txt", ios::in);
    for (int j = 97; j < 122; j++){
        int count = 0;
        for (int i = 0; i < 150; i++){
            iletters.getline(letters, 150);
            if (char(letters[i]) == char(j)){
                count++;
            }
        }
        cout << char(j) << "                " << count << endl;
    }
}