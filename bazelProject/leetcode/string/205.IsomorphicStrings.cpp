#include "205.IsomorphicStrings.h"
#include <unordered_map>
#include <vector>

bool isIsomorphic(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    unordered_map<char, vector<int>> hashMap;
    unordered_map<char, int> hashFreq;
    for(int i = 0; i < s.size(); ++i) {
        hashMap[s[i]].push_back(i);
    }
    for(const auto & ch : t) {
        ++hashFreq[ch];
    }

    for(auto pIter = hashMap.begin(); pIter != hashMap.end(); ++pIter) {
        char ch = t[pIter->second[0]];
        if(hashFreq[ch] != pIter->second.size()) {
            return false;
        }
        for(const auto & idx : pIter->second) {
            if(t[idx] != ch) {
                return false;
            }
        }
    }

    return true;
}