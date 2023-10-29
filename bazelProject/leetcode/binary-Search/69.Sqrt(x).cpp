#include "69.Sqrt(x).h"
#include <cmath>
#include <cstdint>

int mySqrt(int x)
{
    int l = 0, r = x;
    uint64_t sum = 0;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        sum = (uint64_t)mid * mid;
        if(sum == x) {
            return mid;
        }

        if(sum < x) {
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }
    
    sum = (uint64_t)l * l;
    if(sum > x)  {
        return l - 1;
    }
    return l;
}

int mySqrt1(int x)
{
    if(!x) return x;
    int l = 1, r = x, mid, sqrt;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        sqrt = x / mid;
        if(sqrt == mid) {
            return mid;
        }else if(sqrt < mid) {
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    return r;
}

int mySqrt2(int x)
{
    int64_t res = x;
    while(res * res > x)  {
        res = (res + x / res) / 2;
    }
    return res;
}

// 牛顿法
// https://www.zhihu.com/question/20690553
// https://www.cnblogs.com/Allen-rg/p/13602550.html
double sqr(double n) { 
     double k=1.0;
     while(abs(k*k-n)>1e-9) { 
         k=(k+n/k)/2; 
     } 
     return k; 
}

int mySqrt3(int x) {
    return pow(x, 0.5);
}