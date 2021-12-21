#include "231.PowerofTwo.h"


//暴力
bool isPowerOfTwo(int n)
{
    if(n <= 0) return false;
    while(n)
    {
        if(n % 2 == 1 && n != 1){
            return false;
        }
        n/=2;
    }
    return true;
}

/*
bit 运算

- 对于是2的幂次 如
    4 = 100，而4-1 = 3 = 011  4 & 3 = 0
    8 = 1000, 而8-1 = 7 = 0111 8 & 7 = 0
    ...
    2^n 在int32中，一定是32bit中的任意一位d是1，2^n-1 则d位为0，其他的全部为1，即2^31 & 2 ^31 - 1 = 0

- 对于不是2的幂次a，可以看作
2^n + b = a，即对于任意a在31bit中bit为1的数量大于等于2，则a-1 = b + (2^n - 1)，当a & (a-1)时，b所占据的1不会改变，因此
a & a-1 = 2^n > 0 

因此有了结论 
*/
 

bool isPowerOfTwo1(int n)
{
    return n > 0 && (!(n & (n - 1)));
}