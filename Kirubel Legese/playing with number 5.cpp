#include <iostream>
#include <math.h>
#include <ctype.h>
using namespace std;
int main(){
    unsigned int num, num2, temp, temp1, temp2, no_digit, digit[10], freq[10]={}, reverse, sum, prod, fact_digit;
    char menu;
    cout<<"Enter 'A' to find the reverse of a number.\nEnter 'B' to find number of digits in a number.\nEnter 'C' to find sum of digits of a number.\nEnter 'D' to find product of even digits of a number.\nEnter 'E' to print the first and last digits of a number and find their sum.\nEnter 'F' to swaps the first and last digits of a number.\nEnter 'G' to check whether a number is palindrome or not.\nEnter 'H' to find the frequency of each digit and print that in a table format.\nEnter 'I' to check whether a number is Armstrong or not.\nEnter 'J' to checks whether a number is Strong or not.\nEnter 'K' to checks whether a number is Perfect or not.\n";
    cin>>menu;
    menu = toupper(menu);
    cout<<"Enter a positive integer: ";
    cin>>num;
    switch(menu){
        case 'A':
        temp = num;
        reverse = temp2 = 0;
        while(temp!=0){
            temp2 = temp % 10;
            reverse = reverse*10 +temp2;
            temp /= 10;
        }
        cout<<"The reverse of "<<num<<" is "<<reverse;
        break;
        case 'B':
        no_digit = 0;
        temp=num;
        while(temp!=0){
            temp /= 10;
            no_digit += 1;
        }
        cout<<"The number of digits of "<<num<<" is "<<no_digit;
        break;
        case 'C':
        temp = num;
        sum = temp2 = 0;
        while(temp!=0){
            temp2 = temp % 10;
            sum = sum+temp2;
            temp /= 10;
        }
        cout<<"The sum of digits of "<<num<<" is "<<sum;
        break;
        case 'D':
        temp = num;
        temp1 = prod = 1;
        temp2 = 0;
        while(temp!=0){
            temp2 = temp % 10;
            temp1 *= temp2;
            if(temp2%2 == 0){
                prod *= temp2;
            }
            temp /= 10;
        }
        if(temp1%2 == 0){
            cout<<"The product of even digits of "<<num<<" is "<<prod;
        }
        else{
            cout<<"The number "<<num<<" doesn't have even digits.";
        }
        break;
        case 'E':
        no_digit = 0;
        temp=num;
        while(temp!=0){
            temp /= 10;
            no_digit += 1;
        }
        temp = num;
        for(int i=0;i<no_digit;++i){
            digit[i] = temp % 10;
            temp /= 10;
        }
        sum = digit[0] + digit[no_digit - 1];
        cout<<"The first digit of "<<num<<" is "<<digit[no_digit - 1]<<" and the last digit is "<<digit[0]<<endl;
        cout<<"Their sum is "<<sum;
        break;
        case 'F':
        no_digit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            no_digit += 1;
        }
        temp = num;
        for(int i=0;i<no_digit;++i){
            digit[i] = temp % 10;
            temp /= 10;
        }
        cout<<"When the first and last digits of "<<num<<" are swapped, it becomes "<<digit[0];
        for(int i=no_digit-2;i>0;--i){
            cout<<digit[i];
        }
        if(no_digit>1){
            cout<<digit[no_digit-1];
        }
        break;
        case 'G':
        temp = num;
        reverse = temp2 = 0;
        while(temp!=0){
            temp2 = temp % 10;
            reverse = reverse*10 +temp2;
            temp /= 10;
        }
        if(reverse == num){
            cout<<"The number "<<num<<" is a Palindrome.";
        }
        else{
            cout<<"The number "<<num<<" is not a Palindrome.";
        }
        break;
        case 'H':
        no_digit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            no_digit += 1;
        }
        temp = num;
        for(int i=0;i<no_digit;++i){
            digit[i] = temp % 10;
            temp /= 10;
        }
        for(int i=0;i<no_digit;++i){
            temp2 = 0;
            for(int j=i-1;j>=0;--j){
                if(digit[i] == digit[j]){
                    temp2 += 1;
                }
            }
            if(temp2 != 0){
                continue;
            }
            for(int j=0;j<no_digit;++j){
                if(digit[i] == digit[j]){
                    freq[i] += 1;
                }
            }
        }
        cout<<"_____________________"<<endl;
        cout<<"| Digit | Frequency |"<<endl;
        cout<<"---------------------"<<endl;
        for(int i=no_digit-1;i>=0;--i){
            if(freq[i] == 0){
                continue;
            }
            cout<<"|   "<<digit[i]<<"   |     "<<freq[i]<<"     |"<<endl;
        }
        cout<<"---------------------";
        break;
        case 'I':
        no_digit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            no_digit += 1;
        }
        temp = num;
        num2=0;
        for(int i=0;i<no_digit;++i){
            digit[i] = temp % 10;
            num2 += pow(digit[i] , no_digit);
            temp /= 10;
        }
        if(num == num2){
            cout<<num<<" is an Armstrong number.";
        }
        else{
            cout<<num<<" is not an Armstrong number.";
        }
        break;
        case 'J':
        no_digit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            no_digit += 1;
        }
        temp = num;
        num2=0;
        for(int i=0;i<no_digit;++i){
            temp1 = temp % 10;
            fact_digit=1;
            if(temp1>0){
                for(int temp2=temp1;temp2>=1;--temp2){
                    fact_digit *= temp2;
                }
            }
            num2 += fact_digit;
            temp /= 10;
        }   
        if(num == num2){
            cout<<num<<" is a Strong number.";
        }
        else{
            cout<<num<<" is not a Strong number.";
        }
        break;
        case 'K':
        num2 = 0;
        for(int temp=1;temp<num;++temp){
            if(num%temp == 0){
                num2 += temp;
            }
        }
        if(num == num2){
            cout<<num<<" is a Perfect number.";
        }
        else{
            cout<<num<<" is not a Perfect number.";
        }
        break;
        default:
        cout<<"Invalid input.";
        break;
    }
    return 0;
}

