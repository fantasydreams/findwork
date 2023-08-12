#include "32.LongestValidParentheses.h"
#include <vector> 

// https://zhuanlan.zhihu.com/p/110240060

int longestValidParentheses(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != '(') {
            continue;
        }

        int cntL = 0, cntR = 0;
        for(int j = i; j < s.size(); ++j) {
            if(s[j] == '(') {
                ++cntL;
            }else if(s[j] == ')') {
                ++cntR;
            }

            if(cntR > cntL) {
                break;
            }

            if(cntL == cntR) {
                ans = std::max(ans, 2 * cntL);
            }
        }
    }

    return ans;
}



int getLongestValidParentheses(const std::string& s, char ch, bool bReverse = false) {
    int cntL = 0, cntR = 0, ans = 0;
    int start = bReverse ? s.size() - 1 : 0;
    int end = bReverse ? -1 : s.size();
    int step = bReverse ? -1 : 1;

    while(start != end) {
        if(s[start] == ch) {
            ++cntL;
        }else {
            ++cntR;
            if(cntR > cntL) {
                cntL = cntR = 0;
            }else if(cntL == cntR) {
                ans = std::max(ans, 2 * cntL);
            }
        }
        start = start + step;
    }

    return ans;
}

int longestValidParentheses1(string s) {
    return std::max(getLongestValidParentheses(s, '('), getLongestValidParentheses(s, ')', true));
}


int longestValidParenthesesDp(string s) {
    std::vector<int> dp(s.size(), 0);
    int ans = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == ')') {
            if(s[i - 1] == '(') {
                dp[i] += 2;
                if(i - 2 >= 0) {
                    dp[i] += dp[i - 2];
                }
            }else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] += 2 + dp[i - 1];
                if(i - dp[i - 1] - 2 >= 0) {
                    dp[i] += dp[i - dp[i - 1] - 2];
                }
            }
        }

        ans = std::max(ans, dp[i]);
    }
    return ans;
}