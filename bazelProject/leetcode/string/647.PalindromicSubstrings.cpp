#include "647.PalindromicSubstrings.h"

int countSubstrings(const string & s, int l, int r) {
    int cnt = 0;
    while(l >=0 && r <= s.size() && s[l] == s[r]) {
        --l;
        ++r;
        ++cnt;
    }

    return cnt;
}

int countSubstrings(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        ans += countSubstrings(s, i, i);
        ans += countSubstrings(s, i, i + 1);
    }

    return ans;
}

