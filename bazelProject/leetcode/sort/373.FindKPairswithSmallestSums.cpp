#include "373.FindKPairswithSmallestSums.h"
#include <queue>
#include <tuple>

class Compare {
public:
    bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<0>(a) > std::get<0>(b);
    }
};

vector<vector<int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int> >,Compare> que;
    bool bFlag = false;
    if(nums1.size() > nums2.size()) {
        swap(nums1, nums2);
        bFlag = true;
    }

    for(int i = 0; i < nums1.size(); ++i) {
        que.push({nums1[i] + nums2[0], i, 0});
    }

    std::vector<vector<int> > vecAns;
    while(vecAns.size() < k && !que.empty()) {
        auto [val, x, y] = que.top(); que.pop();
        if(bFlag) {
            vecAns.push_back({nums2[y], nums1[x]});
        }else {
            vecAns.push_back({nums1[x], nums2[y]});
        }
        if(y + 1 < nums2.size()) {
            que.push({nums1[x] + nums2[y + 1], x, y + 1});
        }
    }

    return vecAns;
}


vector<vector<int> > kSmallestPairs1(vector<int>& nums1, vector<int>& nums2, int k) {
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int> >,Compare> que;

    for(int i = 0; i < std::min(nums1.size(), nums2.size()); ++i) {
        que.push({nums1[i] + nums2[0], i, 0});
    }

    std::vector<vector<int> > vecAns;
    while(vecAns.size() < k && !que.empty()) {
        auto [val, x, y] = que.top(); que.pop();
        vecAns.push_back({nums1[x], nums2[y]});
        if(y + 1 < nums2.size()) {
            que.push({nums1[x] + nums2[y + 1], x, y + 1});
        }
    }

    return vecAns;
}