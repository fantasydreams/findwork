#include "70.ClimbingStairs.h"
#include <vector>

int climbStairs(int n)
{
    std::vector<int> dp(3, 0);
    dp[1] = 1;
    dp[2] = 2;
    // dp[i] = dp[i-1] + dp[i-2]
    if(n == 1 || n ==2) {
        return dp[n];
    }

    for(int i = 2; i <n; ++i) 
    {
        dp[0] = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = dp[0];
    }
    return dp[0];
}

int climbStairsDp(int n) {
    std::vector<int> dp(3, 0);
    dp[1] = 1; dp[2] = 2;
    if (n <= 2) {
        return dp[n];
    }

    for(int k = 3; k <=n; ++k) {
        dp[0] = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = dp[0];
    }

    return dp[0];
}