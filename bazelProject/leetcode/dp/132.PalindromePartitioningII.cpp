#include "132.PalindromePartitioningII.h"
#include <climits>

void GetMinCut(const std::string& s, std::vector<std::vector<bool> >& dp, int start, int& ans, int curCut) {
    if(start >= s.size()) {
        ans = std::min(ans, curCut - 1);
        return;
    }

    for(int end = start; end < s.size(); ++end) {
        if((s[start] == s[end]) && ((end - start <= 2) || (start + 1 < s.size() && end - 1 >= 0 && dp[start + 1][end - 1]))) {
            dp[start][end] = true;
            GetMinCut(s, dp, end + 1, ans, curCut + 1);
        }
    }
}

int minCut(string s) {
    if(s.empty()) {
        return 0;
    }
    
    int ans = INT_MAX, curCut = 0;
    std::vector<std::vector<bool> >dp(s.size(), std::vector<bool>(s.size(), false));
    GetMinCut(s, dp, 0, ans, curCut);
    return ans;
}