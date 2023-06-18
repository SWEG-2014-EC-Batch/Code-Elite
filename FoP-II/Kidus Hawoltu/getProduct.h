#ifndef GETPRODUCT_H
#define GETPRODUCT_H

#include "welcomeMsg.h"
double getProduct(int num1 , double num2){
    double product;
    product = double(num1) * num2;
    welcomeMsg();
    return product;
}

#endif