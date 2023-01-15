#include "215.KthLargestElementinanArray.h"
#include <cmath>
int findKthLargest(vector<int>& nums, int k)
{
    int l = 0, r = nums.size() - 1, tmp, i, j;
    while(l < r)
    {
        i = l, j = r;
        while(i < j)
        {
            while(i < j && nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[j], nums[i]);

            while(i < j && nums[i] >= nums[j]){
                ++i;
            }
            swap(nums[i], nums[j]);
        }

        if(j == k - 1) {
            return nums[j];
        }else if(j > k - 1) {
            r = j - 1;
        }else {
            l = j + 1;
        }
    }

    return nums[r];
}