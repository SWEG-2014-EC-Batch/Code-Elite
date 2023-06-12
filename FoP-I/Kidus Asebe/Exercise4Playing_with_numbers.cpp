#include <iostream>
#include <ctype.h>
#include <math.h>

using namespace std;
int main(){
    unsigned int num, num2, temp, temp1, temp2, numOfDigit, digit[10], freq[10]={}, reverse, sum, product, fact_digit;
    char menu;
    cout<<"Enter 'A' to find the reverse of a number.\nEnter 'B' to find number of digits in a number.\nEnter 'C' to find sum of digits of a number.\nEnter 'D' to find product of even digits of a number.\nEnter 'E' to print the first and last digits of a number and find their sum.\nEnter 'F' to swaps the first and last digits of a number.\nEnter 'G' to check whether a number is palindrome or not.\nEnter 'H' to find the frequency of each digit and print that in a table format.\nEnter 'I' to check whether a number is Armstrong or not.\nEnter 'J' to checks whether a number is Strong or not.\nEnter 'K' to checks whether a number is Perfect or not.\n";
    cin>>menu;
    menu = toupper(menu);
    cout<<"Enter a positive integer: ";
    cin>>num;
    switch(menu){
        case 'A':
        //program to print the reverse of a number
        int remainder, reversed = 0;
        while(num != 0) {
           remainder = num % 10;
           reversed = reversed * 10 + remainder;
            num /= 10;
        }

        cout << "The reversed number: " << reversed;
        break;

        case 'B':
        // program to find number of digits in a number
        int digits = 0;
        while(num>=1){
            num /= 10;
            digits++;
        }

        cout << "The number of digits of your number is: "<<digits;
        break;

        case 'C':
        //program to find sum of digits of a number
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
  
        cout<< "The sum of the digits you entered is: "<<sum;
        break;

        case 'D':
        //program to find product of even digits of a number
        temp = num;
        temp1 = product = 1;
        temp2 = 0;
        while(temp!=0){
            temp2 = temp % 10;
            temp1 *= temp2;
            if(temp2%2 == 0){
                product *= temp2;
            }
            temp /= 10;
        }
        if(temp1%2 == 0){
            cout<<"The product of even digits of "<<num<<" is "<<product;
        }
        else{
            cout<<"The number "<<num<<" doesn't have even digits.";
        }
        break;

        case 'E':
        //program to print the first and last digits of a number and find their sum
        int last, first, x = 0,theirSum = 0;
        while(num != 0) {
            first = num % 10;
            if(x==0) {
                last = first;
                theirSum += last;
            }
            num /= 10;
            x++;
        }
        theirSum += first;
        cout<< "The first digit of your number is: "<<first<<endl;
        cout<< "The last digit of your number is: "<<last<<endl;
        cout<< "And their sum is: "<< theirSum;
        break;

        case 'F':
        //program that swaps the first and last digits of a number
        int middle;
        int number = num;
        while(num != 0) {
            first = num % 10;
            if(x==0) {
                last = first;
            }
            num /= 10;
            x++;
        }
        middle = (number - first*pow(10,(x - 1)) - last)/10;

        cout<< "Your number when the first and last digit is swapped = "<<last<<middle<<first;
        break;

        case 'G':
        //program to check whether a number is palindrome or not
        int temp = num;
        while(num != 0) {
            remainder = num % 10;
            reversed = reversed * 10 + remainder;
            num /= 10;
        }
        if(temp == reversed) {
        cout<< "The number you entered is palindrome";
        }else{
        cout<< "The number you entered is not palindrome";
        }
        break;

        case 'H':
        //program to find the frequency of each digit and print that in a table format
        numOfDigit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            numOfDigit += 1;
        }
        temp = num;
        for(int x=0;x<numOfDigit;++x){
            digit[x] = temp % 10;
            temp /= 10;
        }
        for(int i=0;i<numOfDigit;++i){
            temp2 = 0;
            for(int j=i-1;j>=0;--j){
                if(digit[i] == digit[j]){
                    temp2 += 1;
                }
            }
            if(temp2 != 0){
                continue;
            }
            for(int j=0;j<numOfDigit;++j){
                if(digit[i] == digit[j]){
                    freq[i] += 1;
                }
            }
        }
        cout<<"_____________________"<<endl;
        cout<<"| Digit | Frequency |"<<endl;
        cout<<"---------------------"<<endl;
        for(int i=numOfDigit-1;i>=0;--i){
            if(freq[i] == 0){
                continue;
            }
            cout<<"|   "<<digit[i]<<"   |     "<<freq[i]<<"     |"<<endl;
        }
        cout<<"---------------------";
        break;

        case 'I':
        //program that checks whether a number is Armstrong or not
        //An Armstrong number is an integer, where the sum of its digits each raised to the power of its number of digits, is equal to the number itself.
        numOfDigit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            numOfDigit += 1;
        }
        temp = num;
        num2=0;
        for(int i=0;i<numOfDigit;++i){
            digit[i] = temp % 10;
            num2 += pow(digit[i] , numOfDigit);
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
        //program that checks whether a number is Strong or not
        //A Strong number is an integer, where the sum of the factorial of its digits, is equal to the number itself.
        numOfDigit = 0;
        for(int j = num ; j != 0 ; ){
            j /= 10;
            numOfDigit += 1;
        }
        temp = num;
        num2=0;
        for(int i=0;i<numOfDigit;++i){
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
        //program that checks whether a number is Perfect or not
        //A Perfect number is an integer, where the sum of its factors (except the number itself), is equal to the number itself.
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