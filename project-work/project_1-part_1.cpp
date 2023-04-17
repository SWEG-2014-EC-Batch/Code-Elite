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
                cout<<endl<<"Enter the principal: ";
                cin>>principal;
                cout<<"Enter the minimum interest rate(%): ";
                cin>>minRate;
                cout<<"Enter the maximum interest rate(%): ";
                cin>>maxRate;
                cout<<"Enter the number of years: ";
                cin>>numYears;
                if(principal<0 || minRate<0 || maxRate<0 || numYears<0){
                    cout<<"Wrong value (negative numbers)."<<endl;
                    break;
                }
                if(minRate>maxRate){
                    cout<<"Wrong value (minimum rate is greater than maximum rate)"<<endl;
                    break;
                }
                rate=(minRate+maxRate)/200;
                accountBalance=principal*pow((1+rate),numYears);
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;
                break;

            case 'B':
                cout<<endl<<"Enter the annual deposit: ";
                cin>>annualDeposit;
                cout<<"Enter the minimum interest rate(%): ";
                cin>>minRate;
                cout<<"Enter the maximum interest rate(%): ";
                cin>>maxRate;
                cout<<"Enter the number of years: ";
                cin>>numYears;
                if(annualDeposit<0 || minRate<0 || maxRate<0 || numYears<0){
                    cout<<"Wrong value (negative numbers)."<<endl;
                    break;
                }
                if(minRate>maxRate){
                    cout<<"Wrong value (minimum rate is greater than maximum rate)"<<endl;
                    break;
                }
                rate=(minRate+maxRate)/200;
                for(int i=0; i<=numYears; ++i){
                    accountBalance += annualDeposit * pow((1+rate) , (numYears-i));
                }
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;
                break;

            case 'C':
                cout<<endl<<"Enter the number of years: ";
                cin>>numYears;
                cout<<"Enter the minimum interest rate(%): ";
                cin>>minRate;
                cout<<"Enter the maximum interest rate(%): ";
                cin>>maxRate;
                if(minRate<0 || maxRate<0 || numYears<0){
                    cout<<"Wrong value (negative numbers)."<<endl;
                    break;
                }
                if(minRate>maxRate){
                    cout<<"Wrong value (minimum rate is greater than maximum rate)"<<endl;
                    break;
                }
                annualDeposit2 = new float[numYears+1];
                for(int i=0; i<=numYears; ++i){
                    count2=0;
                    do{
                        if(i==0){
                        cout<<"Enter the amount you deposited at first: ";
                        }
                        else{
                        cout<<"Enter the deposit made after "<<i<<" years: ";
                        }
                        cin>>annualDeposit2[i];
                        if(annualDeposit2[i]<0){
                            cout<<"Wrong Value. ";
                            if(count2!=2){
                                cout<<"Try again.";
                            }
                            cout<<endl;
                            count2+=1;
                        }
                    }while(annualDeposit2[i]<0 && count2<3);
                    if(count2==3){
                        break;
                    }
                }
                if(count2==3){
                    break;
                }
                rate=(minRate+maxRate)/200;
                for(int i=0; i<=numYears; ++i){
                    accountBalance += annualDeposit2[i] * pow((1+rate) , (numYears-i));
                }
                cout<<"Your balance after "<<numYears<<" years is "<<accountBalance<<endl;
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

    return 0;
}
