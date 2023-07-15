#include <iostream>
#include <ctype.h>
#include <math.h>
using namespace std;

void input(int &year, float &minRate, float &maxRate);
bool isWrongInput(float minRate, float maxRate, int year, float deposit=0);
void calculateBalance(float deposit, float rate, int year, float &balance);

int main(){
    // Declare variables
    float principal , minRate , maxRate , rate , annualDeposit , accountBalance , *annualDeposit2;
    char menu;
    int count=0 , count2=0 , numYears;
    
    // Prompt user to input menu choice
    cout<<endl<<"This program calculates your account balance after n number of years\nEnter 'A' if you deposited money only once and you don't make any more deposits or withdrawals\nEnter 'B' if you deposit the same amount of money each year\nEnter 'C' if you deposit different amount of money each year\nEnter 'E' to End the program";
    do{
        cout<<endl<<"Menu: ";
        cin>>menu;                  // Read users input
        menu = toupper(menu);
        accountBalance = 0;
        switch(menu){
            case 'A':
                cout<<endl<<"Enter the principal: ";
                cin>>principal;
                input(numYears, minRate, maxRate);
                if(isWrongInput(minRate, maxRate, numYears, principal)){
                    break;
                }
                rate=(minRate+maxRate)/200;                                                  // calculate rate
                calculateBalance(principal, rate, numYears, accountBalance);                      // calculate account balance
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;   // print account balance
                break;

            case 'B':
                // Read annual deposit, min rate, max rate, number of years
                cout<<endl<<"Enter the annual deposit: ";
                cin>>annualDeposit;
                input(numYears, minRate, maxRate);
                if(isWrongInput(minRate, maxRate, numYears, annualDeposit)){
                    break;
                }
                rate=(minRate+maxRate)/200;                                                 // calculate rate
                for(int i=0; i<=numYears; ++i){                                             // calculate account balance                    
                    calculateBalance(annualDeposit, rate, numYears-i, accountBalance);
                }
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;   // print account balance
                break;

            case 'C':
                input(numYears, minRate, maxRate);
                if(isWrongInput(minRate, maxRate, numYears)){
                    break;
                }
                annualDeposit2 = new float[numYears+1];
                for(int i=0; i<=numYears; ++i){
                    count2=0;
                    do{
                        if(i==0){
                        cout<<"Enter the amount you deposited at first: ";      // Read principal deposit
                        }
                        else{
                        cout<<"Enter the deposit made after "<<i<<" years: ";    // Read deposit of the year
                        }
                        cin>>annualDeposit2[i];
                        if(annualDeposit2[i]<0){
                            cout<<"Wrong Value. ";                               // if deposit is negative print error message
                            if(count2!=2){
                                cout<<"Try again.";
                            }
                            cout<<endl;
                            count2+=1;
                        }
                    }while(annualDeposit2[i]<0 && count2<3);
                    if(count2==3){                                                 // if input is wrong 3 times break the loop
                        break;
                    }
                }
                if(count2==3){                                                      // if input is wrong 3 times end the program
                    break;
                }
                rate=(minRate+maxRate)/200;                                         // calculate rate
                for(int i=0; i<=numYears; ++i){                                     // calculate account balance
                    calculateBalance(annualDeposit2[i], rate, numYears-i, accountBalance);
                }
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;   // print account balance
                delete [] annualDeposit2;
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

    return 0;       // end program
}

void input(int &year, float &minRate, float &maxRate){          // Read number of years, min rate, max rate
    cout<<endl<<"Enter the number of years: ";
    cin>>year;
    cout<<"Enter the minimum interest rate(%): ";
    cin>>minRate;
    cout<<"Enter the maximum interest rate(%): ";
    cin>>maxRate;
}

bool isWrongInput(float minRate, float maxRate, int year, float deposit){
    if(deposit<0 || minRate<0 || maxRate<0 || year<0){      // if any input is negative print error message
        cout<<"Wrong value (negative numbers)."<<endl;
        return true;
    }
    if(minRate>maxRate){                                                        // if minRate > maxRate print error message
        cout<<"Wrong value (minimum rate is greater than maximum rate)"<<endl;
        return true;
    }
    return false;
}

void calculateBalance(float deposit, float rate, int year, float &balance){
    balance += deposit * pow((1+rate), year);
}
