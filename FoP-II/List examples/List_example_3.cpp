#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    
    list<int>::iterator it = myList.begin();
    ++it; // Move iterator to the second position
    myList.insert(it, 15); // Insert element at the second position

    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    
   return 0;
}