#include "136.SingleNumber.h"

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
        ans ^= nums[i];
    }

    return ans;
}

int singleNumber1(vector<int> &nums) {
    int ans = 0;
    for(const auto& num : nums) {
        ans ^= num;
    }

    return ans;
}