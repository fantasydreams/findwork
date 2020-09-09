//
// Created by Sharwen on 2020/2/3.
//
#include "../../header/offer/pow.h"

#include <cmath>
#include <exception>
using namespace std;
bool equal(double a,double b){
    const double precision = 1e-7;
    if(abs(a-b) < precision){
        return true;
    }else{
        return false;
    }

}

double caculate_UIexponent(double base, unsigned int ex){
    if(ex == 0) return 1;
    if(ex == 1) return base;

    double result = caculate_UIexponent(base,ex >> 1);
    result *= result;
    if(ex & 0x1){
        result *=  base;
    }
    return result;
}

double POW(double base, int exponent){
    if(equal(base,0.0) && exponent == 0) {
        throw new exception;
    }

    bool negativeEx = false;
    unsigned int NewExponent = exponent;
    if(exponent < 0){
        NewExponent = -exponent;
        negativeEx = true;
    }

    double result = caculate_UIexponent(base,NewExponent);
    if(negativeEx){
        result = 1.0/result;
    }

    return result;

}
