#include "46.Permutations.h"

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