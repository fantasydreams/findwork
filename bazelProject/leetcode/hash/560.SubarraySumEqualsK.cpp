#include "560.SubarraySumEqualsK.h"
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>

int subarraySum(vector<int>& nums, int k) {
    int ans = 0, cSum = 0;
    unordered_map<int, int> hash_map;
    hash_map[0] = 1;

    for(const auto num : nums) {
        cSum += num;
        if(hash_map.count(cSum - k)) {
            ans += hash_map[cSum - k];
        }
        ++hash_map[cSum];
    }

    return ans;
}

int subarraySum1(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, set<int>> hash_map;
    // hash_map[0].insert(0);

    int sum = 0;
    std::vector<int> mSum(nums.size() + 1, 0);
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        hash_map[sum].insert(i);
        mSum[i + 1] = sum;
    }

    for(int i = 0; i < mSum.size(); ++i) {
        if(hash_map.count(mSum[i] + k)) {
            auto & oSet = hash_map[mSum[i] + k];
            while(!oSet.empty() && (*oSet.begin() < ((k == 0) ? i : i - 1))) {
                oSet.erase(oSet.begin());
            }
            ans += oSet.size();
        }
    }

    return ans;
}
