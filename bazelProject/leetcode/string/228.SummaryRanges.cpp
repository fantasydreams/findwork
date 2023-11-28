#include "228.SummaryRanges.h"
#include <string>

vector<string> summaryRanges(vector<int>& nums) {
    std::vector<std::string> vecAns;
    if(nums.empty()) {
        return vecAns;
    }

    int pre = nums[0];
    for(int i = 1; i <= nums.size(); ++i) {
        if(i == nums.size() || nums[i] != nums[i - 1] + 1) {
            if(pre == nums[i - 1]) {
                vecAns.push_back(std::to_string(pre));
            }else {
                vecAns.push_back(std::to_string(pre) + "->" + std::to_string(nums[i - 1]));
            }

            if(i != nums.size()) {
                pre = nums[i];
            }
        }
    }

    return vecAns;
}