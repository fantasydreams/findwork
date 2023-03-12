#include "870.AdvantageShuffle.h"
#include <algorithm>
#include <numeric>
#include <map>

vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    for(int i = nums2.size() - 1; i >= 0; --i) {
        auto pIter = upper_bound(nums1.begin(), nums1.end(), nums2[i]);
        if(pIter != nums1.end()) {
            ans.push_back(*pIter);
            nums1.erase(pIter);
        }else {
            ans.push_back(*nums1.begin());
            nums1.erase(nums1.begin());
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> advantageCount1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    map<int, int> hashMap;
    for(int i = 0; i < nums1.size(); ++i) {
        ++hashMap[nums1[i]];
    }

    for(int i = nums2.size() - 1; i >= 0; --i) {
        auto pIter = hashMap.upper_bound(nums2[i]);
        if(pIter != hashMap.end()) {
            ans.push_back(pIter->first);
            --(pIter->second);
            if(pIter->second == 0) {
                hashMap.erase(pIter);
            }
        }else {
            ans.push_back(hashMap.begin()->first);
            --(hashMap.begin()->second);
            if(hashMap.begin()->second == 0) {
                hashMap.erase(hashMap.begin());
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> advantageCount2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    map<int, int> hashMap;
    for(int i = 0; i < nums1.size(); ++i) {
        ++hashMap[nums1[i]];
    }

    for(int i = 0; i < nums2.size(); ++i) {
        auto pIter = hashMap.upper_bound(nums2[i]);
        if(pIter != hashMap.end()) {
            ans.push_back(pIter->first);
            --(pIter->second);
            if(pIter->second == 0) {
                hashMap.erase(pIter);
            }
        }else {
            ans.push_back(hashMap.begin()->first);
            --(hashMap.begin()->second);
            if(hashMap.begin()->second == 0) {
                hashMap.erase(hashMap.begin());
            }
        }
    }

    return ans;
}