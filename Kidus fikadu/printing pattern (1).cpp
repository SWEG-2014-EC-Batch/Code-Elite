#include<iostream>
using namespace std;

int main(){
    /* this program prompt a user a menu of * , number,letter box 
    or pyramid*/
    int col,row,k,i;
    char menu;
    cout<<"enter 1 if you want a rectangle by * \n enter 2 if you need it by number \n enter 3 if you need it by letter\n enter 4 if you need a pyramid \n enter 5 if you need down pyramid \n";
    cin>>menu;
    if(menu=='1'){
    cout <<"enter a number of row \n";  
    cin>>row;
     cout <<"enter a number of column\n";
     cin>>col;
    }else if(menu>='2' && menu<='5')
    { 
    cout <<"how many rows you want\n";
    cin>>row;}
    
    
    
  switch (menu){
   case'1':{
   for(k=1;k<row+1;k++)
    {
 
   for (i=1;i<col+1;i++)
     {
      cout<<"* ";
     }
     cout<<endl;
    }
     break ;
    } 
    case '2':{ 
   for(k=1;k<row+1;k++)
    {
 
   for (i=1;i<2;i++)
     {
      cout<<"1 2 3 4 5";
     }
     cout<<endl;
    }
     break ;
    }
    case '3':{  
     for(k=1;k<row+1;k++)
    {
 
   for (i=1;i<2;i++)
     {
      cout<<"a b c d e ";
     }
     cout<<endl;
    }
    break ;
    
   case '4':{
     
     for(k=0;k<row;k++)
    {
 
   for (i=0;i<=k;i++)
     {
      cout<<"* ";
      
     }
    cout<<endl;
    }   
    }break;
   case '5':{
   
     for(k=row;k>0;k--)
    {
 
   for (i=1;i<=k;i++)
     {
      cout<<"* ";
      
     }
    cout<<endl;
    }  
   }break; 
    
     default:{cout<<"wrong input";}} }
    
   cout<<"thanks" ;
    
    
    
    
    return 0;
}