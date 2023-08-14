#include "44.WildcardMatching.h"
#include <vector>

// https://wulc.me/2016/10/23/LeetCode%E8%A7%A3%E9%A2%98%E6%8A%A5%E5%91%8A(10,%2044)--%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E7%9A%84%E5%8C%B9%E9%85%8D%E4%B8%8E%E9%80%9A%E9%85%8D%E7%AC%A6%E7%9A%84%E5%8C%B9%E9%85%8D/
bool isMatch(string s, string p) {
    std::vector<std::vector<bool> > dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
    dp[0][0] = true;
    for(int j = 1; j <= p.size(); ++j) {
        if(p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for(int i = 1; i <= s.size(); ++i) {
        for(int j = 1; j <= p.size(); ++j) {

            if(p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            

            if(p[j - 1] == '*') {
                    // 前面的已经匹配，*号不匹配任何值 // 前面的已经匹配，*号延长 1个或者多个 
                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
            }
        }
    }

    return dp[s.size()][p.size()];
}