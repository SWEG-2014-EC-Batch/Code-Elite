#include <iostream>
#include <ctype.h>
#include <math.h>
using namespace std;
int main(){
    float principal , minRate , maxRate , rate , annualDeposit , accountBalance , *annualDeposit2;
    char menu;
    int count=0 , count2=0 , numYears;
    
    cout<<endl<<"This program calculates your account balance after n number of years\nEnter 'A' if you deposited money only once and you don't make any more deposits or withdrawals\nEnter 'B' if you deposit the same amount of money each year\nEnter 'C' if you deposit different amount of money each year\nEnter 'E' to End the program";
    do{
        cout<<endl<<"Menu: ";
        cin>>menu;
        menu = toupper(menu);
        accountBalance = 0;
        switch(menu){
            case 'A':
                break;

            case 'B':
                break;

            case 'C':
                break;

            case 'E':
                cout<<"Thank you for using this program!!";
                count = 3;
                break;

            default:
                cout<<"Wrong Input!!"<<endl;
                count += 1;
                break;
        }
    }while(count<3);

    return 0;
}
