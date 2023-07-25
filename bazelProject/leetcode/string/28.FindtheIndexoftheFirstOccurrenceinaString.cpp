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


int strStr1(string haystack, string needle) {
    // int idx = haystack.find_first_of(needle);
    int idx = haystack.find(needle); // 需要注意的是 find和find_first_of， find_first_of(const char* ptr) 只要ptr中任意字符在原串中出现就返回那个字符在原串中的位置
    return idx;
}