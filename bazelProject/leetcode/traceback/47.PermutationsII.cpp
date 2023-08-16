#include "47.PermutationsII.h"
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void traceback(vector<int> & nums, int pos, std::set<vector<int>> & ans)
{
    if(pos >= nums.size()) 
    {
        ans.insert(nums);
        return;
    }

    for(int i = pos; i < nums.size(); ++i)
    {
        swap(nums[i], nums[pos]);
        traceback(nums, pos + 1, ans);
        swap(nums[i], nums[pos]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
    set<vector<int>> ans;
    traceback(nums, 0, ans);
    return vector<vector<int>>(ans.begin(), ans.end());
}


void traceback1(vector<int> & nums, vector<bool> & picked, std::vector<vector<int>> & ans, vector<int> & tmp)
{
    if(nums.size() == tmp.size()) 
    {
        ans.push_back(tmp);
        return;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        if(picked[i] || (i > 0 && nums[i] == nums[i - 1] && !picked[i-1])) {
            continue;
        }
        picked[i] = true;
        tmp.push_back(nums[i]);
        traceback1(nums, picked, ans, tmp);
        tmp.pop_back();
        picked[i] = false;
    }
}

vector<vector<int>> permuteUnique1(vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<bool> picked(nums.size(), false);
    vector<int> tmp;
    traceback1(nums, picked, ans, tmp);
    return ans;
}


void bt(vector<int>& nums, int idx, std::set<std::vector<int> > &setUniq) {
    if(idx >= nums.size()) {
        setUniq.insert(nums);
        return;
    }

    for(int i = idx; i < nums.size(); ++i) {
        swap(nums[i], nums[idx]);
        bt(nums, idx + 1, setUniq);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int> > permuteUnique2(vector<int>& nums) { // 2023/8/16
    std::set<std::vector<int> > setUniq;
    bt(nums, 0, setUniq);
    return vector<vector<int> >(setUniq.begin(), setUniq.end());
}


void bt1(const vector<int>& nums, vector<bool>& picked, vector<int>& tmp, vector<vector<int> >& ans) {
    if(tmp.size() == nums.size()) {
        ans.push_back(tmp);
        return;
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(picked[i] || (i > 0 && nums[i] == nums[i - 1] && !picked[i - 1])) {
            continue;
        }

        picked[i] = true;
        tmp.push_back(nums[i]);
        bt1(nums, picked, tmp, ans);
        tmp.pop_back();
        picked[i] = false;  
    }
}


vector<vector<int> > permuteUnique3(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<bool> picked(nums.size(), false);
    vector<int> tmp;
    vector<vector<int> > ans;
    bt1(nums, picked, tmp, ans);
    return ans;
}