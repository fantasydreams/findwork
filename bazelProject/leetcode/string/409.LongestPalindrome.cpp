#include "409.LongestPalindrome.h"
#include <unordered_map>

int longestPalindrome(string s) {
    int ans = 0;
    unordered_map<char, int> hash;
    for(const auto & ch : s) {
        ++hash[ch];
    }
    
    int single = 0;
    for(const auto & [key, cnt] : hash) {
        if(cnt & 0x1) { //这里可以考虑的是，奇数的可以保留偶数个放进去，最后如果存在奇数的数量，则加1
            single = 1;
            ans += (cnt - 1);
        }else {
            ans += cnt;
        }
    }
    return ans + single;
}