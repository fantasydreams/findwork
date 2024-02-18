#include "57.InsertInterval.h"
#include <algorithm>
#include <iterator>
#include "56.MergeIntervals.h"

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


// https://leetcode.wang/leetCode-57-Insert-Interval.html 思路启发
vector<vector<int> > insert1(vector<vector<int> >& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
}

vector<vector<int> > insert2(vector<vector<int> >& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    return merge(intervals);
}


// 硬找位置
vector<vector<int> > insert3(vector<vector<int> >& intervals, vector<int>& newInterval) {
    //为空
    std::vector<std::vector<int> >vecAns;
    if(intervals.empty()) {
        vecAns.emplace_back(newInterval);
        return vecAns;
    }

    // 全新区间在第一个位置
    if(newInterval[1] < intervals[0][0]) {
        vecAns = intervals;
        vecAns.insert(vecAns.begin(), newInterval);
        return vecAns;
    }

    // 全新区间在最后一个位置
    if(newInterval[0] > intervals.back()[1]) {
        vecAns = intervals;
        vecAns.emplace_back(newInterval);
        return vecAns;
    }

    // 找区间位置
    int iFindIdx = intervals.size();
    for(int i = 0; i < intervals.size(); ++i) {
        if(intervals[i][1] >= newInterval[0]) {
            if(intervals[i][0] > newInterval[1]) { // 全新区间
                vecAns.emplace_back(newInterval);
                for(int j = i;j < intervals.size(); ++j) {
                    vecAns.emplace_back(intervals[j]);
                }
                return vecAns;
            }

            iFindIdx = i;
            break;
        }else {
            vecAns.push_back(intervals[i]);
        }
    }

    if(iFindIdx == intervals.size()) {
        vecAns.emplace_back(newInterval);
        return vecAns;
    }

    int iLeft = std::min(intervals[iFindIdx][0], newInterval[0]);
    int iIdx = iFindIdx;
    while(iIdx < intervals.size() && intervals[iIdx][1] < newInterval[1]) {
        if(iIdx + 1 < intervals.size() && intervals[iIdx + 1][0] > newInterval[1]) {
            break;
        }
        ++iIdx;
    }

    iIdx = std::min(iIdx, (int)intervals.size() - 1);
    int iRight = std::max(intervals[iIdx][1], newInterval[1]);
    vecAns.push_back({iLeft, iRight});
    while(++iIdx < intervals.size()) {
        vecAns.push_back(intervals[iIdx]);
    }

    return vecAns;
}