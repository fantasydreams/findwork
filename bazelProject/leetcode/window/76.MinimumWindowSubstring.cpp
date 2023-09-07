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