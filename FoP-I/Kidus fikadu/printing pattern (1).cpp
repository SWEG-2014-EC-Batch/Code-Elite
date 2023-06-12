#include<iostream>
using namespace std;

int main()
{
    int choice, row, col, num;
    
     cout<<"enter the choice\n1 for number box\n2 for box by astrex\n3 for hallow box\n4 for right pyramid\n5 for hallow pyramid\n6 for right down\n7 for down hallow pyramid\n8 for pyramid \n9 for hallow pyramid\n10 for down pyramid\n11 for down hallow pyramid\n12 for box by number\n13 for right pyramid by number\n14 for pyramid by inverted number\n15 for box by letter\n16 for box by capital letter\n17 for right pyramid by number\n\n";
    cin>>choice ;
     
  switch (choice) {
  case 1:{

      cout<<"Enter the number of rows: ";
     cin>>row; 
     cout<<"Enter the number of columns: "; 
     cin>>col; cout<<"Enter the starting number: ";
     cin>>num;
      for(int i=0;i<row*col;++i)
    { 
      cout<<num+i<<' '; 
     if((i+1)%col == 0){ cout<<endl; } }}
    break;
   case 2:{
   int i,j;
    
    for( i=0;i<4;++i){
     for( j=0;j<7;++j)
       { cout<<"* "; } 
       cout<<endl; }}
    break ;
    
  case 3:{
   for(int i=0;i<7;++i){
    for(int j=0;j<8;++j){
     if(i==0 || i == 6 || j == 0 || j == 7)
      { cout<<"* "; } 
     else{ cout<<" "; } } 
       cout<<endl; }}
     break ;
    
    case 4:{
    for(int i=0;i<6;++i)
      { for(int j=0;j<=i;++j)
       { cout<<"* "; } 
         cout<<endl<<endl; }}
      break ;
    
    case 5:{
    for(int i=0;i<6;++i){
     for(int j=0;j<=i;++j){ 
       if(i==5 || j==0 || j==i)
        { cout<<"* "; } 
        else
        { cout<<" "; } }
          cout<<endl<<endl; }}
       break ;
    
    case 6:{
    for(int i=0;i<6;++i){ 
     for(int j=0;j<6-i;++j)
       { cout<<"* "; } 
       cout<<endl<<endl; }}
      break ;
    
    case 7:{
    for(int i=0;i<6;++i){
     for(int j=0;j<6-i;++j)
       { if(i==0 || j==0 || j==5-i)
        { cout<<"* "; } 
        else{ cout<<" "; } } 
        cout<<endl<<endl; }}
      break ;
    
    case 8:{
    for(int i=0;i<6;++i){ 
     for(int j=0;j<5-i;++j)
       { cout<<" "; } 
        for(int j=0;j<i+1;++j)
         { cout<<"* "; } 
          cout<<endl<<endl; }}
      break ;
    
    case 9:{
    for(int i=0;i<6;++i){ 
     for(int j=0;j<11;++j){ 
        if(i+j==5 || j-i==5 || (i==5 && j%2==0))
         { cout<<"* "; } 
         else{ cout<<" "; } } 
         cout<<endl<<endl; }}
     break ;
    
    case 10:{
    for(int i=0;i<6;++i){
       for(int j=0;j<i;++j){  
          cout<<" "; 
             } 
        for(int j=0;j<6-i;++j)
         { cout<<"* "; } 
          cout<<endl<<endl; }}
     break ;
    
    case 11:{
    for(int i=0;i<6;++i){
      for(int j=0;j<11;++j){
       if(i+j==10 || i==j || (i==0 && j%2==0))
        { cout<<"* "; } 
      else{ cout<<" "; } 
        } cout<<endl<<endl; }}
    break ;
       
     case 12:{
    for(int i=0;i<5;++i){
      for(int j=0;j<5;++j){
        cout<<j+1<<" "; }
          cout<<endl; }}
     break ;
    
    case 13:{
    for(int i=0;i<5;++i){
      for(int j=0;j<i+1;++j){
       cout<<j+1<<" "; } 
         cout<<endl; }}
    break ;
    
    case 14:{
    for(int i=0;i<5;++i){ 
     for(int j=0;j<4-i;++j){ 
       cout<<" "; }
       for(int j=4-i;j<5;++j)
       { cout<<5-j<<" "; } 
       cout<<endl; }}
    break ;
    
    case 15:{
    for(int i=0;i<5;++i){ 
     for(int j=0;j<5;++j){
      cout<<char(97+j)<<" "; }
       cout<<endl; }}
    break ;
    
    case 16:{
    for(int i=0;i<24;++i){
      cout<<char(65+i)<<' ';
       if((i+1)%6==0)
         { cout<<endl; } }}
      break ; 
    
     case 17:{
    for(int i=0;i<5;++i){
      for(int j=0;j<i+1;++j){ 
       cout<<char(65+j)<<" "; }
         cout<<endl; }}
        break;
        default:{cout<<"invalid input";}}
    
    
    
    
    
    
    return 0;
}