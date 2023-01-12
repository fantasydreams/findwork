#include "633.SumofSquareNumbers.h"
#include <algorithm>
#include <cmath>

bool judgeSquareSum(int c)
{
    int iSqrt = (int)sqrt(c);
    uint64_t iSum = 0;
    for(int iStart = 0; iStart <= iSqrt; )
    {
        iSum = (uint64_t)iStart * iStart + (uint64_t)iSqrt * iSqrt;
        if(iSum == c){
            return true;
        }
        if(iSum < c){
            ++iStart;
        }else {
            --iSqrt;
        }
    }

    return false;
}

// n^2 = 1 + 3 + 5 + ... + 2(n-1);
bool judgeSquareSum1(int c)
{
    for(uint32_t i = 0; i * i <= c; ++i)
    {
        int j = c - i * i;
        int k = 1, sum = 0;
        while(sum < j)
        {
            sum += k;
            k += 2;
        }

        if(j == sum) {
            return true;
        }
    }

    return false;
}

// 二分
bool binarySearch(long s, long e, long n)
{
    if(s > e) return false;
    
    while(s <= e)
    {
        long mid = s + (e - s) / 2;
        long sum = mid * mid;
        if(sum == n) {
            return true;
        }else if(sum < n) {
            s = mid + 1;
        }else {
            e = mid - 1;
        }
    }
    
    return false;
}

bool binary_search(long s, long e, int n) 
{
    if (s > e)
        return false;
    long mid = s + (e - s) / 2;
    if (mid * mid == n)
        return true;
    if (mid * mid > n)
        return binary_search(s, mid - 1, n);
    return binary_search(mid + 1, e, n);
}
bool judgeSquareSum2(int c)
{
    for(long i = 0; i * i <= c; ++i)
    {
        int j = c - i * i;
        if(binarySearch(0, j, j)) {
            return true;
        }
    }
    return false;
}


