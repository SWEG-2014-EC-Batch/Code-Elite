#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_front(5);

    myList.pop_front(); // Remove the first element

    list<int>::iterator it;
    for (it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}