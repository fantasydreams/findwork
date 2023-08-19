#include "49.GroupAnagrams.h"
#include <string>
#include <algorithm>

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