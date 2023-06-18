#include <iostream>
using namespace std;
void discountCalculator(double &price, double discount, bool isPercentage);
void output(double price, double discount, bool isPercentage);

int main(){
    double price=1000, discount=20;
    output(1000, 20, true);
    output(1000, 190, false);
    // output(1000, 120, true);  //the discount is greater than the price
    // output(1000, -20, false);  //the discount is negative
    return 0;
}

void discountCalculator(double &price, double discount, bool isPercentage){
    assert(!(discount<0));
    if(isPercentage){
        discount *= (price/100);
    }
    assert(!(discount>=price));
    price -= discount;
}

void output(double price, double discount, bool isPercentage){
    cout<<"\nPrice before discount: "<<price;
    discountCalculator(price, discount, isPercentage);
    cout<<"\nPrice after discount: "<<price<<'\n';
}
