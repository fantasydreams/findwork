#include "179.LargestNumber.h"

string largestNumber(vector<int>& nums) {
    std::vector<std::vector<std::string> >hash(10, std::vector<std::string>()); // 0-9
    for(int i = 0; i < nums.size(); ++i) {
        std::string str = std::to_string(nums[i]);
        hash[str[0] - '0'].emplace_back(std::move(str));
    }

    for(int i = 0; i < hash.size(); ++i) {
        std::sort(hash[i].begin(), hash[i].end(), [&](std::string& str1, std::string& str2) {
            std::string s1 = str1 + str2;
            std::string s2 = str2 + str1;
            return s1 > s2;
        });
    }
    std::string ans;

    for(int i = 9; i >= 0; --i) {
        for(auto& str : hash[i]) {
            ans += str;
            if(ans == "0") {
                return ans;
            }
        }
    }

    
    return ans;
}