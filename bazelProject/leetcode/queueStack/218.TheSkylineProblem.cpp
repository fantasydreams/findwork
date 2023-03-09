#include "218.TheSkylineProblem.h"
#include <queue>
#include <algorithm>
#include <set>

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<std::pair<int, int>> heigt;
    for(const auto & vec : buildings) {
        heigt.push_back({vec[0], -vec[2]});
        heigt.push_back({vec[1], vec[2]});
    } 

    sort(heigt.begin(), heigt.end());
    multiset<int, std::greater<int>> mSet;
    mSet.insert(0);
    vector<vector<int>> ans;
    for(const auto & [x, h] : heigt) {
        if(h < 0) {
            if(-h > (*mSet.begin())) {
                ans.push_back({x, -h});
            }
            mSet.insert(-h);
        }else {
            mSet.erase(mSet.find(h));
            if(h > (*mSet.begin())) {
                ans.push_back({x, (*mSet.begin())});
            }
        }
    }

    return ans;
}

vector<vector<int>> getSkyline1(vector<vector<int>>& buildings) {
    priority_queue<pair<int, int>> max_heap;
    int cur_x;
    decltype(buildings.size()) idx = 0;
    vector<vector<int>> ans;
    while(idx < buildings.size() || !max_heap.empty()) {
        if(max_heap.empty() || (idx < buildings.size() && buildings[idx][0] <= max_heap.top().second)) {
            cur_x = buildings[idx][0];
            while(idx < buildings.size() && cur_x == buildings[idx][0]) {
                max_heap.push({buildings[idx][2], buildings[idx][1]});
                ++idx;
            }
        }else {
            cur_x = max_heap.top().second;
            while(!max_heap.empty() && cur_x >= max_heap.top().second) {
                max_heap.pop();
            }
        }

        int cur_h = max_heap.empty() ? 0 : max_heap.top().first;
        if(ans.empty() || cur_h != ans.back()[1]) {
            ans.push_back({cur_x, cur_h});
        }
    } 

    return ans;
}