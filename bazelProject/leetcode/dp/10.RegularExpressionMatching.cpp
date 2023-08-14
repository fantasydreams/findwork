#include "10.RegularExpressionMatching.h"
#include <vector> 

bool isMatch(string s, string p)
{
    std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(p.size() + 1));
    dp[0][0] = true; //s.empty && p.empty

    for(int i = 1; i <= p.size(); ++i)
    {
        if(p[i - 1] == '*' && dp[0][i - 2]) { //类似 s = "", p = "a*"; base case
            dp[0][i] = true;
        }
    }

    for(int i = 1; i <= s.size(); ++i)
    {
        for(int j = 1; j <= p.size(); ++j)
        {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            }if(p[j - 1] == '*')
            {
                if(p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                    dp[i][j] = dp[i][j - 2];
                }else {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                    // 为 * ,s[i - 1] 和 p[j - 1]匹配的情况有三种
                    // (0 1 和 n n > 1) 
                    // 0 s[i - 1] 与 p[j - 3] 是否匹配 dp[i][j - 2];
                    // 1 s[i - 1] 与 p[j - 2] 匹配 如 "a" "a*" dp[i][j - 1];
                    // n s[i - 2] 与 p[j - 1] 匹配 如 "abbb" "ab*" dp[i-1][j]
                }
            }
        }
    }
    return dp[s.size()][p.size()];
}


bool isMatch1(string s, string p) // 2023/ 08 /14
{
    if(s.empty() || p.empty()) {
        return false;
    }

    std::vector<std::vector<int> > dp(s.size() + 1, std::vector<int>(p.size() + 1, false)); // dp[i][j] 表示字符串 s.substr(0, i) 与字符串p.substr(0, j)  是否匹配的问题
    dp[0][0] = true; // base case, 作为计算其他数据的开始
    for(int i = 1; i <= p.size(); ++i) {
        if( p[i - 1] == '*' && dp[0][i-2] ) { // 如果前面匹配了同时存在前面已经匹配了，上一个是p是*，
            dp[0][i] = true;
        }
    }

    for(int i = 1; i <= s.size(); ++i) {
        for(int j = 1; j <= p.size(); ++j) {
            if(p[j - 1] == '.' || p[j - 1] == s[i - 1]) { // 上一个值是.号或者上一个字符相同，则按照之前的匹配情况进行存储
                dp[i][j] = dp[i - 1][j - 1]; // 这里计算的是i,j
            }

            if(p[j - 1] == '*') {
                if(p[j - 2] != s[i - 1] && p[j - 2] != '.') { // 这种情况只能是一个也匹配不上
                    dp[i][j] = dp[i][j - 2];
                }else {
                    dp[i][j] = dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j];
                    // 为 * ,s[i - 1] 和 p[j - 1]匹配的情况有三种
                    // (0 1 和 n n > 1) 
                    // 0 s[i - 1] 与 p[j - 3] 是否匹配 dp[i][j - 2];
                    // 1 s[i - 1] 与 p[j - 2] 匹配 如 "a" "a*" dp[i][j - 1];
                    // n s[i - 2] 与 p[j - 1] 匹配 如 "abbb" "ab*" dp[i-1][j]
                }
            } 
        }
    }

    return dp[s.size()][p.size()];
}