#include "219.ContainsDuplicateII.h"
#include <unordered_map>

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    std::unordered_map<int, int> unMap;
    for(int i = 0; i < nums.size(); ++i) {
        auto pIter = unMap.insert({nums[i], i});
        if(pIter.second == false) {
            if(i - pIter.first->second <= k) {
                return true;
            }else {
                pIter.first->second = i;
            }
        }
    }    
    return false;
}