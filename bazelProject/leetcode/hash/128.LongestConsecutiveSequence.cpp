#include "128.LongestConsecutiveSequence.h"
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

int longestConsecutive(vector<int>& nums) {
    int ans = 0, tmp = 0;
    // unordered_set<int> hashSet;
    // for(decltype(nums.size()) idx = 0; idx < nums.size(); ++idx) {
    //     hashSet.insert(nums[idx]);
    // }

    // unordered_set<int>::iterator preIter = hashSet.begin();
    // for(auto pIter = hashSet.begin(); pIter != hashSet.end(); ++pIter) {
    //     if(*pIter == ((*preIter) + 1)) {
    //         ++tmp;
    //     }else {
    //         tmp = 1;
    //     }
    //     ans = std::max(tmp, ans);
    //     preIter = pIter;
    // }
    // 这段不能这么写，unordered_set遍历不会自然有序的

    

    unordered_map<int, int> hash_map;
    for(const auto & num : nums) {
        hash_map.insert({num, 1});
    }

    for(auto pIter = hash_map.begin(); pIter != hash_map.end(); ++pIter) {
        if(pIter->second == 1) {
            int data = pIter->first - 1;
            while(hash_map.count(data - 1)) {
                --data;
            }

            data += 1;
            data = pIter->first;
            while(hash_map.count(data + 1)) {
                hash_map[data + 1] = hash_map[data] + 1;
                ++data;
            }
            ans = std::max(ans, hash_map[data]);
        }
    }

    return ans;
}


//改一下策略，删除某个值的前后
int longestConsecutive1(vector<int>& nums) {
    int ans = 0, tmp = 0;
    unordered_set<int> hash_set;
    for(const auto & num : nums) {
        hash_set.insert(num);
    }

    while(!hash_set.empty()) {
        int data = *hash_set.begin();
        int cnt = 0, tmp = data;
        while(hash_set.count(tmp - 1)) {
            --tmp;
            ++cnt;
            hash_set.erase(tmp);
        }

        while(hash_set.count(data)) {
            hash_set.erase(data);
            ++data;
            ++cnt;
        }

        ans = max(ans, cnt);
    }

    return ans;
}

int longestConsecutive2(vector<int>& nums) {
    unordered_set<int> hash(nums.begin(), nums.end());
    int ans = 0;
    while(!hash.empty()) {
        int len = 1;
        int cur = *hash.begin();
        int find = cur + 1;
        hash.erase(cur);

        std::unordered_set<int>::iterator pIter = hash.find(find);
        while(pIter != hash.end()) {
            ++len;
            hash.erase(pIter);
            pIter = hash.find(++find);
        }

        find = cur - 1;
        pIter = hash.find(find);
        while(pIter != hash.end()) {
            ++len;
            hash.erase(pIter);
            pIter = hash.find(--find);
        }

        ans = std::max(ans, len);
    }

    return ans;
}

// 这个是不对的，出现重复的数字，计算结果就不对了
int longestConsecutive3(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    std::sort(nums.begin(), nums.end());
    int ans = 1, tmp = 1;
    for(int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i - 1] + 1) {
            ++tmp;
            ans = std::max(ans, tmp);
        }
        else if(nums[i] == nums[i - 1]) {
            continue;
        }else {
            tmp = 1;
        }
    }

    return ans;
}