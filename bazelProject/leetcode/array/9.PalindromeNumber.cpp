#include "9.PalindromeNumber.h"

bool isPalindromeByString(int x)
{
    std::string orign = std::to_string(x);
    std::string revert = orign;
    std::reverse(revert.begin(), revert.end());

    return orign == revert ? true : false;
}


bool isPalindrome(int x)
{
    if(x < 0) return false;
    int revert = 0;
    int tmp = x;
    while(tmp)
    {
        if(revert > INT_MAX / 10 || (revert == INT_MAX / 10 && tmp % 10 > 7)){
            return false;
        }
        revert = revert * 10 + tmp % 10;
        tmp /= 10;
    }

    
    return revert == x ? true : false;
}

//进行优化
bool isPalindromeOptimise(int x) 
{
    if(x < 0 || (x !=0 && x %10 == 0))return false;
    int revert = 0;
    while(x > revert){
        revert = revert * 10 + x % 10;
        x /= 10;
    }
    
    return x == revert || x == revert /10;
}