#include <iostream>
#include <fstream>
using namespace std;

ifstream readIntegerArray;
void fileReader(string, int*, int*);

int main(){
    int array[10], count=0;
    fileReader("Question_01.txt", array, &count);
    for(int i=0; i<count; ++i){
        cout<<"Array["<<i<<"] = "<<array[i]<<endl;
    }

    // fileReader("file.txt", array, &count);
    return 0;
}

void fileReader(string fileName, int *array, int *count){
    readIntegerArray.open(fileName , ios::beg | ios::in);
    assert(readIntegerArray.is_open());
    for(int i=0; !readIntegerArray.eof(); ++i){
        readIntegerArray>>array[i];
        (*count)++;
    }
    readIntegerArray.close();
}
