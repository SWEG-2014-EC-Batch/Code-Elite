#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream readFile;
    char character;
    int count;

    readFile.open("Question_08.txt");
    assert(readFile.is_open());

    cout<<"Character  Occurrence"<<endl;
    for(int i=0; i<26; ++i){
        count = 0;
        readFile.seekg(0, ios::beg);
        for(; !readFile.eof();){
            readFile.get(character);
            if(character == 'a' + i){
                count++;
            }
        }
        if(count != 0){
            cout<<"    "<<char('a' + i)<<"          "<<count<<endl;
        }
    }

    readFile.close();
    return 0;
}
