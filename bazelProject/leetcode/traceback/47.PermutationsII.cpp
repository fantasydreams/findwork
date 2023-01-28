#include "47.PermutationsII.h"
#include <set>
#include <algorithm>

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