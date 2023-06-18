#include<iostream>
#include<cstdlib>
using namespace std;
double discountappli(double price, double discount, bool indicate);
int main()
{
    double nprice, ndiscount;
    bool nindicate;
    cout << "enter the price of an item: ";
    cin >> nprice;
    cout << "enter 1 for fixed discount amount or enter 0 for percentage discount amount: ";
    cin >> nindicate;
    if (nindicate)
    {
        retray:
        cout << "enter the fixed discount on the item: ";
        cin >> ndiscount;
        if (ndiscount < 0)
        {
            cout << "errrrror!!!, discount can not be negative, try again" << endl;
            goto retray;
        }
    }
    else
    {
        retray1:
        cout << "enter the percentage amount for discount on the item: ";
        cin >> ndiscount;
        if (ndiscount < 0)
        {
            cout << "errrrror!!!, discount can not be negative, try again" << endl;
            goto retray1;
        }
    }
    if (nprice <= ndiscount)
    {
        cout << "errrrror!!!,discount can not be more than price, try again";
        exit(-1);
    }
    cout<<discountappli(nprice, ndiscount, nindicate);
    return 0;
}
double discountappli(double price, double discount, bool indicate)
{
    double price2, discount2;
    if (indicate)
    {
        price2 = price - discount;
        return price2;
    }
    else
    {
        discount2 = price * discount;
        price2 = price - discount2;
        return price2;
    }   
}
