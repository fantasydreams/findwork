#include "97.InterleavingString.h"
#include <vector>

bool isInterleave(string s1, string s2, string s3) {
    if(s1.length() + s2.length() != s3.length()) {
        return false;
    }

    std::vector<std::vector<bool> > dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));
    dp[0][0] = true;
    for(int i = 1; i <= s1.size() && dp[i - 1][0]; ++i) {
        if(s1[i - 1] == s3[i - 1]) {
            dp[i][0] = true;
        }
    }

    for(int i = 1; i <= s2.size() && dp[0][i - 1]; ++i) {
        if(s2[i - 1] == s3[i - 1]) {
            dp[0][i] = true;
        }
    }

    for(int i = 1; i <= s1.size(); ++i) {
        for(int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
        }
    }

    return dp[s1.size()][s2.size()];
}

bool isInterleave1(string s1, string s2, string s3) {
    if(s1.length() + s2.length() != s3.length()) {
        return false;
    }

    std::vector<std::vector<bool> > dp(s1.size() + 1, std::vector<bool>(s2.size() + 1));
    dp[0][0] = true;
    for(int i = 1; i <= s1.size() && dp[i - 1][0]; ++i) {
        if(s1[i - 1] == s3[i - 1]) {
            dp[i][0] = true;            
        }
    }

    for(int i = 1; i <= s2.size() && dp[0][i - 1]; ++i) {
        if(s2[i - 1] == s3[i - 1]) {
            dp[0][i] = true;
        }
    }

    for(int i = 1; i <= s1.size(); ++ i) {
        for(int j = 1; j <= s2.size(); ++j) {
            dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
        }
    }

    return dp.back().back();
}