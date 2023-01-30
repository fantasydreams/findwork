#include "279.PerfectSquares.h"
#include <vector>
#include <cmath>

int solve(std::vector<int> & list, int n)
{
    if(n < 0) {
        return 0;
    }

    if(n == 0 || n == 1) {
        return n;
    } 

    int _min = n;
    for(const auto & num : list) 
    {
        if(n - num * num < 0) {
            continue;
        }
        _min = std::min(_min, solve(list, n - num * num) + 1);
    }

    return _min;
}

int numSquares(int n)
{
    if(n < 0) {
        return 0;
    }
    if(n <= 1) {
        return n;
    }

    std::vector<int> list;
    for(int i = 1; i <= sqrt(n); ++i) {
        list.push_back(i);
    }

    return solve(list, n);
}



int numSquares1(int n)
{
    if(n < 0) {
        return 0;
    }
    if(n <= 1) {
        return n;
    }

    std::vector<int> dp(n + 1, n);
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= sqrt(i); ++j) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }

    return dp[n];
}