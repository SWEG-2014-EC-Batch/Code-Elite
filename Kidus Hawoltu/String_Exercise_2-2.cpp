#include <iostream>
#include <string.h>
using namespace std;
int main(){;
    char name[51] , city[16] , country[16], comma[]=",";
    cout<<"Enter your name: ";
    gets(name);
    strcat(name, comma);
    cout<<"Enter your city: ";
    gets(city);
    strcat(city, comma);
    cout<<"Enter your country: ";
    gets(country);
    cout<<(strcat((strcat(name, city)), country));
    return 0;
}