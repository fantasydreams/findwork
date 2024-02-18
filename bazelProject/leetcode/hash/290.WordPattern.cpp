#include "290.WordPattern.h"
#include <unordered_map>
#include <set>

bool wordPattern(string pattern, string s) {
    if(s.empty() && pattern.empty()) {
        return true;
    }

    if(s.empty() || pattern.empty()) {
        return false;
    }
    std::unordered_map<char, std::vector<int> >HashIdx;
    std::unordered_map<std::string, int> HashFreq;
    std::vector<std::string> vecStrs;
    size_t iPos = 0;
    do {
        auto iSpacePos = s.find(' ', iPos);
        ++HashFreq[s.substr(iPos, iSpacePos - iPos)];
        vecStrs.push_back(s.substr(iPos, iSpacePos - iPos));
        iPos = s.find_first_not_of(' ', iSpacePos);
    }while(iPos != std::string::npos);

    if(vecStrs.size() != pattern.length()) {
        return false;
    }

    for(int i = 0; i < pattern.size(); ++i) {
        HashIdx[pattern[i]].push_back(i);
    }

    for(auto pIter = HashIdx.begin(); pIter != HashIdx.end(); ++pIter) {
        int idx = pIter->second[0];
        const std::string & str = vecStrs[idx];
        if(HashFreq[str] != pIter->second.size()) {
            return false;
        }

        for(const auto i : HashIdx[pattern[idx]]) {
            if(vecStrs[i] != str) {
                return false;
            }
        }
    }

    return true;
}