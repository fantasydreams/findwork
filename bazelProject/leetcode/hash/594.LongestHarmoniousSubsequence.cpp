#include "594.LongestHarmoniousSubsequence.h"
#include <unordered_map>

int findLHS(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> hashMap;
    for(const auto & num : nums) {
        ++hashMap[num];
    }

    for(auto [num, freq] : hashMap) {
        auto pIter = hashMap.find(num + 1);
        if(pIter != hashMap.end()) {
            ans = std::max(ans, freq + pIter->second);
        }
    }
    return ans;
}