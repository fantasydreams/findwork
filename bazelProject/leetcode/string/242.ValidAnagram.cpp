#include "242.ValidAnagram.h"
#include <vector>

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    vector<int> hash(26, 0);
    for(const auto & ch : s) {
        ++hash[ch - 'a'];
    }

    for(const auto & ch : t) {
        --hash[ch - 'a'];
    }

    for(const auto & freq : hash) {
        if(freq != 0) {
            return false;
        }
    }

    return true;
}


bool isAnagram1(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    vector<int> hash(26, 0);
    for(const auto & ch : s) {
        ++hash[ch - 'a'];
    }

    for(const auto & ch : t) {
        if(--hash[ch - 'a'] < 0) {
            return false;
        };
    }

    return true;
}

bool isAnagram2(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    vector<int> hash(128, 0);
    for(const auto & ch : s) {
        ++hash[ch];
    }

    for(const auto & ch : t) {
        if(--hash[ch] < 0) {
            return false;
        }
    }

    return true;
}