#include <iostream>
using namespace std;

void calcDiscount(double&, double, bool);

int main(){
    double price, discount;
    bool percentageOrFixed;
    cout<<"Enter the price of the item: ";
    cin>>price;
    cout<<"Enter 0 to calculate price per discount percentage \nor enter 1 to calculate price per fixed discount: ";
    cin>>percentageOrFixed;
    
    if(percentageOrFixed){

        cout<<"Enter discount amount: ";
        cin>>discount;
    }
    else{
        cout<<"Enter discount percentage: ";
        cin>>discount;
    }

    if(discount < 0){
        return 0;
    }

    calcDiscount(price, discount, percentageOrFixed);
    if(price <= 0){
        return 0;
    }
    cout<<"The price is: "<<price;

}
void calcDiscount(double &price, double disc, bool pof){
    if(pof == 0){
        disc = price*disc/100;
    }
    price -= disc;
}