#include "139.WordBreak.h"
#include <unordered_set>
#include <vector>

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


// https://liweiwei1419.github.io/leetcode-solution-blog/leetcode-problemset/dynamic-programming/0139-word-break.html#%E6%96%B9%E6%B3%95%EF%BC%9A%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92
bool wordBreakDp(string s, vector<string>& wordDict) {
    if(s.empty()) {
        return false;
    }

    unordered_set<std::string> hash(wordDict.begin(), wordDict.end());
    std::vector<bool> dp(s.size(), false);
    for(int i = 0; i < s.size(); ++i) {
        std::string tmp = s.substr(0, i + 1);
        if(hash.count(tmp)) {
            dp[i] = true;
            continue;
        }
        for(int l = 0; l < i; ++l) {
            if(dp[l] && hash.count(s.substr(l + 1, i - l))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size() - 1];
}


bool wordBreakDp1(string s, vector<string>& wordDict) {
    if(s.empty()) {
        return false;
    }

    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for(int i = 0; i <= s.size(); ++i) {
        for(const auto& str : wordDict) {
            if(i < str.size()) {
                continue;
            }

            if(!dp[i] && s.substr(i - str.size(), str.size()) == str) {
                dp[i] = dp[i - str.size()];
            }
        }
    }

    return dp[s.size()];
} 