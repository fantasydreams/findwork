#include "696.CountBinarySubstrings.h"

int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, cnt = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == s[i - 1]) {
            ++cur;
        }else {
            pre = cur;
            cur = 1;
        }

        if(pre >= cur) {
            ++cnt;
        }
    }
    return cnt;
}