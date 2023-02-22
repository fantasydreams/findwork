#include "494.TargetSum.h"
#include <unordered_map>

void findTargetSumWays(vector<int>& nums, int pos, int cursum, int target, int & ans)
{
    if(pos >= nums.size())
    {
        if(target == cursum){
            ++ans;
        }
        return;
    }

    findTargetSumWays(nums, pos + 1, cursum + nums[pos], target, ans);
    findTargetSumWays(nums, pos + 1, cursum - nums[pos], target, ans);
} 

int findTargetSumWays(vector<int>& nums, int target)
{
    int ans = 0;
    findTargetSumWays(nums, 0, 0, target, ans);
    return ans;
}


int findTargetSumWays2(vector<int>& nums, int target)
{
    if(nums.size() == 0) {
        return 0;
    }

    std::unordered_map<int, int> map;
    ++map[nums[0]], ++map[-nums[0]];
    for(int i = 1; i < nums.size(); ++i)
    {
        std::unordered_map<int, int> newMap;
        for(const auto & oPair : map) 
        {
            newMap[oPair.first + nums[i]] += oPair.second;
            newMap[oPair.first - nums[i]] += oPair.second;
        }
        swap(newMap, map);
    }
    
    return map[target];
}