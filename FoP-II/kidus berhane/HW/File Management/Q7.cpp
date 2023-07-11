#include <iostream>
#include <fstream>
using namespace std;

struct tool{
    int record;
    string toolName;
    int quantity;
    double cost;
};
tool tool1[100];

void getdata(int i){
  tool1[i].record = i+1;
  cout<<"\nEnter tool name for record"<<i+1<<": ";
  cin>>tool1[i].toolName;
  cout<<"\nEnter quantity: ";
  cin>>tool1[i].quantity;
  cout<<"\nEnter cost : ";
  cin>>tool1[i].cost;
}

void AddRecord(int i){
  ofstream outfl;
  outfl.open("hardware.dat",ios::app|ios::binary);

  getdata(i);
  outfl.write( (char *) &tool1[i], sizeof(tool1[i]) );
  outfl.close();
}

void readData()
{
  fstream infl;
  infl.open("hardware.dat", ios::in|ios::binary); 

  cout<<"\nrecord\tTool Name\tquantity\tcost\n";

  infl.read( (char *) &tool1[0], sizeof(tool1[0]) ); 
  int i = 0;
  while(infl.eof() == false){
    if(tool1[i].record == 0){
        continue;
    }
    cout<<tool1[i].record<<"\t|\t"<<tool1[i].toolName<<"\t|\t"<<tool1[i].quantity<<"\t|\t"<<tool1[i].cost;
    i++;
    infl.read( (char *) &tool1[i], sizeof(tool1[i]) ); 
  }
  infl.close();
}


int main(){

    int num;
    cout<<"How many records of tools do you want to enter: ";
    cin>>num;
    for(int i = 0; i < num; i++){
        AddRecord(i);
    }
    readData();

    
}