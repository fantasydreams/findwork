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


bool isIsomorphic1(string s, string t) {
    if(s.size() != t.size()) {
        return false;
    }

    std::unordered_map<char, std::vector<int> >hashMap;
    std::unordered_map<char, int> hashFreq;
    for(int i = 0; i < s.size(); ++i) {
        hashMap[s[i]].push_back(i);
    }

    for(const char ch : t) {
        ++hashFreq[ch];
    }

    for(auto pIter = hashMap.begin(); pIter != hashMap.end(); ++pIter) {
        char ch = t[pIter->second[0]];
        if(pIter->second.size() != hashFreq[ch]) {
            return false;
        }

        for(const auto idx : pIter->second) {
            if(t[idx] != ch) {
                return false;
            }
        }
    }

    return true;
}


bool isIsomorphic2(string s, string t) {
    if(s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, std::vector<int> > hashIdx;
    std::unordered_map<char, int> hashFreq;
    for(int i = 0; i < s.length(); ++i) {
        hashIdx[s[i]].push_back(i);
    }
    for(const auto & ch : t) {
        ++hashFreq[ch];
    }

    for(auto pIter = hashIdx.begin(); pIter != hashIdx.end(); ++pIter) {
        auto ch = t[pIter->second[0]];
        if(hashFreq[ch] != pIter->second.size()) {
            return false;
        }

        for(int i = 0; i < pIter->second.size(); ++i) {
            if(ch != t[pIter->second[i]]) {
                return false;
            }
        }
    } 
    return true;
}