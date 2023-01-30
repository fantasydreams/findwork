#include "1137.NthTribonacciNumber.h"
#include <vector>

int tribonacci(int n)
{
    std::vector<int> dp(4, 0);
    dp[1] = 1; dp[2] = 1;
    if(n <= 2) {
        return dp[n];
    }
    
    for(int i = 3; i <= n; ++i)  
    {
        dp[3] = dp[0] + dp[1] + dp[2];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];
    }

    return dp[3];
}