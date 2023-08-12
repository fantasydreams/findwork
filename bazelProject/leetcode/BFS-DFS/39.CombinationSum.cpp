#include "39.CombinationSum.h"
#include <vector>

void dfs(const vector<int>&candidates, int idx, int cur, int target, vector<int>& tmp, vector<vector<int> >& ans) {
    if(idx < 0 || idx >= candidates.size()) {
        return;
    }

    if(cur > target) {
        return;
    }

    if(cur == target) {
        ans.push_back(tmp);
        return;
    }

    for(int i = idx; i < candidates.size(); ++i) {
        tmp.push_back(candidates[i]);
        dfs(candidates, i, cur + candidates[i], target, tmp, ans);
        tmp.pop_back();
    }
}


vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    vector<int> tmp;
    dfs(candidates, 0, 0, target, tmp, ans);
    return ans;
}