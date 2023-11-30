#include "229.MajorityElementII.h"
#include <unordered_map>

vector<int> majorityElement(vector<int>& nums) {
    std::unordered_map<int, int> mapCnt;
    int oneThird = nums.size() / 3;
    for(int i = 0; i < nums.size(); ++i) {
        ++mapCnt[nums[i]];
    }

    std::vector<int> vecAns;
    for(auto pIter = mapCnt.begin(); pIter != mapCnt.end(); ++pIter) {
        if(pIter->second > oneThird) {
            vecAns.push_back(pIter->first);
        }
    }

    return vecAns;
}


// https://leetcode.cn/problems/majority-element-ii/solutions/1058790/qiu-zhong-shu-ii-by-leetcode-solution-y1rn/

vector<int> majorityElement1(vector<int>& nums) {
    int vote1 = 0, vote2 = 0;
    int num1 = 0, num2 = 0;
    for(const auto& oItem : nums) {
        if(vote1 > 0 && oItem == num1) {
            ++vote1;
        }else if(vote2 > 0 && oItem == num2) {
            ++vote2;
        }else if(vote1 == 0) {
            ++vote1;
            num1 = oItem;
        }else if(vote2 == 0) {
            ++vote2;
            num2 = oItem;
        }else {
            --vote1;
            --vote2;
        }
    }

    int iCnt1 = 0, iCnt2 = 0;
    for(const auto& oItem : nums) {
        if(vote1 > 0 && oItem == num1) {
            ++iCnt1;
        }
        if(vote2 > 0 && oItem == num2) {
            ++iCnt2;
        }
    }

    std::vector<int> vecAns;
    if(vote1 > 0 && iCnt1 > nums.size() / 3 ) {
        vecAns.push_back(num1);
    }
    if(vote2 > 0 && iCnt2 > nums.size() / 3) {
        vecAns.push_back(num2);
    }

    return vecAns;
}