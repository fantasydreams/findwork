#include "115.DistinctSubsequences.h"
#include <algorithm>
#include <vector>

// reference 
// https://www.google.com.hk/search?q=leetcode+115&oq=leetcode+115&aqs=chrome..69i57j0i512l9.2457j0j1&sourceid=chrome&ie=UTF-8#fpstate=ive&ip=1&vld=cid:9b1d090f,vid:mPqqXh8XvWY,st:0
int numDistinct(string s, string t) {
    std::vector<std::vector<uint32_t> > dp(t.size() + 1, std::vector<uint32_t> (s.size() + 1, 0));
    std::fill(begin(dp[0]), end(dp[0]), 1);

    for(int i = 1; i <= t.size(); ++i) {
        for(int j = 1; j <= s.size(); ++j) {
            dp[i][j] = dp[i][j - 1] + ((t[i - 1] == s[j - 1]) ? dp[i - 1][j - 1] : 0);
        }
    }

    return dp[t.size()][s.size()];
}