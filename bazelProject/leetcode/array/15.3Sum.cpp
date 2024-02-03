#include "15.3Sum.h"


vector<vector<int> > twoSum(const vector<int>& nums, int b, int e, int target) {
    std::vector<vector<int> > vecAns;
    while(b < e) {
        int iSum = nums[b] + nums[e];
        if(iSum == target) {
            vecAns.push_back({nums[b], nums[e]});
            while(b < --e && nums[e] == nums[e + 1]);
            while(++b < e && nums[e] == nums[b - 1]);
        }else if(iSum < target){
            ++b;
        }else {
            --e;
        }
    }

    return vecAns;
}

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > vecAns;
    int b = 0, e = nums.size() - 1;
    std::sort(nums.begin(), nums.end());

    while(b + 1 < e) {
        vector<vector<int> > vecTmp = twoSum(nums, b + 1, e, 0 - nums[b]);
        for(int i = 0; i < vecTmp.size(); ++i) {
            vecTmp[i].insert(vecTmp[i].begin(), nums[b]);
            vecAns.emplace_back(std::move(vecTmp[i]));
        }

        while(++b < e && nums[b] == nums[b - 1]);
    }
    return vecAns;
}