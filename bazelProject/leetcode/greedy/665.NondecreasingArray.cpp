#include "665.NondecreasingArray.h"
bool checkPossibility(std::vector<int>& nums)
{
    int iCnt = 0;
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] < nums[i - 1])
        {
            if(i == 1 || i == nums.size() - 1 || ((nums[i + 1] >= nums[i - 1]) || (nums[i - 2] <= nums[i]))) {
                ++iCnt;
            }else {
                return false;
            }
            
            if(iCnt > 1) {
                return false;
            } 
        }
    }

    return true;
}