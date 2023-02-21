#include "376.WiggleSubsequence.h"
#include <cmath>


//问题简化为找山顶和山顶的数量 
int wiggleMaxLength(vector<int>& nums)
{
    int peak = 1, valley = 1;
    for(int i = 1; i < nums.size(); ++i)
    {
        int diff = nums[i] - nums[i - 1];
        if(diff > 0) {
            peak = valley + 1;
        }else if(diff < 0) {
            valley = peak + 1;
        }
    }

    return std::max(valley, peak);
}


//直接比较，这里不能记录第一次翻转的下标，有些情况下可能丢失翻转记录，如： 1 17 20 19 ，第一次翻转在17，如果记录之后，后面的相对于他都没有进行翻转，丢失了20这个顶点
int wiggleMaxLength1(vector<int>& nums)
{
    if(nums.size() <= 1) {
        return nums.size();
    }

    int count = 1;
    int pre_diff = nums[1] - nums[0];
    if(pre_diff != 0) {
        count += 1;
    }
    for(int i = 2; i < nums.size(); ++i)
    {
        int cur_diff = nums[i] - nums[i - 1];
        if((cur_diff > 0 && pre_diff <= 0) ||  (cur_diff < 0 && pre_diff >= 0))
        {
            count += 1;
            pre_diff = cur_diff;
        }
    }

    return count;
}