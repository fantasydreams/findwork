#include "80.RemoveDuplicatesfromSortedArrayII.h"

int removeDuplicates(vector<int>& nums) {
    int left = 0, cnt = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(left == 0) {
            nums[left++] = nums[i];
            cnt = 1;
        }else {
            if(nums[i] == nums[left - 1]) {
                ++cnt;
                if(cnt < 3) {
                    nums[left++] = nums[i];
                }
            }else {
                nums[left++] = nums[i];
                cnt = 1;
            }
        }
    }

    return left;
}