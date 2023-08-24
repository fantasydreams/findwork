#include "57.InsertInterval.h"
#include <algorithm>
#include <iterator>

vector<vector<int>> insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    if(intervals.empty()) {
        ans.emplace_back(newInterval);
        return ans;
    }

    // 如果在所有序列之前
    if(intervals[0][0] > newInterval[1]) {
        ans = intervals;
        ans.insert(ans.begin(), newInterval);
        return ans;
    }

    // 找到在有序序列中的位置
    int findIdx = intervals.size();
    for(int i = 0; i < intervals.size(); ++i) {
        if(intervals[i][1] >= newInterval[0]) {
            if(intervals[i][0] > newInterval[1]) {
                ans.emplace_back(newInterval);
                for(int k = i; k < intervals.size(); ++k) {
                    ans.emplace_back(intervals[k]);
                }
                return ans;
            }else if(intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[1]) {
                ans = intervals;
                ans[i][0] = std::min(intervals[i][0], newInterval[0]);
                ans[i][1] = std::max(intervals[i][1], newInterval[1]);
                return ans;
            }

            findIdx = i;
            break;
        }else {
            ans.emplace_back(intervals[i]);
        }
    }
    
    if(findIdx == intervals.size()) {
        ans.emplace_back(newInterval);
        return ans;
    }

    int rightIdx = findIdx;
    while(rightIdx < intervals.size() && intervals[rightIdx][0] <= newInterval[1]) {
        ++rightIdx;
    }

    

    ans.push_back({std::min(intervals[findIdx][0], newInterval[0]), std::max(newInterval[1], intervals[rightIdx - 1][1])});
    for(int i = rightIdx; i < intervals.size(); ++i) {
        ans.push_back(intervals[i]);
    }

    return ans;
}