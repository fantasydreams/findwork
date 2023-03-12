#include "697.DegreeofanArray.h"
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <tuple>

int findShortestSubArray(vector<int>& nums) {
    int ans = 0, freq = 0;
    unordered_map<int, std::pair<int,int>> hashMap;
    unordered_map<int, int> hashFreq;
    for(int i = 0; i < nums.size(); ++i) {
        auto & [left, right] = hashMap[nums[i]];
        if(hashFreq.count(nums[i]) == 0) {
            left = i;
        }
        right = i;
        hashFreq[nums[i]]++;
        auto pIter = hashFreq.find(nums[i]);
        if(pIter->second > freq) {
            freq = pIter->second;
            ans = right - left + 1;
        }else if(pIter->second == freq) {
            ans = std::min(ans, right - left + 1);
        }
    }

    return ans;
}

int findShortestSubArray1(vector<int>& nums) {
    int ans = 0, _freq = 0;
    unordered_map<int, std::tuple<int,int,int>> hashMap; //[freq, left, right]
    for(int i = 0; i < nums.size(); ++i) {
        auto & [freq, left, right] = hashMap[nums[i]];
        if(freq == 0) {
            left = i;
        }
        right = i;
        freq += 1;

        if(freq > _freq) {
            ans = right - left + 1;
            _freq = freq;
        }else if(freq == _freq) {
            ans = std::min(ans, right - left + 1);
        }
    }

    return ans;
}