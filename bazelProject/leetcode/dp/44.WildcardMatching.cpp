#include "44.WildcardMatching.h"
#include <vector>

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