#include "392.IsSubsequence.h"

bool isSubsequence(string s, string t) {
    if(s.length() > t.length()) {
        return false;
    }

    int iIdx = 0;
    for(int i = 0; i < t.size() && iIdx < s.size(); ++i) {
        if(t[i] == s[iIdx]) {
            ++iIdx;
        }
    }
    return iIdx == s.size();
}