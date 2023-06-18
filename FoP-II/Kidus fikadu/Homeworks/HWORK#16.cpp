
#include <iostream>
#include <ctype.h>
using namespace std;

void readTime(int& hr, int& min) {
    cout << "Enter the time in 24 - hour \nHours: ";
    cin >> hr;
    cout << "Minutes: ";
    cin >> min;
}
void convert(int& hr, char& clock) {
    if (hr >= 13) {
        hr -= 12;
        clock = 'P';
    }
}
void display(int hr, int min, char time) {
    cout << "The time in 12 - hour notation: " << hr << ":" << min << " " << time << "M" << endl;
}

int main() {
    char menu;
    do {
        int hours, minutes;
        char meridian = 'A';
        readTime(hours, minutes);

        for (int i = 0; i < 3; i++) {
            if (hours > 24 || hours < 0) {
                cout << "enter the hour correctly\n";
                cin >> hours;
            }
            else {
                break;
            }
            if (i == 2) {
                return 0;
            }
        }
        
        for (int i = 0; i < 3; i++) {
            if (minutes > 24 || minutes < 0) {
                cout << "enter the minuets correctly\n";
                cin >> minutes;
            }
            else {
                break;
            }
            if (i == 2) {
                return 0;
            }
        }
        convert(hours, meridian);
        display(hours, minutes, meridian);

        cout << "if you want the program to repeat press 'Y'\nelse the program terminates. ";
        cin >> menu;
        menu = toupper(menu);
    } while (menu == 'Y');
}
