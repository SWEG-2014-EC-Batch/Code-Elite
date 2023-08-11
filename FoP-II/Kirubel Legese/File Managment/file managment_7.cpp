#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

struct Tool {
    int record;
    string toolName;
    int quantity;
    double cost;
}tool[100];

void getdata(int);
void AddRecord(int);
void readData();

int main() {
    int num;
    cout << "How many records of tools do you want to enter: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        AddRecord(i);
    }
    readData();
    return 0;
}

void getdata(int i) {
    tool[i].record = i + 1;
    cout << "\nEnter tool name for record" << i + 1 << ": ";
    cin >> tool[i].toolName;
    cout << "\nEnter quantity: ";
    cin >> tool[i].quantity;
    cout << "\nEnter cost : ";
    cin >> tool[i].cost;
}

void AddRecord(int i) {
    ofstream outfl;
    outfl.open("hardware.dat", ios::app | ios::binary);
    assert(outfl.is_open());

    getdata(i);
    outfl.write((char*)&tool[i], sizeof(tool[i]));
    outfl.close();
}

void readData() {
    fstream infl;
    infl.open("hardware.dat", ios::in | ios::binary);
    assert(infl.is_open());

    cout << "\nrecord\tTool Name\tquantity\tcost\n";

    infl.read((char*)&tool[0], sizeof(tool[0]));
    int i = 0;
    while (infl.eof() == false) {
        if (tool[i].record == 0) {
            continue;
        }
        cout << tool[i].record << "\t|\t" << tool[i].toolName << "\t|\t" << tool[i].quantity << "\t|\t" << tool[i].cost;
        i++;
        infl.read((char*)&tool[i], sizeof(tool[i]));
    }
    infl.close();
}
