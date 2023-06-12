#include<iostream>
using namespace std;
int main(){
   //one dimentional arrays 
  float total,Average,monthlySalary[6];
   monthlySalary[0]=2000;
   monthlySalary[1]=2500;
   monthlySalary[2]=3000;
   monthlySalary[3]=4500;
   monthlySalary[4]=2000;
   monthlySalary[5]=1000;
   cout<<"Monthly salary from month 1 to 6: "<<monthlySalary[0]<<" "<<monthlySalary[1]<<" "<<monthlySalary[2]<<" "<<monthlySalary[3]<<" "<<monthlySalary[4]<<" "<<monthlySalary[5];
     total=monthlySalary[0]+monthlySalary[1]+monthlySalary[2]+monthlySalary[3]+monthlySalary[4] + monthlySalary[5];
     Average=total/6;                                 
 cout<<"\nMy  total salary in 6 month is: "<<total;
 cout<<"\nMy Average salary in 6 month is: "<<Average;
  return 0;
  //1D with in a Loop
  int i=0;
  float monthlySalarys[6]={2000,2500,3000,4500,2000,1000};
  for(monthlySalarys[i];i<5;i++)
  {
    cout<<monthlySalarys[i]<<" ";
  }
   for(const float &k:monthlySalarys)
   {
    cout<<k;
   }
  
 //Two dimentional arrays
int studentList,subject;
  float mark[5][5]={{98,99,95,85,89},{78,88,99,77,85},{65,45,89,75,100},{78,45,98,65,86},{95,84,54,75,65}};
  for(int i=0;i<5;i++)
  {
    for(int j=0;j<5;j++)
    {
      cout<<mark[i][j]<<" ";
    }
    cout<<endl;
  }  
}