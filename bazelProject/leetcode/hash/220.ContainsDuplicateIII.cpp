#include "220.ContainsDuplicateIII.h"
#include <algorithm>
#include <set>
#include <unordered_map>
// 滑动窗口 + 有序集合
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    if(nums.size() <= 1) {
        return false;
    }

    std::set<int64_t> sets;
    for(int i = 0 ; i < nums.size(); ++i) {
        auto pIter = sets.lower_bound((int64_t)nums[i] - valueDiff);
        if(pIter != sets.end() && *pIter <= ((int64_t)nums[i] + valueDiff)) {
            return true;
        }
        sets.insert(nums[i]);
        if(i >= indexDiff) {
            sets.erase(nums[i - indexDiff]);
        }
    }

    return false;
}





// 桶排序   

inline int GetBucketId(int iNum, int64_t iWindows) {
    return iNum < 0 ? (iNum) / iWindows - 1 : iNum / iWindows;
}

bool containsNearbyAlmostDuplicateBuckets(vector<int>& nums, int indexDiff, int valueDiff) {
    if(nums.size() <= 1) {
        return false;
    }

    std::unordered_map<int, int> bucket;
    for(int i = 0; i < nums.size(); ++i) {
        int iBucketId = GetBucketId(nums[i], valueDiff + 1ll);
        if(bucket.count(iBucketId)) {
            return true;
        }

        auto pIterLeftNe = bucket.find(iBucketId - 1);
        if(pIterLeftNe != bucket.end() && abs(pIterLeftNe->second - nums[i]) <= valueDiff) {
            return true;
        }
        
        auto pIterRifht = bucket.find(iBucketId + 1);
        if(pIterRifht != bucket.end() && abs(pIterRifht->second - nums[i]) <= valueDiff) {
            return true;
        }

        bucket[iBucketId] = nums[i];
        if(i >= indexDiff) {
            bucket.erase(GetBucketId(nums[i - indexDiff], valueDiff + 1ll));
        }
    }

    return false;
}