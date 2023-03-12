#include "287.FindtheDuplicateNumber.h"
#include <algorithm>
#include <unordered_set>

int findDuplicate(vector<int>& nums) {
    std::unordered_set<int> hash;
    for(int i = 0; i < nums.size(); ++i) {
        if(hash.count(nums[i])) {
            return nums[i];
        }
        hash.insert(nums[i]);
    }
    return 0;
}

int findDuplicate1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i - 1]) {
            return nums[i];
        }
    }
    return 0;
}

int findDuplicate2(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
        int idx = abs(nums[i]);
        if(nums[idx - 1] < 0) {
            return idx;
        }else {
            nums[idx - 1] = -nums[idx - 1];
        }
    }
    return 0;
}

int findDuplicate3(vector<int>& nums) {
    int fast = 0, slow = 0;
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    slow = 0;
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}