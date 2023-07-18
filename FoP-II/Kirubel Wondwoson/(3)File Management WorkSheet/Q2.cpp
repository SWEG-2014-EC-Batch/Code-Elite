#include <iostream>
#include <fstream>
using namespace std;
struct Employee{
    string name, temp;
    float payRate, regularPay, overtimePay, grossPay;
    int hours;
};
Employee employee[4];
void readandprint();
int main(){ 
    cout<<"_____________________________________________________________________________________"<<endl;
    cout << "Name                Pay Rate      Hours    Regular-Pay    Overtime-Pay    Gross-Pay" << endl;
    cout<<"_____________________________________________________________________________________"<<endl;
    readandprint();
    return 0;
}
void readandprint(){
    int i = 0;
    fstream q2txt;
    q2txt.open("Q2.txt");
    if(!q2txt.is_open()){
        cout<<"un able to open.";
        exit(1);
    }
    do{

        q2txt >> employee[i].name;
        q2txt >> employee[i].temp;
        q2txt >> employee[i].payRate;
        q2txt >> employee[i].hours;
        // compute
        if (employee[i].hours < 40){
            employee[i].regularPay = employee[i].hours * employee[i].payRate;
            employee[i].overtimePay = 0;
            employee[i].grossPay = employee[i].regularPay;
        }
        else{
            employee[i].regularPay = 40 * employee[i].payRate;
            employee[i].overtimePay = (employee[i].hours - 40) * employee[i].payRate; // not sure
            employee[i].grossPay = employee[i].regularPay + employee[i].overtimePay;
        }
        // display
        cout << employee[i].name<<" "<<employee[i].temp<< "          " << employee[i].payRate << "            " << employee[i].hours << "        "
             << employee[i].regularPay << "              " << employee[i].overtimePay << "            " << employee[i].grossPay;
        cout << endl;
        cout<<"_____________________________________________________________________________________"<<endl;
        i++;
    } while (i < 4);
}
// void read(){
//     int i = 0;
//     fstream q2txt;
//     q2txt.open("Q2.txt");
//     do{
//         q2txt>>employee[i].name;
//         q2txt>>employee[i].payRate;
//         q2txt>>employee[i].hours;
//         i++;
//     }while(i < 4);
// }
// void compute(){
//     int i = 0;
//     fstream q2txt;
//     q2txt.open("Q2.txt");
//     do{
//         read();
//         if(employee[i].hours < 40){
//             employee[i].regularPay = employee[i].hours*employee[i].payRate;
//             employee[i].overtimePay = 0;
//             employee[i].grossPay = employee[i].regularPay;
//         }
//         else{
//             employee[i].regularPay = 40*employee[i].payRate;
//             employee[i].overtimePay = (employee[i].hours - 40)*employee[i].payRate;  // not sure
//             employee[i].grossPay = employee[i].regularPay + employee[i].overtimePay;
//         }
//         i++;
//     }while(i < 4);
// }
// void display(){
//     int i = 0;
//     fstream q2txt;
//     q2txt.open("Q2.txt");
//     do{
//         compute();
//         cout<<employee[i].name<<"        "<<employee[i].payRate<<"          "<<employee[i].hours<<"       "
//             <<employee[i].regularPay<<"            "<<employee[i].overtimePay<<"            "<<employee[i].grossPay;
//             cout<<endl;
//     }while(i<4);
// }
