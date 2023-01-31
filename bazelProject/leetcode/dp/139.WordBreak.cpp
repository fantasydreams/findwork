#include "139.WordBreak.h"

bool wordBreak(string s, vector<string>& wordDict)
{
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for(int i = 1; i <= s.size(); ++i)
    {
        for(const auto & word : wordDict)
        {
            if((i - (int)word.length()) < 0) {
                continue;
            }

            if(s.substr(i - (int)word.length(), word.length()) == word) {
                dp[i] = dp[i] || dp[i - word.length()];
            }
        }
    }

    return dp[s.size()];
}