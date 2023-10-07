#include "125.ValidPalindrome.h"
#include <algorithm>
#include <cctype>

bool isPalindrome(string s) {
    int b = 0, e = s.size() - 1;
    while(b < e) {
        while(b < e && (!isalpha(s[b]) && !isalnum(s[b]))) {
            // printf("%c\n", s[b]);
            ++b;
        }
        while(b < e && (!isalpha(s[e]) && !isalnum(s[e]))) {
            // printf("%c\n", s[e]);
            --e;
        }
        if(b >= e) {
            return true;
        }

        s[b] = std::tolower(s[b]);
        s[e] = std::tolower(s[e]);
        if(s[b++] != s[e--]) {
            return false;
        }
    }

    return true;
}