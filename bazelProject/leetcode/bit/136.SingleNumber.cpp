#include "136.SingleNumber.h"

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
        ans ^= nums[i];
    }

    return ans;
}