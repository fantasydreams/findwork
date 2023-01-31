#include "1143.LongestCommonSubsequence.h"
#include <vector>

int longestCommonSubsequence(string text1, string text2)
{
    if(text1.size() == 0 || text2.size() == 0) {
        return 0;
    }

    std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    //重要的是这种思路，dp[i][j]表示第一个字符串0-i与第二个字符串0-j的最长公共子串
    for(int i = 1; i <= text1.size(); ++i)
    {
        for(int j = 1; j <= text2.size(); ++j)
        {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}