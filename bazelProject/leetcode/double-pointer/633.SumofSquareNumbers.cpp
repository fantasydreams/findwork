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