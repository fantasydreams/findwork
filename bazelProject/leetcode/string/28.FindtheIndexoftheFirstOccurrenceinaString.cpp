#include "28.FindtheIndexoftheFirstOccurrenceinaString.h"
#include <vector>

void getNextArr(const std::string & s, vector<int> & vecNext) {
    if(s.empty()) {
        return;
    }
    vecNext.reserve(s.size());
    vecNext[0] = -1;
    int i = 0, j = -1;
    while(i < s.size() - 1) {
        if(j == -1 || s[i] == s[j]) {
            ++i;
            ++j;
            vecNext[i] = j;
        }else {
            j = vecNext[j];
        }
    }
}


// kmp算法
int strStr(string haystack, string needle) {
    vector<int> vecNext;
    getNextArr(needle, vecNext);
    int i = 0, j = 0;
    while(i < haystack.size()) {
        if(j == -1 || haystack[i] == needle[j]) {
            if(j == needle.size() - 1) {
                return i - j;
            }

            ++i;
            ++j;
        }else {
            j = vecNext[j];
        }
    }
    
    return -1;
}