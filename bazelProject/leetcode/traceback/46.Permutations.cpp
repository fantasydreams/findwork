#include "46.Permutations.h"
#include <algorithm>
#include <vector>

void backtrace(const vector<int> & nums, vector<int> & place, vector<vector<int>> & res, vector<int> & tmp)
{
    if(tmp.size() == nums.size()) 
    {
        res.push_back(tmp);
        return;
    }
    
    for(int i = 0; i < place.size(); ++i)
    {
        if(place[i] == 0)
        {
            tmp.push_back(nums[i]);
            place[i] = 1;
            backtrace(nums, place, res, tmp);
            tmp.erase(tmp.begin() + tmp.size() - 1);
            place[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> tmp;
    vector<int> place(nums.size(), 0);
    for(int i = 0; i < nums.size(); ++i) 
    {
        tmp.push_back(nums[i]);
        place[i] = 1;
        backtrace(nums, place, res, tmp);
        tmp.erase(tmp.begin() + tmp.size() - 1);
        place[i] = 0;
    }

    return res;
}

void backtrace1(vector<int> &nums,int idx,vector<vector<int>> &res)
{
    if(idx >= nums.size()) 
    {
        res.push_back(nums);
        return;
    }

    for(int i = idx; i < nums.size(); ++i)
    {
        swap(nums[idx], nums[i]);
        backtrace1(nums, idx + 1, res);
        swap(nums[idx], nums[i]);
    }
}


vector<vector<int>> permute1(vector<int>& nums)
{
    vector<vector<int>> res;
    backtrace1(nums, 0, res);
    return res;
}


void bt(vector<int>& nums, int idx, vector<vector<int> >& ans) {
    if(idx >= nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int i = idx ; i < nums.size(); ++i) {
        swap(nums[idx], nums[i]);
        bt(nums, idx + 1, ans);
        swap(nums[idx], nums[i]);
    }
}


vector<vector<int>> permute2(vector<int>& nums) { // 2023/8/16
    std::vector<std::vector<int>>  ans;

    bt(nums, 0, ans);

    return ans;
}


vector<vector<int> > permute3(vector<int>& nums1) {
    vector<int>& nums = nums1;
    std::sort(nums.begin(), nums.end());
    vector<vector<int> > vecAns;
    vecAns.push_back(nums);
    while(std::next_permutation(nums.begin(), nums.end())) {
        vecAns.push_back(nums);
    }

    return vecAns;
}

void traceback4(vector<int>& nums, int idx, vector<vector<int> >& vecAns) {
    if(idx >= nums.size()) {
        vecAns.push_back(nums);   
        return;
    }

    for(int i = idx; i < nums.size(); ++i) {
        swap(nums[i], nums[idx]);
        traceback4(nums, idx + 1, vecAns);
        swap(nums[i], nums[idx]);
    }
}

vector<vector<int> > permute4(vector<int>& nums) {
    std::vector<vector<int> > vecAns;
    traceback4(nums, 0, vecAns);
    return vecAns;
}