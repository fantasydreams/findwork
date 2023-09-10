#include "87.ScrambleString.h"
#include <algorithm>
#include <string>
#include <unordered_map>

// 暴力递归
// 这种方法先想出来通用的解法，然后在此基础上进行优化和改进
bool isScramble(string s1, string s2) {
    if(s1 == s2) {
        return true;
    }

    if(s1.size() != s2.size()) {
        return false;
    }
    std::string stmp1 = s1, stmp2 = s2;
    std::sort(stmp1.begin(), stmp1.end());
    std::sort(stmp2.begin(), stmp2.end());
    if(stmp2 != stmp1) {
        return false;
    }

    for(int i = 1; i < s1.size(); ++i) {
        std::string s11 = s1.substr(0, i), s12 = s1.substr(i);
        std::string s21 = s2.substr(0, i), s22 = s2.substr(i);
        if(isScramble(s11, s21) && isScramble(s12, s22)) {
            return true;
        }

        s21 = s2.substr(s2.size() - i);
        s22 = s2.substr(0, s2.size() - i);

        if(isScramble(s11, s21) && isScramble(s12, s22)) {
            return true;
        }
    }

    return false;
}


// 记忆话递归
bool isScrambleMemo(string s1, string s2) {
    static unordered_map<std::string, unordered_map<std::string, bool> > memo;

    if(memo.count(s1) && memo[s1].count(s2)) {
        return memo[s1][s2];
    }
    
    if(s1 == s2) {
        return memo[s1][s2] = true;
    }

    if(s1.size() != s2.size()) {
        return memo[s1][s2] = false;
    }

    std::string stmp1 = s1, stmp2 = s2;
    std::sort(stmp1.begin(), stmp1.end());
    std::sort(stmp2.begin(), stmp2.end());
    if(stmp2 != stmp1) {
        return memo[s1][s2] = false;
    }

    for(int i = 1; i < s1.size(); ++i) {
        std::string s11 = s1.substr(0, i), s12 = s1.substr(i);
        std::string s21 = s2.substr(0, i), s22 = s2.substr(i);
        if(isScrambleMemo(s11, s21) && isScrambleMemo(s12, s22)) {
            return memo[s1][s2] = true;
        }

        s21 = s2.substr(s2.size() - i);
        s22 = s2.substr(0, s2.size() - i);

        if(isScrambleMemo(s11, s21) && isScrambleMemo(s12, s22)) {
            return memo[s1][s2] = true;
        }
    }

    return memo[s1][s2] = false;
}