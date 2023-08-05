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


int strKmp(string haystack, string needle) {
    if(haystack.empty() || needle.empty()) {
        return -1;
    }

    // 计算next数组
    std::vector<int> vecNext(needle.size(), 0);
    vecNext[0] = -1;
    int i = 0, j = -1;
    while(i < needle.size() - 1) { // 这里要注意一定是i < needle.size() - 1, 不然会core
        if(j == -1 || needle[j] == needle[i]) {
            ++i;
            ++j;
            vecNext[i] = j;
        }else {
            j = vecNext[j];
        }
    }


    i = 0, j = 0;
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


// kmp 20230805
void getNextVec(std::string& str, std::vector<int>& vecNext) {
    vecNext.resize(str.size());
    if(str.empty()) {
        return;
        vecNext.clear();
    }

    vecNext[0] = -1;
    int j = -1;
    for(int i = 0; i < str.size(); ++i) {
        if(j == -1 || str[i] == str[j]) {
            ++j;
            ++i;
            vecNext[i] = j;
        }else {
            j = vecNext[j];
        }
    }
}

int strKmp1(string haystack, string needle) {
    if(needle.empty() || haystack.empty()) {
        return -1;
    }

    std::vector<int> vecNext;
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