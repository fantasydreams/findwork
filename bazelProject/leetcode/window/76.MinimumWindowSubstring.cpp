#include "76.MinimumWindowSubstring.h"
#include <climits>

string minWindow(string s, string t) {
    std::vector<int> vecWindow(128, 0);
    for(const auto& ch : t) {
        ++vecWindow[ch];
    }

    int left = 0, start = 0, minLen = INT_MAX, inWinCnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(vecWindow[s[i]]-- > 0) {
            ++inWinCnt;
        }

        while(inWinCnt == t.size()) {
            if(i - left + 1 < minLen) {
                minLen = i - left + 1;
                start = left;
            }

            if(++vecWindow[s[left++]] > 0) {
                --inWinCnt;
            }
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

string minWindow1(string s, string t)  {
    std::vector<int> vecHash(128, 0);
    int iMinLen = INT_MAX, iStartIdx = -1;
    int iLeft = 0, iInWinCnt = 0;

    for(const auto & ch : t) {
        ++vecHash[ch];
    }

    for(int i = 0; i < s.size(); ++i) {
        if(vecHash[s[i]]-- > 0) {
            ++iInWinCnt;
        }

        while(iInWinCnt == t.size()) {
            int iLen = i - iLeft + 1;
            if(iLen < iMinLen) {
                iMinLen = iLen;
                iStartIdx = iLeft;
            }

            if(++vecHash[s[iLeft++]] > 0) {
                --iInWinCnt;
            }
        }
    }

    return iStartIdx == -1 ? "" : s.substr(iStartIdx, iMinLen);
}