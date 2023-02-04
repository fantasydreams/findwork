#include "10.RegularExpressionMatching.h"
#include <vector> 

bool isMatch(string s, string p)
{
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(p.size() + 1));
    dp[0][0] = true; //s.empty && p.empty

    for(int i = 1; i <= p.size(); ++i)
    {
        if(p[i - 1] == '*' && dp[0][i - 2]) { //类似 s = "", p = "a*"; base case
            dp[0][i] = true;
        }
    }

    for(int i = 1; i <= s.size(); ++i)
    {
        for(int j = 1; j <= p.size(); ++j)
        {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }if(p[j - 1] == '*')
            {
                if(p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                }else {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                    // 为 * ,s[i - i] 和 p[j - 1]匹配的情况有三种
                    // (0 1 和 n n > 1) 
                    // 0 s[i - 1] 与 p[j - 3] 是否匹配 dp[i][j - 2];
                    // 1 s[i - 1] 与 p[j - 2] 匹配 如 "a" "a*" dp[i][j - 1];
                    // n s[i - 2] 与 p[j - 1] 匹配 如 "abbb" "ab*" dp[i-1][j]
                }
            }
        }
    }
    return dp[s.size()][p.size()];
}
