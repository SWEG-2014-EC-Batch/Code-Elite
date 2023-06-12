#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
    /* this program reverses the number the 
    user inputs*/
   int number;
   cout<<"enter a number\n1 for reversing\n2 for counting\n3 for summing-up the digits\n4 for multiplying the even\n5 for knowing the 1st,last and sum\n6 for swiping the first and last\n7 to know palindrome number or not\n8 to know the frequency\n9 to know Armstrong number or not\n10 to know strong number or not\n11 to know perfect number\n\n";
   cin>>number;
    
    
  switch (number){
     case 1:{
    int num,r1, rev1=0;
    num=number;
    cout<<"enter a number to be reversed\n";
    cin>>num;
    
     while (num){
    r1=num%10;
     rev1=(rev1*10)+r1;
     num=num/10;
    }
        cout<<"the reverse is "<<rev1;}
     break ;
  case 2:{
    int i2=0,num2;
    number=num2;
     cout<<"enter a number\n";
     cin>>num2;
   while (num2>0){
     num2=num2/10;
     i2=i2+1;}
    cout<<"the number of digits is "<<i2;}
    break ;
  case 3:{  
    int num3,r3, rev3=0;
    number =num3;
    cout<<"enter a number to be summed\n";
    cin>>num3;
    
     while (num3){
    r3=num3%10;
     rev3=rev3+r3;
     num3=num3/10;
    }
        cout<<"the sum is "<<rev3;}
      break ; 
    
   case 4:{ 
    int  r4,i5,k4=1,num4;
    number =num4;
    cout<<"enter a number\n" ;
    cin>>num4;
    while (num4>0){
      r4=num4%10;
        i5=num4%2;
       if(i5==0){
         k4=k4*r4;}
      num4=num4/10;}
      cout<<"the product of the even numbers in your number is "<<k4;
      }
      break ;
   case 5:{
       int num5,r5;
      number =num5;
       cout<<"enter a number were the last and the first digits to be summed\n";
      cin>>num5;
       r5=num5%10;
       while (num5>9){
       num5=num5/10;
      }
        cout<<"the first is "<<num5<<"\nthe last is "<<r5;
     cout<<"\nthe sum is "<<r5+num5;}
      break;
   case 6:{
      int nums, first, last, sums, digits, final, a, b;
       number =nums;
        cout << " enter any number\n ";
        cin >> nums;
         digits = (int)log10(nums); 
         first = nums / pow(10, digits); 
          last = nums % 10; a = first * (pow(10, digits));
          b = nums % a;
          nums = b / 10; 
           final = last * (pow(10, digits)) + (nums * 10 + first);
          cout << " The number after swaping is\n " << final << endl; 
        }break;  
  case 7:{
    int n6, num6, digit6, rev6 = 0; 
    number =num6;

     cout << "Enter a positive number\n "; 
     cin >> num6; 
      n6 = num6; 
   do { digit6 = num6 % 10; 
     rev6 = (rev6 * 10) + digit6; 
     num6 = num6 / 10; } 
    while (num6 != 0); 
      cout << " The reverse of the number is\n " ;
       cout<< rev6 << endl; 
      if (n6 == rev6) 
       cout << " The number is a palindrome."; 
      else 
    cout << " The number is not a palindrome.";}
    break ;
      
   case 8:{
    int num7, i7, j7, ctr, r7;
    number =num7;
   
    cout << " enter any number\n ";
    cin >> num7;
    for (i7 = 0; i7 < 10; i7++) 
    {
        cout << "The frequency of " << i7 << " = ";
        ctr = 0;
        for (j7 = num7; j7 > 0; j7 = j7 / 10) 
        {
            r7 = j7 % 10;
            if (r7 == i7) 
            {
                ctr++;
            }
        }
        cout << ctr << endl;}
        break ;
   case 9:{
    
    int num8, originalNum, remainder, result = 0; 
    number =num8;
    cout << "Enter a three-digit integer\n "; 
    cin >> num8; 
    originalNum = num8;
     while (originalNum != 0) { 
     remainder = originalNum % 10; 
    result += remainder * remainder * remainder;
     originalNum /= 10; 
    } 
    if (result == num8) 
     cout << num8 << " is an Armstrong number.";
    else 
     cout << num8 << " is not an Armstrong number."; 
   }
    break ;
  case 10:{
    int i9, num9, n1, k9= 0, j9;
    number =num9;
    long fact;
    cout << " enter a number to check whether it is Strong number\n ";
    cin >> num9;
    n1 = num9;
    for (j9 = num9; j9 > 0; j9 = j9 / 10) {
        fact = 1;
        for (i9 = 1; i9 <= j9 % 10; i9++) {
            fact = fact * i9;
        }
        k9= k9 + fact;
    }
    if (k9== n1) {
        cout << n1 << " is Strong number." << endl;
    }
    else {
        cout << n1 << " is not a Strong number." << endl;
    }}
    break;
    
  case 11:{
        int  u=1, summ=0,num10;
         number=num10;
 
         cout << "enter a number\n ";
         cin >> num10;
     while(u<=num10)
      {                              
       if(u<num10)
      {
      if(num10%u==0 )
      summ=summ+u;
      }                         
      u++;
       }                           
      if(summ==num10)
       {
      cout<<num10<<" is a Perfect number\n";
      }
      else
      {
       cout<<num10<<" is not a Perfect number\n"; 
         }}} break ;
 
    default:{cout<<"invalid input";}
    

    
    
    return 0;
}}