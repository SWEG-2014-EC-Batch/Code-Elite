#include <iostream>
#include <fstream>
using namespace std;
ifstream read1;
void fileRead(string file, int* array, int* count) 
{
    read1.open(file, ios::beg | ios::in);
    if (!read1.is_open());
    {
        cout << "error,unable to open file";
    }
    for (int i = 0; !read1.eof(); ++i) {
        read1>> array[i];
        (*count)++;
    }
    read1.close();
}
int main() 
{
    int array[10], count = 0;
    fileRead("file managment_1.txt", array, &count);
    for (int i = 0; i < count; ++i) {
        cout << array[i] << endl;
    }
    return 0;
}

