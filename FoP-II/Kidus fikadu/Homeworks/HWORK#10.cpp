#include <iostream>
#include <ctype.h>
using namespace std;

void input(float& length, float& subLength, int num) {
    if (num == 1) {
        cout << "Enter length" << endl << "Feet: ";
        cin >> length;
        cout << "Inches: ";
        cin >> subLength;
    }
    else {
        cout << "Enter length" << endl << "Meters: ";
        cin >> length;
        cout << "Centimeters: ";
        cin >> subLength;
    }
}
void cal(float& feet, float& inch, float& me, float& ce, int num) {
    int k;
    if (num == 1) {
        me = feet * 0.3048 + inch * 0.3048 / 12;
        k = me;
        ce = (me - k) * 100;
        me = k;
    }
    else {
        feet = me / 0.3048 + ce / 100 / 0.3048;
        k = feet;
        inch = (feet - k) * 12;
        feet = k;
    }
}
void output(float length, float subLength, int num) {
    if (num == 1) {
        cout << "Meters: " << length << " " << "Centimeters: " << subLength << endl;
    }
    else {
        cout << "Feet: " << length << " " << "Inches: " << subLength << endl;
    }
}
int main() {
    float feet, inches, meters, centimeters;
    int menu1;
    char menu2;
    do {

        cout << "Enter 1 to convert  (feet - inches) to (meters - centimeters) \n or 2 to convert from (meters - centimeters) to (feet - inches): ";
        cin >> menu1;
        switch (menu1) {
        case 1:
            input(feet, inches, menu1);
            cal(feet, inches, meters, centimeters, menu1);
            output(meters, centimeters, menu1);
            break;
        case 2:
            input(meters, centimeters, menu1);
            cal(feet, inches, meters, centimeters, menu1);
            output(feet, inches, menu1);
            break;
        default:
            break;
        }

        cout << "if you want the program to repeat press 'y'\nelse the program terminates.\n ";
        cin >> menu2;
        menu2 = toupper(menu2);
    } while (menu2 == 'Y');
}