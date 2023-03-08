#include "448.FindAllNumbersDisappearedinanArray.h"
#include <algorithm>

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    vector<bool> record(nums.size() + 1, false);
    for(int i = 0; i < nums.size(); ++i) {
        record[nums[i]] = true;
    }

    for(int i = 1; i < record.size(); ++i) {
        if(record[i] == false) {
            ans.push_back(i);
        }
    }
    return ans;
}


vector<int> findDisappearedNumbers1(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); ++i) {
        int pos = abs(nums[i]) - 1;
        if(nums[pos] > 0) {
            nums[pos] = -nums[pos];
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] > 0) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}