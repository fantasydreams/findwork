#include "78.Subsets.h"


void getSubsets(vector<vector<int> >& ans, vector<int>& nums, int pos, vector<bool>& vecSelected) {
    if(pos >= nums.size()) {
        std::vector<int> oRecord;
        for(int i = 0; i < vecSelected.size(); ++i) {
            if(vecSelected[i] == true) {
                oRecord.push_back(nums[i]);
            }
        }
        ans.emplace_back(oRecord);
        return;
    }

    getSubsets(ans, nums, pos + 1, vecSelected);
    vecSelected[pos] = true;
    getSubsets(ans, nums, pos + 1, vecSelected);
    vecSelected[pos] = false;
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > ans;

    std::vector<bool> vecSelected(nums.size(), false);
    getSubsets(ans, nums, 0, vecSelected);
    return ans;
}