#include "49.GroupAnagrams.h"
#include <string>
#include <algorithm>
#include <unordered_map>

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > ans;
    unordered_map<std::string, std::vector<std::string> >  mapAnagramVec;
    if(strs.empty()) {
        return ans;
    }

    for(const auto & str : strs) {
        std::string sTmp = str;
        std::sort(sTmp.begin(), sTmp.end());
        mapAnagramVec[sTmp].push_back(str);
    }

    for(const auto & oPair : mapAnagramVec) {
        ans.emplace_back(oPair.second);
    }

    return ans;
}


vector<vector<string> > groupAnagrams1(vector<string>& strs) {
    vector<vector<std::string> > ans;
    if(strs.empty()) {
        return ans;
    }

    unordered_map<std::string, std::vector<std::string> > map;
    for(const auto & str : strs) {
        std::string sTmp = str;
        std::sort(sTmp.begin(), sTmp.end());
        map[sTmp].emplace_back(str);
    }

    for(auto & oPair : map) {
        ans.emplace_back(oPair.second);
    }

    return ans;
}