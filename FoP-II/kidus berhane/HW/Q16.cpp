#include <iostream>
using namespace std;

void input(int &hour, int &minute) {
    cout << "Enter the hour (0-23): ";
    cin >> hour;
    cout << "Enter the minute (0-59): ";
    cin >> minute;
}

void convert(int &hour, int &minute, char &meridiem) {
    if (hour == 0) {
        hour = 12;
        meridiem = 'A';
    } else if (hour < 12) {
        meridiem = 'A';
    } else if (hour == 12) {
        meridiem = 'P';
    } else {
        hour -= 12;
        meridiem = 'P';
    }
}

void output(int hour, int minute, char meridiem) {
    cout << "The time in 12-hour notation is: ";
    if (hour < 10) {
        cout << "0";
    }
    cout << hour << ":";
    if (minute < 10) {
        cout << "0";
    }
    cout << minute << " ";
    if (meridiem == 'A') {
        cout << "AM" << endl;
    } else {
        cout << "PM" << endl;
    }
}

int main() {
    int hour, minute;
    char meridiem;
    char repeat;

    do {
        input(hour, minute);
        convert(hour, minute, meridiem);
        output(hour, minute, meridiem);

        cout << "Do you want to repeat the computation? enter 'Y' to repeat or enter 'N' to end the program(Y/N): ";
        cin >> repeat;
        cout << endl;

    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}