/*This is a program that calculates the total mark and grade of a student by prompting the user's Quiz,test,project,Assignment and final result */
#include<iostream>
using namespace std;
int main(){
 float mark,test,Quiz,project,Assignment,finalresult;
 int i,j,k,l,m;
cout<<"Enter your Quiz resut out of 5: ";
cin>>Quiz;
    while ((Quiz<0 || Quiz>5) && i<=3){
          cout<<"Invalid input.Your Quiz result must be in the range of 0&5.\nRe enter your Quiz result: ";
          cin>>Quiz;
          i++;
         }
cout<<"Enter your test result out of 15: ";
cin>>test;
    while((test<0 || test>15) && j<=2){
         cout<<"Invalid input.Your test result must be in the range of 0 & 15.\nRe enter you test result: ";
         cin>>test;
         j++;
         }
cout<<"Enter your project resut out of 20: ";
cin>>project;
    while((project<0||project>20) && k++){
         cout<<"Invalid input.Your project result must be in the range of 0 & 20\nRe enter your project result: ";
         cin>>project;
         k++;
         }
cout<<"Enter your Assignment resut out of 10: ";
cin>>Assignment;
    while((Assignment<0 || Assignment>10) && l<=2){
         cout<<"Invalid input.Your Assignment result must be in the range of 0 &10\nRe enter your Assignment result: ";
         cin>>Assignment;
         l++;
         }
cout<<"Enter your Final resut out of 50: ";
cin>>finalresult;
    while((finalresult<0 || finalresult>50) && m++){
         cout<<"Invalid input.Your finalresult must be in the range of 0 & 50\nRe enter your final result: ";
         cin>>finalresult;
         m++;
         }
   mark=test+Quiz+project+Assignment+finalresult;
 if(mark>=90){
    cout<<"Your Total mark is:"<<mark<<" and Your grade is A+";
}
 else if(mark>=80){
    cout<<"Your Total mark is:"<<mark<<"and Your grade is A";
}
else if(mark>=75){
    cout<<"Your Total mark is:"<<mark<<"and Your grade is B+";
}
else if(mark>=60){
    cout<<"Your Total mark is:"<<mark<<" and Your grade is B";
}
else if(mark>=55){
    cout<<"Your Total mark is:"<<mark<<" and Your grade is C+";
}
else if(mark>=45){
    cout<<"Your Total mark is:"<<mark<<" and Your grade is C";
}
else if(mark>=30){
    cout<<"Your Total mark is:"<<mark<<" and Your grade is D";
}
else{cout<<"Your Total mark is:"<<mark<<" and Your grade is F";}
return 0;
}
 
