#include "50.Powx.n.h"
#include <climits>

double myPow(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    if(n < 0) {
        if(n == INT_MIN) { 
            x = 1.0 / x;
            
            double tmp = myPow(x * x, INT_MAX / 2); 
            return tmp * x * x;

            // return myPow(x * x, INT_MAX / 2 + 1);

            // 保证指数一致就可以
            // 也可以写作
            // double tmp = myPow(x * x, (INT_MAX - 1) / 2); 
            // return tmp * x * x;
        }else {
            n = -n;
            x = 1.0 / x;
        }
    }
    
    double tmp = myPow(x * x, n / 2);
    return n & 0x1 ? tmp * x : tmp;
}


// 对于符号反转的一定要注意overflow！！！

double myPow2(double x, long long n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    if(n < 0) {
        n = -n;
        x = 1.0 / x;
    }
    
    double tmp = myPow(x * x, n / 2);
    return n & 0x1 ? tmp * x : tmp; 
}

double myPowx(double x, int n) {
    return myPow2(x, n);
}