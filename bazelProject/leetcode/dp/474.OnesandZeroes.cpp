#include "474.OnesandZeroes.h"

std::pair<int, int> count(const string & str)
{
    int one = 0;
    for(const auto & ch : str){
        one += (ch == '1');
    }
    return {str.size() - one, one};
}

int findMaxForm(vector<string>& strs, int m, int n)
{
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for(const auto & str : strs)
    {
        auto [zero, one] = count(str);
        for(int i = m; i >= zero; --i)
        {
            for(int j = n; j >= one; --j) {
                dp[i][j] = std::max(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
    }

    return dp[m][n];
}