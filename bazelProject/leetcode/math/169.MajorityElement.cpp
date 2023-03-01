#include "169.MajorityElement.h"

int majorityElement(vector<int>& nums) {
    int major = nums[0], cnt = 1;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == major) {
            ++cnt;
        }else {
            if(cnt) {
                --cnt;
            }else {
                major = nums[i];
                cnt = 1;
            }
        }
    }

    return major;
}