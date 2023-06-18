#include <iostream>
using namespace std;
void input(int &hr, int &min);  //accepts inputs
void converter(int &hr, char &am_pm); //converts 24hr format to 12hr format
void output(int hr, int min, char am_pm); //displays the result

int main(){
    int hour, minute;
    char am_pm, menu = 'y';
    while(menu == 'y'){
        input(hour, minute);
        converter(hour, am_pm);
        output(hour, minute, am_pm);
        cout<<"\nEnter y to repeat and any other character to end the program: ";
        cin>>menu;
    }
    return 0;
}

void input(int &hr, int &min){
    cout<<"\nEnter the hour: ";
    cin>>hr;
    cout<<"Enter the minute: ";
    cin>>min;
}

void converter(int &hr, char &am_pm){
    if(hr==0){
        am_pm = 'A';
        hr = 12;
    }
    else if(hr<12){
        am_pm = 'A';
    }
    else if(hr==12){
        am_pm = 'P';
    }
    else if(hr<24){
        am_pm = 'P';
        hr %= 12;
    }
}

void output(int hr, int min, char am_pm){
    if(hr<0 || hr>23 || min<0 || min>59){
        cout<<"\nInvalid input!";
    }
    else{
        cout<<"\nThe 12 hr format is "<<hr<<':';
        if(min<10){
            cout<<'0';
        }
        cout<<min<<am_pm<<"M.";
    }
}
