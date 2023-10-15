#include "137.SingleNumberII.h"
#include <unordered_map>

int singleNumberHash(vector<int>& nums) {
    std::unordered_map<int, short> mc;
    for(const auto & num : nums) {
        ++mc[num];
    }

    for(const auto &oPair : mc) {
        if(oPair.second != 3) {
            return oPair.first;
        }
    }

    return 0;
}


// https://www.cnblogs.com/grandyang/p/4263927.html
int singleNumberBit(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
        int sum = 0;
        for(int j = 0; j < nums.size(); ++j) {
            sum += (nums[j] >> i) & 0x1;
        } 

        if(sum % 3) {
            ans += 1 << i;
        }
    }

    return ans;
}

// https://hanfeng.ink/post/bitwise/
int singleNumberBit1(vector<int>& nums) {
    int one = 0, two = 0;
    for(const auto& num : nums) {
        one = (one ^ num) & (~two);
        two = (two ^ num) & (~one);
    }

    return one;
}

