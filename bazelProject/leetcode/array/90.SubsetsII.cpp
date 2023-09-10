#include "90.SubsetsII.h"
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

void bt(vector<vector<int> > &ans, int pos, const vector<int>& nums, std::vector<int>& tmp) {
    if(pos >= nums.size()) {
        ans.emplace_back(tmp);
        return;
    }

    tmp.push_back(nums[pos]);
    bt(ans, pos + 1, nums, tmp);
    tmp.pop_back();

    bt(ans, pos+ 1, nums, tmp);
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > tmp;
    sort(nums.begin(), nums.end());
    vector<int> record;
    bt(tmp, 0, nums, record);
    std::set<std::vector<int> > set(tmp.begin(), tmp.end());
    vector<vector<int> > ans(set.begin(), set.end());
    return ans;
}


void bt1(vector<vector<int> > &ans, int pos, const vector<int>& nums, std::vector<int>& tmp) {
    ans.emplace_back(tmp);

    for(int i = pos; i < nums.size(); ++i) { // 这里能够保证所有的都能入选
        if(i > pos && nums[i] == nums[i - 1]){ // 这里能保证所有元素能入选
            continue;
        }
        
        tmp.push_back(nums[i]);
        bt1(ans, i + 1, nums, tmp);
        tmp.pop_back(); // 往后退的过程中，就能保证序列不重复但是重复的元素的个数n (1-n)的情况都能选上, 同时保证不重复
    }    


}

vector<vector<int> > subsetsWithDup1(vector<int>& nums) {
    vector<vector<int> > ans;
    sort(nums.begin(), nums.end());
    vector<int> record;
    bt1(ans, 0, nums, record);
    return ans;
}