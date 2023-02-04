#include "650.2KeysKeyboard.h"
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>

int minSteps(int n)
{
    if(n < 0) {
        return 0;
    }
    
    std::vector<int> dp(n + 1, n);
    dp[0] = 0; dp[1] = 0;

    int sq = sqrt(n);
    for(int i = 2; i <= n; ++i)
    {
        dp[i] = i;
        for(int j = i - 1; j > 1; --j) // 直接考虑前j个字符
        {
            if((i % j) == 0) 
            {
                dp[i] = dp[j] + i / j;
                break;
            }
        }
    }

    return dp[n];
}

//找质因子
// 12 -> 6 -> 3
// 18 -> 9 -> 3 ，找到约数就粘贴复制，如果没有遇到就说需要粘贴
int minSteps1(int n)
{
    if(n < 0) {
        return 0;
    }
    
    int ans = 0;
    while(n > 1)
    {
        for(int i = 2; i <= n; ++i) 
        {
            if(n % i == 0) 
            {   
                ans += 2;
                n /= i;    
                break;
            }
            ++ans;
        }
    }

    return ans;
}

int minSteps2(int n)
{
    if(n < 0) {
        return 0;
    }
    
    int ans = 0;
    while(n > 1)
    {
        for(int i = 2; i <= n; ++i) 
        {
            if(n % i == 0) 
            {   
                ans += i;
                n /= i;
                break;
            }
        }
    }

    return ans;
}