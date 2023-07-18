#include <iostream>
#include <fstream>
using namespace std;
struct Store{
    int recNum, quantity;
    string toolName;
    float cost;

    int recordNum;
} store[100], temp;
void read();
void addinfo();
void print();
void update();
int main()
{
    int c;    
    read();
    do{
        cout << "Enter : 1 to input addition data to each tool\t2 to know your current list of tools\t3 if you want to update any information in the list : ";
        cin >> c;
        switch (c){
        case 1:
            do{
                cout << "What is the record number of the tool ? ";
                cin >> temp.recordNum;
                addinfo();
                cout<<"Enter 0 to stop 1 to continue";
                cin>>c;
            } while (c != 0);
            break;
        case 2:
            print();
            break;
        case 3:
            do{
                update();
                cout<<"Enter 0 to stop 1 to continue";
                cin>>c;
            }while(c!=0);
            break;
        default:
            cout<<"Invalid input."<<endl;
            break;
        }
        return 0;
        cout << "Enter 0 to stop 1 to continue.";
        cin >> c;
    } while (c != 0);
}
void read(){
    ifstream irecords("Q7.dat", ios::in);
    if(!irecords.is_open()){
        cout<<"unable to open.";
        exit(1);
    }
    for (int i = 0; i < 8; i++){
        irecords >> store[i].recNum 
                 >> store[i].toolName 
                 >> store[i].quantity 
                 >> store[i].cost;
    }
}
void addinfo(){
    fstream records("Q7.dat");
    if(!records.is_open()){
        cout<<"unable to ope.";
        exit(1);
    }
    for (int i = 0; i < 8; i++){
        if (temp.recordNum == store[i].recNum){
            cout << "Enter the new quantity of " << store[i].toolName << " : ";
            cin >> store[i].quantity;
            records << store[i].quantity;
            cout << "Enter the new cost of " << store[i].toolName << " : ";
            cin >> store[i].cost;
            records << store[i].cost;
        }
    }
    for (int i = 0; i < 8; i++){
        records << store[i].recNum << "          "
                << store[i].toolName << "         "
                << store[i].quantity << "         "
                << store[i].cost
                << endl;
    }
}
void print(){
    for (int i = 0; i < 8; i++){
        cout << store[i].recNum << "       "
             << store[i].toolName << "      "
             << store[i].quantity << "       "
             << store[i].cost
             << endl;
    }
}
void update(){
    fstream records("Q7.dat");
    if(!records.is_open()){
        cout<<"unable to open.";
        exit(1);
    }
    for(int i = 0 ; i < 8 ; i++){
        cout<<"Record "<< i+1<<endl;
        cout<<"Enter the record number : ";
        cin>>store[i].recNum;
        records<<store[i].recNum;
        cout<<"Enter the name of the tool : ";
        cin>>store[i].toolName;
        records<<store[i].toolName;
        cout<<"Enter the quantity of "<<store[i].toolName<<" : ";
        cin>>store[i].quantity;
        records<<store[i].quantity;
        cout<<"Enter the cost of "<<store[i].toolName<<" : ";
        cin>>store[i].cost;
        records<<store[i].cost;
    }
    for(int i = 0 ; i < 8 ; i++){
        records<<store[i].recNum<<"      "
               <<store[i].toolName<<"      "
               <<store[i].quantity<<"       "
               <<store[i].cost
               <<endl;
    }
}