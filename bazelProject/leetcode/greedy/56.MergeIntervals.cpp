#include "56.MergeIntervals.h"
#include <algorithm>

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    vector<vector<int> > ans;
    if(intervals.empty()) {
        return ans;
    }

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    });
    int iMin = intervals[0][0], iMax = intervals[0][1];
    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i][0] <= iMax) {
            iMax = std::max(iMax, intervals[i][1]);
        }else {
            ans.push_back({iMin, iMax});
            iMin = intervals[i][0];
            iMax = intervals[i][1];
        }
    }

    ans.push_back({iMin, iMax});
    return ans;
}