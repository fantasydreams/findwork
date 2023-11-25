#include "214.ShortestPalindrome.h"
#include <algorithm>

string shortestPalindrome(string s) {
    std::string sReverse = s;
    std::reverse(sReverse.begin(), sReverse.end());
    int pos = -1;
    for(int i = s.size(); i > 0; --i) {
        if(s.substr(0, i) == sReverse.substr(sReverse.size() - i, i)) {
            pos = i;
            break;
        }
    }

    std::string sAns;
    if(pos < s.size()) {
        sAns += s.substr(pos, s.size() - pos);
        std::reverse(sAns.begin(), sAns.end());
    }
    sAns += s;
    return sAns;
}


string shortestPalindromeDp(string s) {
    std::vector<std::vector<bool> > dp(s.size(), std::vector<bool>(s.size(), false));
    for(int i = 0; i < s.size(); ++i)
    {
        dp[i][i] = true;
        if(i + 1 < s.size()) {
            dp[i][i + 1] = (s[i] == s[i + 1]); // 偶数的情况
        }
    }

    int len = 0;
    for(int j = 0; j < s.size(); ++j) {
        for(int i = j; i >= 0; --i) {
            if(i == j) {
                dp[i][i] = true;
            }else if(i + 1 == j) {
                dp[i][j] = s[i] == s[j];
            }else{
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
            }

            if(dp[i][j] && (i == 0 && j - i + 1 > len)) {
                len = j - i + 1;
            }
        }
    }

    // printf("len = %d\n", len);
    std::string sAns;
    if(len < s.size()) {
        std::string sTmp = s.substr(len, s.size() - len);
        std::reverse(sTmp.begin(), sTmp.end());
        sAns += sTmp;
    }

    sAns += s;
    return sAns;
}



// 双指针

int GetIndex(int i, int j, const std::string& str) {
    while(j >= 0) {
        if(str[i] == str[j]) {
            ++i;
        }
        --j;
    }
    return i;
}

string shortestPalindromeDoublePointer(string s) {
    int i = s.size();
    while(true) {
        i = GetIndex(0, i - 1, s);
        std::string sTmp = s.substr(0, i);
        std::string sRe(sTmp.rbegin(), sTmp.rend());
        if(sTmp == sRe) {
            break;
        }
    }

    std::string sAns;
    if(i < s.size()) {
        std::string sTmp = s.substr(i, s.size() - i);
        std::reverse(sTmp.begin(), sTmp.end());
        sAns = std::move(sTmp);
    }
    sAns += s;
    return sAns;
} 


// 马拉车算法
string shortestPalindromeManacher(string s) {
    // printf("12\n");
    std::string tmp = "$";
    for(const auto & ch : s) {
        tmp += "#";
        tmp += ch;
    }
    tmp += "#@";
    // printf("123\n");
    std::vector<int> vecMa(tmp.size(), 0);
    int iCenter = 0, curR = 0, maxCenter = 0, maxR = 0, last;
    int zeroMaxR = 0;
    for(int i = 1;i < tmp.size() - 1; ++i) {
        last = iCenter + curR;
        if(last > i) {
            vecMa[i] = std::min(last - i, vecMa[2 * iCenter - i]);
        }

        while(tmp[i - vecMa[i] - 1] == tmp[i + vecMa[i] + 1]) {
            ++vecMa[i];
        }

        if(vecMa[i] > maxR) {
            maxCenter = i;
            maxR = vecMa[i];

            if((maxCenter - maxR) / 2 == 0) {
                zeroMaxR = maxR;
            }
        }

        if(i + vecMa[i] > last) {
            iCenter = i;
            curR = vecMa[i];
        }
    }

    // printf("1234\n");
    std::string sAns;
    if(zeroMaxR < s.size()) {
        std::string sTmp = s.substr(zeroMaxR, s.size() - zeroMaxR);
        std::reverse(sTmp.begin(), sTmp.end());
        sAns = sTmp;
    }
    sAns += s;
    return sAns;
}