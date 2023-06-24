

#include <iostream>
#include "vowelandcons.h"
#include "reverse.h"
#include "compare.h"
#include "case.h"


using namespace std;
void mains(string& letter) {
    cout << "enter the string \n";
    cin >> letter;
}
int main()
{
    string alpha, letter, let1, let2;
    char menu, menu2;
    int end;

    do {
        int u = 0;

        cout << " enter 'a' for string length\n enter 'b' for vowel,cons and num length\n enter 'c' for reverse it\n enter 'd' to compare it\n enter 'e' to case change\n";
        cin >> menu;

        switch (menu) {
        case 'a':
            mains(letter);
            cout << "string length : " << slen(letter) << endl; break;
        case 'b':
            mains(letter);
            vclen(letter); break;
        case 'c':
            mains(letter);
            cout << "reverse : " << rev(letter) << endl; break;

        case 'd': {
            cout << "enter two strings \n";
            cin >> let1 >> let2;
            cout << comp(let1, let2) << endl; }
                break;
        case 'e':
            cout << "enter 'l' to lower\nenter 'u' to upper\n";
            cin >> menu2;
            switch (menu2) {
            case 'l': cout << "enter the string of alphabets only \n";
                cin >> alpha;
                for (int i = 0; i < slen(alpha); ++i) {
                    do {
                        if (alpha[i] < 65 || (alpha[i] > 90 && alpha[i] < 97) || alpha[i]>122) {
                            if (u == 2) {
                                return 0;
                            }
                            cout << "enter the string of alphabets only \n";
                            cin >> alpha;
                            u++;
                           
                        }
                    } while (alpha[i] < 65 || (alpha[i] > 90 && alpha[i] < 97) || alpha[i]>122);

                }
                cout << tolow(alpha) << endl;
                break;
            case 'u':
                cout << "enter the string of alphabets only \n";
                cin >> alpha;
                for (int i = 0; i < slen(alpha); ++i) {
                    do {
                        if (alpha[i] < 65 || (alpha[i] > 90 && alpha[i] < 97) || alpha[i]>122) {
                            if (u == 2) {
                                return 0;
                            }
                            cout << "enter the string of alphabets only \n";
                            cin >> alpha;
                            u++;
                            
                        }
                    } while (alpha[i] < 65 || (alpha[i] > 90 && alpha[i] < 97) || alpha[i]>122);
                }

                cout << toup(alpha) << endl;
                break;
            default:
                cout << "enter l or u please\n";
            }
            break;
        default:
            return 0;
        }
        cout << "enter '1' to repeat\n";
        cin >> end;
    } while (end == 1);
    return 0;
}
