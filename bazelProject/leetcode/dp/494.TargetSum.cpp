#include "494.TargetSum.h"


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