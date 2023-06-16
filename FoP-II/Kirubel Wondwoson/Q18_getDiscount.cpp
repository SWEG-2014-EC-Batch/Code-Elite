#include<iostream>
using namespace std;
void getDiscount(double &price , double discount , bool percentage);
int main()
{
    double price , discount;bool percentage;
    cout<<"Enter the price : ";
    cin>>price;
    cout<<"Enter the discount : ";
    cin>>discount;
    if(discount >= price || price < 0 || discount < 0){
        cout<<"Invalid input";
    }
    getDiscount(price , discount , percentage);
    return 0;
}
void getDiscount(double &price , double discount , bool percentage)
{
    cout<<"Enter 0 if the discount you entered is fixed amount , any other number if it is percentage : ";
    cin>>percentage;
    if(percentage == true){
      //pecentage discount
        price = price - (price/discount);
        cout<<price;
    }
    else if(percentage == false){        
    // fixed amount discount
    price -= discount;
    cout<<price;
    }
}