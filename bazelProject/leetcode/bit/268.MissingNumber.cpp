#include "268.MissingNumber.h"
#include <algorithm>

int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i) {
        if(i != nums[i]) {
            return i;
        }
    }

    return nums.size();
}

int missingNumber1(vector<int>& nums) {
    int ans = nums.size();
    for(int i = 0; i < nums.size(); ++i) {
        ans ^= i;
        ans ^= nums[i];
    }

    return ans;
}