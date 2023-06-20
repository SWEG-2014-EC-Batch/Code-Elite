

#include <iostream>
#include <string.h>
using namespace std;

void getcu(double a[5] ) {
    for (int i = 0; i < 5; ++i) {
        cout << "enter the currents\n";
        cin >> a[i];
    }

}
void powe(double res[5],double b[5],double c[5]) {
    
    for (int i = 0; i < 5; ++i) {
        c[i] = res[i] * pow(b[i], 2);
    }
}
void display(double r[5], double c[5], double p[5],double s[3]) {
   
    for (int i = 0; i < 5; i++) {
       
        cout << r[i] << "  " << c[i] << "  " << p[i] << endl;
        
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {

       // cout << r[i] << "  " << c[i] << "  " << p[i] << endl;
        cout << s[i] << "  ";
    }
    cout << endl;

}
double caltotal(double arr[5]) {
    double sum=0;
    for (int i = 0; i < 5; ++i) {
        sum =sum+arr[i];

    }
    return sum;
}
int main()
{
    double r[] = { 16,27,39,56,81 };
    //double curr[5], power[5];
    double c[5];
    double p[5];
    
    getcu(c);
    powe(r, c, p);
    double s[3] = { caltotal(r),caltotal(c) ,caltotal(p) };
   
    display(r, c, p,s);

    
}
